/********************************************************************************
** Form generated from reading UI file 'hello_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_GUI_H
#define UI_HELLO_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helloGui
{
public:
    QAction *actionCamera_1;
    QAction *actionCamera_2;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QMenu *menuoption;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *helloGui)
    {
        if (helloGui->objectName().isEmpty())
            helloGui->setObjectName(QString::fromUtf8("helloGui"));
        helloGui->resize(435, 586);
        helloGui->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"border-image: url(:/new/prefix1/img/bac3.png);\n"
"}\n"
""));
        actionCamera_1 = new QAction(helloGui);
        actionCamera_1->setObjectName(QString::fromUtf8("actionCamera_1"));
        actionCamera_1->setCheckable(true);
        actionCamera_2 = new QAction(helloGui);
        actionCamera_2->setObjectName(QString::fromUtf8("actionCamera_2"));
        actionCamera_2->setCheckable(true);
        centralwidget = new QWidget(helloGui);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-width: 2px;\n"
"border-style: outset;\n"
"border-color:#8E3B35;\n"
"    background-color: #808080; /* Cornflower blue */\n"
"    color: #000000; /* White */\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 10px;}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:#8E3B35;\n"
"    border-style: inset;\n"
"}"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-width: 2px;\n"
"border-style: outset;\n"
"    background-color: #808080; /* Cornflower blue */\n"
"    color: #000000; /* White */\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 10px;}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:#8E3B35;\n"
"    border-style: inset;\n"
"}"));

        verticalLayout->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-width: 2px;\n"
"border-style: outset;\n"
"    background-color: #808080; /* Cornflower blue */\n"
"    color: #000000; /* White */\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 10px;}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:#8E3B35;\n"
"    border-style: inset;\n"
"}"));

        verticalLayout->addWidget(pushButton_9);


        verticalLayout_3->addLayout(verticalLayout);

        helloGui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(helloGui);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 435, 22));
        menuoption = new QMenu(menubar);
        menuoption->setObjectName(QString::fromUtf8("menuoption"));
        helloGui->setMenuBar(menubar);
        statusbar = new QStatusBar(helloGui);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        helloGui->setStatusBar(statusbar);
        toolBar = new QToolBar(helloGui);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        helloGui->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuoption->menuAction());
        menuoption->addSeparator();
        menuoption->addAction(actionCamera_1);
        menuoption->addAction(actionCamera_2);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionCamera_1);
        toolBar->addSeparator();
        toolBar->addAction(actionCamera_2);
        toolBar->addSeparator();

        retranslateUi(helloGui);

        QMetaObject::connectSlotsByName(helloGui);
    } // setupUi

    void retranslateUi(QMainWindow *helloGui)
    {
        helloGui->setWindowTitle(QApplication::translate("helloGui", "MainWindow", nullptr));
        actionCamera_1->setText(QApplication::translate("helloGui", "Camera_1", nullptr));
        actionCamera_2->setText(QApplication::translate("helloGui", "Camera_2", nullptr));
        pushButton_7->setText(QApplication::translate("helloGui", "window 2", nullptr));
        pushButton_8->setText(QApplication::translate("helloGui", "window 3", nullptr));
        pushButton_9->setText(QApplication::translate("helloGui", "window 4", nullptr));
        menuoption->setTitle(QApplication::translate("helloGui", "option", nullptr));
        toolBar->setWindowTitle(QApplication::translate("helloGui", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helloGui: public Ui_helloGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_GUI_H
