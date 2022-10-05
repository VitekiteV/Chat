#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>

class Message
{
public:
    Message(const QString& name, const QString& date, const QString& time, const QString& data);

    QString GetName() const;
    QString GetDate() const;
    QString GetTime() const;
    QString GetData() const;

private:
    QString name_;
    QString date_;
    QString time_;
    QString data_;
};


#endif // MESSAGE_H
