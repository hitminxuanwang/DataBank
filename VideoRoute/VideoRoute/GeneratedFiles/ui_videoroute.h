/********************************************************************************
** Form generated from reading UI file 'videoroute.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOROUTE_H
#define UI_VIDEOROUTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoRouteClass
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QWidget *VideoRouteClass)
    {
        if (VideoRouteClass->objectName().isEmpty())
            VideoRouteClass->setObjectName(QStringLiteral("VideoRouteClass"));
        VideoRouteClass->resize(1300, 1000);
        groupBox = new QGroupBox(VideoRouteClass);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 1200, 400));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 600, 400));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(600, 0, 600, 400));
        groupBox_2 = new QGroupBox(VideoRouteClass);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 430, 1200, 405));
        groupBox_3 = new QGroupBox(VideoRouteClass);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 835, 1200, 100));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 30, 75, 23));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(890, 20, 75, 23));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 30, 54, 12));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 30, 71, 16));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(510, 30, 71, 16));
        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(240, 30, 71, 20));
        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(420, 30, 71, 20));
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(580, 30, 71, 20));

        retranslateUi(VideoRouteClass);
        QObject::connect(pushButton, SIGNAL(clicked()), VideoRouteClass, SLOT(save()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), VideoRouteClass, SLOT(play()));

        QMetaObject::connectSlotsByName(VideoRouteClass);
    } // setupUi

    void retranslateUi(QWidget *VideoRouteClass)
    {
        VideoRouteClass->setWindowTitle(QApplication::translate("VideoRouteClass", "VideoRoute", 0));
        groupBox->setTitle(QApplication::translate("VideoRouteClass", "GroupBox", 0));
        label->setText(QApplication::translate("VideoRouteClass", "TextLabel", 0));
        label_2->setText(QApplication::translate("VideoRouteClass", "TextLabel", 0));
        groupBox_2->setTitle(QApplication::translate("VideoRouteClass", "GroupBox", 0));
        groupBox_3->setTitle(QApplication::translate("VideoRouteClass", "GroupBox", 0));
        pushButton->setText(QApplication::translate("VideoRouteClass", "Process", 0));
        pushButton_2->setText(QApplication::translate("VideoRouteClass", "Play", 0));
        label_3->setText(QApplication::translate("VideoRouteClass", "Speed-Up", 0));
        label_4->setText(QApplication::translate("VideoRouteClass", "Start Video", 0));
        label_5->setText(QApplication::translate("VideoRouteClass", "End Video", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoRouteClass: public Ui_VideoRouteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOROUTE_H
