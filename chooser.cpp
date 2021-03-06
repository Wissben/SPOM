#include "chooser.h"
#include "ui_chooser.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include "mainwindow.h"
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opencv2/opencv.hpp"
#include <qmessagebox.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core_c.h"
#include "opencv2/core/core.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include "opencv2/videoio.hpp"
#include <QFileDialog>
#include <QSpinBox>
#include <QWidget>
#include <string>
#include <QString>
#include "mymath.h"
#include "qprogressbar.h"
#include "qthread.h"
#include <QTimer>
#include <thread>
#include <QPushButton>
#include <QThread>
#include <QDebug>
#include <QElapsedTimer>

using namespace std;
using namespace cv;

Chooser::Chooser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chooser)
{

    ui->setupUi(this);


    QObject::connect(ui->GradControl,SIGNAL(valueChanged(int)),this,SLOT(updateControlGrad()));
    QObject::connect(ui->arithControl,SIGNAL(valueChanged(int)),this,SLOT(updateControlArith()));
    QObject::connect(ui->RecControl,SIGNAL(valueChanged(int)),this,SLOT(updateControlRec()));
    QObject::connect(ui->SDControl,SIGNAL(valueChanged(int)),this,SLOT(updateControlSD()));
    QObject::connect(ui->SAPControl,SIGNAL(valueChanged(int)),this,SLOT(updateControlSAP()));


    ui->grad_results_table->setColumnCount(2);
    ui->grad_results_table->verticalHeader()->setVisible(false);
    ui->grad_results_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->grad_results_table->setHorizontalHeaderItem(0, new QTableWidgetItem("alpha"));
    ui->grad_results_table->setColumnWidth(1,200);
    ui->grad_results_table->setColumnWidth(0,48);
    ui->grad_results_table->setHorizontalHeaderItem(1, new QTableWidgetItem("temps en secondes"));
    grad_Stat_Index=0;

    ui->rec_results_table->setColumnCount(2);
    ui->rec_results_table->verticalHeader()->setVisible(false);
    ui->rec_results_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->rec_results_table->setHorizontalHeaderItem(0, new QTableWidgetItem("alpha"));
    ui->rec_results_table->setColumnWidth(1,200);
    ui->rec_results_table->setColumnWidth(0,48);
    ui->rec_results_table->setHorizontalHeaderItem(1, new QTableWidgetItem("temps en secondes"));
    rec_Stat_Index=0;

    ui->SAP_results_table->setColumnCount(2);
    ui->SAP_results_table->verticalHeader()->setVisible(false);
    ui->SAP_results_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->SAP_results_table->setHorizontalHeaderItem(0, new QTableWidgetItem("Mul"));
    ui->SAP_results_table->setColumnWidth(1,200);
    ui->SAP_results_table->setColumnWidth(0,48);
    ui->SAP_results_table->setHorizontalHeaderItem(1, new QTableWidgetItem("temps en secondes"));
    SAP_Stat_Index=0;

    ui->SD_results_table->setColumnCount(2);
    ui->SD_results_table->verticalHeader()->setVisible(false);
    ui->SD_results_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->SD_results_table->setHorizontalHeaderItem(0, new QTableWidgetItem("N"));
    ui->SD_results_table->setColumnWidth(1,200);
    ui->SD_results_table->setColumnWidth(0,48);
    ui->SD_results_table->setHorizontalHeaderItem(1, new QTableWidgetItem("temps en secondes"));
    SD_Stat_Index=0;
    int insertRow;
//    insertRow=ui->grad_results_table->rowCount();
//    ui->grad_results_table->insertRow(insertRow);
//    ui->grad_results_table->setItem(ui->grad_results_table->rowCount(), 0, new QTableWidgetItem("jdsjsj"));
//    ui->grad_results_table->setItem(ui->grad_results_table->rowCount(), 1, new QTableWidgetItem("ésdd"));


//    for (int i=0; i<ui->grad_results_table->rowCount();i++)
//    {
//        qDebug() << ui->grad_results_table->item(i,0)->text().toFloat();
//        float col1=ui->grad_results_table->item(i,0)->text().toFloat();
//        //float col2=tw->item(i,1)->text().toFloat();
//            qDebug() << ui->grad_results_table->item(0,1)->text();

//    }
    //setting up Gradiant
    std::string str;
    //ui->alphaChooserGrad->setValue(400);
    str = std::to_string((float)ui->alphaChooserGrad->value()/1000).substr(0,5);
    QString tmp = QString(str.c_str());
    ui->labelGradAlphaValue->setText(tmp);
    //end of setting

    //setting up recur
    str = std::to_string((float)ui->alphaChooserRec->value()/1000).substr(0,5);
    tmp = QString(str.c_str());
    ui->labelRecAlphaValue->setText(tmp);
    //end of setting
    valueChanged=false;

    //Setting up SAP
    str = std::to_string((float)ui->alphaChooserSAP->value()/1000).substr(0,5);
    tmp = QString(str.c_str());
    ui->labelSAPAlphaValue->setText(tmp);
    ui->alphaChooserSAP->setVisible(false);
    ui->labelSAPAlpha->setVisible(false);
    ui->labelSAPAlphaValue->setVisible(false);
    //End of setting

    ui->labelGradAlpha->setToolTip("Alpha est le taux d'oublis (voir la section Aide/À propos)");

    gradIndex=0;
    arithIndex=0;
    recIndex=0;
    SDIndex=0;
    SAPIndex=0;

    shadowArith=true;
    shadowGrad=true;
    shadowRec=true;
    shadowSAP=true;
    shadowSD=true;

    speedArith=30;
    speedGrad=30;
    speedRec=30;
    speedSAP=30;
    speedSD=30;

    ui->control->setEnabled(false);
    //ui->control->setFlat(true);
    ui->accel->setEnabled(false);
    ui->deccel->setEnabled(false);
    ui->speedDown->setEnabled(false);
    ui->speedUp->setEnabled(false);
    ui->end->setEnabled(false);
    ui->begin->setEnabled(false);


    ui->controlArith->setEnabled(false);
    ui->accel_Arith->setEnabled(false);
    ui->deccel_Arith->setEnabled(false);
    ui->speedDown_Arith->setEnabled(false);
    ui->speedUp_Arith->setEnabled(false);
    ui->end_Arith->setEnabled(false);
    ui->begin_Arith->setEnabled(false);

    ui->controlRec->setEnabled(false);
    ui->accel_Rec->setEnabled(false);
    ui->deccel_Rec->setEnabled(false);
    ui->speedDown_Rec->setEnabled(false);
    ui->speedUp_Rec->setEnabled(false);
    ui->end_Rec->setEnabled(false);
    ui->begin_Rec->setEnabled(false);

    ui->controlSD->setEnabled(false);
    ui->accel_SD->setEnabled(false);
    ui->deccel_SD->setEnabled(false);
    ui->speedDown_SD->setEnabled(false);
    ui->speedUp_SD->setEnabled(false);
    ui->end_SD->setEnabled(false);
    ui->begin_SD->setEnabled(false);

    ui->controlSAP->setEnabled(false);
    ui->accel_SAP->setEnabled(false);
    ui->deccel_SAP->setEnabled(false);
    ui->speedDown_SAP->setEnabled(false);
    ui->speedUp_SAP->setEnabled(false);
    ui->end_SAP->setEnabled(false);
    ui->begin_SAP->setEnabled(false);



}

Chooser::~Chooser()
{
    delete ui;
}





void Chooser::on_alphaChooserSAP_valueChanged(int value)
{
    std::string str;
    str = std::to_string((float)value/1000).substr(0,5);//"0,"+toString(ui->alphaChooserRec->value());
    QString tmp = QString(str.c_str());
    ui->labelSAPAlphaValue->setText(tmp);
}


void Chooser::on_alphaChooserRec_valueChanged(int value)
{
    std::string str;
    str = std::to_string((float)value/1000).substr(0,5);//"0,"+toString(ui->alphaChooserRec->value());
    QString tmp = QString(str.c_str());
    ui->labelRecAlphaValue->setText(tmp);
}



void Chooser::updateControlGrad()
{
    gradIndex=ui->GradControl->value();
    ui->counterGrad->setText(to_string(gradIndex).c_str());
}
void Chooser::updateControlArith()
{
    arithIndex=ui->arithControl->value();
}


void Chooser::updateControlRec()
{
    recIndex=ui->RecControl->value();
}


void Chooser::updateControlSD()
{
    SDIndex=ui->SDControl->value();
}

void Chooser::updateControlSAP()
{
    SAPIndex=ui->SAPControl->value();
}


void Chooser::on_gradiantChooser_clicked()
{
    timerGrad = new QTimer(this);
    connect(timerGrad,SIGNAL(timeout()),this,SLOT(updateGrad()));
    gradFramesFore.clear();
    gradFramesMask.clear();
    gradFramesOriginal.clear();
    gradIndex=0;
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
    if(filename !=NULL)
    {
        Chooser::gradiantOublieux(filename.toStdString(),(float) ui->alphaChooserGrad->value()/1000,this);

        ui->control->setEnabled(true);
        ui->accel->setEnabled(true);
        ui->deccel->setEnabled(true);
        ui->speedDown->setEnabled(true);
        ui->speedUp->setEnabled(true);
        ui->gradiantChooser->setEnabled(false);
        ui->end->setEnabled(true);
        ui->begin->setEnabled(true);
        ui->control->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));

        timerGrad->start(speedGrad);
    }

}


void Chooser::updateGrad()
{
    if(gradFramesFore.empty() || gradFramesMask.empty() || gradFramesOriginal.empty())
        return;
    Mat tmp;
    //tmp=gradFramesOriginal.at(gradIndex);
    //ui->image_label_original->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=gradFramesFore.at(gradIndex);
    ui->grad_image_label_foreground->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=gradFramesMask.at(gradIndex);
    ui->grad_image_label_mask->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=gradFramesOriginal.at(gradIndex);
    ui->grad_image_label_original->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));
    //QThread::msleep(100);
    //QTest::qSleep(100);
    ui->GradControl->setMinimum(0);
    ui->GradControl->setMaximum(gradFramesOriginal.size()-1);
    ui->GradControl->setValue(gradIndex);

    gradIndex++;
    if(gradIndex>=gradFramesFore.size() || gradIndex>=gradFramesOriginal.size() || gradIndex>=gradFramesMask.size())
    {
        gradIndex=0;
        timerGrad->stop();
        ui->control->setEnabled(false);
        ui->gradiantChooser->setEnabled(true);
    }

}


void Chooser::on_control_clicked()
{
    if(timerGrad->isActive())
    {
        timerGrad->stop();
        ui->control->setIcon(QIcon("Resources/MediaControl/Play-26.png"));
        ui->control->setIconSize(QSize(26,26));
    }
    else
    {
        ui->control->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
        ui->control->setIconSize(QSize(26,26));
        timerGrad->start(speedGrad);
    }
}

void Chooser::on_accel_clicked(bool checked)
{
    timerGrad->stop();
    gradIndex+=15;
    if(gradIndex>=gradFramesOriginal.size())
        gradIndex=gradFramesOriginal.size()-1;
    timerGrad->start(speedGrad);
}



