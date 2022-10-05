#include "Account.h"

Account::Account(const QString &login, const QString &pass) : login_(login), pass_(pass)
{

}

QString Account::GetLogin() const
{
    return login_;
}

QString Account::GetPass() const
{
    return pass_;
}
