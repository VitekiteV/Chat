#include "Chat.h"
#include "Message.h"

Chat::Chat(const QString &name) : name_(name)
{

}

QString Chat::GetName() const
{
    return name_;
}

void Chat::AddMember(const QString& name)
{
    members_.push_back(name);
}

QVector<QString> Chat::GetMembers() const
{
    return members_;
}

void Chat::AddMsg(const Message &msg)
{
    messages_.push_back(msg);
}

QVector<Message> Chat::GetMessages() const
{
    return messages_;
}
