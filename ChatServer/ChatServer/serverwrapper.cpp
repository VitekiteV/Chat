#include "serverwrapper.h"
#include "ui_serverwrapper.h"
#include "Server.h"
#include <QApplication>

ServerWrapper::ServerWrapper(QWidget *parent)
    : QDialog(parent)
    , ui_(std::make_unique<Ui::ServerWrapper>())
{
    ui_->setupUi(this);
    connect(ui_->close_pb, &QPushButton::clicked, this, &ServerWrapper::on_close_pb_clicked);
    server_ = new Server;
    if (server_->ServerIsListening())
        ui_->text_display->append("Server is running...");
    else
        ui_->text_display->append("Server is not running");
}

ServerWrapper::~ServerWrapper()
{
}

void ServerWrapper::on_close_pb_clicked()
{
    qApp->quit();
}

void ServerWrapper::slotAboutToQuit()
{
    server_->AboutToQuit();
    ui_->text_display->append("Server is closing...");
}

