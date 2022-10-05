#include "Server.h"
#include <QFile>
#include "MsgTypes.h"
#include <QTime>
#include "UserSocket.h"
#include "Account.h"
#include "Chat.h"
#include "Message.h"
#include "User.h"
#include <QDir>

Server::Server()
{
    if (!QDir("data_files").exists())
        QDir().mkdir("data_files");
    InitializeAccounts();
    InitializeAllChats();
    if (this->listen(QHostAddress::Any, 6543))
        is_listening_ = true;
    else
        is_listening_ = false;
}

Server::~Server()
{
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    UserSocket* socket = new UserSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::slotDeleteSocket);
    sockets_.push_back(socket);
}

void Server::slotReadyRead()
{
    quint16 data_size = 0;
    auto socket = static_cast<UserSocket*>(sender());
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_3);
    if (in.status() == QDataStream::Ok)
    {
        while(true)
        {
            if (data_size == 0)
            {
                if (socket->bytesAvailable() < 2)
                    break;
                else
                    in >> data_size;
            }
            if (socket->bytesAvailable() < data_size)
                break;
            else
            {
                quint8 msg_type = 0;
                QString name;
                in >> msg_type >> name;

                if (msg_type == direct_msg)
                {
                    QString second_name;
                    in >> second_name;
                    QString chat_name = DMChatName(name, second_name);
                    bool is_found = false;
                    if (!all_chats_.empty())
                        for (const auto& chat: all_chats_)
                        {
                            if (chat == chat_name)
                            {
                                is_found = true;
                                break;
                            }
                        }
                    if (!is_found)
                        all_chats_.push_back(chat_name);
                    Chat received_chat = GetChat(chat_name);
                    SendChatToClient(socket, received_chat, req_chat_sending);
                }
                else if (msg_type == chat_msgs_req)
                {
                    QString chat_name;
                    in >> chat_name;
                    if (!ChatIsLoaded(chat_name))
                        LoadChat(chat_name);
                    Chat received_chat = GetChat(chat_name);
                    SendChatToClient(socket, received_chat, req_chat_sending);
                }
                else if (msg_type == message)
                {
                    QString chat_name, data_str;
                    in >> chat_name >> data_str;
                    if (!ChatIsLoaded(chat_name))
                        LoadChat(chat_name);
                    SendMsgToClient(name, chat_name, data_str);
                }
                else if (msg_type == reload_contacts)
                {
                    auto user = GetUser(name);
                    user->ClearContacts();
                    while(socket->bytesAvailable())
                    {
                        QString word;
                        in >> word;
                        user->AddContact(word);
                    }
                    SendContactsToClient(socket, reloaded_contacts);
                }
                else if (msg_type == try_to_create_gc)
                {
                    QString chat_name;
                    in >> chat_name;
                    bool is_found = false;
                    if (!all_chats_.empty())
                        for(const auto& chat : all_chats_)
                            if (chat == chat_name)
                            {
                                is_found = true;
                                [[maybe_unused]] auto trash_data = socket->readAll();
                                SendInfoToClient(socket, unsuccesful_create_gc);
                                break;
                            }
                    if (!is_found)
                    {
                        Chat new_chat(chat_name);
                        all_chats_.push_back(chat_name);
                        new_chat.AddMember(name);
                        while(socket->bytesAvailable())
                        {
                            QString word;
                            in >> word;
                            new_chat.AddMember(word);
                        }
                        auto members = new_chat.GetMembers();
                        for (const auto& member : members)
                        {
                            bool is_found = false;
                            for (auto& user : users_)
                                if (user->GetName() == member)
                                {
                                    is_found = true;
                                    user->AddChat(chat_name);
                                }
                            if (!is_found)
                                WriteNewChatName("data_files/" + member + "_chats.chl", chat_name);
                        }
                        active_chats_.push_back(new_chat);
                        SendNewGC(socket, chat_name, succesful_create_gc);
                    }
                }
                else
                {
                    QString data;
                    in >> data;
                    bool found_flag = false;
                    if (!accounts_.empty())
                        for (const auto& acc : accounts_)
                        {
                            if (acc.GetLogin() == name)
                            {
                                if (msg_type == try_to_add)
                                {
                                    found_flag = true;
                                    auto user = GetUser(socket->GetName());
                                    user->AddContact(name);
                                    SendInfoToClient(socket, succesful_add);
                                }
                                else if (msg_type == try_to_reg)
                                {
                                    found_flag = true;
                                    SendInfoToClient(socket, unsuccesful_reg);
                                }
                                else if (acc.GetPass() == data && msg_type == try_to_log_in)
                                {
                                    found_flag = true;
                                    socket->SetName(name);
                                    if (!UserIsLoaded(name))
                                        LoadUserFiles(name);
                                    SendDataToClient(socket, succesful_enter);
                                }
                                break;
                            }
                        }
                    if (!found_flag)
                    {
                        if (msg_type == try_to_add)
                            SendInfoToClient(socket, unsuccesful_add);
                        else if (msg_type == try_to_log_in)
                            SendInfoToClient(socket, unsuccesful_enter);
                        else if (msg_type == try_to_reg)
                        {
                            accounts_.push_back(Account(name, data));
                            users_.push_back(std::make_shared<User>(name));
                            socket->SetName(name);
                            SendInfoToClient(socket, succesful_reg);
                        }
                    }
                }
                break;
            }
        }
    }
}

