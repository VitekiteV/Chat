#include "addcontact.h"
#include "ui_addcontact.h"
#include <QMessageBox>

AddContact::AddContact(QWidget *parent) :
    QDialog(parent),
    ui_(std::make_unique<Ui::AddContact>())
{
    ui_->setupUi(this);
}

AddContact::~AddContact()
{
}


void AddContact::on_add_pb_clicked()
{
    if (ui_->name_elbl->text() == "")
        QMessageBox::critical(this, "Error", "A name isn't entered");
    else
        emit signalTryAdd(ui_->name_elbl->text());
}

void AddContact::slotAddError(QString error)
{
    if (error == "exists")
        QMessageBox::critical(this, "Error", "The contact already exists");
    else if (error == "nonexistant")
        QMessageBox::critical(this, "Error", "There is no an account with this name");
    else
        QMessageBox::critical(this, "Error", "You can't add yourself");
}

void AddContact::slotClearWindow()
{
    ui_->name_elbl->clear();
}


void AddContact::on_cancel_pb_clicked()
{
    ui_->name_elbl->clear();
    this->close();
}

