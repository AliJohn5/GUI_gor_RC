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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <hello_gui.h>

QT_BEGIN_NAMESPACE

class Ui_helloGui
{
public:
    QAction *actionopen_camera;
    QAction *actioncamera_2_ON_OFF;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    helloGui::CustomLabel *label;
    QSpacerItem *horizontalSpacer;
    helloGui::CustomLabel *frame_2_label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonCamera;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_8;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QMenuBar *menubar;
    QMenu *menuoption;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *helloGui)
    {
        if (helloGui->objectName().isEmpty())
            helloGui->setObjectName(QString::fromUtf8("helloGui"));
        helloGui->resize(1132, 638);
        helloGui->setStyleSheet(QString::fromUtf8(""));
        actionopen_camera = new QAction(helloGui);
        actionopen_camera->setObjectName(QString::fromUtf8("actionopen_camera"));
        actionopen_camera->setCheckable(true);
        actionopen_camera->setChecked(false);
        actionopen_camera->setEnabled(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../src/cameraicon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen_camera->setIcon(icon);
        actioncamera_2_ON_OFF = new QAction(helloGui);
        actioncamera_2_ON_OFF->setObjectName(QString::fromUtf8("actioncamera_2_ON_OFF"));
        actioncamera_2_ON_OFF->setCheckable(true);
        actioncamera_2_ON_OFF->setIcon(icon);
        centralwidget = new QWidget(helloGui);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new helloGui::CustomLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("border-color: rgb(193, 125, 17);"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        frame_2_label = new helloGui::CustomLabel(centralwidget);
        frame_2_label->setObjectName(QString::fromUtf8("frame_2_label"));
        frame_2_label->setStyleSheet(QString::fromUtf8("border-color: rgb(193, 125, 17);\n"
""));

        horizontalLayout->addWidget(frame_2_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("border-color: rgb(193, 125, 17);"));

        horizontalLayout->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pushButtonCamera = new QPushButton(centralwidget);
        pushButtonCamera->setObjectName(QString::fromUtf8("pushButtonCamera"));
        pushButtonCamera->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #FFA500;\n"
""));

        horizontalLayout_3->addWidget(pushButtonCamera);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #FFA500;\n"
""));

        horizontalLayout_3->addWidget(pushButton_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        gridLayout_2->addWidget(line, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(8, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #FFA500;\n"
""));

        verticalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #FFA500;\n"
""));

        verticalLayout_2->addWidget(pushButton_6);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #FFA500;\n"
""));

        verticalLayout_2->addWidget(pushButton_9);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #FFA500;\n"
""));

        verticalLayout_2->addWidget(pushButton_3);


        horizontalLayout_9->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #FFA500;\n"
""));

        verticalLayout_3->addWidget(pushButton);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #FFA500;\n"
""));

        verticalLayout_3->addWidget(pushButton_7);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #FFA500;\n"
""));

        verticalLayout_3->addWidget(pushButton_2);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #FFA500;\n"
""));

        verticalLayout_3->addWidget(pushButton_8);


        horizontalLayout_9->addLayout(verticalLayout_3);


        horizontalLayout_10->addLayout(horizontalLayout_9);


        horizontalLayout_2->addLayout(horizontalLayout_10);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 185, 110);\n"
"border-color: rgb(233, 185, 110);"));

        verticalLayout_4->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 185, 110);\n"
"border-color: rgb(233, 185, 110);"));

        verticalLayout_4->addWidget(lineEdit_2);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 185, 110);\n"
"border-color: rgb(233, 185, 110);"));

        verticalLayout_4->addWidget(lineEdit_4);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 185, 110);\n"
"border-color: rgb(233, 185, 110);"));

        verticalLayout_4->addWidget(lineEdit_3);


        horizontalLayout_2->addLayout(verticalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        helloGui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(helloGui);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1132, 22));
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
        menuoption->addAction(actionopen_camera);
        menuoption->addAction(actioncamera_2_ON_OFF);
        toolBar->addAction(actionopen_camera);
        toolBar->addSeparator();
        toolBar->addAction(actioncamera_2_ON_OFF);
        toolBar->addSeparator();

        retranslateUi(helloGui);

        QMetaObject::connectSlotsByName(helloGui);
    } // setupUi

    void retranslateUi(QMainWindow *helloGui)
    {
        helloGui->setWindowTitle(QApplication::translate("helloGui", "MainWindow", nullptr));
        actionopen_camera->setText(QApplication::translate("helloGui", "camera1 (ON/OFF)", nullptr));
        actioncamera_2_ON_OFF->setText(QApplication::translate("helloGui", "camera 2 (ON/OFF)", nullptr));
        label->setText(QString());
        frame_2_label->setText(QString());
        label_2->setText(QString());
        pushButtonCamera->setText(QApplication::translate("helloGui", "Camera 1", nullptr));
        pushButton_4->setText(QApplication::translate("helloGui", "Camera 2", nullptr));
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_9->setText(QString());
        pushButton_3->setText(QString());
        pushButton->setText(QApplication::translate("helloGui", "Enter", nullptr));
        pushButton_7->setText(QString());
        pushButton_2->setText(QString());
        pushButton_8->setText(QString());
        menuoption->setTitle(QApplication::translate("helloGui", "option", nullptr));
        toolBar->setWindowTitle(QApplication::translate("helloGui", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helloGui: public Ui_helloGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_GUI_H
