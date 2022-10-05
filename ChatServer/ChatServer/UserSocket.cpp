#include "UserSocket.h"

UserSocket::UserSocket(QObject *parent)
    : QTcpSocket{parent}
{

}

void UserSocket::SetName(const QString &name)
{
    name_ = name;
}

QString UserSocket::GetName() const
{
    return name_;
}
