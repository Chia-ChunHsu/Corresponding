#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::picOpenPint(cv::Mat mat)
{
    this->open();
    temp = cvCreateMat(480,640,CV_8UC3);
    temp = mat.clone();
    ShowOnLabel(temp,ui->pointLabel);


}
bool Dialog::eventFilter(QObject *obj, QEvent *event)
{
  QString str;
  QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

  //mouseEvent->localPos()
  int x;
  int y;
  if (event->type() == QEvent::MouseMove)
  {
       QPoint pt = mouseEvent->pos();
       mouseEvent = static_cast<QMouseEvent*>(event);
       str = "MouseMove" + QString::number(pt.x()) +", " + QString::number(pt.y());
       setWindowTitle(str);                            // 顯示座標
       return false;

  }else if(obj->isWidgetType() && event->type() == QEvent::MouseButtonPress){
       //QPoint pt = mouseEvent->
       //str = "MouseButtonPress" + QString::number(pt.x()) +", " + QString::number(pt.y());
       //setWindowTitle(str);                            // 顯示座標
       //x = pt.x();
       //y = pt.y();
       //qDebug()<<pt.x();
       x = mouseEvent->x();
       y = mouseEvent->y();
       cv::Point p(x,y);
       dpoints.push_back(p);
       draw(x,y);

  }

  return false;
}
void Dialog::ShowOnLabel(cv::Mat mat, QLabel *k)
{
    if(mat.channels()==3)
    {
        //cv::cvtColor(mat,mat,CV_BGR2RGB);
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

void Dialog::on_CancelButton_clicked()
{
    dpoints.clear();
    this->close();
}

void Dialog::draw(int x, int y)
{
    int rx = ui->pointLabel->x();
    int ry = ui->pointLabel->y();
    cv::Point p(x-rx,y-ry);
    cv::circle(temp,p,1,cv::Scalar(255,0,0),-1,8);
    //cv::imshow("temp",temp);
    ui->pointLabel->clear();
    ShowOnLabel(temp,ui->pointLabel);
}

void Dialog::on_ApplyButton_clicked()
{
    qDebug()<<dpoints.size();
    this->close();
}
