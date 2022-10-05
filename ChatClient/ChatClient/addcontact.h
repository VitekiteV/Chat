#ifndef ADDCONTACT_H
#define ADDCONTACT_H

#include <QDialog>
#include <memory>

namespace Ui {
class AddContact;
}

class AddContact : public QDialog
{
    Q_OBJECT

public:
    explicit AddContact(QWidget *parent = nullptr);
    ~AddContact();

private slots:
    void on_add_pb_clicked();
    void on_cancel_pb_clicked();

public slots:
    void slotAddError(QString error);
    void slotClearWindow();

signals:
    void signalTryAdd(QString name);

private:
    std::unique_ptr<Ui::AddContact> ui_;
};

#endif // ADDCONTACT_H
