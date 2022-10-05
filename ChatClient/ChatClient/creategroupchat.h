#ifndef CREATEGROUPCHAT_H
#define CREATEGROUPCHAT_H

#include <QDialog>
#include <QVector>
#include <memory>

namespace Ui {
class CreateGroupChat;
}

class CreateGroupChat : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGroupChat(QWidget *parent = nullptr);
    ~CreateGroupChat();
    void SetContacts(const QVector<QString>& contacts);

private slots:
    void on_create_pb_clicked();

    void on_cancel_pb_clicked();

public slots:
    void slotCreateGCError();

signals:
    void signalTryCreateGC(QString chat_name, const QVector<QString>& contacts);

private:
    QVector<QString> contacts_;
    std::unique_ptr<Ui::CreateGroupChat> ui_;
};

#endif // CREATEGROUPCHAT_H
