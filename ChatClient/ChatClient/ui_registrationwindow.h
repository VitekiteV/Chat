/********************************************************************************
** Form generated from reading UI file 'registrationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWINDOW_H
#define UI_REGISTRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWindow
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_9;
    QLabel *info_lbl;
    QSpacerItem *horizontalSpacer_10;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_7;
    QLabel *login_lbl;
    QLineEdit *login_elbl;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_5;
    QLabel *pass1_lbl;
    QLineEdit *pass1_elbl;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QLabel *pass2_lbl;
    QLineEdit *pass2_elbl;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *create_pb;
    QPushButton *cancel_pb;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *RegistrationWindow)
    {
        if (RegistrationWindow->objectName().isEmpty())
            RegistrationWindow->setObjectName(QString::fromUtf8("RegistrationWindow"));
        RegistrationWindow->resize(304, 164);
        RegistrationWindow->setMinimumSize(QSize(304, 164));
        RegistrationWindow->setMaximumSize(QSize(304, 164));
        verticalLayout = new QVBoxLayout(RegistrationWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        info_lbl = new QLabel(RegistrationWindow);
        info_lbl->setObjectName(QString::fromUtf8("info_lbl"));

        horizontalLayout_2->addWidget(info_lbl);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_7 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        login_lbl = new QLabel(RegistrationWindow);
        login_lbl->setObjectName(QString::fromUtf8("login_lbl"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login_lbl->sizePolicy().hasHeightForWidth());
        login_lbl->setSizePolicy(sizePolicy);
        login_lbl->setMinimumSize(QSize(133, 16));
        login_lbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(login_lbl, 0, 1, 1, 1);

        login_elbl = new QLineEdit(RegistrationWindow);
        login_elbl->setObjectName(QString::fromUtf8("login_elbl"));
        sizePolicy.setHeightForWidth(login_elbl->sizePolicy().hasHeightForWidth());
        login_elbl->setSizePolicy(sizePolicy);
        login_elbl->setMinimumSize(QSize(133, 19));

        gridLayout->addWidget(login_elbl, 0, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(114, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 0, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        pass1_lbl = new QLabel(RegistrationWindow);
        pass1_lbl->setObjectName(QString::fromUtf8("pass1_lbl"));
        sizePolicy.setHeightForWidth(pass1_lbl->sizePolicy().hasHeightForWidth());
        pass1_lbl->setSizePolicy(sizePolicy);
        pass1_lbl->setMinimumSize(QSize(133, 16));
        pass1_lbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(pass1_lbl, 1, 1, 1, 1);

        pass1_elbl = new QLineEdit(RegistrationWindow);
        pass1_elbl->setObjectName(QString::fromUtf8("pass1_elbl"));
        sizePolicy.setHeightForWidth(pass1_elbl->sizePolicy().hasHeightForWidth());
        pass1_elbl->setSizePolicy(sizePolicy);
        pass1_elbl->setMinimumSize(QSize(133, 19));

        gridLayout->addWidget(pass1_elbl, 1, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(114, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        pass2_lbl = new QLabel(RegistrationWindow);
        pass2_lbl->setObjectName(QString::fromUtf8("pass2_lbl"));
        sizePolicy.setHeightForWidth(pass2_lbl->sizePolicy().hasHeightForWidth());
        pass2_lbl->setSizePolicy(sizePolicy);
        pass2_lbl->setMinimumSize(QSize(133, 16));
        pass2_lbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(pass2_lbl, 2, 1, 1, 1);

        pass2_elbl = new QLineEdit(RegistrationWindow);
        pass2_elbl->setObjectName(QString::fromUtf8("pass2_elbl"));
        sizePolicy.setHeightForWidth(pass2_elbl->sizePolicy().hasHeightForWidth());
        pass2_elbl->setSizePolicy(sizePolicy);
        pass2_elbl->setMinimumSize(QSize(133, 19));

        gridLayout->addWidget(pass2_elbl, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(114, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        create_pb = new QPushButton(RegistrationWindow);
        create_pb->setObjectName(QString::fromUtf8("create_pb"));
        create_pb->setMinimumSize(QSize(78, 24));

        horizontalLayout->addWidget(create_pb);

        cancel_pb = new QPushButton(RegistrationWindow);
        cancel_pb->setObjectName(QString::fromUtf8("cancel_pb"));
        cancel_pb->setMinimumSize(QSize(78, 24));

        horizontalLayout->addWidget(cancel_pb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(RegistrationWindow);

        QMetaObject::connectSlotsByName(RegistrationWindow);
    } // setupUi

    void retranslateUi(QDialog *RegistrationWindow)
    {
        RegistrationWindow->setWindowTitle(QCoreApplication::translate("RegistrationWindow", "Registration", nullptr));
        info_lbl->setText(QCoreApplication::translate("RegistrationWindow", "New account creation:", nullptr));
        login_lbl->setText(QCoreApplication::translate("RegistrationWindow", "Enter a login:", nullptr));
        pass1_lbl->setText(QCoreApplication::translate("RegistrationWindow", "Enter a password:", nullptr));
        pass2_lbl->setText(QCoreApplication::translate("RegistrationWindow", "Enter a password again:", nullptr));
        create_pb->setText(QCoreApplication::translate("RegistrationWindow", "Create", nullptr));
        cancel_pb->setText(QCoreApplication::translate("RegistrationWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationWindow: public Ui_RegistrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWINDOW_H
