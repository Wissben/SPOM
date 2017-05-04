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
#include <QShortcut>

using namespace std;
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("backgrouds/bgblue.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    //this->setStyleSheet("background: url(backgrouds/bggris.png);");
        capWebcam.open(0);

            if(capWebcam.isOpened())
                cout << "webcam ok";


            QTimer *tmrTimer = new QTimer(this);
            connect(tmrTimer,SIGNAL(timeout()),this, SLOT(processFrameAndUpdateGUI()));
            tmrTimer->start(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    this->selector.show();


}

void MainWindow::on_pushButton_2_clicked()
{
    exit(EXIT_SUCCESS);
}

void MainWindow::processFrameAndUpdateGUI(){

    capWebcam.read(matWebcam);
    if(matWebcam.empty())
        cout << "matWebcam empty";

    QImage qimgWebcam(matWebcam.data,matWebcam.cols, matWebcam.step, QImage::Format_RGB888);
    //ui->label->setPixmap(QPixmap::fromImage(qimgWebcam));
}
