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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helloGui
{
public:
    QAction *actionopen_camera;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *frame_2_label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *min_v_slider;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *max_v_slider_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSlider *min_s_slider;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSlider *max_s_slider;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSlider *min_v_slider_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSlider *max_v_slider;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButtonCamera;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QMenuBar *menubar;
    QMenu *menuoption;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *helloGui)
    {
        if (helloGui->objectName().isEmpty())
            helloGui->setObjectName(QString::fromUtf8("helloGui"));
        helloGui->resize(1132, 638);
        helloGui->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/back.jpg);"));
        actionopen_camera = new QAction(helloGui);
        actionopen_camera->setObjectName(QString::fromUtf8("actionopen_camera"));
        centralwidget = new QWidget(helloGui);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        frame_2_label = new QLabel(centralwidget);
        frame_2_label->setObjectName(QString::fromUtf8("frame_2_label"));

        horizontalLayout->addWidget(frame_2_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_4->addWidget(lineEdit);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        min_v_slider = new QSlider(centralwidget);
        min_v_slider->setObjectName(QString::fromUtf8("min_v_slider"));
        min_v_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(min_v_slider);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        max_v_slider_2 = new QSlider(centralwidget);
        max_v_slider_2->setObjectName(QString::fromUtf8("max_v_slider_2"));
        max_v_slider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(max_v_slider_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        min_s_slider = new QSlider(centralwidget);
        min_s_slider->setObjectName(QString::fromUtf8("min_s_slider"));
        min_s_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(min_s_slider);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        max_s_slider = new QSlider(centralwidget);
        max_s_slider->setObjectName(QString::fromUtf8("max_s_slider"));
        max_s_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(max_s_slider);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        min_v_slider_2 = new QSlider(centralwidget);
        min_v_slider_2->setObjectName(QString::fromUtf8("min_v_slider_2"));
        min_v_slider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(min_v_slider_2);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        max_v_slider = new QSlider(centralwidget);
        max_v_slider->setObjectName(QString::fromUtf8("max_v_slider"));
        max_v_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(max_v_slider);


        verticalLayout->addLayout(horizontalLayout_8);


        horizontalLayout_10->addLayout(verticalLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_2->addWidget(pushButton_4);

        pushButtonCamera = new QPushButton(centralwidget);
        pushButtonCamera->setObjectName(QString::fromUtf8("pushButtonCamera"));
        pushButtonCamera->setStyleSheet(QString::fromUtf8("border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));

        verticalLayout_2->addWidget(pushButtonCamera);


        horizontalLayout_9->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout_3->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout_3->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout_3->addWidget(pushButton_8);


        horizontalLayout_9->addLayout(verticalLayout_3);


        horizontalLayout_10->addLayout(horizontalLayout_9);


        verticalLayout_4->addLayout(horizontalLayout_10);

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

        menubar->addAction(menuoption->menuAction());
        menuoption->addSeparator();
        menuoption->addAction(actionopen_camera);

        retranslateUi(helloGui);

        QMetaObject::connectSlotsByName(helloGui);
    } // setupUi

    void retranslateUi(QMainWindow *helloGui)
    {
        helloGui->setWindowTitle(QApplication::translate("helloGui", "MainWindow", nullptr));
        actionopen_camera->setText(QApplication::translate("helloGui", "open_camera", nullptr));
        label->setText(QString());
        frame_2_label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("helloGui", "minimum H", nullptr));
        label_4->setText(QApplication::translate("helloGui", "maximum H", nullptr));
        label_5->setText(QApplication::translate("helloGui", "minimum S", nullptr));
        label_6->setText(QApplication::translate("helloGui", "maximum S", nullptr));
        label_7->setText(QApplication::translate("helloGui", "minimum V", nullptr));
        label_8->setText(QApplication::translate("helloGui", "maximum V", nullptr));
        pushButton->setText(QApplication::translate("helloGui", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("helloGui", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("helloGui", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("helloGui", "PushButton", nullptr));
        pushButtonCamera->setText(QString());
        pushButton_5->setText(QApplication::translate("helloGui", "PushButton", nullptr));
        pushButton_6->setText(QApplication::translate("helloGui", "PushButton", nullptr));
        pushButton_7->setText(QApplication::translate("helloGui", "PushButton", nullptr));
        pushButton_8->setText(QApplication::translate("helloGui", "PushButton", nullptr));
        menuoption->setTitle(QApplication::translate("helloGui", "option", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helloGui: public Ui_helloGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_GUI_H