void Chooser::on_deccel_clicked(bool checked)
{
    timerGrad->stop();
    gradIndex-=15;
    if(gradIndex<0)
        gradIndex=0;
    QThread::msleep(50);
    timerGrad->start(speedGrad);

}





void Chooser::on_speedDown_clicked(bool checked)
{
    timerGrad->stop();
    this->speedGrad+=10;
    if(speedGrad>=100)
        speedGrad=100;
    timerGrad->start(speedGrad);
}

void Chooser::on_speedUp_clicked(bool checked)
{

    timerGrad->stop();
    this->speedGrad-=10;
    if(speedGrad<=5)
        speedGrad=5;
    timerGrad->start(speedGrad);
}


void Chooser::on_end_clicked(bool checked)
{
    timerGrad->stop();
    gradIndex=gradFramesOriginal.size()-1;
    ui->gradiantChooser->setEnabled(true);
    ui->accel->setEnabled(false);
    ui->deccel->setEnabled(false);
    ui->speedDown->setEnabled(false);
    ui->speedUp->setEnabled(false);
    timerGrad->start(speedGrad);
}

void Chooser::on_begin_clicked(bool checked)
{
    timerGrad->stop();
    gradIndex=0;
    ui->control->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
    ui->control->setEnabled(true);
    ui->accel->setEnabled(true);
    ui->deccel->setEnabled(true);
    ui->speedDown->setEnabled(true);
    ui->speedUp->setEnabled(true);
    ui->gradiantChooser->setEnabled(false);
    timerGrad->start(speedGrad);
}

void Chooser::on_alphaChooserGrad_valueChanged(int value)
{
    std::string str;
    str = std::to_string((float)value/1000).substr(0,5);//"0,"+toString(ui->alphaChooserRec->value());
    QString tmp = QString(str.c_str());
    ui->labelGradAlphaValue->setText(tmp);
}

//void Chooser::on_horizontalSlider_valueChanged(int value)
//{
//    //std::cout << ui->horizontalSlider->value();
//}

void Chooser::on_horizontalSlider_sliderReleased()
{
    std::cout << this->valueChanged;
    this->valueChanged=false;
}

void Chooser::on_horizontalSlider_sliderPressed()
{
    std::cout << this->valueChanged;
    this->valueChanged=true;
}

void Chooser::on_Chooser_destroyed()
{
    delete ui;
    exit(EXIT_SUCCESS);
}

void Chooser::on_arithChooser_clicked(bool checked)
{
    timerArith = new QTimer(this);
    connect(timerArith,SIGNAL(timeout()),this,SLOT(updateArith()));
    arithFramesFore.clear();
    arithFramesMask.clear();
    arithFramesOriginal.clear();
    arithFramesBack.clear();
    arithIndex=0;
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
    if(filename !=NULL)
    {
        Chooser::moyenne_Arith(filename.toStdString(),this);
        ui->controlArith->setEnabled(true);
        ui->accel_Arith->setEnabled(true);
        ui->deccel_Arith->setEnabled(true);
        ui->speedDown_Arith->setEnabled(true);
        ui->speedUp_Arith->setEnabled(true);
        ui->arithChooser->setEnabled(false);
        ui->end_Arith->setEnabled(true);
        ui->begin_Arith->setEnabled(true);
        ui->controlArith->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
        timerArith->start(speedArith);
    }

}

void Chooser::updateArith()
{
    if(arithFramesFore.empty() || arithFramesMask.empty() || arithFramesOriginal.empty() || arithFramesBack.empty())
        return;
    Mat tmp;
    //tmp=gradFramesOriginal.at(gradIndex);
    //ui->image_label_original->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=arithFramesFore.at(arithIndex);
    ui->arith_image_label_foreground->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));


    tmp=arithFramesMask.at(arithIndex);
    ui->arith_image_label_mask->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=arithFramesOriginal.at(arithIndex);
    ui->arith_image_label_original->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=arithFramesBack.at(0);
    ui->arith_image_label_back->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    ui->arithControl->setMinimum(0);
    ui->arithControl->setMaximum(arithFramesOriginal.size()-1);
    ui->arithControl->setValue(arithIndex);
    //QThread::msleep(100);
    //QTest::qSleep(100);

    arithIndex++;
    if(arithIndex>=arithFramesFore.size() || arithIndex>=arithFramesOriginal.size() || arithIndex>=arithFramesMask.size())
    {
        arithIndex=0;
        timerArith->stop();
        ui->controlArith->setEnabled(false);
        ui->arithChooser->setEnabled(true);
    }
}


void Chooser::on_controlArith_clicked(bool checked)
{
    if(timerArith->isActive())
    {
        timerArith->stop();
        ui->controlArith->setIcon(QIcon("Resources/MediaControl/Play-26.png"));
        ui->controlArith->setIconSize(QSize(26,26));
    }
    else
    {
        timerArith->start(30);
        ui->controlArith->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
        ui->controlArith->setIconSize(QSize(26,26));
    }
}




void Chooser::on_accel_Arith_clicked(bool checked)
{
    timerArith->stop();
    arithIndex+=15;
    if(arithIndex>=arithFramesOriginal.size())
        arithIndex=arithFramesOriginal.size()-1;
    timerArith->start(speedArith);
}

void Chooser::on_deccel_Arith_clicked()
{
    timerArith->stop();
    arithIndex-=15;
    if(arithIndex<0)
        arithIndex=0;
    timerArith->start(speedArith);
}

void Chooser::on_speedUp_Arith_clicked(bool checked)
{
    timerArith->stop();
    this->speedArith-=10;
    if(speedArith<=5)
        speedArith=5;
    timerArith->start(speedArith);
}

void Chooser::on_speedDown_Arith_clicked(bool checked)
{
    timerArith->stop();
    this->speedArith+=10;
    if(speedArith>=100)
        speedArith=100;
    timerArith->start(speedArith);
}

void Chooser::on_end_Arith_clicked(bool checked)
{
    timerArith->stop();
    arithIndex=arithFramesOriginal.size()-1;
    ui->arithChooser->setEnabled(true);
    ui->accel_Arith->setEnabled(false);
    ui->deccel_Arith->setEnabled(false);
    ui->speedDown_Arith->setEnabled(false);
    ui->speedUp_Arith->setEnabled(false);
    timerArith->start(speedArith);
}

void Chooser::on_begin_Arith_clicked(bool checked)
{
    timerArith->stop();
    arithIndex=0;
    ui->controlArith->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
    ui->controlArith->setEnabled(true);
    ui->accel_Arith->setEnabled(true);
    ui->deccel_Arith->setEnabled(true);
    ui->speedDown_Arith->setEnabled(true);
    ui->speedUp_Arith->setEnabled(true);
    ui->arithChooser->setEnabled(false);
    timerArith->start(speedArith);
}





void Chooser::on_recChooser_clicked()
{
    timerRec = new QTimer(this);
    connect(timerRec,SIGNAL(timeout()),this,SLOT(updateRec()));
    recFramesFore.clear();
    recFramesMask.clear();
    recFramesOriginal.clear();
    recFramesBack.clear();
    recIndex=0;
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
    if(filename !=NULL)
    {
        Chooser::moyenne_Reccur(filename.toStdString(),(float) ui->alphaChooserRec->value()/1000,this);
        ui->controlRec->setEnabled(true);
        ui->accel_Rec->setEnabled(true);
        ui->deccel_Rec->setEnabled(true);
        ui->speedDown_Rec->setEnabled(true);
        ui->speedUp_Rec->setEnabled(true);
        ui->recChooser->setEnabled(false);
        ui->end_Rec->setEnabled(true);
        ui->begin_Rec->setEnabled(true);
        ui->controlRec->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
        timerRec->start(speedRec);
    }


}


void Chooser::updateRec()
{

    if(recFramesFore.empty() || recFramesMask.empty() || recFramesOriginal.empty() || recFramesBack.empty())
        return;
    Mat tmp;
    //tmp=gradFramesOriginal.at(gradIndex);
    //ui->image_label_original->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=recFramesFore.at(recIndex);
    ui->rec_image_label_foreground->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));


    tmp=recFramesMask.at(recIndex);
    ui->rec_image_label_mask->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=recFramesOriginal.at(recIndex);
    ui->rec_image_label_original->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=recFramesBack.at(0);
    ui->rec_image_label_back->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    //QThread::msleep(10);
    //QTest::qSleep(100);

    ui->RecControl->setMinimum(0);
    ui->RecControl->setMaximum(recFramesOriginal.size()-1);
    ui->RecControl->setValue(recIndex);


    recIndex++;
    if(recIndex>=recFramesFore.size() || recIndex>=recFramesOriginal.size() || recIndex>=recFramesMask.size() )
    {
        recIndex=0;
        timerRec->stop();
        ui->controlRec->setEnabled(false);
        ui->recChooser->setEnabled(true);
    }
}



void Chooser::on_controlRec_clicked(bool checked)
{
    if(timerRec->isActive())
    {
        timerRec->stop();
        ui->controlRec->setIcon(QIcon("Resources/MediaControl/Play-26.png"));
        ui->controlRec->setIconSize(QSize(26,26));
    }
    else
    {
        timerRec->start(speedRec);
        ui->controlRec->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
        ui->controlRec->setIconSize(QSize(26,26));
    }
}



void Chooser::on_speedUp_Rec_clicked(bool checked)
{
    timerRec->stop();
    this->speedRec-=10;
    if(speedRec<=5)
        speedRec=5;
    timerRec->start(speedRec);
}

void Chooser::on_speedDown_Rec_clicked(bool checked)
{
    timerRec->stop();
    this->speedRec+=10;
    if(speedRec>=100)
        speedRec=100;
    timerRec->start(speedRec);
}

void Chooser::on_deccel_Rec_clicked()
{
    timerRec->stop();
    recIndex-=15;
    if(recIndex<0)
        recIndex=0;
    timerRec->start(speedRec);
}

void Chooser::on_accel_Rec_clicked(bool checked)
{
    timerRec->stop();
    recIndex+=15;
    if(recIndex>=recFramesOriginal.size())
        recIndex=recFramesOriginal.size()-1;
    timerRec->start(speedRec);
}

void Chooser::on_begin_Rec_clicked(bool checked)
{
    timerRec->stop();
    recIndex=0;
    ui->controlRec->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
    ui->controlRec->setEnabled(true);
    ui->accel_Rec->setEnabled(true);
    ui->deccel_Rec->setEnabled(true);
    ui->speedDown_Rec->setEnabled(true);
    ui->speedUp_Rec->setEnabled(true);
    ui->recChooser->setEnabled(false);
    timerRec->start(speedRec);
}

void Chooser::on_end_Rec_clicked(bool checked)
{
    timerRec->stop();
    recIndex=recFramesOriginal.size()-1;
    ui->recChooser->setEnabled(true);
    ui->accel_Rec->setEnabled(false);
    ui->deccel_Rec->setEnabled(false);
    ui->speedDown_Rec->setEnabled(false);
    ui->speedUp_Rec->setEnabled(false);
    timerRec->start(speedRec);
}





