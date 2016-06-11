/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *PicLabel;
    QLabel *RGBLabel;
    QPushButton *LoadPic;
    QPushButton *LoadRGB;
    QPushButton *PointButtom;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(671, 420);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PicLabel = new QLabel(centralWidget);
        PicLabel->setObjectName(QStringLiteral("PicLabel"));
        PicLabel->setGeometry(QRect(10, 10, 320, 240));
        PicLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        RGBLabel = new QLabel(centralWidget);
        RGBLabel->setObjectName(QStringLiteral("RGBLabel"));
        RGBLabel->setGeometry(QRect(340, 10, 320, 240));
        RGBLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        LoadPic = new QPushButton(centralWidget);
        LoadPic->setObjectName(QStringLiteral("LoadPic"));
        LoadPic->setGeometry(QRect(10, 260, 321, 51));
        LoadRGB = new QPushButton(centralWidget);
        LoadRGB->setObjectName(QStringLiteral("LoadRGB"));
        LoadRGB->setGeometry(QRect(340, 260, 321, 51));
        PointButtom = new QPushButton(centralWidget);
        PointButtom->setObjectName(QStringLiteral("PointButtom"));
        PointButtom->setGeometry(QRect(10, 320, 321, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 671, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        PicLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        RGBLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LoadPic->setText(QApplication::translate("MainWindow", "Load Caputre Picture", 0));
        LoadRGB->setText(QApplication::translate("MainWindow", "Load RGB", 0));
        PointButtom->setText(QApplication::translate("MainWindow", "Point", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
