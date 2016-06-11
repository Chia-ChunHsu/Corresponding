#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ShowOnLabel(cv::Mat mat, QLabel *k)
{
    if(mat.channels()==3)
    {
        cv::cvtColor(mat,mat,CV_BGR2RGB);
        QImage qtemp = QImage((const unsigned char*)(mat.data),mat.cols,mat.rows,mat.step,QImage::Format_RGB888);
        k->clear();
        k->setPixmap(QPixmap::fromImage(qtemp.scaled(k->width(),k->height(),Qt::KeepAspectRatio)));
        k->show();
    }
    else if(mat.channels() == 1)
    {
        QVector<QRgb> colorTable;
        for(int i=0;i<256;i++)
        {
            colorTable.push_back(qRgb(i,i,i));
        }
        //const uchar *qImageBuffer = (const uchar*)mat.data;
        QImage qtemp = QImage((const unsigned char*)(mat.data),mat.cols,mat.rows,mat.step,QImage::Format_Indexed8);
        qtemp.setColorTable(colorTable);
        k->clear();
        k->setPixmap(QPixmap::fromImage(qtemp.scaled(k->width(),k->height(),Qt::KeepAspectRatio)));
        k->show();
    }
}

void MainWindow::drawOnRGB(std::vector<cv::Point> p)
{
    cv::Mat temp =rgb.clone();
    for(int i=0;i<p.size();i++)
    {
        cv::circle(temp,p[i],10,cv::Scalar(255,0,0),-1,8);
    }
    ShowOnLabel(temp,ui->RGBLabel);
    cv::imshow("temp",temp);
}



void MainWindow::on_LoadPic_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Pic Image"), "D:/Dropbox/", tr("Image Files (*.jpg)"));

    if(fileName.isEmpty())
    {
        return;
    }
    pic = cv::imread(fileName.toStdString().c_str());  //,CV_LOAD_IMAGE_COLOR
    qDebug()<<pic.channels();
//    cv::cvtColor(pic,pic,CV_GRAY2BGR);
//    qDebug()<<pic.channels();
    ShowOnLabel(pic, ui->PicLabel);

}

void MainWindow::on_LoadRGB_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open RGB Image"), "D:/Dropbox/", tr("Image Files (*.jpg)"));

    if(fileName.isEmpty())
    {
        return;
    }
    rgb = cv::imread(fileName.toStdString().c_str());
    cv::resize(rgb,rgb,cv::Size(720,480),CV_INTER_LINEAR);
    ShowOnLabel(rgb, ui->RGBLabel);
}



void MainWindow::on_PointButtom_clicked()
{
    if(!pic.empty())
    {
        //std::vector<cv::Point> points;
        //picdialog.dpoints = points;
        picdialog.picOpenPint(pic,rgb);

    }
    return;
}

