#include "serverwrapper.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerWrapper w;
    QObject::connect(&a, &QCoreApplication::aboutToQuit, &w, &ServerWrapper::slotAboutToQuit);
    w.show();
    return a.exec();
}
