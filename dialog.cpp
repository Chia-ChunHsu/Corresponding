#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    flag = 0;
    allangle = 0;
    allscale = 1.0;

}

Dialog::~Dialog()
{
    flag = 0;
    delete ui;
}

void Dialog::picOpenPint(cv::Mat mat, cv::Mat RGB)
{
    this->open();
    temp = cvCreateMat(480,640,CV_8UC3);
    temp = mat.clone();
    rtemp = RGB.clone();
    rrgb = RGB.clone();
    ShowOnLabel(temp,ui->pointLabel);
    ShowOnLabel(rtemp,ui->pointRGBLabel);
    picPoint.clear();
    rgbPoint.clear();


}
bool Dialog::eventFilter(QObject *obj, QEvent *event)
{
  QString str;
  QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

  //mouseEvent->localPos()
  int x;
  int y;
  if(flag == 0)
  {
      if( event->type() == QMouseEvent::MouseMove && obj->isWindowType())
      {
           QPointF pt = mouseEvent->localPos();
           event = static_cast<QMouseEvent*>(event);
           str = "MouseMove" + QString::number(pt.x()) +", " + QString::number(pt.y());
           setWindowTitle(str);                            // 顯示座標
           return false;

      }else if(event->type() == QMouseEvent::MouseButtonPress && obj->isWindowType()){
           QPointF pt = mouseEvent->localPos();
           str = "MouseButtonPress" + QString::number(pt.x()) +", " + QString::number(pt.y());
           setWindowTitle(str);                            // 顯示座標
           //x = pt.x();
           //y = pt.y();
           //qDebug()<<pt.x();
           x = pt.rx();
           y = pt.ry();
           qDebug()<<"==="<<x<<y;
           cv::Point p(x,y);
           //dpoints.push_back(p);
           if(y<ui->pointLabel->geometry().y()+ui->pointLabel->height())
            draw(x,y);

      }
  }
  else if(flag ==1 )
  {
      if(event->type() == QMouseEvent::MouseButtonDblClick && obj->isWindowType())
      {
         qDebug()<<p1.x<<p1.y<<p2.x<<p2.y;
         qDebug()<<p1.x-ui->pointRGBLabel->geometry().x() << p1.y-ui->pointRGBLabel->geometry().y();
         cv::Rect r = cv::Rect(p1.x-ui->pointRGBLabel->geometry().x(),p1.y-ui->pointRGBLabel->geometry().y(),abs(p2.y-p1.y),abs(p2.y-p1.y));
         roi = rrgb(r);
         //cv::imshow("roi",roi);
         rrgb = roi.clone();
         ShowOnLabel(rrgb,ui->pointRGBLabel);
      }
      else if(event->type() == QMouseEvent::MouseButtonPress && (mouseEvent->button() &Qt::LeftButton)&& obj->isWindowType() && save == true)
      {
          QPointF p = mouseEvent->localPos();
          p1 = cv::Point(p.rx(),p.ry());
          qDebug()<<"p1"<<p1.x<<p1.y;

      }
      else if(event->type() == QMouseEvent::MouseButtonRelease && (mouseEvent->button() &Qt::RightButton) && obj->isWindowType() && save == true)
      {
          QPointF p = mouseEvent->localPos();
          int s = abs(p1.x-p.x());
          p2 = cv::Point(p.rx(),p.ry());
          qDebug()<<"p2"<<p2.x<<p2.y;
          save =false;
      }
  }
  else if(flag ==2)
  {
      if ( event->type() == QMouseEvent::MouseMove && obj->isWindowType())
      {
           QPointF pt = mouseEvent->localPos();
           event = static_cast<QMouseEvent*>(event);
           str = "MouseMove" + QString::number(pt.x()) +", " + QString::number(pt.y());
           setWindowTitle(str);                            // 顯示座標
           return false;

      }else if(event->type() == QMouseEvent::MouseButtonPress && obj->isWindowType()){
           QPointF pt = mouseEvent->localPos();
           str = "MouseButtonPress" + QString::number(pt.x()) +", " + QString::number(pt.y());
           setWindowTitle(str);                            // 顯示座標

           x = pt.rx();
           y = pt.ry();

           //cv::Point p(x,y);

           if(y<ui->pointLabel->geometry().y()+ui->pointLabel->height())
             setOriginal(x,y);

      }

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

void Dialog::cut(int x, int y,double ds,double da)
{
    cv::Mat t= temp.clone();
    cv::Mat rt = roi.clone();
    cv::Point2f p(rt.cols/2,rt.rows/2);
    cv::Mat rotate = cv::getRotationMatrix2D(p,da,1);
    cv::warpAffine(rt,rt,rotate,rt.size());
    qDebug()<<int(rt.cols*ds)<<int(rt.rows*ds);
    cv::Size s(int(rt.cols*ds),int(rt.rows*ds));
    cv::Mat ft;
    qDebug()<<"=======";
    cv::resize(rt,ft,s,CV_INTER_LINEAR);
    qDebug()<<"1=======";
    for(int i=0;i<ft.cols;i++)
    {
        for(int j=0;j<ft.rows;j++)
        {
            t.at<cv::Vec3b>(j+y,i+x)[0] = ft.at<cv::Vec3b>(j,i)[0];
            t.at<cv::Vec3b>(j+y,i+x)[1] = ft.at<cv::Vec3b>(j,i)[1];
            t.at<cv::Vec3b>(j+y,i+x)[2] = ft.at<cv::Vec3b>(j,i)[2];
        }
    }
    ShowOnLabel(t,ui->pointLabel);
}

void Dialog::setOriginal(int x,int y)
{
    if(x < ui->pointLabel->geometry().x()+ui->pointLabel->geometry().width())
    {
        qDebug()<<"left"<<x<<ui->pointLabel->geometry().x() ;
        cv::Point p(x-ui->pointLabel->geometry().x(),y-ui->pointLabel->geometry().y());
        qDebug()<<p.x<<p.y;
        //cv::Point textp(x-ui->pointLabel->geometry().x(),y-ui->pointLabel->geometry().y()-10);
        //cv::circle(temp,p,1,cv::Scalar(255,0,0),-1,8);
        //cv::putText(temp,QString::number(picPoint.size()+1).toStdString(),textp,cv::FONT_HERSHEY_COMPLEX,0.4,cv::Scalar(255,0,0));
        //ShowOnLabel(temp,ui->pointLabel);
        //picPoint.push_back(p);
    }
    else
    {
        qDebug()<<"right"<<x<<ui->pointRGBLabel->geometry().x();
        cv::Point p(int(x-ui->pointRGBLabel->geometry().x()), int(y-ui->pointRGBLabel->geometry().y()));
        qDebug()<<p.x<<p.y;
        //cv::Point textp(x-ui->pointRGBLabel->geometry().x(),y-ui->pointRGBLabel->geometry().y()-10);
        cv::circle(roi,p,1,cv::Scalar(255,0,0),-1,8);
        //cv::putText(rtemp,QString::number(rgbPoint.size()+1).toStdString(),textp,cv::FONT_HERSHEY_COMPLEX,0.4,cv::Scalar(255,0,0));
        ui->pointRGBLabel->setGeometry(ui->pointRGBLabel->x(),ui->pointRGBLabel->y(),roi.cols,roi.rows);

        ShowOnLabel(roi,ui->pointRGBLabel);
        ui->pointLabel->show();
        //rgbPoint.push_back(p);
    }

}

void Dialog::on_CancelButton_clicked()
{
    dpoints.clear();
    this->close();
}

void Dialog::draw(int x, int y)
{
    if(x < ui->pointLabel->geometry().x()+ui->pointLabel->geometry().width())
    {
        qDebug()<<"left"<<x<<ui->pointLabel->geometry().x();
        cv::Point p(x-ui->pointLabel->geometry().x(),y-ui->pointLabel->geometry().y());
        cv::Point textp(x-ui->pointLabel->geometry().x(),y-ui->pointLabel->geometry().y()-10);
        cv::circle(temp,p,1,cv::Scalar(255,0,0),-1,8);
        cv::putText(temp,QString::number(picPoint.size()+1).toStdString(),textp,cv::FONT_HERSHEY_COMPLEX,0.4,cv::Scalar(255,0,0));
        ShowOnLabel(temp,ui->pointLabel);
        picPoint.push_back(p);
    }
    else
    {
        qDebug()<<"right"<<x<<ui->pointRGBLabel->geometry().x();
        cv::Point p(x-ui->pointRGBLabel->geometry().x(),y-ui->pointRGBLabel->geometry().y());
        cv::Point textp(x-ui->pointRGBLabel->geometry().x(),y-ui->pointRGBLabel->geometry().y()-10);
        cv::circle(rtemp,p,1,cv::Scalar(255,0,0),-1,8);
        cv::putText(rtemp,QString::number(rgbPoint.size()+1).toStdString(),textp,cv::FONT_HERSHEY_COMPLEX,0.4,cv::Scalar(255,0,0));
        ShowOnLabel(rtemp,ui->pointRGBLabel);
        rgbPoint.push_back(p);
    }
}

void Dialog::on_ApplyButton_clicked()
{
    qDebug()<<picPoint.size()<<rgbPoint.size();
    if(picPoint.size() != rgbPoint.size())
        return;
    int size = picPoint.size();

    double m1,m2;
    for(int i=0;i<1;i++)
    {
        a = double(rgbPoint[i+1].x-rgbPoint[i].x)/double(picPoint[i+1].x-picPoint[i].x);
        m1 = double(picPoint[i].y-picPoint[i+1].y)/double(picPoint[i].x-picPoint[i+1].x);
        m2 = double(rgbPoint[i].y-rgbPoint[i+1].y)/double(rgbPoint[i].x-rgbPoint[i+1].x);
    }
    for(int i=0;i<picPoint.size();i++)
    {
        srcTri.push_back(rgbPoint[i]);
        dstTri.push_back(picPoint[i]);
    }
    angle = atan((m2-m1)/(1+m1*m2))*180/3.14159265;
    qDebug()<<m1<<m2<<angle;
    cv::Mat k;
    cv::resize(rrgb,k,cv::Size(720/a,480/a),CV_INTER_LINEAR);
    ShowOnLabel(k,ui->pointRGBLabel);
    //this->close();
}

void Dialog::on_TurnButton_clicked()
{
    //cv::Mat k = rrgb.clone();
    cv::Point2f p(rrgb.cols/2,rrgb.rows/2);
    //cv::Mat rotate = cv::getRotationMatrix2D(p,angle,1);
    cv::Mat rotate = cv::getAffineTransform(srcTri,dstTri);
    cv::warpAffine(rrgb,rrgb,rotate,rrgb.size());

    flag =1;


    ShowOnLabel(rrgb,ui->pointRGBLabel);
}

void Dialog::on_cutButton_clicked()
{
    flag = 2;
    //ShowOnLabel(rrgb,ui->pointRGBLabel);
    cv::Mat t= temp.clone();
    for(int i=0;i<roi.cols;i++)
    {
        for(int j=0;j<roi.rows;j++)
        {
            t.at<cv::Vec3b>(j+100,i+50)[0] = roi.at<cv::Vec3b>(j,i)[0];
            t.at<cv::Vec3b>(j+100,i+50)[1] = roi.at<cv::Vec3b>(j,i)[1];
            t.at<cv::Vec3b>(j+100,i+50)[2] = roi.at<cv::Vec3b>(j,i)[2];
        }
    }
    ShowOnLabel(t,ui->pointLabel);
}


void Dialog::on_spinBoxx_valueChanged(int arg1)
{
    cut(arg1,ui->spinBoxy->value(),allscale,allangle);
}

void Dialog::on_spinBoxy_valueChanged(int arg1)
{
    cut(ui->spinBoxx->value(),arg1,allscale,allangle);
}

void Dialog::on_doubleSpinBox_valueChanged(double arg1)
{
    allscale = arg1;
    cut(ui->spinBoxx->value(),ui->spinBoxy->value(),allscale,allangle);
}

void Dialog::on_leftButton_clicked()
{
    allangle= allangle+1.0;
    cut(ui->spinBoxx->value(),ui->spinBoxy->value(),allscale,allangle);
}

void Dialog::on_rightButton_clicked()
{
    allangle= allangle-1.0;
    cut(ui->spinBoxx->value(),ui->spinBoxy->value(),allscale,allangle);
}

void Dialog::on_HomoButton_clicked()
{
    cv::Mat H = cv::findHomography(rgbPoint,picPoint);

    cv::Mat test;
    test.create(rrgb.rows,rrgb.cols,rrgb.type());
    cv::warpPerspective(rrgb,test,H,rrgb.size());
    ShowOnLabel(test,ui->pointRGBLabel);
    //cv::imshow("test.jpg",test);
}
