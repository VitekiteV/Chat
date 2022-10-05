/********************************************************************************
** Form generated from reading UI file 'addcontact.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONTACT_H
#define UI_ADDCONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddContact
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *enter_name_lbl;
    QLineEdit *name_elbl;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *add_pb;
    QPushButton *cancel_pb;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *AddContact)
    {
        if (AddContact->objectName().isEmpty())
            AddContact->setObjectName(QString::fromUtf8("AddContact"));
        AddContact->resize(242, 97);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddContact->sizePolicy().hasHeightForWidth());
        AddContact->setSizePolicy(sizePolicy);
        AddContact->setMinimumSize(QSize(242, 97));
        AddContact->setMaximumSize(QSize(242, 97));
        verticalLayout = new QVBoxLayout(AddContact);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        enter_name_lbl = new QLabel(AddContact);
        enter_name_lbl->setObjectName(QString::fromUtf8("enter_name_lbl"));
        sizePolicy.setHeightForWidth(enter_name_lbl->sizePolicy().hasHeightForWidth());
        enter_name_lbl->setSizePolicy(sizePolicy);
        enter_name_lbl->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(enter_name_lbl);

        name_elbl = new QLineEdit(AddContact);
        name_elbl->setObjectName(QString::fromUtf8("name_elbl"));
        sizePolicy.setHeightForWidth(name_elbl->sizePolicy().hasHeightForWidth());
        name_elbl->setSizePolicy(sizePolicy);
        name_elbl->setMinimumSize(QSize(133, 22));

        horizontalLayout->addWidget(name_elbl);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        add_pb = new QPushButton(AddContact);
        add_pb->setObjectName(QString::fromUtf8("add_pb"));
        add_pb->setMinimumSize(QSize(75, 24));

        horizontalLayout_2->addWidget(add_pb);

        cancel_pb = new QPushButton(AddContact);
        cancel_pb->setObjectName(QString::fromUtf8("cancel_pb"));
        cancel_pb->setMinimumSize(QSize(75, 24));

        horizontalLayout_2->addWidget(cancel_pb);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(AddContact);

        QMetaObject::connectSlotsByName(AddContact);
    } // setupUi

    void retranslateUi(QDialog *AddContact)
    {
        AddContact->setWindowTitle(QCoreApplication::translate("AddContact", "Add contact", nullptr));
        enter_name_lbl->setText(QCoreApplication::translate("AddContact", "Enter a name:", nullptr));
        add_pb->setText(QCoreApplication::translate("AddContact", "Add", nullptr));
        cancel_pb->setText(QCoreApplication::translate("AddContact", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddContact: public Ui_AddContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONTACT_H
