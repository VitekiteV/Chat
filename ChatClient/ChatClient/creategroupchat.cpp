#include "creategroupchat.h"
#include "ui_creategroupchat.h"
#include <QMessageBox>

CreateGroupChat::CreateGroupChat(QWidget *parent) :
    QDialog(parent),
    ui_(std::make_unique<Ui::CreateGroupChat>())
{
    ui_->setupUi(this);
    ui_->contacts_lw->setSelectionMode(QAbstractItemView::MultiSelection);
}

CreateGroupChat::~CreateGroupChat()
{
}

void CreateGroupChat::SetContacts(const QVector<QString> &contacts)
{
    ui_->contacts_lw->clear();
    contacts_ = contacts;
    if (!contacts_.empty())
        for (const auto& contact : contacts_)
            ui_->contacts_lw->addItem(contact);
}

void CreateGroupChat::on_create_pb_clicked()
{
    auto selected = ui_->contacts_lw->selectedItems();
    QVector<QString> contacts;
    for (const auto& item : selected)
        contacts.push_back(item->text());
    if (ui_->chat_name_elbl->text() == "")
        QMessageBox::critical(this, "Error", "Enter a chat name");
    else if (contacts.empty())
        QMessageBox::critical(this, "Error", "Select chat members");
    else
        emit signalTryCreateGC(ui_->chat_name_elbl->text(), contacts);
}

void CreateGroupChat::slotCreateGCError()
{
    QMessageBox::critical(this, "Error", "Group chat with this name already exists. Chose another chat name");
}


void CreateGroupChat::on_cancel_pb_clicked()
{
    ui_->chat_name_elbl->clear();
    this->close();
}

