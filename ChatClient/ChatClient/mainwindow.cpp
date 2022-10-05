#include "mainwindow.h"
#include "qdatetime.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QScrollBar>
#include "MsgTypes.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(std::make_unique<Ui::MainWindow>())
{
    ui_->setupUi(this);
    ui_->menu_w->hide();
    ui_->tab_w->setCurrentIndex(0);
    ui_->chat_w->hide();
    ui_->contacts_lw->setSelectionMode(QAbstractItemView::ExtendedSelection);

    socket_ = new QTcpSocket;
    connect(socket_, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket_, &QTcpSocket::disconnected, this, &MainWindow::slotDisconnected);

    reg_window_ = new RegistrationWindow;
    connect(reg_window_, &::RegistrationWindow::signalTryReg, this, &::MainWindow::slotTryReg);
    connect(this, &MainWindow::signalToReg, reg_window_, &RegistrationWindow::slotToReg);
    connect(this, &MainWindow::signalClearRegWindow, reg_window_, &RegistrationWindow::slotClearWindow);

    add_contact_window_ = new AddContact;
    connect(add_contact_window_, &::AddContact::signalTryAdd, this, &::MainWindow::slotTryAdd);
    connect(this, &MainWindow::signalAddError, add_contact_window_, &AddContact::slotAddError);
    connect(this, &MainWindow::signalClearAddWindow, add_contact_window_, &AddContact::slotClearWindow);

    create_gc_window_ = new CreateGroupChat;
    connect(create_gc_window_, &CreateGroupChat::signalTryCreateGC, this, &MainWindow::slotTryCreateGC);
    connect(this, &MainWindow::signalCreateGCError, create_gc_window_, &CreateGroupChat::slotCreateGCError);

    connect(ui_->chat_list_lw, &QListWidget::itemClicked, this, &MainWindow::on_chat_list_clicked);
    connect(ui_->tab_w, &QTabWidget::tabBarClicked, this, &MainWindow::on_menu_tab_clicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket_);
    in.setVersion(QDataStream::Qt_6_3);
    if (in.status() == QDataStream::Ok)
    {
        while(true)
        {
            if (data_size_ == 0)
            {
                if (socket_->bytesAvailable() < 2)
                    break;
                else
                    in >> data_size_;
            }
            else if (socket_->bytesAvailable() < data_size_)
                break;
            else
            {
                quint8 msg_type = 0;
                in >> msg_type;

                if (msg_type == reloaded_contacts)
                {
                    contacts_.clear();
                    ui_->contacts_lw->clear();
                    while (socket_->bytesAvailable())
                    {
                        QString word;
                        in >> word;
                        contacts_.push_back(word);
                        ui_->contacts_lw->addItem(word);
                    }
                }
                else if  (msg_type == req_chat_sending)
                {
                    ui_->chat_display->clear();
                    QByteArray chat_data;
                    in >> chat_data;
                    QDataStream str(&chat_data, QIODevice::ReadOnly);
                    QString first_word;
                    str >> first_word;
                    str.device()->seek(0);
                    if (first_word != "##NULL##")
                    {
                        while (!str.atEnd())
                        {
                            QString name, date, time, msg;
                            str >> name >> date >> time >> msg;
                            ui_->chat_display->setCurrentFont(QFont("Segoe UI", 12));
                            ui_->chat_display->setTextColor(QColor(28, 54, 148));
                            ui_->chat_display->append(name + ", " + date + ", " + time);
                            ui_->chat_display->setCurrentFont(QFont("Book Antiqua", 11));
                            ui_->chat_display->setTextColor(QColor(0, 0, 0));
                            ui_->chat_display->append(msg);
                        }
                        ui_->chat_display->verticalScrollBar()->setSliderPosition(ui_->chat_display->verticalScrollBar()->maximum());
                    }
                }
                else if(msg_type == succesful_create_gc)
                {
                    quint8 is_creator;
                    QString chat_name;
                    in >> is_creator >> chat_name;
                    ReloadChatName(chat_name);
                    if (is_creator == 1)
                    {
                        chat_name_ = chat_name;
                        ui_->chat_name_lbl->setText(chat_name_);
                        create_gc_window_->close();
                        ui_->menu_w->hide();
                        ui_->chat_display->clear();
                        ui_->chat_w->show();
                    }
                }
                else if(msg_type == unsuccesful_create_gc)
                    emit signalCreateGCError();
                else if(msg_type == unsuccesful_add)
                    emit signalAddError("nonexistant");
                else if(msg_type == succesful_add)
                {
                    bool is_inserted = false;
                    if (!contacts_.empty())
                        for (auto i = 0; i < contacts_.size(); ++i)
                            if (contacts_[i] > temp_name_)
                            {
                                contacts_.insert(i, temp_name_);
                                ui_->contacts_lw->insertItem(i, temp_name_);
                                is_inserted = true;
                                break;
                            }
                    if (!is_inserted)
                    {
                        contacts_.push_back(temp_name_);
                        ui_->contacts_lw->addItem(temp_name_);
                    }
                    emit signalClearAddWindow();
                    add_contact_window_->close();
                }
                else if(msg_type == succesful_reg)
                {
                    ui_->nickname_lbl->setText(name_);
                    reg_window_->close();
                    ui_->login_elbl->setText(name_);
                    ui_->pass_elbl->setText(pass_);
                    ui_->login_w->hide();
                    ui_->menu_w->show();
                    emit signalClearRegWindow();
                }
                else if(msg_type == unsuccesful_reg)
                    emit signalToReg("exists");
                else if (msg_type == unsuccesful_enter)
                    QMessageBox::critical(this, "Authorisation error", "Wrong login or password");
                else if (msg_type == succesful_enter)
                {
                    name_ = ui_->login_elbl->text();
                    ui_->nickname_lbl->setText(name_);
                    quint16 amount = 0;
                    in >> amount;
                    while (amount)
                    {
                        QString word;
                        in >> word;
                        chats_.push_back(word);
                        AddChatListItem(word);
                        --amount;
                    }
                    while (socket_->bytesAvailable())
                    {
                        QString word;
                        in >> word;
                        contacts_.push_back(word);
                        ui_->contacts_lw->addItem(word);
                    }
                    ui_->login_w->hide();
                    ui_->menu_w->show();
                }
                else
                {
                    QTime time;
                    QDateTime date;
                    QString name, data_str, chat_name;
                    in >> chat_name >> date >> time >> name >> data_str;
                    ReloadChatName(chat_name);
                    if (chat_name == chat_name_)
                    {
                        ui_->chat_display->setCurrentFont(QFont("Segoe UI", 12));
                        ui_->chat_display->setTextColor(QColor(28, 54, 148));
                        ui_->chat_display->append(name + ", " + date.toString("dd.MM.yyyy") + ", " + time.toString("hh:mm"));
                        ui_->chat_display->setCurrentFont(QFont("Book Antiqua", 11));
                        ui_->chat_display->setTextColor(QColor(0, 0, 0));
                        ui_->chat_display->append(data_str);
                    }
                }
                data_size_ = 0;
                break;
            }
        }
    }

}

