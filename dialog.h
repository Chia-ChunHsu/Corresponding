#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <opencv.hpp>
#include <QLabel>
#include <QDebug>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void picOpenPint(cv::Mat mat,cv::Mat RGB);
    std::vector<cv::Point> dpoints;
private slots:
    bool eventFilter(QObject *obj,QEvent *event);//事件偵測(滑鼠)

    void on_CancelButton_clicked();

    void draw(int x,int y);

    void on_ApplyButton_clicked();

    void on_TurnButton_clicked();

    void on_cutButton_clicked();

    void on_spinBoxx_valueChanged(int arg1);

    void on_spinBoxy_valueChanged(int arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_leftButton_clicked();

    void on_rightButton_clicked();

    void on_HomoButton_clicked();

private:
    Ui::Dialog *ui;
    void ShowOnLabel(cv::Mat mat, QLabel *k);
    void cut(int x,int y,double scale,double angle);
    cv::Mat temp;
    cv::Mat rtemp;

    std::vector<cv::Point2f> picPoint;
    std::vector<cv::Point2f> rgbPoint;

    cv::Mat rrgb;

    int flag;

    bool save = true;

    cv::Point p1;
    cv::Point p2;

    double angle;

    void setOriginal(int x,int y);
    double a;

    cv::Mat roi;

    double allangle;
    double allscale;

    //srcTri,dstTri
    std::vector<cv::Point2f> srcTri;
    std::vector<cv::Point2f> dstTri;
};

#endif // DIALOG_H
