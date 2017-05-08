#include "welcome.h"
#include "ui_welcome.h"
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
#include <QShortcut>
#include "chooser.h"
#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QThread>
#include <QMediaPlayer>
#include <QDebug>
#include <QSound>
Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    this->setFixedSize(480,640);
    paint = false;
    ui->aboutText->setVisible(false);
    aboutText="is a cross-platform application framework that is used for developing application software that can be run on various software a"
              "nd hardware platforms with little or no change in the underlying codebase, while still being a native application with native "
              "capabilities and speed. Qt is currently being developed both by The Qt Company, a company listed on the Nasdaq Helsinki Stock "
              "Exchange, and the Qt Project under open-source governance, involving individual developers and firms working to advance "
              "Qt.[10][11][12] Qt is available with both commercial[4] and open source[13] GPL 2.0, GPL 3.0, and LGPL 3.0 licenses.[5][6]";
    //QPixmap bkgnd("Resources/backgrouds/Plandetravail1VGA.png");
      //      bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        //    QPalette palette;
          //  palette.setBrush(QPalette::Background, bkgnd);
            //this->setPalette(palette);

             ui->about->setVisible(false);
             ui->about->setEnabled(false);

             ui->pushButton->setVisible(false);
             ui->pushButton->setEnabled(false);

             ui->pushButton_3->setVisible(false);
             ui->pushButton_3->setEnabled(false);

             ui->help->setVisible(false);
             ui->help->setEnabled(false);
            // w is your widget
            QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->label->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
           // PLay the sound

            QMediaPlayer *player = new QMediaPlayer;
            player->setMedia(QUrl::fromLocalFile("Resources/Sounds/soo.mp3"));
            player->setVolume(100);
            player->play();
           // end
            a->setDuration(3000);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);
            QThread::sleep(2);
            //fading away
//            ui->label->setGraphicsEffect(eff);
//            a->setDuration(2000);
//            a->setStartValue(1);
//            a->setEndValue(0);
//            a->setEasingCurve(QEasingCurve::OutBack);
//            a->start(QPropertyAnimation::DeleteWhenStopped);
            connect(a,SIGNAL(finished()),this,SLOT(hideThisWidget()));
            //connect(ui->help,SIGNAL(clicked(bool)),ui->about,SLOT(click()));
            // now implement a slot called hideThisWidget() to do
            // things like hide any background dimmer, etc.

//            ui->about->setVisible(true);
//            ui->about->setEnabled(true);

//            ui->pushButton->setVisible(true);
//            ui->pushButton->setEnabled(true);

//            ui->pushButton_3->setVisible(true);
//            ui->pushButton_3->setEnabled(true);

}
void Welcome::hideThisWidget()
{
                ui->about->setVisible(true);
                ui->about->setEnabled(true);

                ui->pushButton->setVisible(true);
                ui->pushButton->setEnabled(true);

                ui->pushButton_3->setVisible(true);
                ui->pushButton_3->setEnabled(true);

                ui->help->setVisible(true);
                ui->help->setEnabled(true);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_pushButton_3_clicked()
{

    x.show();
}

void Welcome::on_about_clicked(bool checked)
{
    paint = !paint;
    if(paint)
    {
        ui->aboutText->setVisible(true);
        ui->aboutText->raise();
        ui->aboutText->setEnabled(true);
        ui->aboutText->setText(aboutText);
    }
    else
    {
        ui->aboutText->setVisible(false);
        ui->aboutText->lower();
        ui->aboutText->setEnabled(false);
    }

}

void Welcome::on_pushButton_clicked()
{
    exit(EXIT_SUCCESS);
}

void Welcome::paintEvent(QPaintEvent *e)
{
}