void Chooser::on_SDChooser_clicked(bool checked)
{
    timerSD = new QTimer(this);
    connect(timerSD,SIGNAL(timeout()),this,SLOT(updateSD()));
    SDFramesFore.clear();
    SDFramesMask.clear();
    SDFramesOriginal.clear();
    SDIndex=0;
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
    if(filename !=NULL)
    {
        Chooser::SD2(filename.toStdString(),ui->NChooser->value(),this);
        ui->controlSD->setEnabled(true);
        ui->accel_SD->setEnabled(true);
        ui->deccel_SD->setEnabled(true);
        ui->speedDown_SD->setEnabled(true);
        ui->speedUp_SD->setEnabled(true);
        ui->SDChooser->setEnabled(false);
        ui->end_SD->setEnabled(true);
        ui->begin_SD->setEnabled(true);
        ui->controlSD->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
        timerSD->start(30);
    }
}

void Chooser::updateSD()
{
    if(SDFramesFore.empty() || SDFramesMask.empty() || SDFramesOriginal.empty())
    {
        return;
    }
    Mat tmp;
    //tmp=gradFramesOriginal.at(gradIndex);
    //ui->image_label_original->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=SDFramesFore.at(SDIndex);
    ui->SD_image_label_foreground->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=SDFramesMask.at(SDIndex);
    ui->SD_image_label_mask->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=SDFramesOriginal.at(SDIndex);
    ui->SD_image_label_original->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));
    //QThread::msleep(100);
    //QTest::qSleep(100);

    ui->SDControl->setMinimum(0);
    ui->SDControl->setMaximum(SDFramesOriginal.size()-1);
    ui->SDControl->setValue(SDIndex);

    SDIndex++;
    if(SDIndex>=SDFramesFore.size() || SDIndex>=SDFramesOriginal.size() || SDIndex>=SDFramesMask.size())
    {
        SDIndex=0;
        timerSD->stop();
        ui->controlSD->setEnabled(false);
        ui->SDChooser->setEnabled(true);
    }
}


void Chooser::on_controlSD_clicked(bool checked)
{
    if(timerSD->isActive())
    {
        timerSD->stop();
        ui->controlSD->setIcon(QIcon("Resources/MediaControl/Play-26.png"));
        ui->controlSD->setIconSize(QSize(26,26));
    }
    else
    {
        ui->controlSD->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
        ui->controlSD->setIconSize(QSize(26,26));
        timerSD->start(30);
    }
}



void Chooser::on_begin_SD_clicked(bool checked)
{
    timerSD->stop();
    SDIndex=0;
    ui->controlSD->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
    ui->controlSD->setEnabled(true);
    ui->accel_SD->setEnabled(true);
    ui->deccel_SD->setEnabled(true);
    ui->speedDown_SD->setEnabled(true);
    ui->speedUp_SD->setEnabled(true);
    ui->SDChooser->setEnabled(false);
    timerSD->start(speedSD);
}

void Chooser::on_deccel_SD_clicked(bool checked)
{
    timerSD->stop();
    SDIndex-=15;
    if(SDIndex<0)
        SDIndex=0;
    timerSD->start(speedSD);
}

void Chooser::on_speedDown_SD_clicked(bool checked)
{
    timerSD->stop();
    this->speedSD+=10;
    if(speedSD>=100)
        speedSD=100;
    timerSD->start(speedSD);
}

void Chooser::on_speedUp_SD_clicked(bool checked)
{
    timerSD->stop();
    this->speedSD-=10;
    if(speedSD<=5)
        speedSD=5;
    timerSD->start(speedSD);
}

void Chooser::on_accel_SD_clicked(bool checked)
{
    timerSD->stop();
    SDIndex+=15;
    if(SDIndex>=SDFramesOriginal.size())
        SDIndex=SDFramesOriginal.size()-1;
    timerSD->start(speedSD);
}

void Chooser::on_end_SD_clicked(bool checked)
{
    timerSD->stop();
    SDIndex=SDFramesOriginal.size()-1;
    ui->SDChooser->setEnabled(true);
    ui->accel_SD->setEnabled(false);
    ui->deccel_SD->setEnabled(false);
    ui->speedDown_SD->setEnabled(false);
    ui->speedUp_SD->setEnabled(false);
    timerSD->start(speedSD);
}


void Chooser::on_SAPChooser_clicked(bool checked)
{

    timerSAP = new QTimer(this);
    connect(timerSAP,SIGNAL(timeout()),this,SLOT(updateSAP()));
    SAPFramesFore.clear();
    SAPFramesMask.clear();
    SAPFramesOriginal.clear();
    SAPFramesBack.clear();
    SAPIndex=0;
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
    if(filename !=NULL)
    {
        Chooser::SAP(filename.toStdString(),ui->multipleChooser->value(),ui->alphaChooserSAP->value(),this);
        ui->controlSAP->setEnabled(true);
        ui->accel_SAP->setEnabled(true);
        ui->deccel_SAP->setEnabled(true);
        ui->speedDown_SAP->setEnabled(true);
        ui->speedUp_SAP->setEnabled(true);
        ui->SAPChooser->setEnabled(false);
        ui->end_SAP->setEnabled(true);
        ui->begin_SAP->setEnabled(true);
        ui->controlSAP->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
        timerSAP->start(30);
    }

}

void Chooser::updateSAP()
{
    if(SAPFramesFore.empty() || SAPFramesMask.empty() || SAPFramesOriginal.empty() || SAPFramesBack.empty())
    {
        return;
    }
    Mat tmp;
    //tmp=gradFramesOriginal.at(gradIndex);
    //ui->image_label_original->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=SAPFramesFore.at(SAPIndex);
    ui->SAP_image_label_foreground->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));


    tmp=SAPFramesMask.at(SAPIndex);
    ui->SAP_image_label_mask->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=SAPFramesOriginal.at(SAPIndex);
    ui->SAP_image_label_original->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    tmp=SAPFramesBack.at(0);
    ui->SAP_image_label_back->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

    //QThread::msleep(100);
    //QTest::qSleep(100);

    ui->SAPControl->setMinimum(0);
    ui->SAPControl->setMaximum(SAPFramesOriginal.size()-1);
    ui->SAPControl->setValue(SAPIndex);


    SAPIndex++;
    if(SAPIndex>=SAPFramesFore.size() || SAPIndex>=SAPFramesOriginal.size() || SAPIndex>=SAPFramesMask.size())
    {
        SAPIndex=0;
        timerSAP->stop();
        ui->controlSAP->setEnabled(false);
        ui->SAPChooser->setEnabled(true);
    }
}



void Chooser::on_controlSAP_clicked(bool checked)
{
    if(timerSAP->isActive())
    {
        timerSAP->stop();
        ui->controlSAP->setIcon(QIcon("Resources/MediaControl/Play-26.png"));
        ui->controlSAP->setIconSize(QSize(26,26));
    }
    else
    {
        timerSAP->start(30);
        ui->controlSAP->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
        ui->controlSAP->setIconSize(QSize(26,26));
    }
}


void Chooser::on_speedUp_SAP_clicked(bool checked)
{
    timerSAP->stop();
    this->speedSAP-=10;
    if(speedSAP<=5)
        speedSAP=5;
    timerSAP->start(speedSAP);
}

void Chooser::on_speedDown_SAP_clicked(bool checked)
{
    timerSAP->stop();
    this->speedSAP+=10;
    if(speedSAP>=100)
        speedSAP=100;
    timerSAP->start(speedSAP);
}

void Chooser::on_deccel_SAP_clicked(bool checked)
{
    timerSAP->stop();
    SAPIndex-=15;
    if(SAPIndex<0)
        SAPIndex=0;
    timerSAP->start(speedSAP);
}

void Chooser::on_accel_SAP_clicked(bool checked)
{
    timerSAP->stop();
    SAPIndex+=15;
    if(SAPIndex>=SAPFramesOriginal.size())
        SAPIndex=SAPFramesOriginal.size()-1;
    timerSAP->start(speedSAP);
}

void Chooser::on_begin_SAP_clicked(bool checked)
{
    timerSAP->stop();
    SAPIndex=0;
    ui->controlSAP->setIcon(QIcon("Resources/MediaControl/Pause-26-Disabled.png"));
    ui->controlSAP->setEnabled(true);
    ui->accel_SAP->setEnabled(true);
    ui->deccel_SAP->setEnabled(true);
    ui->speedDown_SAP->setEnabled(true);
    ui->speedUp_SAP->setEnabled(true);
    ui->SAPChooser->setEnabled(false);
    timerSAP->start(speedSAP);
}

void Chooser::on_end_SAP_clicked(bool checked)
{
    timerSAP->stop();
    SAPIndex=SAPFramesOriginal.size()-1;
    ui->SAPChooser->setEnabled(true);
    ui->accel_SAP->setEnabled(false);
    ui->deccel_SAP->setEnabled(false);
    ui->speedDown_SAP->setEnabled(false);
    ui->speedUp_SAP->setEnabled(false);
    timerSAP->start(speedSAP);
}







/////////////////////////////////////
/// function de traitements opencv///
/////////////////////////////////////

using namespace   std;
using namespace cv;


