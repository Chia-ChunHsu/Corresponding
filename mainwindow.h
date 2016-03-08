#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <opencv.hpp>
#include <QLabel>
#include "thread_stitch.h"
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

private slots:
    void on_LoadRefButton_clicked();

    void on_LoadBeforeButton_clicked();

private:
    Ui::MainWindow *ui;

    Thread_Stitch TS;
    Thread_Stitch TS_Detect;
    std::vector<cv::Mat> nonDilateMask;

    cv::Mat RefResult;
    std::vector<cv::Point> CorPoint;

    std::vector<cv::Mat> subref;
    std::vector<cv::Mat> subWref;

    std::vector<cv::Mat> subbefore;
    std::vector<cv::Mat> subWbefore;

};

#endif // MAINWINDOW_H
