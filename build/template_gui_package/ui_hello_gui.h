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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helloGui
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *sub_B;
    QLabel *sub;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pub_B;
    QLabel *pub;
    QLabel *frame_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *helloGui)
    {
        if (helloGui->objectName().isEmpty())
            helloGui->setObjectName(QString::fromUtf8("helloGui"));
        helloGui->resize(702, 411);
        centralwidget = new QWidget(helloGui);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sub_B = new QPushButton(centralwidget);
        sub_B->setObjectName(QString::fromUtf8("sub_B"));

        horizontalLayout->addWidget(sub_B);

        sub = new QLabel(centralwidget);
        sub->setObjectName(QString::fromUtf8("sub"));

        horizontalLayout->addWidget(sub);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pub_B = new QPushButton(centralwidget);
        pub_B->setObjectName(QString::fromUtf8("pub_B"));

        horizontalLayout_2->addWidget(pub_B);

        pub = new QLabel(centralwidget);
        pub->setObjectName(QString::fromUtf8("pub"));

        horizontalLayout_2->addWidget(pub);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        frame_label = new QLabel(centralwidget);
        frame_label->setObjectName(QString::fromUtf8("frame_label"));

        verticalLayout_2->addWidget(frame_label);


        verticalLayout_3->addLayout(verticalLayout_2);

        helloGui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(helloGui);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 702, 22));
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
        sub_B->setText(QApplication::translate("helloGui", "sub (hello ali)", nullptr));
        sub->setText(QApplication::translate("helloGui", "sub", nullptr));
        pub_B->setText(QApplication::translate("helloGui", "pub_B", nullptr));
        pub->setText(QApplication::translate("helloGui", "pub", nullptr));
        frame_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class helloGui: public Ui_helloGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_GUI_H
