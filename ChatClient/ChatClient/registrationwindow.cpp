#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include <QMessageBox>

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui_(std::make_unique<Ui::RegistrationWindow>())
{
    ui_->setupUi(this);
}

RegistrationWindow::~RegistrationWindow()
{
}

void RegistrationWindow::on_create_pb_clicked()
{
    if (ui_->pass1_elbl->text() != ui_->pass2_elbl->text())
        QMessageBox::warning(this, "Warning", "Passwords don't coincide");
    else if (ui_->pass1_elbl->text() == "" || ui_->login_elbl->text() == "")
        QMessageBox::critical(this, "Error", "Login or password aren't entered");
    else
        emit signalTryReg(ui_->login_elbl->text(), ui_->pass1_elbl->text());
}

void RegistrationWindow::slotToReg(const QString &type)
{
    if (type == "exists")
        QMessageBox::critical(this, "Error", "Account with this login already exists");
    else if (type == "no_connection")
        QMessageBox::critical(this, "Error", "There is no connection to server");
}

void RegistrationWindow::slotClearWindow()
{
    ui_->login_elbl->clear();
    ui_->pass1_elbl->clear();
    ui_->pass2_elbl->clear();
}


void RegistrationWindow::on_cancel_pb_clicked()
{
    slotClearWindow();
    this->close();
}

