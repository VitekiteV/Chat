#ifndef CHAT_H
#define CHAT_H

#include <QString>
#include <QVector>

class Message;

class Chat
{
public:
    Chat(const QString& name);

    QString GetName() const;
    void AddMember(const QString &name);
    QVector<QString> GetMembers() const;
    void AddMsg(const Message& msg);
    QVector<Message> GetMessages() const;

private:
    QString name_;
    QVector<QString> members_;
    QVector<Message> messages_;
};

#endif // CHAT_H
