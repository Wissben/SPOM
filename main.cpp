#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>     
#include <stdint.h>
#include "mainwindow.h"
#include <QApplication>
#include "chooser.h"
#include "welcome.h"
using namespace std;
using namespace cv;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

//    Chooser x;
//    x.show();
////    MainWindow w;
////    w.show();

    Welcome x;
    x.show();
    return a.exec();
}

