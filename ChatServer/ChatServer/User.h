#ifndef USER_H
#define USER_H

#include <QVector>
#include <QString>

class User
{
public:
    User();
    User(const QString& name);
    ~User();

    QString GetName() const;
    void SetChatList(const QVector<QString>& chat_list);
    QVector<QString> GetChatList() const;
    void SetContactsList(const QVector<QString>& contacts_list);
    QVector<QString> GetContactsList() const;
    void AddContact(const QString& contact);
    void ClearContacts();
    void AddChat(const QString& chat);
    void PushUpChat(const QString& chat);

private:
    QString name_;
    QVector<QString> chat_list_;
    QVector<QString> contacts_list_;
};

#endif // USER_H