void Chooser::moyenne_Reccur(string path, double alpha,Chooser* c)
{
    QElapsedTimer etimer;
    etimer.start();

    VideoCapture vc(path); // objet de la classe VideoCapture qui permettra de lire la video
    int initX=20; //position initiale sur X
    int initY=500; // position initiale sur Y
    Mat M = Mat::zeros(1, 1, CV_32FC3); // Objet de la classe Mat qui contiendra la moyenne finale
    Mat I = Mat::zeros(1, 1, CV_32FC3); // Objet de la classe Mat qui contiendra l'image courante
    vector<Mat> images;
    vc >> M; // on lit le premier frame et on le met dans la matrice M
    M.convertTo(M, CV_64FC3);// convertir la matrice pour que chaque element soit de type Vec3d c'est a dire un vecteur de 3 nombre double

    //    M = alpha*M; // ini
    //    M.copyTo(M1);
    int max = vc.get(CV_CAP_PROP_FRAME_COUNT);
    int frame;
    int p;
    if (!vc.isOpened())// check if we succeeded
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    c->ui->label_progressRec->setText("Cacluls du fond statique ...");
    while (vc.get(CV_CAP_PROP_POS_FRAMES)<= vc.get(CV_CAP_PROP_FRAME_COUNT))
    {
        QCoreApplication::processEvents();
        frame = vc.get(CV_CAP_PROP_POS_FRAMES);
        p=(int) frame*100/max;
        c->ui->backgroundProgressRec->setValue(p);
        //M= alpha*I+(1-alpha)M1 ;
        vc >> I; // Lire le frame courant dans l'image
        if (I.empty() || M.empty()) // si une des images utilisé plus tard est déjà vide , on break
        {
            break;
        }
        I.convertTo(I, CV_64FC3); //convertir la matrice pour que chaque element soit de type Vec3d c'est a dire un vecteur de 3 nombre double
        //cout << I;
        M = alpha*I + (1 - alpha)*M; // La formule pour calculer la moyenne reccursivement
        M.convertTo(M, CV_64FC3); // reconvertir l'image pour la réutilisation dans l'ittération suivante
    }

    //cheat begin
    if(c->ui->backgroundProgressRec->value()<100)
    {
        c->ui->backgroundProgressRec->setValue(100);
    }
    //cheat end


    vc.release(); // dès qu'on termine le parcours de la vidéo on libère l'objet VideoCapture
    Mat original = Mat::zeros(M.rows,M.cols,CV_8UC3);//Matrice qui contiendra l'image original
    M.convertTo(M, CV_8UC3);//conversion en elements de type vecteur d'un char 8 bits non signé
    Mat MRGB;
    cvtColor(M,MRGB,CV_BGR2RGB);
    c->recFramesBack.push_back(MRGB);
    Mat M8UC3;
    M.convertTo(M8UC3,CV_8UC3);
    //imshow("backGround", M);//Affichage de la matrice M
    //moveWindow("backGround",initX+original.cols,initY);
    //waitKey(0);
    cvtColor(M, M, COLOR_BGR2GRAY);//Convertion de l'espace de couleur de la matrice M de RGB en GrayScale
    VideoCapture v(path);//Creation d'un autre objet de lecture de video.
    int frames = v.get(CV_CAP_PROP_FRAME_COUNT);
    c->ui->label_progressRec->setText("Cacluls en cours ...");
    while (v.get(CV_CAP_PROP_POS_FRAMES) <= v.get(CV_CAP_PROP_FRAME_COUNT)) // Tant que la video n'est pas finie
    {
        QCoreApplication::processEvents();

        //cout << v.get(CV_CAP_PROP_POS_FRAMES) << "/" << v.get(CV_CAP_PROP_FRAME_COUNT) << endl;
        c->ui->backgroundProgressRec->setValue((int)v.get(CV_CAP_PROP_POS_FRAMES)*100/frames);
        Mat foreground = Mat::zeros(M.rows,M.cols,CV_8UC3);
        v >> original;
        if (original.empty())
            break;//Si le frame est vide on sort de la boucle

        if(c->shadowRec)
        original=Chooser::shadowRemoval_HSV(&original,M8UC3,c);

        original.copyTo(I);//Copie de l'image originale pour de futurs traitements
        cvtColor(I, I, COLOR_BGR2GRAY);
        absdiff(I, M, I);//equivalent a I=M-I
        double min,max;
        cv::minMaxLoc(I, &min, &max);//function that returns the max and min value of every pixel's intensity in an Mat object
        threshold(I, I,(int) (max+min)/4 , 255, THRESH_BINARY);//Suillage statique d'une valeur d'intensité = 45
        //cout << (int) (max+min)/3 << endl;
        cv::erode(I,I,Mat());//Une erosion
        cv::erode(I,I,Mat());//Une erosion
        cv::dilate(I,I,Mat());//Une dilatation
        cv::dilate(I,I,Mat());//Une dilatation
        original.convertTo(original,CV_8UC3);//Dunno what to do with that maybe it's useless
        I.convertTo(I,CV_8U);
        Mat I8UC3;
        cvtColor(I,I8UC3,COLOR_GRAY2BGR);
        I8UC3.convertTo(I8UC3,CV_8UC3);

//        cvtColor(M,M , CV_GRAY2BGR);
//        I=Chooser::shadowRemoval_HSV(&I,M,c);

        foreground=Chooser::getForeGroundRGB_8UC3(original,I); // Appel a la fonction qui retourne l'avant plan
        Chooser::drawBoxesRGB_8UC3(&original,I);//Appel a la methode qui permet de dessiner les boites englobantes
        Chooser::drawBoxesRGB_8UC3(&foreground,I);//Appel a la methode qui permet de dessiner les boites englobantes

        Mat originalRGB;
        cvtColor(original,originalRGB,CV_BGR2RGB);
        c->recFramesOriginal.push_back(originalRGB);

        Mat foregroundRGB;
        cvtColor(foreground,foregroundRGB,CV_BGR2RGB);
        c->recFramesFore.push_back(foregroundRGB);

        Mat maskRGB;
        cvtColor(I8UC3,maskRGB,CV_BGR2RGB);
        c->recFramesMask.push_back(maskRGB);

        //        images.push_back(original);
        //        images.push_back(foreground);
        //        images.push_back(I8UC3);
        //showMultipleImage_8UC3(images,"Results",c);
        //imshow("forground",foreground);
        //imshow("Masque", I);
        //        if(waitKey(0)=='\33')
        //        {
        //            destroyAllWindows();
        //            return;

        //        }
        //I=Chooser::shadowRemoval_HSV(&I,M,c);
    }
    if(c->ui->backgroundProgressRec->value()<100)
    {
        c->ui->backgroundProgressRec->setValue(100);
    }
    float elapsed=(float)etimer.elapsed()/1000;
    QString res = "Terminé après : "+QString::number(elapsed)+" secondes";
    c->ui->label_progressRec->setText(res);

    c->rec_Alpha_Map[(float)c->ui->alphaChooserRec->value()/1000]=elapsed;
    updateTableWidget(c->ui->rec_results_table,c->rec_Alpha_Map);

    v.release();
    //    if(waitKey(0)=='\33')
    //    {
    //        destroyAllWindows();
    //        return;

    //    }
}


//////////////////////////
/////////////////////////////::


void Chooser::gradiantOublieux(string pathToVideo , double alpha,Chooser* c)
{
    QElapsedTimer etimer;
    etimer.start();

    //cout << "alpha:" << alpha << endl;
    Mat X, Y, M, m, prev;
    Mat original;
    vector<Mat> images;
    VideoCapture capture(pathToVideo); // open the video specified in the variable pathToVideo
    if (!capture.isOpened())// check if there is an error
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);//We exit the program if we can't
    }
    //otherwise we continue
    capture >> original;//We read the first frame and store it in original
    if(original.empty())//if the frame is empty we break out of the loop
    {
        cout << "ERROR EMPTY FRAME"<<endl;
        cerr << "BREAKING"<< endl;
        exit(EXIT_FAILURE);
    }
    original.copyTo(X);
    Mat foreGround;
    X.copyTo(M);
    X.copyTo(m);
    Mat diff;
    int frames=capture.get(CV_CAP_PROP_FRAME_COUNT);
    c->ui->label_progressGrad->setText("Calculs en cours ...");
    while (capture.get(CV_CAP_PROP_POS_FRAMES)<=capture.get(CV_CAP_PROP_FRAME_COUNT))
    {
        QCoreApplication::processEvents();

        c->ui->progressBarGrad->setValue((int)capture.get(CV_CAP_PROP_POS_FRAMES)*100/frames);
        capture >> original;
        Mat mask;
        if (!original.empty() )
        {

            //            imshow("d",tmp);
            //            waitKey(0);
            //images.push_back(original);
            foreGround = Mat::zeros(X.rows, X.cols, CV_8UC3);
            //begin main function
            original.copyTo(X);

            //conversions begin
            X.convertTo(X, CV_32FC3);
            M.convertTo(M, CV_32FC3);
            m.convertTo(m, CV_32FC3);
            //conversions end

            //Process begin
            Mat maxM;
            maxM = max(X, M);
            M = alpha*X + (1 - alpha)*maxM;
            Mat minm;
            minm = min(X, m);
            m = alpha*X + (1 - alpha)*minm;
            mask = M - m;
            //Process end

            //Thresholding begin
            cvtColor(mask, mask, COLOR_BGR2GRAY);
            double min, max;
            cv::minMaxLoc(mask, &min, &max);//function that returns the max and min value of every pixel's intensity in an Mat object
            //double dynamicThresh = (max+min)/2;//the dynamicThresh is the average of the max and min values that we calculated earlier
            threshold(mask, mask, (int) (min+max)/4, 255, THRESH_BINARY);

            cv::dilate(mask,mask,Mat());
            cv::dilate(mask,mask,Mat());

            cv::erode(mask,mask,Mat());
            //cv::erode(mask,mask,Mat());

            Mat mask8UC3;
            cvtColor(mask,mask8UC3,COLOR_GRAY2BGR);
            mask8UC3.convertTo(mask8UC3,CV_8UC3);
            //imshow("hist",hist(mask8UC3));
            //Thresholding end

            //Post-processing being
            mask.convertTo(mask, CV_8U);
            foreGround=Chooser::getForeGroundRGB_8UC3(original,mask);//We get the foreground with the function getForeGroundRGB_8UC3
            Chooser::drawBoxesRGB_8UC3(&original,mask);//we draw the englobing boxes with the function drawBoxesRGB_8UC3

            Mat originalRGB;
            cvtColor(original,originalRGB , CV_BGR2RGB);
            c->gradFramesOriginal.push_back(originalRGB);

            //            images.push_back(foreGround);
            //            images.push_back(mask8UC3);
            //            //The most important piece of code ever
            //Mat dst=showMultipleImage_8UC3(images,"hhh");
            //End of the most import piece of coder ever
            //QThread::msleep();
            //Chooser::showMultipleImage_8UC3(images,"Results",c);
            //Post-processing end
            //Mat res = Chooser::getMultipleImage_8UC3(images,"Results",c);
            Chooser::drawBoxesRGB_8UC3(&foreGround,mask);
            Mat foreRGB;
            cvtColor(foreGround,foreRGB , CV_BGR2RGB);
            c->gradFramesFore.push_back(foreRGB);
            //            imshow("ddd",tmp);
            //            waitKey(0);

            Chooser::drawBoxesRGB_8UC3(&mask,mask);
            Mat maskRGB;
            cvtColor(mask8UC3,maskRGB , CV_BGR2RGB);
            c->gradFramesMask.push_back(maskRGB);
            //c->gradFrames.
            //            imshow("dd",tmp);
            //            waitKey(0);
        }
        else
        {
            cout << "ERROR EMPTY FRAME" << endl;
            break;
        }



        //            //Display begin
        //            imshow("original", original);
        //            imshow("Mask", mask);
        //            imshow("ForeGround",foreGround);
        //            //Display end

        //waitKey(1);
    }
    if(c->ui->progressBarGrad->value()<100)
        c->ui->progressBarGrad->setValue(100);

    float elapsed=(float)etimer.elapsed()/1000;
    QString res = "Terminé après : "+QString::number(elapsed)+" secondes";
    c->ui->label_progressGrad->setText(res);

    c->grad_Alpha_Map[(float)c->ui->alphaChooserGrad->value()/1000]=elapsed;
    updateTableWidget(c->ui->grad_results_table,c->grad_Alpha_Map);

    capture.release();


}

//////////////////////

//void Chooser::sigmaDelta(string path)
//{
//    VideoCapture vc(path);
//    Mat X;
//    Mat M;
//    RNG rng(10);
//    int N = 2;
//    if (!vc.isOpened())// check if we succeeded
//    {
//        cout << "Error while opening video " << endl;
//        exit(EXIT_FAILURE);
//    }
//    vc >> X;
//    X.convertTo(X, CV_32FC3);
//    X.copyTo(M);
//    //// get the average
//    while (vc.get(CV_CAP_PROP_POS_FRAMES) <= vc.get(CV_CAP_PROP_FRAME_COUNT))
//    {
//        //cout << vc.get(CV_CAP_PROP_POS_FRAMES) << "/" << vc.get(CV_CAP_PROP_FRAME_COUNT) << endl;
//        vc >> X;
//        if (!X.empty() && !M.empty())
//        {
//            X.convertTo(X, CV_32FC3);
//            M += X;
//            //imshow("final", tmp);
//            //waitKey(1);
//        }
//        else
//        {
//            cout << "EMTPY FRAME " << endl;
//            break;
//        }

