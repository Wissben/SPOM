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
#include "method.h"
#include "selector.h"
#include <QWidget>
#include <string>
#include <QString>
#include "mymath.h"
Chooser::Chooser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chooser)
{
    ui->setupUi(this);
    //setting up Gradiant
    std::string str;
    str = "0,"+toString(ui->alphaChooserGrad->value());
    QString tmp = QString(str.c_str());
    ui->labelGradAlphaValue->setText(tmp);
    //end of setting

    //setting up recur
    str = "0,"+toString(ui->alphaChooserRec->value());
    tmp = QString(str.c_str());
    ui->labelRecAlphaValue->setText(tmp);
    //end of setting

}

Chooser::~Chooser()
{
    delete ui;
}

void Chooser::on_gradiantMorph_clicked()
{
    //ui->verticalWidget->lower();
    ui->tabWidget->setVisible(true);
    ui->tabWidget->setEnabled(true);

}

void Chooser::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
    if(filename != NULL)
    {
        //Method::gradiantOublieux(filename.toStdString(),0.2f);

    }
}

void Chooser::on_alphaChooserSAP_valueChanged(int value)
{
    std::string str;
    str = "0,"+toString(ui->alphaChooserSAP->value());
    QString tmp = QString(str.c_str());
    ui->labelSAPAlphaValue->setText(tmp);
}


void Chooser::on_alphaChooserRec_valueChanged(int value)
{
    std::string str;
    str = "0,"+toString(ui->alphaChooserRec->value());
    QString tmp = QString(str.c_str());
    ui->labelRecAlphaValue->setText(tmp);
}

void Chooser::on_recChooser_clicked()
{

}

void Chooser::on_gradiantChooser_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
    if(filename !=NULL)
    Method::gradiantOublieux(filename.toStdString(),(float) ui->alphaChooserGrad->value()/1000,this);
}

void Chooser::on_alphaChooserGrad_valueChanged(int value)
{
    std::string str;
    str = "0,"+toString(value);
    QString tmp = QString(str.c_str());
    ui->labelGradAlphaValue->setText(tmp);
}
