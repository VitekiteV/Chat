#ifndef USERSOCKET_H
#define USERSOCKET_H

#include <QTcpSocket>

class UserSocket : public QTcpSocket
{
public:
    explicit UserSocket(QObject *parent = nullptr);

    void SetName(const QString& name);
    QString GetName() const;

private:
    QString name_;
};

#endif // USERSOCKET_H
