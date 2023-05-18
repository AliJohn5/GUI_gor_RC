/********************************************************************************
** Form generated from reading UI file 'mainwindow4.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW4_H
#define UI_MAINWINDOW4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mainwindow4.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow4
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    MainWindow4::CustomLabel *label;
    QSpacerItem *horizontalSpacer;
    MainWindow4::CustomLabel *frame_2_label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow4)
    {
        if (MainWindow4->objectName().isEmpty())
            MainWindow4->setObjectName(QString::fromUtf8("MainWindow4"));
        MainWindow4->resize(800, 600);
        centralwidget = new QWidget(MainWindow4);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new MainWindow4::CustomLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        frame_2_label = new MainWindow4::CustomLabel(centralwidget);
        frame_2_label->setObjectName(QString::fromUtf8("frame_2_label"));
        frame_2_label->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        horizontalLayout->addWidget(frame_2_label);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout->addWidget(pushButton_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(label_4);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_3->addWidget(spinBox);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_5);

        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_4->addWidget(spinBox_2);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_6->addWidget(pushButton_5);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_6->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_6->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);"));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MainWindow4->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow4);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow4->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow4);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow4->setStatusBar(statusbar);

        retranslateUi(MainWindow4);

        QMetaObject::connectSlotsByName(MainWindow4);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow4)
    {
        MainWindow4->setWindowTitle(QApplication::translate("MainWindow4", "MainWindow", nullptr));
        label->setText(QString());
        frame_2_label->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow4", "Camera 1", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow4", "Camera 2", nullptr));
        label_4->setText(QApplication::translate("MainWindow4", "camera 1", nullptr));
        label_5->setText(QApplication::translate("MainWindow4", "camera 2", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow4", "reset", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow4", "print", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow4", "print size", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow4: public Ui_MainWindow4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW4_H
