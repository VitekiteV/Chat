#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QVector>
#include <memory>
#endif // SERVER_H

class UserSocket;
class Account;
class Chat;
class User;

class Server : public QTcpServer
{
    Q_OBJECT

private:
    QVector<UserSocket*> sockets_;
    QVector<Account> accounts_;
    QVector<QString> all_chats_;
    QVector<Chat> active_chats_;
    QVector<std::shared_ptr<User>> users_;
    bool is_listening_ = false;

    void SendInfoToClient(UserSocket *socket, quint8 msg_type);
    void SendDataToClient(UserSocket *socket, quint8 msg_type);
    void SendContactsToClient(UserSocket *socket, quint8 msg_type);
    void SendMsgToClient(const QString& name, const QString& chat_name, const QString& data_str);
    void SendChatToClient(UserSocket *socket, const Chat& chat, quint8 msg_type);
    void SendNewGC(UserSocket* creator_socket, const QString& gc_name, quint8 msg_type);

    void InitializeAccounts();
    void InitializeAllChats();
    void UpdUserFiles(const QString& name) const;
    void LoadUserFiles(const QString& name);
    bool ChatIsLoaded(const QString& chat_name) const;
    void LoadChat(const QString& chat_name);
    Chat GetChat(const QString& chat) const;
    void WriteNewChatName(const QString& file_name, const QString& chat_name);
    QString DMChatName(const QString& name1, const QString& name2);
    void PushUpChat(const QString &file_name, const QString& chat_name);
    QVector<QString> GetChatMembers(const QString& chat_name);
    std::shared_ptr<User> GetUser(const QString& name) const;
    bool UserIsLoaded(const QString& name) const;

public:
    Server();
    ~Server();

private slots:
    void incomingConnection(qintptr socketDescriptor) override;
    void slotReadyRead();
    void slotDeleteSocket();

public:
    bool ServerIsListening() const;
    void AboutToQuit();
};
