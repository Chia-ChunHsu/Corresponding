/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *pointLabel;
    QPushButton *ApplyButton;
    QPushButton *CancelButton;
    QLabel *pointRGBLabel;
    QPushButton *TurnButton;
    QPushButton *cutButton;
    QPushButton *pushButton_2;
    QSpinBox *spinBoxx;
    QSpinBox *spinBoxy;
    QPushButton *rightButton;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *leftButton;
    QPushButton *HomoButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1391, 551);
        pointLabel = new QLabel(Dialog);
        pointLabel->setObjectName(QStringLiteral("pointLabel"));
        pointLabel->setGeometry(QRect(10, 10, 640, 480));
        pointLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        ApplyButton = new QPushButton(Dialog);
        ApplyButton->setObjectName(QStringLiteral("ApplyButton"));
        ApplyButton->setGeometry(QRect(10, 500, 231, 41));
        CancelButton = new QPushButton(Dialog);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(520, 500, 131, 41));
        pointRGBLabel = new QLabel(Dialog);
        pointRGBLabel->setObjectName(QStringLiteral("pointRGBLabel"));
        pointRGBLabel->setGeometry(QRect(660, 10, 720, 480));
        pointRGBLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        TurnButton = new QPushButton(Dialog);
        TurnButton->setObjectName(QStringLiteral("TurnButton"));
        TurnButton->setGeometry(QRect(660, 500, 141, 41));
        cutButton = new QPushButton(Dialog);
        cutButton->setObjectName(QStringLiteral("cutButton"));
        cutButton->setGeometry(QRect(810, 500, 151, 41));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(970, 500, 111, 41));
        spinBoxx = new QSpinBox(Dialog);
        spinBoxx->setObjectName(QStringLiteral("spinBoxx"));
        spinBoxx->setGeometry(QRect(1090, 500, 71, 41));
        spinBoxx->setMaximum(640);
        spinBoxx->setValue(100);
        spinBoxy = new QSpinBox(Dialog);
        spinBoxy->setObjectName(QStringLiteral("spinBoxy"));
        spinBoxy->setGeometry(QRect(1160, 500, 71, 41));
        spinBoxy->setMaximum(480);
        spinBoxy->setValue(50);
        rightButton = new QPushButton(Dialog);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(1240, 500, 75, 23));
        doubleSpinBox = new QDoubleSpinBox(Dialog);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(1320, 500, 71, 41));
        doubleSpinBox->setSingleStep(0.01);
        doubleSpinBox->setValue(1);
        leftButton = new QPushButton(Dialog);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(1240, 520, 75, 23));
        HomoButton = new QPushButton(Dialog);
        HomoButton->setObjectName(QStringLiteral("HomoButton"));
        HomoButton->setGeometry(QRect(250, 500, 261, 41));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        pointLabel->setText(QApplication::translate("Dialog", "TextLabel", 0));
        ApplyButton->setText(QApplication::translate("Dialog", "Apply", 0));
        CancelButton->setText(QApplication::translate("Dialog", "Cancel", 0));
        pointRGBLabel->setText(QApplication::translate("Dialog", "TextLabel", 0));
        TurnButton->setText(QApplication::translate("Dialog", "Turn", 0));
        cutButton->setText(QApplication::translate("Dialog", "Cut", 0));
        pushButton_2->setText(QApplication::translate("Dialog", "Set Original", 0));
        rightButton->setText(QApplication::translate("Dialog", "turn right", 0));
        leftButton->setText(QApplication::translate("Dialog", "turn left", 0));
        HomoButton->setText(QApplication::translate("Dialog", "Homography", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
