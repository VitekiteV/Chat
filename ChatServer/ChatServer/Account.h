#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class Account
{
public:
    Account(const QString& login, const QString& pass);

    QString GetLogin() const;
    QString GetPass() const;

private:
    QString login_;
    QString pass_;
};

#endif // ACCOUNT_H
