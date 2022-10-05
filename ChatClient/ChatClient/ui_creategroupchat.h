/********************************************************************************
** Form generated from reading UI file 'creategroupchat.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUPCHAT_H
#define UI_CREATEGROUPCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateGroupChat
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLabel *enter_chat_name_lbl;
    QLineEdit *chat_name_elbl;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_7;
    QLabel *chose_contacts_lbl;
    QSpacerItem *horizontalSpacer_8;
    QListWidget *contacts_lw;
    QSpacerItem *horizontalSpacer;
    QPushButton *create_pb;
    QPushButton *cancel_pb;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *CreateGroupChat)
    {
        if (CreateGroupChat->objectName().isEmpty())
            CreateGroupChat->setObjectName(QString::fromUtf8("CreateGroupChat"));
        CreateGroupChat->resize(313, 330);
        CreateGroupChat->setMinimumSize(QSize(313, 330));
        verticalLayout_2 = new QVBoxLayout(CreateGroupChat);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        enter_chat_name_lbl = new QLabel(CreateGroupChat);
        enter_chat_name_lbl->setObjectName(QString::fromUtf8("enter_chat_name_lbl"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(enter_chat_name_lbl->sizePolicy().hasHeightForWidth());
        enter_chat_name_lbl->setSizePolicy(sizePolicy);
        enter_chat_name_lbl->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(enter_chat_name_lbl);

        chat_name_elbl = new QLineEdit(CreateGroupChat);
        chat_name_elbl->setObjectName(QString::fromUtf8("chat_name_elbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(chat_name_elbl->sizePolicy().hasHeightForWidth());
        chat_name_elbl->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(chat_name_elbl);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 0, 1, 2);

        chose_contacts_lbl = new QLabel(CreateGroupChat);
        chose_contacts_lbl->setObjectName(QString::fromUtf8("chose_contacts_lbl"));
        sizePolicy1.setHeightForWidth(chose_contacts_lbl->sizePolicy().hasHeightForWidth());
        chose_contacts_lbl->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(chose_contacts_lbl, 0, 2, 1, 2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 0, 4, 1, 2);

        contacts_lw = new QListWidget(CreateGroupChat);
        contacts_lw->setObjectName(QString::fromUtf8("contacts_lw"));

        gridLayout->addWidget(contacts_lw, 1, 0, 1, 6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        create_pb = new QPushButton(CreateGroupChat);
        create_pb->setObjectName(QString::fromUtf8("create_pb"));
        create_pb->setMinimumSize(QSize(75, 24));

        gridLayout->addWidget(create_pb, 2, 1, 1, 2);

        cancel_pb = new QPushButton(CreateGroupChat);
        cancel_pb->setObjectName(QString::fromUtf8("cancel_pb"));
        cancel_pb->setMinimumSize(QSize(75, 24));

        gridLayout->addWidget(cancel_pb, 2, 3, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 5, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(CreateGroupChat);

        QMetaObject::connectSlotsByName(CreateGroupChat);
    } // setupUi

    void retranslateUi(QDialog *CreateGroupChat)
    {
        CreateGroupChat->setWindowTitle(QCoreApplication::translate("CreateGroupChat", "Create group chat", nullptr));
        enter_chat_name_lbl->setText(QCoreApplication::translate("CreateGroupChat", "Enter a chat name:", nullptr));
        chose_contacts_lbl->setText(QCoreApplication::translate("CreateGroupChat", "Choose contacts:", nullptr));
        create_pb->setText(QCoreApplication::translate("CreateGroupChat", "Create", nullptr));
        cancel_pb->setText(QCoreApplication::translate("CreateGroupChat", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGroupChat: public Ui_CreateGroupChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUPCHAT_H
