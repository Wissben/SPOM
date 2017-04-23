#include "selector.h"
#include "ui_selector.h"
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
#include "method.h"
#include "selector.h"
#include <QWidget>

using namespace std;
using namespace cv;

Selector::Selector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Selector)
{
    QPixmap bkgnd("backgrouds/bggris.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    ui->setupUi(this);
    ui->horizontalSlider->setMaximum(1000);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setValue(50);
    ui->multipleChooser->setValue(1);
    ui->alphaValue->setPalette(Qt::black);
    ui->alphaValue->display(50);
    ui->backgroundProgress->setValue(0);
    /***************************/
    QObject::connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->alphaValue,SLOT(display(int)));
}

Selector::~Selector()
{
    delete ui;
}

void Selector::on_gradiantOublieux_toggled(bool checked)
{
   if(checked)
   {
       ui->gradiantOublieux->setCheckable(false);
       ui->gradiantOublieux->setCheckable(true);
       QString filename = QFileDialog::getOpenFileName(this,
           tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
       if(filename !=NULL)
       Method::gradiantOublieux(filename.toStdString(),(float) ui->horizontalSlider->value()/1000);
   }
}

void Selector::on_moyenneRecurssive_toggled(bool checked)
{
    if(checked)
    {
        ui->moyenneRecurssive->setCheckable(false);
        ui->moyenneRecurssive->setCheckable(true);
        QString filename = QFileDialog::getOpenFileName(this,
            tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
        if(filename !=NULL)
        Method::moyenne_Reccur(filename.toStdString(),(float) ui->horizontalSlider->value()/1000,this);
    }

}

void Selector::on_moyenneArith_toggled(bool checked)
{
    if(checked)
    {
        ui->moyenneArith->setCheckable(false);
        ui->moyenneArith->setCheckable(true);
        QString filename = QFileDialog::getOpenFileName(this,
            tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
        if(filename !=NULL)
         Method::moyenne_Arith(filename.toStdString(),this);
    }
}

void Selector::on_moyenneSD_toggled(bool checked)
{
   if(checked)
   {
       ui->moyenneSD->setCheckable(false);
       ui->moyenneSD->setCheckable(true);
       QString filename = QFileDialog::getOpenFileName(this,
           tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
       if(filename !=NULL)
       Method::SD2(filename.toStdString(),ui->multipleChooser->value());
   }
}



void Selector::on_SAP_toggled(bool checked)
{
    if(checked)
    {
        ui->SAP->setCheckable(false);
        ui->SAP->setCheckable(true);
        QString filename = QFileDialog::getOpenFileName(this,
            tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
        if(filename !=NULL)
        Method::SAP(filename.toStdString(),ui->multipleChooser->value(),(float) ui->horizontalSlider->value()/1000,this);

    }
}

void Selector::on_quitSelector_clicked()
{
    this->close();
    exit(EXIT_SUCCESS);
}

