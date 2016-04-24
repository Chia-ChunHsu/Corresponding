#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <opencv.hpp>
#include <QLabel>
#include <QDebug>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void picOpenPint(cv::Mat mat);
    std::vector<cv::Point> dpoints;
private slots:
    bool eventFilter(QObject *obj,QEvent *event);//事件偵測(滑鼠)

    void on_CancelButton_clicked();

    void draw(int x,int y);

    void on_ApplyButton_clicked();

private:
    Ui::Dialog *ui;
    void ShowOnLabel(cv::Mat mat, QLabel *k);
    cv::Mat temp;

};

#endif // DIALOG_H
