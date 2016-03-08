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

void MainWindow::on_LoadRefButton_clicked()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this,"Select Ref File","D:/","Images (*.jpg)");

    if(filenames.size()!=4)
        return;
    for(int i=0;i<filenames.size();i++)
    {
        cv::Mat temp = cv::imread(filenames[i].toStdString().c_str(),cv::IMREAD_COLOR);
        subref.push_back(temp);
    }
    ShowOnLabel(subref[0],ui->RefLabel0);
    ShowOnLabel(subref[1],ui->RefLabel1);
    ShowOnLabel(subref[2],ui->RefLabel2);
    ShowOnLabel(subref[3],ui->RefLabel3);

    if(TS.Warp(subref,subWref,nonDilateMask,RefResult,CorPoint)!=1)
    {
        return;
    }
    ShowOnLabel(RefResult,ui->Ref);
}

void MainWindow::on_LoadBeforeButton_clicked()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this,"Select Ref File","D:/","Images (*.jpg)");

    if(filenames.size()!=4)
        return;
    for(int i=0;i<filenames.size();i++)
    {
        cv::Mat temp = cv::imread(filenames[i].toStdString().c_str(),cv::IMREAD_COLOR);
        subbefore.push_back(temp);
    }
    ShowOnLabel(subbefore[0],ui->BeforeLabel0);
    ShowOnLabel(subbefore[1],ui->BeforeLabel1);
    ShowOnLabel(subbefore[2],ui->BeforeLabel2);
    ShowOnLabel(subbefore[3],ui->BeforeLabel3);

    if(TS_Detect.StLike(subref,subbefore,subWbefore,TS.getK(),TS.getCam())!=1)
    {
        return;
    }

    std::vector<cv::Mat> CapWarp2;

    CapWarp2.clear();
    for(int i=0;i<4;i++)
    {
        CapWarp2.push_back(subWbefore[i]);
    }

    for(int i=0;i<4;i++)
    {
        cv::Size s = nonDilateMask[i].size();
        cv::resize(CapWarp2[i],subWbefore[i],nonDilateMask[i].size());
        cv::Mat temp = nonDilateMask[i];
        cv::resize(temp,nonDilateMask[i],s);
    }

    CapWarp2.clear();
    for(int n=0;n<subWbefore.size();n++)
    {
        cv::Mat resultTemp = subWbefore[n].clone();
        //qDebug()<<n<<CapWarp[n].cols<<nonDilateMask[n].cols;
        for(int i=0;i<CapWarp[n].cols;i++)
        {
            for(int j=0;j<CapWarp[n].rows;j++)
            {
                if(nonDilateMask[n].at<uchar>(j,i) == 255)
                {

                }
                else if(nonDilateMask[n].at<uchar>(j,i) != 255)
                {
                    resultTemp.at<cv::Vec3b>(j, i)[0] = 0;
                    resultTemp.at<cv::Vec3b>(j, i)[1] = 0;
                    resultTemp.at<cv::Vec3b>(j, i)[2] = 0;
                }
            }
        }
        CapWarp2.push_back(resultTemp);
    }
    subWbefore.clear();
    for(int i=0;i<CapWarp2.size();i++)
    {
        subWbefore.push_back(CapWarp2[i]);
    }

    Stitch(200);
}

void MainWindow::Stitch(int value)
{
    RCapWarp.clear();
    cv::Point t1(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
    for(int i=0;i<CorPoint.size();i++)
    {
        t1.x = std::min(t1.x,CorPoint[i].x);
        t1.y = std::min(t1.y,CorPoint[i].y);
    }

    cv::Size size(CalResult.cols,CalResult.rows);
    CapResult.create(size,CV_MAKETYPE(CapResult.type(),3));
    CapResult = cv::Scalar::all(0);

    for(int i=0;i<CapWarp.size();i++)
    {
        RCapWarp.push_back(CapWarp[i]);
    }
    qDebug()<<RCapWarp[0].cols<<RCapWarp[1].cols<<RCapWarp[2].cols<<RCapWarp[3].cols;

    for(int number=0;number<CapWarp.size();number++)
    {

        int x = CorPoint[number].x;
        int y = CorPoint[number].y;

        for(int i = 0;i<RCapWarp[number].cols;i++)
        {
            for(int j=0;j<RCapWarp[number].rows;j++)
            {
                if((RCapWarp[number].at<cv::Vec3b>(j,i)[0]+RCapWarp[number].at<cv::Vec3b>(j,i)[1]+RCapWarp[number].at<cv::Vec3b>(j,i)[2])/3 >value)
                {
                    if(j+y-t1.y<CalResult.rows && i+x-t1.x<CalResult.cols && j+y-t1.y>=0 && i+x-t1.x>=0 && number == 1)
                    {
                        CapResult.at<cv::Vec3b>(j+y-t1.y,i+x-t1.x)[0] = 255;
                    }
                    else if(j+y-t1.y<CalResult.rows && i+x-t1.x<CalResult.cols && j+y-t1.y>=0 && i+x-t1.x>=0 && number == 2)
                    {
                        CapResult.at<cv::Vec3b>(j+y-t1.y,i+x-t1.x)[1] = 255;
                    }
                    else if(j+y-t1.y<CalResult.rows && i+x-t1.x<CalResult.cols && j+y-t1.y>=0 && i+x-t1.x>=0 && number == 3)
                    {
                        CapResult.at<cv::Vec3b>(j+y-t1.y,i+x-t1.x)[2] = 255;
                    }
                }
            }
        }
    }

    ShowOnLabel(CapResult,ui->CapResultLabel);

}

