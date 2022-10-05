#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTcpSocket>
#include <QMainWindow>
#include <QVector>
#include <memory>
#include "registrationwindow.h"
#include "addcontact.h"
#include "creategroupchat.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QListWidgetItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signalToReg(const QString& type);
    void signalClearRegWindow();
    void signalAddError(QString error);
    void signalClearAddWindow();
    void signalCreateGCError();

private slots:
    void on_send_pb_clicked();
    void on_type_field_returnPressed();
    void on_enter_pb_clicked();
    void on_pass_elbl_returnPressed();
    void on_login_elbl_returnPressed();
    void on_reg_pb_clicked();
    void on_logout_pb_clicked();
    void on_chat_list_clicked(QListWidgetItem *item);
    void on_add_contact_pb_clicked();
    void on_del_contact_pb_clicked();
    void on_create_gc_pb_clicked();
    void on_all_chats_pb_clicked();
    void on_direct_msg_pb_clicked();
    void on_menu_tab_clicked(int index);

    void slotReadyRead();
    void slotDisconnected();
    void slotTryReg(QString login, QString pass);
    void slotTryAdd(QString name);
    void slotTryCreateGC(const QString &chat_name, const QVector<QString> &contacts);

private:
    std::unique_ptr<Ui::MainWindow> ui_;
    QTcpSocket* socket_;
    quint16 data_size_ = 0;
    QString name_;
    QString pass_;
    QString chat_name_;
    QVector<QString> chats_;
    QVector<QString> contacts_;
    QString temp_name_;
    bool connection_lost_flag_ = true;
    quint8 last_tab_index_ = 0;
    RegistrationWindow* reg_window_;
    AddContact* add_contact_window_;
    CreateGroupChat* create_gc_window_;

    void SendToServer(QString data_str);
    void SendToServer(QString data1, QString data2, quint8 msg_type);
    void SendToServer(const QVector<QString> vec, quint8 msg_type);
    void SendToServer(const QString& chat_name, const quint8 msg_type);
    void SendToServer(const quint8 msg_type);
    QString DMChatName(const QString& name1, const QString& name2);
    void AddChatListItem(const QString& item_name);
    void ReloadChatName(const QString& chat_name);    
};
#endif // MAINWINDOW_H
