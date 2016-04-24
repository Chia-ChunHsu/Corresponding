#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <opencv.hpp>
#include <QLabel>
#include "thread_stitch.h"
#include <dialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void ShowOnLabel(cv::Mat mat, QLabel *k);
    void Stitch(int value);
    void drawOnRGB(std::vector<cv::Point> p);

private slots:


    void on_LoadPic_clicked();

    void on_LoadRGB_clicked();


    void on_PointButtom_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Dialog picdialog;

    cv::Mat rgb;
    cv::Mat pic;

    std::vector<cv::Point> p;
};

#endif // MAINWINDOW_H