//    }
//    M /= vc.get(CV_CAP_PROP_FRAME_COUNT);
//    M.convertTo(M,CV_8UC3);
//    cvtColor(M, M, COLOR_BGR2GRAY);
//    vc.release();
//    namedWindow("BackGround",WINDOW_AUTOSIZE);
//    imshow("BackGround",M);
//    moveWindow("BackGround",100,0);
//    waitKey(0);
//    M.convertTo(M,CV_8SC3);
//    ///////////////////
//    VideoCapture capt(path);
//    if (!capt.isOpened())
//    {
//        cout << "Error while opening video " << endl;
//        exit(EXIT_FAILURE);
//    }
//    Mat delta = Mat::zeros(M.rows, M.cols, CV_8SC1);
//    Mat I;
//    Mat M0;
//    Mat V= Mat::zeros(M.rows,M.cols,CV_8SC1);
//    Mat D=Mat::zeros(M.rows,M.cols,CV_8U);
//    M.convertTo(M, CV_8SC1);
//    capt >> M0;
//    cvtColor(M0,M0,COLOR_BGR2GRAY);
//    M0.convertTo(M0,CV_8SC1);
//    while (capt.get(CV_CAP_PROP_POS_FRAMES) <= capt.get(CV_CAP_PROP_FRAME_COUNT))
//    {
//        capt >> I;
//        if (!I.empty())
//        {
//            imshow("Original",I);
//            moveWindow("Originale",500,-250);
//            cvtColor(I, I, COLOR_BGR2GRAY);
//            //cout << I.channels() << endl;
//            I.convertTo(I, CV_8SC1);
//            //cout << M.type() << " and " << I.type() << endl;
//            delta = M-I;
//            delta.convertTo(delta,CV_8U);
//            imshow("delta",delta);
//            waitKey(0);
//            delta.convertTo(delta,CV_8SC1);
//            N= 4;
//            cout << N << endl;
//            for(int i = 0; i < I.rows; i++)
//            {
//                for (int j = 0; j < I.cols; j++)
//                {
//                    //cout << delta.at<int8_t>(i, j) <<endl;
//                    if (delta.at<int8_t>(i, j) < 0)
//                    {
//                        M0.at<int8_t>(i,j) = M0.at<int8_t>(i,j) + 1;
//                    }
//                    if (delta.at<int8_t>(i, j) > 0)
//                    {
//                        M0.at<int8_t>(i, j) = M0.at<int8_t>(i, j) - 1;
//                    }
//                    ////////////////
//                    if( delta.at<int8_t>(i,j)!=0)
//                    {

//                        if(V.at<int8_t>(i,j) < N*abs(delta.at<int8_t>(i,j)))
//                        {
//                            V.at<int8_t>(i,j)+=1;
//                        }
//                        if(V.at<int8_t>(i,j) > N*abs(delta.at<int8_t>(i,j)))
//                        {
//                            V.at<int8_t>(i,j)-=1;
//                        }
//                    }

//                    if( abs(delta.at<int8_t>(i,j)) >= V.at<int8_t>(i,j))
//                    {
//                        //cout << "oui" << endl;
//                        D.at<uchar>(i,j) = 255;
//                    }
//                    else
//                    {
//                        D.at<uchar>(i,j) = 0;
//                    }

//                }

//            }
//            cv::erode(D,D,Mat());
//            vector<vector<Point> > contours;
//            vector<Vec4i> hierarchy;
//            //cvtColor(finMask, fingray, COLOR_BGR2GRAY);
//            Mat diffGray;
//            D.convertTo(diffGray,COLOR_BGR2GRAY);
//            diffGray.convertTo(diffGray, CV_8UC1);
//            Canny(diffGray, diffGray, 30, 30 * 2, 3);
//            findContours(diffGray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_TC89_KCOS, Point(0,0));
//            //cout << contours.at(0) << "\nend\n";
//            for (unsigned int i = 0; i < contours.size(); ++i)
//            {
//                Point p=(contours.at(i)).at(0);
//                int xMax=p.x;
//                int yMax=p.y;
//                int xMin=p.x;
//                int yMin=p.y;
//                for (unsigned int j = 0; j < contours.at(i).size(); ++j)
//                {
//                    Point current=(contours.at(i)).at(j);
//                    if(current.x>xMax)
//                    {
//                        xMax=current.x;
//                    }
//                    if(current.y>yMax)
//                    {
//                        yMax=current.y;
//                    }
//                    if(current.x<xMin)
//                    {
//                        xMin=current.x;
//                    }
//                    if(current.y<yMin)
//                    {
//                        yMin=current.y;
//                    }
//                }

//                rectangle(D,Point(xMin,yMin),Point(xMax,yMax),Scalar(127));
//            }
//            //cout << M0 ;
//            imshow("M(t)",M0);
//            imshow("V",V);
//            imshow("D",D);
//            waitKey(0);
//            cout << capt.get(CV_CAP_PROP_POS_FRAMES) << "/" << capt.get(CV_CAP_PROP_FRAME_COUNT) << endl;
//        }
//        else
//        {
//            cout << "ERROR EMPTY FRAME" << endl;
//            break;
//        }
//    }
//    if(waitKey(0)=='\33')
//    {
//        destroyAllWindows();
//        return;

//    }
//}


///////////////////////////

void Chooser::moyenne_Arith(std::string path ,Chooser* c )
{

    QElapsedTimer etimer;
    etimer.start();

    Mat background;
    Mat X;
    Mat foreGround;
    VideoCapture v(path);
    Mat backGroundGray;
    Mat original;
    double Rnorme;
    Mat foreGroundGray;
    vector<Mat> images;

    c->ui->label_progressArith->setText("Cacluls du fond statique ...");
    background = Chooser::getBackGroundRGB_8UC3(path,c,c->ui->backgroundProgressArith);
    background.convertTo(background, CV_8UC3);

    Mat backRGB;
    cvtColor(background,backRGB , CV_BGR2RGB);
    c->arithFramesBack.push_back(backRGB);

    cvtColor(background, backGroundGray, COLOR_BGR2GRAY);
    backGroundGray.convertTo(backGroundGray, CV_32F);
    Mat diff = Mat::zeros(background.rows,background.cols,CV_32F);
    int frames = v.get(CV_CAP_PROP_FRAME_COUNT);
    c->ui->label_progressArith->setText("Calculs en cours..");
    while (v.get(CV_CAP_PROP_POS_FRAMES) <= v.get(CV_CAP_PROP_FRAME_COUNT))
    {
        QCoreApplication::processEvents();
        c->ui->backgroundProgressArith->setValue((int)v.get(CV_CAP_PROP_POS_FRAMES)*100/frames);
        v >> X;
        if (!X.empty())
        {
            //Mat nonShadow = Chooser::shadowRemoval_HSV(&X,background,c);
            //imshow("nonshadow",nonShadow);
            //qDebug() << c->shadowArith ;
            if(c->shadowArith)
            {
                c->ui->label_7->setText("Image originale sans ombres");
                X=Chooser::shadowRemoval_HSV(&X,background,c);
            }
            else
            {
                c->ui->label_7->setText("Image originale");

            }
            X.copyTo(original);
            cvtColor(X, X, COLOR_BGR2GRAY);
            X.convertTo(X, CV_32F);
            //cout << v.get(CV_CAP_PROP_POS_FRAMES) << "/" << v.get(CV_CAP_PROP_FRAME_COUNT) << endl;
            absdiff(X, backGroundGray, diff);
            double max,min;
            cv::minMaxLoc(diff, &min, &max);//function that returns the max and min value of every pixel's intensity in an Mat object
            threshold(diff, diff, (int) (max+min)/4, 255, THRESH_BINARY);
            cv::erode(diff, diff, Mat());
            cv::dilate(diff, diff, Mat());

            diff.convertTo(diff,CV_8U);
            foreGround = Chooser::getForeGroundRGB_8UC3(original,diff);
            foreGround.convertTo(foreGround, CV_32FC3);
            cvtColor(foreGround, foreGroundGray, COLOR_BGR2GRAY);
            foreGroundGray.convertTo(foreGroundGray, CV_32F);

            //original=shadowRemoval_HSV(&original,background,c);
            //imshow("without shadow ",original);
            //waitKey(0);
            //            for (int i = 0; i < foreGround.rows; i++)
            //            {
            //                for (int j = 0; j < foreGround.cols; j++)
            //                {
            //                    double B = foreGround.at<Vec3f>(i, j)[0];
            //                    double G = foreGround.at<Vec3f>(i, j)[1];
            //                    double R = foreGround.at<Vec3f>(i, j)[2];
            //                    Rnorme = (double)(R / (R + G + B));
            //                    if (Rnorme < 20)
            //                    {
            //                        double CD = abs(foreGroundGray.at<float>(i, j) -backGroundGray.at<float>(i, j));
            //                        //cout << "CD = " << CD << endl;
            //                        if (CD < 1)
            //                        {
            //                            double BD = (double) ((foreGroundGray.at<float>(i, j)*backGroundGray.at<float>(i, j)) / pow(backGroundGray.at<float>(i, j), 2));
            //                            cout << "BD = " << BD << endl;
            //                            if (BD < 1.25f || BD > 1.5f)
            //                            {
            //                                foreGround.at<Vec3f>(i, j)[0]=0;
            //                                foreGround.at<Vec3f>(i, j)[1]=0;
            //                                foreGround.at<Vec3f>(i, j)[2]=0;
            //                            }
            //                        }
            //                    }
            //                }
            //            }

            foreGround.convertTo(foreGround, CV_8UC3);
            Chooser::drawBoxesRGB_8UC3(&original,diff);
            Chooser::drawBoxesRGB_8UC3(&foreGround,diff);
            Chooser::drawBoxesRGB_8UC3(&diff,diff);

            Mat originalRGB;
            cvtColor(original,originalRGB , CV_BGR2RGB);
            c->arithFramesOriginal.push_back(originalRGB);

            Mat diffRGB;
            //Mat diffBGR8UC3;
            //cvtColor(diff,diffBGR8UC3,COLOR_GRAY2RGB);

            cvtColor(diff,diffRGB , CV_GRAY2RGB);

            c->arithFramesMask.push_back(diffRGB);

            Mat foreGroundRGB;
            cvtColor(foreGround,foreGroundRGB , CV_BGR2RGB);
            c->arithFramesFore.push_back(foreGroundRGB);


            //            Mat diff8UC3;
            //            cvtColor(diff,diff8UC3,COLOR_GRAY2BGR);
            //            images.push_back(original);
            //            images.push_back(foreGround);
            //            images.push_back(diff8UC3);
            //showMultipleImage_8UC3(images,"Results",c);
            //images.clear();
            //            imshow("original", original);
            //            imshow("foreground", foreGround);
            //            imshow("diff", diff);
            //            imshow("final2", tmp);
            //            if(waitKey(0)=='\33')
            //            {
            //                destroyAllWindows();
            //                return;

            //            }
            diff.convertTo(diff, CV_32F);

        }
        else
        {
            cout << "ERROR EMPTY FRAME" << endl;
            break;
        }
    }
    if(c->ui->backgroundProgressArith->value()<100)
        c->ui->backgroundProgressArith->setValue(100);
    QString res = "Terminé après : "+QString::number((float)etimer.elapsed()/1000)+" secondes";
    c->ui->label_progressArith->setText(res);
    v.release();
    //    if(waitKey(0)=='\33')
    //    {
    //        destroyAllWindows();
    //        return;

    //    }

}