void MainWindow::slotDisconnected()
{
    if (connection_lost_flag_)
        QMessageBox::critical(this, "Error", "Connection lost!");

    add_contact_window_->close();
    reg_window_->close();
    create_gc_window_->close();
    connection_lost_flag_ = true;
    ui_->menu_w->hide();
    ui_->tab_w->setCurrentIndex(0);
    ui_->chat_w->hide();
    ui_->login_w->show();
    ui_->chat_display->clear();
    ui_->type_field->clear();
    ui_->chat_list_lw->clear();
    ui_->contacts_lw->clear();
    ui_->nickname_lbl->clear();
    contacts_.clear();
    chats_.clear();
}

void MainWindow::SendToServer(QString data_str)
{
    QByteArray sended_data;
    QDataStream out(&sended_data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out << quint16(0) << quint8(message) << name_ << chat_name_ << data_str;
    out.device()->seek(0);
    out << quint16(sended_data.size() - sizeof(quint16));
    socket_->write(sended_data);
    ui_->type_field->clear();
}

void MainWindow::SendToServer(QString name, QString data, quint8 msg_type)
{
    QByteArray sended_data;
    QDataStream out(&sended_data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out << quint16(0) << msg_type << name << data;
    out.device()->seek(0);
    out << quint16(sended_data.size() - sizeof(quint16));
    socket_->write(sended_data);
}

void MainWindow::SendToServer(const QVector<QString> vec, quint8 msg_type)
{
    QByteArray sended_data;
    QDataStream out(&sended_data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out << quint16(0) << msg_type << name_;
    for (const auto& el : vec)
        out << el;
    out.device()->seek(0);
    out << quint16(sended_data.size() - sizeof(quint16));
    socket_->write(sended_data);
}

void MainWindow::SendToServer(const QString& chat_name, const quint8 msg_type)
{
    QByteArray sended_data;
    QDataStream out(&sended_data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out << quint16(0) << msg_type << name_ << chat_name;
    out.device()->seek(0);
    out << quint16(sended_data.size() - sizeof(quint16));
    socket_->write(sended_data);
}

void MainWindow::SendToServer(const quint8 msg_type)
{
    QByteArray sended_data;
    QDataStream out(&sended_data,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out << quint16(0) << msg_type << name_;
    out.device()->seek(0);
    out << quint16(sended_data.size() - sizeof(quint16));
    socket_->write(sended_data);
}

QString MainWindow::DMChatName(const QString &name1, const QString &name2)
{
    QString chat_name;
    if (name1 < name2)
        chat_name = "@" + name1 + "@" + name2;
    else
        chat_name = "@" + name2 + "@" + name1;

    return chat_name;
}

void MainWindow::AddChatListItem(const QString &item_name)
{
    if (item_name.at(0) != '@')
        ui_->chat_list_lw->addItem(item_name);
    else if (item_name.section('@', 1, 1) != name_)
        ui_->chat_list_lw->addItem("@" + item_name.section('@', 1, 1));
    else
        ui_->chat_list_lw->addItem("@" + item_name.section('@', 2, 2));
}

void MainWindow::ReloadChatName(const QString &chat_name)
{

    bool is_found = false;
    if (!chats_.empty())
    {
        auto it = chats_.begin();
        while(it != chats_.end())
        {
            if (*it == chat_name && chat_name != chats_[0])
            {
                QString temp = *it;
                chats_.erase(it);
                chats_.prepend(temp);
                is_found = true;
                break;
            }
            else if (chats_[0] == chat_name)
            {
                is_found = true;
                break;
            }
            ++it;
        }
    }
    if (!is_found)
        chats_.prepend(chat_name);
    ui_->chat_list_lw->clear();
    for (const auto& chat : chats_)
        AddChatListItem(chat);
}

void MainWindow::on_send_pb_clicked()
{
    if (ui_->type_field->text() != "")
        if (socket_->state() == QAbstractSocket::ConnectedState)
            SendToServer(ui_->type_field->text());
}


void MainWindow::on_type_field_returnPressed()
{
    on_send_pb_clicked();
}


void MainWindow::on_enter_pb_clicked()
{
    if (socket_->state() != QAbstractSocket::ConnectedState)
        socket_->connectToHost("127.0.0.1", 6543);
    if (socket_->waitForConnected(100))
        SendToServer(ui_->login_elbl->text(), ui_->pass_elbl->text(), try_to_log_in);
    else
        QMessageBox::critical(this, "Error", "There is no connection to server");
}

void MainWindow::on_pass_elbl_returnPressed()
{
    on_enter_pb_clicked();
}


void MainWindow::on_login_elbl_returnPressed()
{
    on_enter_pb_clicked();
}

void MainWindow::on_reg_pb_clicked()
{
    reg_window_->setModal(true);
    reg_window_->exec();
}

void MainWindow::slotTryReg(QString login, QString pass)
{
    if (socket_->state() != QAbstractSocket::ConnectedState)
        socket_->connectToHost("127.0.0.1", 6543);
    name_ = login;
    pass_ = pass;
    if (socket_->waitForConnected(100))
        SendToServer(login, pass, try_to_reg);
    else
        emit signalToReg("no_connection");
}

void MainWindow::on_logout_pb_clicked()
{
    connection_lost_flag_ = false;
    socket_->disconnectFromHost();
}

void MainWindow::on_chat_list_clicked(QListWidgetItem *item)
{
    chat_name_ = item->text();
    if (chat_name_.at(0) == '@')
        chat_name_ = DMChatName(name_, chat_name_.section('@', 1, 1));
    if (socket_->state() == QAbstractSocket::ConnectedState )
        SendToServer(chat_name_, chat_msgs_req);
    ui_->chat_name_lbl->setText(item->text());
    ui_->menu_w->hide();
    ui_->chat_w->show();
}

void MainWindow::on_add_contact_pb_clicked()
{
    add_contact_window_->setModal(true);
    add_contact_window_->exec();
}

void MainWindow::slotTryAdd(QString name)
{
    temp_name_ = name;
    bool found = false;
    if (!contacts_.empty())
        for (const auto& str : contacts_)
            if (str == name)
            {
                found = true;
                break;
            }
    if (name == name_)
        emit signalAddError("yourself");
    else if (found)
        emit signalAddError("exists");
    else if (socket_->state() == QAbstractSocket::ConnectedState)
        SendToServer(name, name_, try_to_add);
}


void MainWindow::on_del_contact_pb_clicked()
{
    auto contacts = ui_->contacts_lw->selectedItems();
    auto answer = QMessageBox::question(this, "", "Do you realy want to delete this contact?");
    if (answer == QMessageBox::Yes)
    {
        for (auto& contact : contacts)
        {
            contacts_.erase(contacts_.begin()+ui_->contacts_lw->row(contact));
            delete ui_->contacts_lw->takeItem(ui_->contacts_lw->row(contact));
        }
        contacts_.squeeze();
        if (socket_->state() == QAbstractSocket::ConnectedState)
            SendToServer(contacts_, reload_contacts);
    }
}


void MainWindow::on_create_gc_pb_clicked()
{
    create_gc_window_->SetContacts(contacts_);
    create_gc_window_->setModal(true);
    create_gc_window_->exec();
}

void MainWindow::slotTryCreateGC(const QString& chat_name, const QVector<QString>& contacts)
{
    bool found = false;
    if (!chats_.empty())
        for (const auto& str : chats_)
            if (str == chat_name)
            {
                found = true;
                break;
            }
    if (found)
        emit signalCreateGCError();
    else
    {
        auto data = contacts;
        data.prepend(chat_name);
        if (socket_->state() == QAbstractSocket::ConnectedState )
            SendToServer(data, try_to_create_gc);
    }
}

void MainWindow::on_all_chats_pb_clicked()
{
    ui_->tab_w->setCurrentIndex(0);
    ui_->chat_w->hide();
    ui_->menu_w->show();
}

void MainWindow::on_direct_msg_pb_clicked()
{
    auto selected_items = ui_->contacts_lw->selectedItems();
    if (selected_items.empty())
        QMessageBox::warning(this, "Warning", "Select a contact");
    else if (selected_items.size() > 1)
        QMessageBox::warning(this, "Warning", "Select only one contact");
    else
    {
        QString second_name = selected_items[0]->text();
        ui_->chat_name_lbl->setText("@" + second_name);
        chat_name_ = DMChatName(name_, second_name);
        if (socket_->state() == QAbstractSocket::ConnectedState)
            SendToServer(second_name, direct_msg);
        ui_->menu_w->hide();
        ui_->chat_w->show();
    }
}

void MainWindow::on_menu_tab_clicked(int index)
{
    if (index == 0 && last_tab_index_ != 0)
    {
        ui_->contacts_lw->clearSelection();
        last_tab_index_ = 0;
    }
    else if (index == 1 && last_tab_index_ != 1)
    {
        ui_->chat_list_lw->clearSelection();
        last_tab_index_ = 1;
    }
}