void Server::slotDeleteSocket()
{
    UserSocket* socket;
    socket = static_cast<UserSocket*>(sender());

    UpdUserFiles(socket->GetName());

    auto it = sockets_.begin();
    while (it != sockets_.end())
        if (socket == *it)
        {
            sockets_.erase(it);
            break;
        }
        else
            ++it;
    socket->deleteLater();
}

void Server::AboutToQuit()
{
    QFile file1("data_files/accounts.acc");
    if (file1.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QDataStream data_str(&file1);
        for (const auto& acc : accounts_)
            data_str << acc.GetLogin() << acc.GetPass();
    }
    file1.close();

    QFile file2("data_files/all_chats.chl");
    if (file2.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QDataStream data_str(&file2);
        for (const auto& chat : all_chats_)
            data_str << chat;
    }
    file2.close();

    for (const auto& chat: active_chats_)
    {
        QFile file("data_files/" + chat.GetName() + ".ch");
        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            QDataStream data_str(&file);
            auto users = chat.GetMembers();
            for (const auto& user: users)
                data_str << user;
            data_str << QString("#end");

            auto messages = chat.GetMessages();
            for (const auto& msg: messages)
                data_str << msg.GetName() << msg.GetDate() << msg.GetTime() << msg.GetData();
        }
        file.close();
    }

    if (!users_.empty())
        for (const auto& user : users_)
            UpdUserFiles(user->GetName());
}

