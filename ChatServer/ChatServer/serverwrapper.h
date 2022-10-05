#ifndef SERVERWRAPPER_H
#define SERVERWRAPPER_H

#include <QDialog>
#include <memory>

class Server;

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWrapper; }
QT_END_NAMESPACE

class ServerWrapper : public QDialog
{
    Q_OBJECT

public:
    ServerWrapper(QWidget *parent = nullptr);
    ~ServerWrapper();

private slots:
    void on_close_pb_clicked();

public slots:
    void slotAboutToQuit();

private:
    std::unique_ptr<Ui::ServerWrapper> ui_;
    Server* server_;
};
#endif // SERVERWRAPPER_H