//////////////////

void Chooser::SAP(string path, int multiple, double alpha,Chooser* c)
{
    QElapsedTimer etimer;
    etimer.start();

    VideoCapture vc(path);
    Mat I;
    Mat Moy;
    Mat SC;
    Mat S;
    int threshSum=0;
    int N=vc.get(CV_CAP_PROP_FRAME_COUNT);
    Mat sigma;
    Mat mask;
    Mat Icpy;
    Mat oldMoy;
    vc >> I;
    Moy=Mat::zeros(I.size(),CV_32SC3);
    SC = Mat::zeros(I.size(),CV_32SC3);
    S=Mat::zeros(I.size(),CV_32SC3);
    int max = vc.get(CV_CAP_PROP_FRAME_COUNT);
    int frame;
    int p;
    vector<Mat> images;

    if (!vc.isOpened())// check if we succeeded
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    c->ui->label_progressSAP->setText("Calcul du fond statique ...");
    while (vc.get(CV_CAP_PROP_POS_FRAMES) <= vc.get(CV_CAP_PROP_FRAME_COUNT))
    {
        QCoreApplication::processEvents();
        frame = vc.get(CV_CAP_PROP_POS_FRAMES);
        p=(int) frame*100/max;
        c->ui->backgroundProgressSAP->setValue(p);

        vc >> I;
        I.convertTo(I, CV_32SC3);
        if (!I.empty())
        {
            for (int i = 0; i < I.rows; ++i)
            {
                for (int j = 0; j < I.cols; ++j)
                {
                    Moy.at<Vec3i>(i,j)[0]+=I.at<Vec3i>(i,j)[0];
                    Moy.at<Vec3i>(i,j)[1]+=I.at<Vec3i>(i,j)[1];
                    Moy.at<Vec3i>(i,j)[2]+=I.at<Vec3i>(i,j)[2];
                    //
                    SC.at<Vec3i>(i,j)[0]+=pow(I.at<Vec3i>(i,j)[0],2);
                    SC.at<Vec3i>(i,j)[1]+=pow(I.at<Vec3i>(i,j)[1],2);
                    SC.at<Vec3i>(i,j)[2]+=pow(I.at<Vec3i>(i,j)[2],2);
                    //
                    S.at<Vec3i>(i,j)[0]+=I.at<Vec3i>(i,j)[0];
                    S.at<Vec3i>(i,j)[1]+=I.at<Vec3i>(i,j)[1];
                    S.at<Vec3i>(i,j)[2]+=I.at<Vec3i>(i,j)[2];
                }
            }
        }
        else
        {
            cout << "EMPTY FRAME1" << endl;
            break;
        }
    }


    //cheat begin
    if(c->ui->backgroundProgressSAP->value()<100)
    {
        c->ui->backgroundProgressSAP->setValue(100);
    }
    //cheat end


    sigma=Mat::zeros(Moy.size(),CV_32SC3);
    //c->ui->label_progressSAP->setText("Calculs de la variance ...");
    for (int i = 0; i < Moy.rows; ++i)
    {
        //c->ui->backgroundProgressSAP->setValue((int)i*100/Moy.rows);
        for (int j = 0; j < Moy.cols; ++j)
        {
            Moy.at<Vec3i>(i,j)[0]/=N;
            Moy.at<Vec3i>(i,j)[1]/=N;
            Moy.at<Vec3i>(i,j)[2]/=N;
            ////////
            sigma.at<Vec3i>(i,j)[0]=sqrt( SC.at<Vec3i>(i,j)[0]/N - pow(S.at<Vec3i>(i,j)[0]/N,2) );
            sigma.at<Vec3i>(i,j)[1]=sqrt( SC.at<Vec3i>(i,j)[1]/N - pow(S.at<Vec3i>(i,j)[1]/N,2) );
            sigma.at<Vec3i>(i,j)[2]=sqrt( SC.at<Vec3i>(i,j)[2]/N - pow(S.at<Vec3i>(i,j)[2]/N,2) );
        }
        QCoreApplication::processEvents();
    }
    vc.release();
    Mat Moy8UC3;
    Moy.convertTo(Moy8UC3,CV_8UC3);
    //cheat begin
    //if(c->ui->backgroundProgressSAP->value()<100)
    //  c->ui->backgroundProgressSAP->setValue(100);
    //cheat end
    Mat MoyRGB;
    cvtColor(Moy8UC3,MoyRGB,CV_BGR2RGB);
    c->SAPFramesBack.push_back(MoyRGB);

    //imshow("MoyenneCoulour",Moy);
   // Moy.convertTo(Moy,CV_32SC3);
    mask = Mat::zeros(Moy.size(),CV_32SC3);
    VideoCapture capt(path);
    if (!capt.isOpened())// check if we succeeded
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    int frames = capt.get(CV_CAP_PROP_FRAME_COUNT);
    c->ui->label_progressSAP->setText("Calculs en cours");
    while (capt.get(CV_CAP_PROP_POS_FRAMES) <= capt.get(CV_CAP_PROP_FRAME_COUNT))
    {
        //cout << capt.get(CV_CAP_PROP_POS_FRAMES) << "/" << capt.get(CV_CAP_PROP_FRAME_COUNT) << endl;
        c->ui->backgroundProgressSAP->setValue((int)capt.get(CV_CAP_PROP_POS_FRAMES)*100/frames);
        QCoreApplication::processEvents();

        capt >> I;
        if (!I.empty())
        {
            //           Mat IGray;
            //Mat Icpy;
            if(c->shadowSAP)
                I=Chooser::shadowRemoval_HSV(&I,Moy8UC3,c);
            I.copyTo(Icpy);




            I.convertTo(I,CV_32SC3);
            for (int i = 0; i < I.rows; ++i)
            {
                for (int j = 0; j < I.cols; ++j)
                {


                    mask.at<Vec3i>(i,j)[0]=abs(I.at<Vec3i>(i,j)[0] - Moy.at<Vec3i>(i,j)[0]);
                    mask.at<Vec3i>(i,j)[1]=abs(I.at<Vec3i>(i,j)[1] - Moy.at<Vec3i>(i,j)[1]);
                    mask.at<Vec3i>(i,j)[2]=abs(I.at<Vec3i>(i,j)[2] - Moy.at<Vec3i>(i,j)[2]);
                    if(mask.at<Vec3i>(i,j)[0]>=multiple*sigma.at<Vec3i>(i,j)[0]
                            ||mask.at<Vec3i>(i,j)[1]>=multiple*sigma.at<Vec3i>(i,j)[1]
                            ||mask.at<Vec3i>(i,j)[2]>=multiple*sigma.at<Vec3i>(i,j)[2]
                            )
                    {
                        mask.at<Vec3i>(i,j)[0]=255;
                        mask.at<Vec3i>(i,j)[1]=255;
                        mask.at<Vec3i>(i,j)[2]=255;
                        threshSum+=multiple*sigma.at<Vec3i>(i,j)[0]+multiple*sigma.at<Vec3i>(i,j)[1]+multiple*sigma.at<Vec3i>(i,j)[2];
                    }
                    else
                    {
                        mask.at<Vec3i>(i,j)[0]=0;
                        mask.at<Vec3i>(i,j)[1]=0;
                        mask.at<Vec3i>(i,j)[2]=0;
                    }
                }
            }
            I.convertTo(I,CV_8UC3);
            mask.convertTo(mask,CV_8UC3);



            cv::erode(mask,mask,Mat());
            cv::erode(mask,mask,Mat());
            cv::dilate(mask,mask,Mat());
            cv::dilate(mask,mask,Mat());

            Chooser::drawBoxesRGB_8UC3(&Icpy,mask);
            Mat IRGB;
            cvtColor(Icpy,IRGB,CV_BGR2RGB);
            c->SAPFramesOriginal.push_back(IRGB);


            Mat maskGray;
            cvtColor(mask,maskGray,COLOR_BGR2GRAY);
            Mat foreGround = Mat::zeros(maskGray.rows,maskGray.cols,CV_8UC3);
            Chooser::drawBoxesRGB_8UC3(&Icpy,mask);
            foreGround = Chooser::getForeGroundRGB_8UC3(I,maskGray);
            /////
            Chooser::drawBoxesRGB_8UC3(&foreGround,mask);

            Mat foreGroundRGB;
            cvtColor(foreGround,foreGroundRGB,CV_BGR2RGB);
            c->SAPFramesFore.push_back(foreGroundRGB);

            Mat maskRGB;
            cvtColor(mask,maskRGB,CV_BGR2RGB);
            c->SAPFramesMask.push_back(maskRGB);


            //            images.push_back(foreGround);
            //            images.push_back(mask);
            //            //imshow("original",Icpy);
            //imshow("mask",mask);
            Mat non_mask;
            bitwise_not(mask,non_mask);
            threshold(non_mask,non_mask,1,1,THRESH_BINARY);
            //cout << non_mask;
            non_mask.convertTo(non_mask,CV_64FC3);
            //Moy.convertTo(Moy,CV_32FC3);
            I.convertTo(I,CV_64FC3);
            Moy.convertTo(Moy,CV_64FC3);
            //bitwise_and(I,non_mask,I);
            Moy.copyTo(oldMoy);
            //Moy=(1-n)*Moy+n*I;


            mask.convertTo(mask,CV_32SC3);
            Moy.convertTo(Moy,CV_8UC3);



            //imshow("foreground",foreGround);
            //Chooser::showMultipleImage_8UC3(images,"Results",c);
            //            if(waitKey(0)=='\33')
            //            {
            //                destroyAllWindows();
            //                return;

            //            }
            Moy.convertTo(Moy,CV_32SC3);


        }
        else
        {
            cout << "ERROR EMPTY FRAME" << endl;
            break;
        }
    }

    if(c->ui->backgroundProgressSAP->value()<100)
        c->ui->backgroundProgressSAP->setValue(100);

    float elapsed=(float)etimer.elapsed()/1000;
    QString res = "Terminé après : "+QString::number(elapsed)+" secondes";
    c->ui->label_progressSAP->setText(res);

    c->SAP_Mul_Map[c->ui->multipleChooser->value()]=elapsed;
    updateTableWidget(c->ui->SAP_results_table,c->SAP_Mul_Map);

    capt.release();
    //destroyAllWindows();
    //    if(waitKey(0)=='\33')
    //    {
    //        destroyAllWindows();
    //        return;

    //    }
}



