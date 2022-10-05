/********************************************************************************
** Form generated from reading UI file 'serverwrapper.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWRAPPER_H
#define UI_SERVERWRAPPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ServerWrapper
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *text_display;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *close_pb;

    void setupUi(QDialog *ServerWrapper)
    {
        if (ServerWrapper->objectName().isEmpty())
            ServerWrapper->setObjectName(QString::fromUtf8("ServerWrapper"));
        ServerWrapper->resize(291, 211);
        ServerWrapper->setMinimumSize(QSize(291, 211));
        verticalLayout = new QVBoxLayout(ServerWrapper);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        text_display = new QTextBrowser(ServerWrapper);
        text_display->setObjectName(QString::fromUtf8("text_display"));

        verticalLayout->addWidget(text_display);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        close_pb = new QPushButton(ServerWrapper);
        close_pb->setObjectName(QString::fromUtf8("close_pb"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(close_pb->sizePolicy().hasHeightForWidth());
        close_pb->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(close_pb);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ServerWrapper);

        QMetaObject::connectSlotsByName(ServerWrapper);
    } // setupUi

    void retranslateUi(QDialog *ServerWrapper)
    {
        ServerWrapper->setWindowTitle(QCoreApplication::translate("ServerWrapper", "Server", nullptr));
        close_pb->setText(QCoreApplication::translate("ServerWrapper", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWrapper: public Ui_ServerWrapper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWRAPPER_H
