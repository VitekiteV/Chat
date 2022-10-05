/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *main_widget;
    QGridLayout *gridLayout;
    QWidget *menu_w;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *nickname_lbl;
    QPushButton *logout_pb;
    QTabWidget *tab_w;
    QWidget *chat_tab;
    QVBoxLayout *verticalLayout;
    QListWidget *chat_list_lw;
    QHBoxLayout *chats_pb_lo;
    QSpacerItem *horizontalSpacer;
    QPushButton *create_gc_pb;
    QSpacerItem *horizontalSpacer_2;
    QWidget *contacts_tab;
    QVBoxLayout *verticalLayout_2;
    QListWidget *contacts_lw;
    QHBoxLayout *horizontalLayout;
    QPushButton *direct_msg_pb;
    QPushButton *add_contact_pb;
    QPushButton *del_contact_pb;
    QWidget *chat_w;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *all_chats_pb;
    QSpacerItem *horizontalSpacer_5;
    QLabel *chat_name_lbl;
    QTextBrowser *chat_display;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *type_field;
    QPushButton *send_pb;
    QWidget *login_w;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *enter_txt_lo;
    QSpacerItem *horizontalSpacer_14;
    QLabel *enter_lbl;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *login_lo;
    QSpacerItem *horizontalSpacer_8;
    QLabel *login_lbl;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *login_elbl;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *pass_lo;
    QSpacerItem *horizontalSpacer_10;
    QLabel *pass_lbl;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *pass_elbl;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *reg_pb_lo;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *enter_pb;
    QPushButton *reg_pb;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(350, 350);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        main_widget = new QWidget(MainWindow);
        main_widget->setObjectName(QString::fromUtf8("main_widget"));
        main_widget->setEnabled(true);
        main_widget->setMinimumSize(QSize(350, 350));
        gridLayout = new QGridLayout(main_widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        menu_w = new QWidget(main_widget);
        menu_w->setObjectName(QString::fromUtf8("menu_w"));
        menu_w->setEnabled(true);
        sizePolicy.setHeightForWidth(menu_w->sizePolicy().hasHeightForWidth());
        menu_w->setSizePolicy(sizePolicy);
        menu_w->setMinimumSize(QSize(331, 331));
        verticalLayout_3 = new QVBoxLayout(menu_w);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        nickname_lbl = new QLabel(menu_w);
        nickname_lbl->setObjectName(QString::fromUtf8("nickname_lbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nickname_lbl->sizePolicy().hasHeightForWidth());
        nickname_lbl->setSizePolicy(sizePolicy1);
        nickname_lbl->setMinimumSize(QSize(111, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        nickname_lbl->setFont(font);
        nickname_lbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(nickname_lbl);

        logout_pb = new QPushButton(menu_w);
        logout_pb->setObjectName(QString::fromUtf8("logout_pb"));
        sizePolicy1.setHeightForWidth(logout_pb->sizePolicy().hasHeightForWidth());
        logout_pb->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(logout_pb);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tab_w = new QTabWidget(menu_w);
        tab_w->setObjectName(QString::fromUtf8("tab_w"));
        sizePolicy.setHeightForWidth(tab_w->sizePolicy().hasHeightForWidth());
        tab_w->setSizePolicy(sizePolicy);
        tab_w->setMinimumSize(QSize(289, 277));
        chat_tab = new QWidget();
        chat_tab->setObjectName(QString::fromUtf8("chat_tab"));
        verticalLayout = new QVBoxLayout(chat_tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chat_list_lw = new QListWidget(chat_tab);
        chat_list_lw->setObjectName(QString::fromUtf8("chat_list_lw"));
        sizePolicy.setHeightForWidth(chat_list_lw->sizePolicy().hasHeightForWidth());
        chat_list_lw->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(chat_list_lw);

        chats_pb_lo = new QHBoxLayout();
        chats_pb_lo->setObjectName(QString::fromUtf8("chats_pb_lo"));
        chats_pb_lo->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        chats_pb_lo->addItem(horizontalSpacer);

        create_gc_pb = new QPushButton(chat_tab);
        create_gc_pb->setObjectName(QString::fromUtf8("create_gc_pb"));

        chats_pb_lo->addWidget(create_gc_pb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        chats_pb_lo->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(chats_pb_lo);

        tab_w->addTab(chat_tab, QString());
        contacts_tab = new QWidget();
        contacts_tab->setObjectName(QString::fromUtf8("contacts_tab"));
        verticalLayout_2 = new QVBoxLayout(contacts_tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        contacts_lw = new QListWidget(contacts_tab);
        contacts_lw->setObjectName(QString::fromUtf8("contacts_lw"));
        sizePolicy.setHeightForWidth(contacts_lw->sizePolicy().hasHeightForWidth());
        contacts_lw->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(contacts_lw);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        direct_msg_pb = new QPushButton(contacts_tab);
        direct_msg_pb->setObjectName(QString::fromUtf8("direct_msg_pb"));

        horizontalLayout->addWidget(direct_msg_pb);

        add_contact_pb = new QPushButton(contacts_tab);
        add_contact_pb->setObjectName(QString::fromUtf8("add_contact_pb"));

        horizontalLayout->addWidget(add_contact_pb);

        del_contact_pb = new QPushButton(contacts_tab);
        del_contact_pb->setObjectName(QString::fromUtf8("del_contact_pb"));

        horizontalLayout->addWidget(del_contact_pb);


        verticalLayout_2->addLayout(horizontalLayout);

        tab_w->addTab(contacts_tab, QString());

        verticalLayout_3->addWidget(tab_w);


        gridLayout->addWidget(menu_w,  0, 0, -1, -1);

        chat_w = new QWidget(main_widget);
        chat_w->setObjectName(QString::fromUtf8("chat_w"));
        sizePolicy.setHeightForWidth(chat_w->sizePolicy().hasHeightForWidth());
        chat_w->setSizePolicy(sizePolicy);
        chat_w->setMinimumSize(QSize(311, 331));
        verticalLayout_4 = new QVBoxLayout(chat_w);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        all_chats_pb = new QPushButton(chat_w);
        all_chats_pb->setObjectName(QString::fromUtf8("all_chats_pb"));
        sizePolicy1.setHeightForWidth(all_chats_pb->sizePolicy().hasHeightForWidth());
        all_chats_pb->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(all_chats_pb);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_4);

        chat_name_lbl = new QLabel(chat_w);
        chat_name_lbl->setObjectName(QString::fromUtf8("chat_name_lbl"));
        chat_name_lbl->setFont(font);
        chat_name_lbl->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(chat_name_lbl);

        chat_display = new QTextBrowser(chat_w);
        chat_display->setObjectName(QString::fromUtf8("chat_display"));

        verticalLayout_4->addWidget(chat_display);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        type_field = new QLineEdit(chat_w);
        type_field->setObjectName(QString::fromUtf8("type_field"));

        horizontalLayout_2->addWidget(type_field);

        send_pb = new QPushButton(chat_w);
        send_pb->setObjectName(QString::fromUtf8("send_pb"));
        sizePolicy1.setHeightForWidth(send_pb->sizePolicy().hasHeightForWidth());
        send_pb->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(send_pb);


        verticalLayout_4->addLayout(horizontalLayout_2);


        gridLayout->addWidget(chat_w,  0, 0, -1, -1);

        login_w = new QWidget(main_widget);
        login_w->setObjectName(QString::fromUtf8("login_w"));
        login_w->setEnabled(true);
        sizePolicy.setHeightForWidth(login_w->sizePolicy().hasHeightForWidth());
        login_w->setSizePolicy(sizePolicy);
        login_w->setMinimumSize(QSize(331, 331));
        verticalLayout_5 = new QVBoxLayout(login_w);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        enter_txt_lo = new QHBoxLayout();
        enter_txt_lo->setObjectName(QString::fromUtf8("enter_txt_lo"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        enter_txt_lo->addItem(horizontalSpacer_14);

        enter_lbl = new QLabel(login_w);
        enter_lbl->setObjectName(QString::fromUtf8("enter_lbl"));
        enter_lbl->setAlignment(Qt::AlignCenter);

        enter_txt_lo->addWidget(enter_lbl);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        enter_txt_lo->addItem(horizontalSpacer_15);


        verticalLayout_5->addLayout(enter_txt_lo);

        verticalSpacer_5 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_5);

        login_lo = new QHBoxLayout();
        login_lo->setObjectName(QString::fromUtf8("login_lo"));
        horizontalSpacer_8 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        login_lo->addItem(horizontalSpacer_8);

        login_lbl = new QLabel(login_w);
        login_lbl->setObjectName(QString::fromUtf8("login_lbl"));
        sizePolicy1.setHeightForWidth(login_lbl->sizePolicy().hasHeightForWidth());
        login_lbl->setSizePolicy(sizePolicy1);
        login_lbl->setMinimumSize(QSize(50, 0));

        login_lo->addWidget(login_lbl);

        horizontalSpacer_6 = new QSpacerItem(17, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        login_lo->addItem(horizontalSpacer_6);

        login_elbl = new QLineEdit(login_w);
        login_elbl->setObjectName(QString::fromUtf8("login_elbl"));
        sizePolicy1.setHeightForWidth(login_elbl->sizePolicy().hasHeightForWidth());
        login_elbl->setSizePolicy(sizePolicy1);

        login_lo->addWidget(login_elbl);

        horizontalSpacer_9 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        login_lo->addItem(horizontalSpacer_9);


        verticalLayout_5->addLayout(login_lo);

        verticalSpacer_4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_4);

        pass_lo = new QHBoxLayout();
        pass_lo->setObjectName(QString::fromUtf8("pass_lo"));
        horizontalSpacer_10 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        pass_lo->addItem(horizontalSpacer_10);

        pass_lbl = new QLabel(login_w);
        pass_lbl->setObjectName(QString::fromUtf8("pass_lbl"));
        sizePolicy1.setHeightForWidth(pass_lbl->sizePolicy().hasHeightForWidth());
        pass_lbl->setSizePolicy(sizePolicy1);

        pass_lo->addWidget(pass_lbl);

        horizontalSpacer_7 = new QSpacerItem(17, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        pass_lo->addItem(horizontalSpacer_7);

        pass_elbl = new QLineEdit(login_w);
        pass_elbl->setObjectName(QString::fromUtf8("pass_elbl"));
        sizePolicy1.setHeightForWidth(pass_elbl->sizePolicy().hasHeightForWidth());
        pass_elbl->setSizePolicy(sizePolicy1);

        pass_lo->addWidget(pass_elbl);

        horizontalSpacer_11 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        pass_lo->addItem(horizontalSpacer_11);


        verticalLayout_5->addLayout(pass_lo);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_3);

        reg_pb_lo = new QHBoxLayout();
        reg_pb_lo->setObjectName(QString::fromUtf8("reg_pb_lo"));
        horizontalSpacer_12 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        reg_pb_lo->addItem(horizontalSpacer_12);

        enter_pb = new QPushButton(login_w);
        enter_pb->setObjectName(QString::fromUtf8("enter_pb"));
        sizePolicy1.setHeightForWidth(enter_pb->sizePolicy().hasHeightForWidth());
        enter_pb->setSizePolicy(sizePolicy1);
        enter_pb->setMinimumSize(QSize(80, 0));

        reg_pb_lo->addWidget(enter_pb);

        reg_pb = new QPushButton(login_w);
        reg_pb->setObjectName(QString::fromUtf8("reg_pb"));
        sizePolicy1.setHeightForWidth(reg_pb->sizePolicy().hasHeightForWidth());
        reg_pb->setSizePolicy(sizePolicy1);
        reg_pb->setMinimumSize(QSize(80, 0));

        reg_pb_lo->addWidget(reg_pb);

        horizontalSpacer_13 = new QSpacerItem(17, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        reg_pb_lo->addItem(horizontalSpacer_13);


        verticalLayout_5->addLayout(reg_pb_lo);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        gridLayout->addWidget(login_w, 0, 0, -1, -1);

        MainWindow->setCentralWidget(main_widget);
        login_w->raise();
        menu_w->raise();
        chat_w->raise();

        retranslateUi(MainWindow);

        tab_w->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Chat", nullptr));
        nickname_lbl->setText(QString());
        logout_pb->setText(QCoreApplication::translate("MainWindow", "log out", nullptr));
        create_gc_pb->setText(QCoreApplication::translate("MainWindow", "Create group chat", nullptr));
        tab_w->setTabText(tab_w->indexOf(chat_tab), QCoreApplication::translate("MainWindow", "Chats", nullptr));
        direct_msg_pb->setText(QCoreApplication::translate("MainWindow", "Write a message", nullptr));
        add_contact_pb->setText(QCoreApplication::translate("MainWindow", "Add contact", nullptr));
        del_contact_pb->setText(QCoreApplication::translate("MainWindow", "Delete contact", nullptr));
        tab_w->setTabText(tab_w->indexOf(contacts_tab), QCoreApplication::translate("MainWindow", "Contacts", nullptr));
        all_chats_pb->setText(QCoreApplication::translate("MainWindow", "All chats", nullptr));
        chat_name_lbl->setText(QString());
        send_pb->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
        enter_lbl->setText(QCoreApplication::translate("MainWindow", "Enter login and password:", nullptr));
        login_lbl->setText(QCoreApplication::translate("MainWindow", "LogIn", nullptr));
        pass_lbl->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        enter_pb->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        reg_pb->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
