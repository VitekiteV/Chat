#include "Message.h"

Message::Message(const QString& name, const QString& date, const QString& time, const QString& data) :
    name_(name), date_(date), time_(time), data_(data)
{

}

QString Message::GetName() const
{
    return name_;
}

QString Message::GetDate() const
{
    return date_;
}

QString Message::GetTime() const
{
    return time_;
}

QString Message::GetData() const
{
    return data_;
}