void Server::SendMsgToClient(const QString& name, const QString& chat_name, const QString& data_str)
{
    QByteArray byte_data;
    QDataStream out(&byte_data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    auto time = QTime::currentTime();
    auto date = QDateTime::currentDateTime();
    out << quint16(0) << quint8(usr_msg) << chat_name << date << time << name << data_str;
    out.device()->seek(0);
    out << quint16(byte_data.size() - sizeof(quint16));

    auto chat_members = GetChatMembers(chat_name);
    for (const auto& member : chat_members)
    {
        bool is_found = false;
        for (auto& user : users_)
            if (user->GetName() == member)
            {
                is_found = true;
                user->PushUpChat(chat_name);
                break;
            }
        if (!is_found)
            PushUpChat("data_files/" + member + "_chats.chl", chat_name);
    }

    for (auto& socket : sockets_)
        for (const auto& member : chat_members)
            if (member == socket->GetName())
                socket->write(byte_data);

    for (auto& chat : active_chats_)
        if (chat.GetName() == chat_name)
        {
            chat.AddMsg(Message(name, date.toString("dd.MM.yyyy"), time.toString("hh:mm"), data_str));
            break;
        }
}

void Server::SendChatToClient(UserSocket *socket, const Chat &chat, const quint8 msg_type)
{
    QByteArray byte_data;
    QDataStream out(&byte_data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    QByteArray data;
    QDataStream data_str(&data, QIODevice::WriteOnly);
    auto messages = chat.GetMessages();
    if (!messages.empty())
        for (const auto& msg : messages)
            data_str << msg.GetName() << msg.GetDate() << msg.GetTime() << msg.GetData();
    else
        data_str << QString("##NULL##");

    out << quint16(0) << msg_type << data;
    out.device()->seek(0);
    out << quint16(byte_data.size() - sizeof(quint16));
    socket->write(byte_data);
}

void Server::SendInfoToClient(UserSocket* socket, const quint8 msg_type)
{
    QByteArray byte_data;
    QDataStream out(&byte_data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out << quint16(0) << msg_type;
    out.device()->seek(0);
    out << quint16(byte_data.size() - sizeof(quint16));
    socket->write(byte_data);
}

void Server::SendDataToClient(UserSocket* socket, const quint8 msg_type)
{
    QByteArray byte_data;
    QDataStream out(&byte_data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out << quint16(0) << msg_type << quint16(0);

    auto user = GetUser(socket->GetName());
    auto chats = user->GetChatList();
    auto word_count = static_cast<quint16>(chats.size());
    for (const auto& chat : chats)
        out << chat;

    auto contacts = user->GetContactsList();
    for (const auto& contact : contacts)
        out << contact;

    out.device()->seek(3);
    out << word_count;
    out.device()->seek(0);
    out << quint16(byte_data.size() - sizeof(quint16));
    socket->write(byte_data);
}

void Server::SendContactsToClient(UserSocket *socket, quint8 msg_type)
{
    QByteArray byte_data;
    QDataStream out(&byte_data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out << quint16(0) << msg_type;
    auto user = GetUser(socket->GetName());
    auto contacts = user->GetContactsList();
    for (const auto& contact : contacts)
        out << contact;
    out.device()->seek(0);
    out << quint16(byte_data.size() - sizeof(quint16));
    for (auto& sckt : sockets_)
        if (sckt != socket && sckt->GetName() == socket->GetName())
            sckt->write(byte_data);
}

void Server::SendNewGC(UserSocket* creator_socket, const QString &gc_name, quint8 msg_type)
{
    QByteArray byte_data, crtr_data;

    QDataStream out(&byte_data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out << quint16(0) << msg_type << quint8(0) << gc_name;
    out.device()->seek(0);
    out << quint16(byte_data.size() - sizeof(quint16));

    QDataStream crtr_out(&crtr_data, QIODevice::WriteOnly);
    crtr_out.setVersion(QDataStream::Qt_6_3);
    crtr_out << quint16(0) << msg_type << quint8(1) << gc_name;
    crtr_out.device()->seek(0);
    crtr_out << quint16(byte_data.size() - sizeof(quint16));

    auto chat_members = GetChatMembers(gc_name);
    for (auto& socket : sockets_)
        if (socket == creator_socket)
            socket->write(crtr_data);
        else
            for (const auto& member : chat_members)
                if (member == socket->GetName())
                    socket->write(byte_data);
}

void Server::InitializeAccounts()
{
    QFile file("data_files/accounts.acc");
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream txt_str(&file);
        while(!txt_str.atEnd())
        {
            QString login, pass;
            txt_str >> login >> pass;
            accounts_.push_back(Account(login, pass));
        }
    }
}

void Server::InitializeAllChats()
{
    QFile file("data_files/all_chats.chl");
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream txt_str(&file);
        while(!txt_str.atEnd())
        {
            QString chat;
            txt_str >> chat;
            all_chats_.push_back(chat);
        }
    }
}

void Server::UpdUserFiles(const QString& name) const
{
    auto user = GetUser(name);
    auto chat_list = user->GetChatList();
    if(!chat_list.empty())
    {
        QFile file1("data_files/" + name + "_chats.chl");
        if (file1.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            QDataStream data_str(&file1);
            for (const auto& chat : chat_list)
                data_str << chat;
        }
        file1.close();
    }

    auto contacts_list = user->GetContactsList();
    if (!contacts_list.empty())
    {
        QFile file2("data_files/" + name + "_contacts.chl");
        if (file2.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            QDataStream data_str(&file2);
            for (const auto& contact : contacts_list)
                data_str << contact;
        }
        file2.close();
    }
}

void Server::LoadUserFiles(const QString& name)
{
    auto user = std::make_shared<User>(name);
    QVector<QString> chat_list;
    QFile file1("data_files/" + name + "_chats.chl");
    if (file1.open(QIODevice::ReadOnly))
    {
        QDataStream data_str(&file1);
        while (!data_str.atEnd())
        {
            QString word;
            data_str >> word;
            chat_list.push_back(word);
        }
    }
    file1.close();
    user->SetChatList(chat_list);

    QVector<QString> contacts_list;
    QFile file2("data_files/" + name + "_contacts.chl");
    if (file2.open(QIODevice::ReadOnly))
    {
        QDataStream data_str(&file2);
        while (!data_str.atEnd())
        {
            QString word;
            data_str >> word;
            contacts_list.push_back(word);
        }
    }
    file2.close();
    user->SetContactsList(contacts_list);
    users_.push_back(user);
}

bool Server::ChatIsLoaded(const QString &chat_name) const
{
    for (const auto& chat : active_chats_)
        if (chat.GetName() == chat_name)
            return true;
    return false;
}

void Server::LoadChat(const QString &chat_name)
{
    Chat new_chat(chat_name);
    QFile file("data_files/" + chat_name + ".ch");
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream data_str(&file);
        while (true)
        {
            QString word;
            data_str >> word;
            if (word == "#end")
                break;
            else
                new_chat.AddMember(word);
        }
        while (!data_str.atEnd())
        {
            QString name, date, time, data;
            data_str >> name >> date >> time >> data;
            new_chat.AddMsg(Message(name, date, time, data));
        }
        file.close();
    }
    else if (chat_name.at(0) == '@')
    {
        new_chat.AddMember(chat_name.section('@', 1, 1));
        new_chat.AddMember(chat_name.section('@', 2, 2));
    }
    active_chats_.push_back(new_chat);
}

Chat Server::GetChat(const QString &chat) const
{
    if (!active_chats_.empty())
        for (const auto& ch : active_chats_)
            if (ch.GetName() == chat)
                return ch;
    return Chat("error");
}

void Server::WriteNewChatName(const QString &file_name, const QString &chat_name)
{
    QFile file(file_name);
    if (file.size() > 0)
    {
        QByteArray data;
        QDataStream data_wr(&data, QIODevice::WriteOnly);
        file.open(QIODevice::ReadOnly);
        QDataStream r_str(&file);
        while (!file.atEnd())
        {
            QString word;
            r_str >> word;
            data_wr << word;
        }
        file.close();

        file.open(QIODevice::WriteOnly | QIODevice::Truncate);
        QDataStream w_str(&file);
        w_str << chat_name;
        QDataStream data_rd(&data, QIODevice::ReadOnly);
        while (!data_rd.atEnd())
        {
            QString word;
            data_rd >> word;
            w_str << word;
        }
    }
    else if (file.size() == 0)
    {
        file.open(QIODevice::WriteOnly);
        QDataStream w_str(&file);
        w_str << chat_name;
    }
    file.close();
}

QString Server::DMChatName(const QString &name1, const QString &name2)
{
    QString chat_name;
    if (name1 < name2)
        chat_name = "@" + name1 + "@" + name2;
    else
        chat_name = "@" + name2 + "@" + name1;

    return chat_name;
}

void Server::PushUpChat(const QString &file_name, const QString &chat_name)
{
    QByteArray file_data;
    QFile file(file_name);
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream data_str(&file_data, QIODevice::WriteOnly);
        QDataStream txt_rd(&file);
        while(!txt_rd.atEnd())
        {
            QString word;
            txt_rd >> word;
            if (word == chat_name)
                continue;
            else
                data_str << word;
        }
        file.close();
    }

    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QDataStream txt_wr(&file);
    txt_wr << chat_name;
    if (!file_data.isEmpty())
    {
        QDataStream data_str(&file_data, QIODevice::ReadOnly);
        while (!data_str.atEnd())
        {
            QString word;
            data_str >> word;
            txt_wr << word;
        }
    }

    file.close();
}

QVector<QString> Server::GetChatMembers(const QString &chat_name)
{
    if (!active_chats_.empty())
        for (const auto& chat : active_chats_)
            if (chat.GetName() == chat_name)
                return chat.GetMembers();
    QVector<QString> error;
    return error;
}

std::shared_ptr<User> Server::GetUser(const QString &name) const
{
    if (!users_.empty())
        for (const auto& user : users_)
            if (user->GetName() == name)
                return user;
    auto user = std::make_shared<User>("error");
    return user;
}

bool Server::UserIsLoaded(const QString &name) const
{
    if (!users_.empty())
        for (const auto& user : users_)
            if (user->GetName() == name)
                return true;
    return false;
}

bool Server::ServerIsListening() const
{
    return is_listening_;
}
