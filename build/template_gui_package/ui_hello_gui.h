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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helloGui
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonCamera;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *helloGui)
    {
        if (helloGui->objectName().isEmpty())
            helloGui->setObjectName(QString::fromUtf8("helloGui"));
        helloGui->resize(1132, 638);
        helloGui->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/back.jpg);"));
        centralwidget = new QWidget(helloGui);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButtonCamera = new QPushButton(centralwidget);
        pushButtonCamera->setObjectName(QString::fromUtf8("pushButtonCamera"));
        pushButtonCamera->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/cameraicon.jpg);\n"
""));

        horizontalLayout_2->addWidget(pushButtonCamera);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        helloGui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(helloGui);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1132, 22));
        helloGui->setMenuBar(menubar);
        statusbar = new QStatusBar(helloGui);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        helloGui->setStatusBar(statusbar);

        retranslateUi(helloGui);

        QMetaObject::connectSlotsByName(helloGui);
    } // setupUi

    void retranslateUi(QMainWindow *helloGui)
    {
        helloGui->setWindowTitle(QApplication::translate("helloGui", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        pushButtonCamera->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class helloGui: public Ui_helloGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_GUI_H
