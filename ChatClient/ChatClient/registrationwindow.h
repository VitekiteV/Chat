#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include <memory>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

private slots:
    void on_create_pb_clicked();
    void on_cancel_pb_clicked();

public slots:
    void slotToReg(const QString& type);
    void slotClearWindow();

signals:
    void signalTryReg(QString login, QString pass);

private:
    std::unique_ptr<Ui::RegistrationWindow> ui_;
};

#endif // REGISTRATIONWINDOW_H
