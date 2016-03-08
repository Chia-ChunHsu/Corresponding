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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *BeforeTab;
    QWidget *tab;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QLabel *Ref;
    QWidget *tab_5;
    QPushButton *LoadRefButton;
    QLabel *RefLabel2;
    QLabel *RefLabel1;
    QLabel *RefLabel0;
    QLabel *RefLabel3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *tab_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_6;
    QLabel *Before;
    QWidget *tab_7;
    QPushButton *LoadBeforeButton;
    QLabel *BeforeLabel3;
    QLabel *BeforeLabel0;
    QLabel *BeforeLabel1;
    QLabel *BeforeLabel2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QWidget *tab_3;
    QTabWidget *tabWidget_3;
    QWidget *tab_8;
    QLabel *After;
    QWidget *tab_9;
    QPushButton *LoadAfterButtom;
    QLabel *AfterLabel0;
    QLabel *AfterLabel2;
    QLabel *AfterLabel1;
    QLabel *AfterLabel3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *RGBLabel;
    QPushButton *LoadRGBButtom;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1350, 655);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BeforeTab = new QTabWidget(centralWidget);
        BeforeTab->setObjectName(QStringLiteral("BeforeTab"));
        BeforeTab->setGeometry(QRect(10, 10, 671, 561));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget = new QTabWidget(tab);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 661, 521));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        Ref = new QLabel(tab_4);
        Ref->setObjectName(QStringLiteral("Ref"));
        Ref->setGeometry(QRect(10, 10, 640, 480));
        Ref->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        LoadRefButton = new QPushButton(tab_5);
        LoadRefButton->setObjectName(QStringLiteral("LoadRefButton"));
        LoadRefButton->setGeometry(QRect(10, 410, 631, 81));
        RefLabel2 = new QLabel(tab_5);
        RefLabel2->setObjectName(QStringLiteral("RefLabel2"));
        RefLabel2->setGeometry(QRect(10, 210, 256, 192));
        RefLabel2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        RefLabel1 = new QLabel(tab_5);
        RefLabel1->setObjectName(QStringLiteral("RefLabel1"));
        RefLabel1->setGeometry(QRect(330, 10, 256, 192));
        RefLabel1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        RefLabel0 = new QLabel(tab_5);
        RefLabel0->setObjectName(QStringLiteral("RefLabel0"));
        RefLabel0->setGeometry(QRect(10, 10, 256, 192));
        RefLabel0->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        RefLabel3 = new QLabel(tab_5);
        RefLabel3->setObjectName(QStringLiteral("RefLabel3"));
        RefLabel3->setGeometry(QRect(330, 210, 256, 192));
        RefLabel3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(tab_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 10, 51, 191));
        pushButton_2 = new QPushButton(tab_5);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 210, 51, 191));
        pushButton_3 = new QPushButton(tab_5);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(590, 10, 51, 191));
        pushButton_4 = new QPushButton(tab_5);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(590, 210, 51, 191));
        tabWidget->addTab(tab_5, QString());
        BeforeTab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 661, 521));
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        Before = new QLabel(tab_6);
        Before->setObjectName(QStringLiteral("Before"));
        Before->setGeometry(QRect(10, 10, 640, 480));
        Before->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        LoadBeforeButton = new QPushButton(tab_7);
        LoadBeforeButton->setObjectName(QStringLiteral("LoadBeforeButton"));
        LoadBeforeButton->setGeometry(QRect(10, 410, 631, 81));
        BeforeLabel3 = new QLabel(tab_7);
        BeforeLabel3->setObjectName(QStringLiteral("BeforeLabel3"));
        BeforeLabel3->setGeometry(QRect(330, 210, 256, 192));
        BeforeLabel3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        BeforeLabel0 = new QLabel(tab_7);
        BeforeLabel0->setObjectName(QStringLiteral("BeforeLabel0"));
        BeforeLabel0->setGeometry(QRect(10, 10, 256, 192));
        BeforeLabel0->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        BeforeLabel1 = new QLabel(tab_7);
        BeforeLabel1->setObjectName(QStringLiteral("BeforeLabel1"));
        BeforeLabel1->setGeometry(QRect(330, 10, 256, 192));
        BeforeLabel1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        BeforeLabel2 = new QLabel(tab_7);
        BeforeLabel2->setObjectName(QStringLiteral("BeforeLabel2"));
        BeforeLabel2->setGeometry(QRect(10, 210, 256, 192));
        BeforeLabel2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_5 = new QPushButton(tab_7);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(590, 210, 51, 191));
        pushButton_6 = new QPushButton(tab_7);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(270, 210, 51, 191));
        pushButton_7 = new QPushButton(tab_7);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(590, 10, 51, 191));
        pushButton_8 = new QPushButton(tab_7);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(270, 10, 51, 191));
        tabWidget_2->addTab(tab_7, QString());
        BeforeTab->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget_3 = new QTabWidget(tab_3);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(0, 0, 661, 521));
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        After = new QLabel(tab_8);
        After->setObjectName(QStringLiteral("After"));
        After->setGeometry(QRect(10, 10, 640, 480));
        After->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tabWidget_3->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        LoadAfterButtom = new QPushButton(tab_9);
        LoadAfterButtom->setObjectName(QStringLiteral("LoadAfterButtom"));
        LoadAfterButtom->setGeometry(QRect(10, 410, 631, 81));
        AfterLabel0 = new QLabel(tab_9);
        AfterLabel0->setObjectName(QStringLiteral("AfterLabel0"));
        AfterLabel0->setGeometry(QRect(10, 10, 256, 192));
        AfterLabel0->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        AfterLabel2 = new QLabel(tab_9);
        AfterLabel2->setObjectName(QStringLiteral("AfterLabel2"));
        AfterLabel2->setGeometry(QRect(10, 210, 256, 192));
        AfterLabel2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        AfterLabel1 = new QLabel(tab_9);
        AfterLabel1->setObjectName(QStringLiteral("AfterLabel1"));
        AfterLabel1->setGeometry(QRect(330, 10, 256, 192));
        AfterLabel1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        AfterLabel3 = new QLabel(tab_9);
        AfterLabel3->setObjectName(QStringLiteral("AfterLabel3"));
        AfterLabel3->setGeometry(QRect(330, 210, 256, 192));
        AfterLabel3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_9 = new QPushButton(tab_9);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(590, 210, 51, 191));
        pushButton_10 = new QPushButton(tab_9);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(270, 210, 51, 191));
        pushButton_11 = new QPushButton(tab_9);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(590, 10, 51, 191));
        pushButton_12 = new QPushButton(tab_9);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(270, 10, 51, 191));
        tabWidget_3->addTab(tab_9, QString());
        BeforeTab->addTab(tab_3, QString());
        RGBLabel = new QLabel(centralWidget);
        RGBLabel->setObjectName(QStringLiteral("RGBLabel"));
        RGBLabel->setGeometry(QRect(690, 20, 640, 480));
        RGBLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        LoadRGBButtom = new QPushButton(centralWidget);
        LoadRGBButtom->setObjectName(QStringLiteral("LoadRGBButtom"));
        LoadRGBButtom->setGeometry(QRect(690, 510, 641, 61));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1350, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        BeforeTab->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);
        tabWidget_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Ref->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Tab 1", 0));
        LoadRefButton->setText(QApplication::translate("MainWindow", "Load", 0));
        RefLabel2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        RefLabel1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        RefLabel0->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        RefLabel3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", ">", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Tab 2", 0));
        BeforeTab->setTabText(BeforeTab->indexOf(tab), QApplication::translate("MainWindow", "Reference", 0));
        Before->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Tab 1", 0));
        LoadBeforeButton->setText(QApplication::translate("MainWindow", "Load", 0));
        BeforeLabel3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        BeforeLabel0->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        BeforeLabel1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        BeforeLabel2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", ">", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "Tab 2", 0));
        BeforeTab->setTabText(BeforeTab->indexOf(tab_2), QApplication::translate("MainWindow", "Before", 0));
        After->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("MainWindow", "Tab 1", 0));
        LoadAfterButtom->setText(QApplication::translate("MainWindow", "Load", 0));
        AfterLabel0->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        AfterLabel2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        AfterLabel1->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        AfterLabel3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", ">", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_9), QApplication::translate("MainWindow", "Tab 2", 0));
        BeforeTab->setTabText(BeforeTab->indexOf(tab_3), QApplication::translate("MainWindow", "After", 0));
        RGBLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        LoadRGBButtom->setText(QApplication::translate("MainWindow", "Load", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