void Chooser::SD2(std::string path,int mul,Chooser*c )
{
    QElapsedTimer etimer;
    etimer.start();
    Mat X;
    Mat background;
    Mat original;
    uchar Vmin =2;
    uchar Vmax =0;
    int N= mul;
    Mat I;
    Mat M;
    //    Mat M = Method::getBackGroundRGB_8UC3(path);
    //    M.convertTo(M,CV_8UC3);
    //    cvtColor(M, M, COLOR_BGR2GRAY);
    //    namedWindow("BackGround",WINDOW_AUTOSIZE);
    //    imshow("BackGround",M);
    //    moveWindow("BackGround",100,0);
    //    waitKey(0);
    //    ///////////////////
    VideoCapture capt(path);
    if (!capt.isOpened())
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    capt >> I;
    if(!I.empty())
    {
        I.copyTo(M);
        cvtColor(M,M,COLOR_BGR2GRAY);

    }
    Mat delta;// = Mat::zeros(M.rows, M.cols, CV_8U);
    Mat O = Mat::zeros(M.rows,M.cols,CV_8U);
    Mat V = Mat::ones(M.rows,M.cols,CV_8U);
    Mat E = Mat::zeros(M.rows,M.cols,CV_8U);
    Mat foreGround = Mat::zeros(M.rows,M.cols,CV_8UC3);

    if(c->shadowSD)
    background=Chooser::getBackGroundRGB_8UC3(path,c,NULL);

    vector<Mat> images;
    c->ui->label_progressSD->setText("Cacluls en cours ...");
    int frames = capt.get(CV_CAP_PROP_FRAME_COUNT);
    while (capt.get(CV_CAP_PROP_POS_FRAMES) <= capt.get(CV_CAP_PROP_FRAME_COUNT))
    {
        QCoreApplication::processEvents();

        c->ui->progressBarSD->setValue((int)capt.get(CV_CAP_PROP_POS_FRAMES)*100/frames);
        capt >> I;
        if (!I.empty())
        {
            if(c->shadowSD)
            I=Chooser::shadowRemoval_HSV(&I,background,c);

            I.copyTo(original);
            //I.copyTo(M);
            //moveWindow("Originale",500,-250);
            cvtColor(I, I, COLOR_BGR2GRAY);
            Vmax = 255;
            //cout << I.channels() << endl;
            //cout << M.type() << " and " << I.type() << endl;
            for(int i = 0; i < I.rows; i++)
            {
                for (int j = 0; j < I.cols; j++)
                {
                    //cout << delta.at<int8_t>(i, j) <<endl;
                    if (M.at<uchar>(i,j) < I.at<uchar>(i,j))
                    {
                        M.at<uchar>(i,j) = M.at<uchar>(i,j) + 1;
                    }
                    if (M.at<uchar>(i,j) > I.at<uchar>(i,j))
                    {
                        M.at<uchar>(i, j) = M.at<uchar>(i, j) - 1;
                    }
                    ////////////////
                    O.at<uchar>(i,j)=abs(M.at<uchar>(i,j)-I.at<uchar>(i,j));

                    if(O.at<uchar>(i,j)!=0)
                    {

                        if(V.at<uchar>(i,j) < N*abs(O.at<uchar>(i,j)))
                        {
                            V.at<uchar>(i,j)+=1;
                        }
                        if(V.at<uchar>(i,j) > N*abs(O.at<uchar>(i,j)))
                        {
                            V.at<uchar>(i,j)-=1;
                        }
                        V.at<uchar>(i,j) = max(min(V.at<uchar>(i,j),Vmax),Vmin);
                    }

                    if( abs(O.at<uchar>(i,j)) >= V.at<uchar>(i,j))
                    {
                        //cout << "oui" << endl;
                        E.at<uchar>(i,j) = 255;
                    }
                    else
                    {
                        E.at<uchar>(i,j) = 0;
                    }

                }

            }
            cv::erode(E,E,Mat());
            cv::erode(E,E,Mat());
            cv::dilate(E,E,Mat());
            cv::dilate(E,E,Mat());

            Chooser::drawBoxesRGB_8UC3(&original,E);
            foreGround=Chooser::getForeGroundRGB_8UC3(original,E);
            Chooser::drawBoxesRGB_8UC3(&foreGround,E);

            Mat originalRGB;
            cvtColor(original,originalRGB,CV_BGR2RGB);
            c->SDFramesOriginal.push_back(originalRGB);

            Mat foreGroundRGB;
            cvtColor(foreGround,foreGroundRGB,CV_BGR2RGB);
            c->SDFramesFore.push_back(foreGroundRGB);


            //            images.push_back(original);
            //            images.push_back(foreGround);
            //            //imshow("M(t)",M);
            //imshow("V",V);
            Mat E8UC3;
            cvtColor(E,E8UC3,COLOR_GRAY2BGR);
            E8UC3.convertTo(E8UC3,CV_8UC3);

            Mat maskRGB;
            cvtColor(E8UC3,maskRGB,CV_BGR2RGB);
            c->SDFramesMask.push_back(maskRGB);

            //images.push_back(E8UC3);
            //cout << capt.get(CV_CAP_PROP_POS_FRAMES) << "/" << capt.get(CV_CAP_PROP_FRAME_COUNT) << endl;


            //            if(waitKey(0)=='\33')
            //            {
            //                destroyAllWindows();
            //                return;

            //            }
        }
        else
        {
            cout << "ERROR EMPTY FRAME" << endl;
            break;
        }
    }
    if(c->ui->progressBarSD->value()<100)
    {
        c->ui->progressBarSD->setValue(100);
    }
    float elapsed=(float)etimer.elapsed()/1000;
    QString res = "Terminé après : "+QString::number(elapsed)+" secondes";
    c->ui->label_progressSD->setText(res);

    c->SD_N_Map[c->ui->NChooser->value()]=elapsed;
    updateTableWidget(c->ui->SD_results_table,c->SD_N_Map);

    //    if(waitKey(0)=='\33')
    //    {
    //        destroyAllWindows();
    //        return;

    //    }
}


cv::Mat Chooser::getBackGroundRGB_8UC3(std::string path,Chooser* c,QProgressBar* s)
{
    VideoCapture vc(path);
    Mat X;
    Mat M;
    int max = vc.get(CV_CAP_PROP_FRAME_COUNT);
    int frame;
    int p;

    if (!vc.isOpened())// check if we succeeded
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    vc >> X;
    X.convertTo(X, CV_32FC3);
    X.copyTo(M);
    //// get the average
    while (vc.get(CV_CAP_PROP_POS_FRAMES) <= vc.get(CV_CAP_PROP_FRAME_COUNT))
    {
        QCoreApplication::processEvents();

        if(s!=NULL)
        {
            frame = vc.get(CV_CAP_PROP_POS_FRAMES);
            p=(int) frame*100/max;
            s->setValue(p);

        }
        vc >> X;
        if (!X.empty() && !M.empty())
        {
            X.convertTo(X, CV_32FC3);
            M += X;
        }
        else
        {
            cout << "EMTPY FRAME " << endl;
            break;
        }

    }

    if(s!=NULL)
    {
        //cheat begin
        if(s->value()<100)
        {
            s->setValue(100);
        }
        //cheat end
    }

    M /= vc.get(CV_CAP_PROP_FRAME_COUNT);
    M.convertTo(M,CV_8UC3);
    vc.release();
    return M;
}


cv::Mat Chooser::getForeGroundRGB_8UC3(cv::Mat image , cv::Mat mask)
{
    Mat foreGround = Mat::zeros(image.rows,image.cols,CV_8UC3);
    for (int i = 0; i < mask.rows; i++)
    {
        for (int j = 0; j < mask.cols; j++)
        {

            if (mask.at<uchar>(i, j) ==255)
            {
                foreGround.at<cv::Vec3b>(i, j)[0] = image.at<Vec3b>(i, j)[0];
                foreGround.at<cv::Vec3b>(i, j)[1] = image.at<Vec3b>(i, j)[1];
                foreGround.at<cv::Vec3b>(i, j)[2] = image.at<Vec3b>(i, j)[2];

            }
        }
    }
    return foreGround;

}

void Chooser::drawBoxesRGB_8UC3(cv::Mat* image,cv::Mat mask)
{
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    vector<Rect> rectangles;
    Mat diffGray;
    mask.convertTo(diffGray,COLOR_BGR2GRAY);
    diffGray.convertTo(diffGray, CV_8UC1);
    Canny(mask, diffGray, 30, 30 * 2, 3);
    findContours(diffGray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_TC89_KCOS, Point(0,0));
    //cout << contours.at(0) << "\nend\n";
    for (unsigned int i = 0; i < contours.size(); ++i)
    {
        Point p=(contours.at(i)).at(0);
        int xMax=p.x;
        int yMax=p.y;
        int xMin=p.x;
        int yMin=p.y;
        for (unsigned int j = 0; j < contours.at(i).size(); ++j)
        {
            Point current=(contours.at(i)).at(j);
            if(current.x>xMax)
            {
                xMax=current.x;
            }
            if(current.y>yMax)
            {
                yMax=current.y;
            }
            if(current.x<xMin)
            {
                xMin=current.x;
            }
            if(current.y<yMin)
            {
                yMin=current.y;
            }
        }

        Rect x(Point(xMin,yMax),Point(xMax,yMin));

        rectangles.push_back(x);
        //rectangle(Icpy,Point(xMin,yMin),Point(xMax,yMax),Scalar(127));
    }
    for (unsigned int i = 0; i < rectangles.size(); i++)
    {
        for (unsigned int j = 0; j < rectangles.size(); j++)
        {
            if(i!=j)
            {
                bool intersect = ((rectangles.at(i) & rectangles.at(j) ).area()>0);
                if(intersect)
                {
                    rectangles.at(i) = rectangles.at(i) | rectangles.at(j);

                }
                else
                {
                    Point center1=center(rectangles.at(i));
                    Point center2=center(rectangles.at(j));
                    int dst = cv::norm(center1-center2);
                    if(dst < 50)
                    {
                        rectangles.at(i) = rectangles.at(i) | rectangles.at(j);

                    }
                }
            }

        }
        rectangle(*image,rectangles.at(i),Scalar(0,0,255));
    }

}

void calculHist(Mat img, int effectif[256])
{ //calculer l'histogramme
    int i,j;
    for(i=0;i<256;i++)
    {
        effectif[i]=0;
    }
    for(i=0;i<img.rows;i++)
    {
        for(j=0;j<img.cols;j++)
        {
            effectif[img.at<Vec3b>(i,j)[2]]++;
        }
    }

}

