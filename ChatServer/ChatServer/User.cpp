#include "User.h"

User::User()
{
}

User::User(const QString& name) : name_(name)
{
}

User::~User()
{
}

QString User::GetName() const
{
    return name_;
}

void User::SetChatList(const QVector<QString> &chat_list)
{
    chat_list_ = chat_list;
}

QVector<QString> User::GetChatList() const
{
    return chat_list_;
}

void User::SetContactsList(const QVector<QString> &contacts_list)
{
    contacts_list_ = contacts_list;
}

QVector<QString> User::GetContactsList() const
{
    return contacts_list_;
}

void User::AddContact(const QString &contact)
{
    bool is_inserted = false;
    if (!contacts_list_.empty())
    {
        for (auto i = 0; i < contacts_list_.size(); ++i)
            if (contacts_list_[i] > contact)
            {
                contacts_list_.insert(i, contact);
                is_inserted = true;
                break;
            }
    }
    if (!is_inserted)
        contacts_list_.push_back(contact);
}

void User::ClearContacts()
{
    contacts_list_.clear();
}

void User::AddChat(const QString &chat)
{
    chat_list_.prepend(chat);
}

void User::PushUpChat(const QString &chat)
{
    auto it = chat_list_.begin();
    while (it != chat_list_.end())
        if (*it == chat)
        {
            chat_list_.erase(it);
            break;
        }
        else
            ++it;
    chat_list_.prepend(chat);
}
