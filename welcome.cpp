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

Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
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

}