cv::Mat Chooser::shadowRemoval_HSV(cv::Mat* image,cv::Mat backGround,Chooser* c)
{
    Mat imageHSV=Mat::zeros(image->rows,image->cols,CV_8UC3);
    Mat backGroundHSV=Mat::zeros(backGround.rows,backGround.cols,CV_8UC3);
    int min = 255;
    Mat dif=Mat::zeros(image->rows,image->cols,CV_8UC3);;


    //convertir l'image d'entrée en HSV
    cvtColor(*image,imageHSV,CV_BGR2HSV);
    imageHSV.convertTo(imageHSV,CV_8UC3);
    cvtColor(backGround,backGroundHSV,CV_BGR2HSV);
    backGroundHSV.convertTo(backGroundHSV,CV_8UC3);

    absdiff(imageHSV,backGroundHSV,dif);
    //calcul de l'histogramme de valeur pour l'image de fond et l'image courante
    int effectifimg[256];
    int effectifbg[256];
    int diff[256];
    //calculer les histo de "value" pour l'image courante et le background
    calculHist(imageHSV,effectifimg);
    calculHist(backGroundHSV,effectifbg);

    //faire la difference des effictifs
    for(int i=0;i<256;i++)
    {
        diff[i]=abs(effectifimg[i]-effectifbg[i]);
    }

    //chercher le minimum de "value" pour le background
        for(int i=0;i<backGroundHSV.rows;i++)
        {
            for(int j=0;j<backGroundHSV.cols;j++)
            {
                if((backGroundHSV.at<Vec3b>(i,j)[2]) < min)
                    min=backGroundHSV.at<Vec3b>(i,j)[2];
            }
        }
//cout << min << endl;
            //chercher les zone d'ombre et les colorier en bleu
            for(int i=0;i<dif.rows;i++)
                {
                    for(int j=0;j<dif.cols;j++)
                    {
                        if((imageHSV.at<Vec3b>(i,j)[0])!=255 && (imageHSV.at<Vec3b>(i,j)[1])!=255 && (imageHSV.at<Vec3b>(i,j)[2])!=255 )
                        {

                            if((imageHSV.at<Vec3b>(i,j)[2]) - (backGroundHSV.at<Vec3b>(i,j)[2]) <= min )
                            {
                                imageHSV.at<Vec3b>(i,j)[0]=255;
                                imageHSV.at<Vec3b>(i,j)[1]=0;
                                imageHSV.at<Vec3b>(i,j)[2]=0;
                            }

                        }
                    }
                }
              //  imshow("ombre",imageHSV);

                //detecter les zone d'ombre et les eliminer (Classification des pixel)
                for(int i=0;i<dif.rows;i++)
                {
                    for(int j=0;j<dif.cols;j++)
                    {
                        if((imageHSV.at<Vec3b>(i,j)[0])==255 && (imageHSV.at<Vec3b>(i,j)[1])==0 && (imageHSV.at<Vec3b>(i,j)[2])==0 )
                        {
                             {
                                if(((imageHSV.at<Vec3b>(i,j)[2])- (backGroundHSV.at<Vec3b>(i,j)[2]) <= 10))
                                {
                                     if((imageHSV.at<Vec3b>(i,j)[2]) < (backGroundHSV.at<Vec3b>(i,j)[2]))
                                     {
                                        imageHSV.at<Vec3b>(i,j)[0]=backGroundHSV.at<Vec3b>(i,j)[0];
                                        imageHSV.at<Vec3b>(i,j)[1]=backGroundHSV.at<Vec3b>(i,j)[1];
                                        imageHSV.at<Vec3b>(i,j)[2]=backGroundHSV.at<Vec3b>(i,j)[2];
                                     }
                                }
                          }
                        }
                    }
                }
                Mat img;
                cvtColor(imageHSV,img,CV_HSV2BGR);
               // imshow("apres elimBGR",img);
                return (img);

}




cv::Mat Chooser::getMultipleImage_8UC3(std::vector<cv::Mat> &images,char* windowName,Chooser*c,bool background )
{
    Mat result;
    //Image Reading
    vector<IplImage*> iplImages;
    if(background)
    {

        for (int i = 0; i < images.size(); i++)
        {
            IplImage* tmp =  cvCreateImage(cvSize(images.at(i).cols,images.at(i).rows),8,3);
            IplImage ipltemp = images.at(i);
            cvCopy(&ipltemp,tmp);
            iplImages.push_back(tmp);
        }
        //cout << iplImages.size() << endl;
        //    IplImage* img1 = cvLoadImage( "ball.jpg" );
        //    IplImage* img2 = cvLoadImage( "ball.jpg" );
        //    IplImage* img3 = cvLoadImage( "ball.jpg" );
        //    IplImage* img4 = cvLoadImage( "ball.jpg" );
        if(iplImages.empty())
        {
            cout << "ERROR EMPTY VECTOR" << endl;
            return Mat();
        }

        int dstWidth=iplImages.at(0)->width+iplImages.at(0)->width;
        int dstHeight=iplImages.at(0)->height+iplImages.at(0)->height;

        IplImage* dst=cvCreateImage(cvSize(dstWidth,dstHeight),IPL_DEPTH_8U,3);
        cvZero(dst);
        // Copy first image to dst
        cvSetImageROI(dst, cvRect(0, 0,iplImages.at(0)->width,iplImages.at(0)->height) );
        cvCopy(iplImages.at(0),dst,NULL);
        cvResetImageROI(dst);

        // Copy second image to dst
        cvSetImageROI(dst, cvRect(iplImages.at(1)->width, 0,iplImages.at(1)->width,iplImages.at(1)->height) );
        cvCopy(iplImages.at(1),dst,NULL);
        cvResetImageROI(dst);

        // Copy third image to dst
        cvSetImageROI(dst, cvRect(0, iplImages.at(2)->height,iplImages.at(2)->width,iplImages.at(2)->height) );
        cvCopy(iplImages.at(2),dst,NULL);
        cvResetImageROI(dst);

        // Copy fourth image to dst
        cvSetImageROI(dst, cvRect(iplImages.at(3)->width, iplImages.at(3)->height,iplImages.at(3)->width,iplImages.at(3)->height) );
        cvCopy(iplImages.at(3),dst,NULL);
        cvResetImageROI(dst);
        result =cvarrToMat(dst);
        ////

    }
    else
    {

        for (int i = 0; i < images.size(); i++)
        {
            IplImage* tmp =  cvCreateImage(cvSize(images.at(i).cols,images.at(i).rows),8,3);
            IplImage ipltemp = images.at(i);
            cvCopy(&ipltemp,tmp);
            iplImages.push_back(tmp);
        }
        //cout << iplImages.size() << endl;
        //    IplImage* img1 = cvLoadImage( "ball.jpg" );
        //    IplImage* img2 = cvLoadImage( "ball.jpg" );
        //    IplImage* img3 = cvLoadImage( "ball.jpg" );
        //    IplImage* img4 = cvLoadImage( "ball.jpg" );
        if(iplImages.empty())
        {
            cout << "ERROR EMPTY VECTOR" << endl;
            return Mat();
        }

        int dstWidth=iplImages.at(0)->width;
        int dstHeight=iplImages.at(0)->height+iplImages.at(1)->height+iplImages.at(2)->height;

        IplImage* dst=cvCreateImage(cvSize(dstWidth,dstHeight),IPL_DEPTH_8U,3);
        cvZero(dst);
        // Copy first image to dst
        cvSetImageROI(dst, cvRect(0, 0,iplImages.at(0)->width,iplImages.at(0)->height) );
        cvCopy(iplImages.at(0),dst,NULL);
        cvResetImageROI(dst);

        // Copy second image to dst
        cvSetImageROI(dst, cvRect(0, iplImages.at(1)->height,iplImages.at(1)->width,iplImages.at(1)->height) );
        cvCopy(iplImages.at(1),dst,NULL);
        cvResetImageROI(dst);

        // Copy third image to dst
        cvSetImageROI(dst, cvRect(0, (iplImages.at(0)->height+iplImages.at(1)->height) ,iplImages.at(2)->width,iplImages.at(2)->height) );
        cvCopy(iplImages.at(2),dst,NULL);
        cvResetImageROI(dst);
        result =cvarrToMat(dst);

    }

    iplImages.clear();
    images.clear();
    return result;
    //    Mat res = cv::cvarrToMat(dst);
    //    Mat tmp;
    //    cvtColor(res,tmp , CV_BGR2RGB);
    //    c->ui->image_label->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));
    //    //cvWaitKey(0);

}

Mat Chooser::hist(Mat gray)
{
    bool affiche=true;
    if(gray.channels()==3)
        cvtColor(gray,gray,CV_BGR2GRAY);
    //  namedWindow( "Gray", 1 );    imshow( "Gray", gray );


    int histSize = 255;    // bin size
    float range[] = { 0, 255 };
    const float *ranges[] = { range };

    MatND hist;
    calcHist( &gray, 1, 0, Mat(), hist, 1, &histSize, ranges, true, false );

    // Show the calculated histogram in command window
    double total;
    total = gray.rows * gray.cols;
    for( int h = 0; h < histSize; h++ )
    {
        float binVal = hist.at<float>(h);
        //cout<<" "<<binVal;
    }

    // Plot the histogram
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );

    Mat histImage( hist_h, hist_w, CV_8UC1, Scalar( 0,0,0) );
    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

    for( int i = 1; i < histSize; i++ )
    {
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1)) ) ,
              Point( bin_w*(i), hist_h - cvRound(hist.at<float>(i)) ),
              Scalar( 255, 0, 0), 2, 8, 0  );
    }

    if(affiche == true)
    {
        equalizeHist(histImage,histImage);
        namedWindow( "Result", 1 );    imshow( "Result", histImage );
        waitKey(5);
    }

    else
    {
        //cv::destroyAllWindows();
    }

    return histImage;
}









void Chooser::on_exit_clicked()
{
    exit(EXIT_SUCCESS);
}






void Chooser::on_shadowToggleArith_clicked()
{
    shadowArith=!shadowArith;
    if(shadowArith)
    {
        ui->shadowToggleArith->setIcon(QIcon("Resources/Toggle On-96.png"));
        shadowArith=true;
    }
    else
    {

        ui->shadowToggleArith->setIcon(QIcon("Resources/Toggle Off.png"));
        shadowArith=false;
    }
}

void Chooser::on_shadowToggleRec_clicked()
{
    shadowRec=!shadowRec;
    if(shadowRec)
    {
        ui->shadowToggleRec->setIcon(QIcon("Resources/Toggle On-96.png"));
        shadowRec=true;
    }
    else
    {

        ui->shadowToggleRec->setIcon(QIcon("Resources/Toggle Off.png"));
        shadowRec=false;
    }
}

void Chooser::on_shadowToggleSD_clicked()
{
    shadowSD=!shadowSD;
    if(shadowSD)
    {
        ui->shadowToggleSD->setIcon(QIcon("Resources/Toggle On-96.png"));
        shadowSD=true;
    }
    else
    {

        ui->shadowToggleSD->setIcon(QIcon("Resources/Toggle Off.png"));
        shadowSD=false;
    }
}

void Chooser::on_shadowToggleSAP_clicked()
{
    shadowSAP=!shadowSAP;
    if(shadowSAP)
    {
        ui->shadowToggleSAP->setIcon(QIcon("Resources/Toggle On-96.png"));
        shadowSAP=true;
    }
    else
    {

        ui->shadowToggleSAP->setIcon(QIcon("Resources/Toggle Off.png"));
        shadowSAP=false;
    }
}
