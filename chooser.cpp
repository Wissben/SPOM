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
#include "qprogressbar.h"
#include "qthread.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QTimer>


using namespace std;
using namespace cv;

Chooser::Chooser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chooser)
{
    bool onPause=false;
    ui->setupUi(this);
    //setting up Gradiant
    std::string str;
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

    ui->labelGradAlpha->setToolTip("Alpha est le paramètre d'oublis");

    gradIndex=0;
    arithIndex=0;
    recIndex=0;
    SDIndex=0;
    SAPIndex=0;

    ui->control->setEnabled(false);
    ui->controlArith->setEnabled(false);

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

void Chooser::on_recChooser_clicked()
{

    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
    if(filename !=NULL)
    {
        Chooser::moyenne_Reccur(filename.toStdString(),(float) ui->alphaChooserRec->value()/1000,this);
        //ui->
    }
}


void Chooser::updateRec()
{

}


void Chooser::on_gradiantChooser_clicked()
{
    timerGrad = new QTimer(this);
    connect(timerGrad,SIGNAL(timeout()),this,SLOT(updateGrad()));
    gradFramesFore.clear();
    gradFramesMask.clear();
    gradFramesOriginal.clear();
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
    if(filename !=NULL)
    {
        Chooser::gradiantOublieux(filename.toStdString(),(float) ui->alphaChooserGrad->value()/1000,this);

        ui->control->setEnabled(true);
        timerGrad->start(30);
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

    gradIndex++;
    if(gradIndex>=gradFramesFore.size() || gradIndex>=gradFramesOriginal.size() || gradIndex>=gradFramesMask.size())
    {
        gradIndex=0;
        timerGrad->stop();
        ui->control->setEnabled(false);
    }

}


void Chooser::on_control_clicked(bool checked)
{
    if(timerGrad->isActive())
    {
        timerGrad->stop();
    }
    else
    {
        timerGrad->start(30);
    }
}


void Chooser::on_alphaChooserGrad_valueChanged(int value)
{
    std::string str;
    str = std::to_string((float)value/1000).substr(0,5);//"0,"+toString(ui->alphaChooserRec->value());
    QString tmp = QString(str.c_str());
    ui->labelGradAlphaValue->setText(tmp);
}

void Chooser::on_horizontalSlider_valueChanged(int value)
{
    //std::cout << ui->horizontalSlider->value();
}

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
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
    if(filename !=NULL)
    {
        Chooser::moyenne_Arith(filename.toStdString(),this);
        ui->controlArith->setEnabled(true);
        timerArith->start(30);
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

            tmp=arithFramesBack.at(arithIndex);
            ui->arith_image_label_foreground->setPixmap(QPixmap::fromImage(QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888)));

            //QThread::msleep(100);
            //QTest::qSleep(100);

    arithIndex++;
    if(arithIndex>=arithFramesFore.size() || arithIndex>=arithFramesOriginal.size() || arithIndex>=arithFramesMask.size() || arithIndex>=arithFramesBack.size())
    {
        arithIndex=0;
        timerArith->stop();
        ui->controlArith->setEnabled(true);
    }
}


void Chooser::on_controlArith_clicked(bool checked)
{
    if(timerArith->isActive())
    {
        timerArith->stop();
    }
    else
    {
        timerArith->start(30);
    }
}



void Chooser::on_SAPChooser_clicked(bool checked)
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "", tr("Image Files (*.avi *.mp4)"));
    if(filename !=NULL)
        Chooser::SAP(filename.toStdString(),ui->multipleChooser->value(),ui->alphaChooserSAP->value(),this);
}

void Chooser::updateSAP()
{

}

void Chooser::on_SDChooser_clicked(bool checked)
{

}

void Chooser::updateSD()
{

}

/////////////////////////////////////
/// function de traitements opencv///
/////////////////////////////////////

using namespace   std;
using namespace cv;


void Chooser::moyenne_Reccur(string path, double alpha,Chooser* c)
{
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
    while (vc.get(CV_CAP_PROP_POS_FRAMES)<= vc.get(CV_CAP_PROP_FRAME_COUNT))
    {
        frame = vc.get(CV_CAP_PROP_POS_FRAMES);
        p=(int) frame*100/max;
        c->ui->backgroundProgressRec->setValue(p);
        //M= alpha*I+(1-alpha)M1 ;
        vc >> I; // Lire le frame courant dans l'image I
        //cout << I;
        //M1.convertTo(M1, CV_32FC3);
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
    //imshow("backGround", M);//Affichage de la matrice M
    //moveWindow("backGround",initX+original.cols,initY);
    //waitKey(0);
    cvtColor(M, M, COLOR_BGR2GRAY);//Convertion de l'espace de couleur de la matrice M de RGB en GrayScale
    VideoCapture v(path);//Creation d'un autre objet de lecture de video.
    while (v.get(CV_CAP_PROP_POS_FRAMES) <= v.get(CV_CAP_PROP_FRAME_COUNT)) // Tant que la video n'est pas finie
    {
        Mat foreground = Mat::zeros(M.rows,M.cols,CV_8UC3);
        v >> original;
        if (original.empty())
            break;//Si le frame est vide on sort de la boucle
        original.copyTo(I);//Copie de l'image originale pour de futurs traitements
        //        imshow("Original", original);
        //        moveWindow("Original",initX,initY);
        cvtColor(I, I, COLOR_BGR2GRAY);
        absdiff(I, M, I);//equivalent a I=M-I
        threshold(I, I, 50, 255, THRESH_BINARY);//Suillage statique d'une valeur d'intensité = 45
        cv::erode(I,I,Mat());//Une erosion
        cv::dilate(I,I,Mat());//Une dilatation
        //cv::erode(I,I,Mat());
        //cv::dilate(I,I,Mat());
        original.convertTo(original,CV_8UC3);//Dunno what to do with that maybe it's useless
        I.convertTo(I,CV_8U);
        Mat I8UC3;
        cvtColor(I,I8UC3,COLOR_GRAY2BGR);
        I8UC3.convertTo(I8UC3,CV_8UC3);
        foreground=Chooser::getForeGroundRGB_8UC3(original,I); // Appel a la fonction qui retourne l'avant plan
        Chooser::drawBoxesRGB_8UC3(&original,I);//Appel a la methode qui permet de dessiner les boites englobantes
        Chooser::drawBoxesRGB_8UC3(&foreground,I);//Appel a la methode qui permet de dessiner les boites englobantes
        images.push_back(original);
        images.push_back(foreground);
        images.push_back(I8UC3);
        //showMultipleImage_8UC3(images,"Results",c);
        //imshow("forground",foreground);
        //imshow("Masque", I);
        imshow("hist",hist(I8UC3));
        if(waitKey(0)=='\33')
        {
            destroyAllWindows();
            return;

        }
    }
    v.release();
    if(waitKey(0)=='\33')
    {
        destroyAllWindows();
        return;

    }
}


//////////////////////////
/////////////////////////////::


void Chooser::gradiantOublieux(string pathToVideo , double alpha,Chooser* c)
{

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
    while (capture.get(CV_CAP_PROP_POS_FRAMES)<=capture.get(CV_CAP_PROP_FRAME_COUNT))
    {
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
            threshold(mask, mask, 45, 255, THRESH_BINARY);

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
        if(waitKey(10)=='\33')
        {
            destroyAllWindows();
            return;

        }

    }
//    imshow("fore",c->gradFramesFore.at(0));
//    imshow("mask",c->gradFramesMask.at(0));
//    imshow("ori",c->gradFramesOriginal.at(0));
//    waitKey(0);
    capture.release();
    if(waitKey(0)=='\33')
    {
        destroyAllWindows();
        return;

    }


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
    Mat background;
    Mat X;
    Mat foreGround;
    VideoCapture v(path);
    Mat backGroundGray;
    Mat original;
    double Rnorme;
    Mat foreGroundGray;
    vector<Mat> images;

    background = Chooser::getBackGroundRGB_8UC3(path,c->ui->backgroundProgressArith);
    background.convertTo(background, CV_8UC3);

    cvtColor(background, backGroundGray, COLOR_BGR2GRAY);
    backGroundGray.convertTo(backGroundGray, CV_32F);
    Mat diff = Mat::zeros(background.rows,background.cols,CV_32F);
    while (v.get(CV_CAP_PROP_POS_FRAMES) <= v.get(CV_CAP_PROP_FRAME_COUNT))
    {
        v >> X;
        if (!X.empty())
        {
            //Mat nonShadow = Chooser::shadowRemoval_HSV(&X,tmp,s);
            //imshow("nonshadow",nonShadow);
            X.copyTo(original);
            cvtColor(X, X, COLOR_BGR2GRAY);
            X.convertTo(X, CV_32F);
            cout << v.get(CV_CAP_PROP_POS_FRAMES) << "/" << v.get(CV_CAP_PROP_FRAME_COUNT) << endl;
            absdiff(X, backGroundGray, diff);
            threshold(diff, diff, 30, 255, THRESH_BINARY);
            cv::erode(diff, diff, Mat());
            cv::dilate(diff, diff, Mat());
            diff.convertTo(diff,CV_8U);
            foreGround = Chooser::getForeGroundRGB_8UC3(original,diff);
            foreGround.convertTo(foreGround, CV_32FC3);
            cvtColor(foreGround, foreGroundGray, COLOR_BGR2GRAY);
            foreGroundGray.convertTo(foreGroundGray, CV_32F);
            //original=shadowRemoval_HSV(&original,background,c);
            //imshow("without shadow ",original);
            waitKey(0);
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

            Mat backRGB;
            cvtColor(background,backRGB , CV_BGR2RGB);
            c->arithFramesBack.push_back(backRGB);


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
    while (vc.get(CV_CAP_PROP_POS_FRAMES) <= vc.get(CV_CAP_PROP_FRAME_COUNT))
    {
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

    for (int i = 0; i < Moy.rows; ++i)
    {
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
    }
    vc.release();
    Moy.convertTo(Moy,CV_8UC3);
    //imshow("MoyenneCoulour",Moy);
    Moy.convertTo(Moy,CV_32SC3);
    mask = Mat::zeros(Moy.size(),CV_32SC3);
    VideoCapture capt(path);
    if (!capt.isOpened())// check if we succeeded
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    while (capt.get(CV_CAP_PROP_POS_FRAMES) <= capt.get(CV_CAP_PROP_FRAME_COUNT))
    {
        capt >> I;
        if (!I.empty())
        {
            //           Mat IGray;
            //Mat Icpy;
            I.copyTo(Icpy);
            images.push_back(Icpy);
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
            Mat maskGray;
            cvtColor(mask,maskGray,COLOR_BGR2GRAY);
            Mat foreGround = Mat::zeros(maskGray.rows,maskGray.cols,CV_8UC3);
            Chooser::drawBoxesRGB_8UC3(&Icpy,mask);
            foreGround = Chooser::getForeGroundRGB_8UC3(I,maskGray);
            /////
            Chooser::drawBoxesRGB_8UC3(&foreGround,mask);
            images.push_back(foreGround);
            images.push_back(mask);
            //imshow("original",Icpy);
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
            ////
            mask.convertTo(mask,CV_32SC3);
            Moy.convertTo(Moy,CV_8UC3);
            //imshow("foreground",foreGround);
            //Chooser::showMultipleImage_8UC3(images,"Results",c);
            images.clear();
            if(waitKey(0)=='\33')
            {
                destroyAllWindows();
                return;

            }
            Moy.convertTo(Moy,CV_32SC3);


        }
        else
        {
            cout << "ERROR EMPTY FRAME" << endl;
            break;
        }
    }
    capt.release();
    destroyAllWindows();
    if(waitKey(0)=='\33')
    {
        destroyAllWindows();
        return;

    }
}



void Chooser::SD2(std::string path,int mul)
{
    Mat X;
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
    vector<Mat> images;
    while (capt.get(CV_CAP_PROP_POS_FRAMES) <= capt.get(CV_CAP_PROP_FRAME_COUNT))
    {
        capt >> I;
        if (!I.empty())
        {

            I.copyTo(original);
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

                    if( O.at<uchar>(i,j)!=0)
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
            images.push_back(original);
            images.push_back(foreGround);
            //imshow("M(t)",M);
            //imshow("V",V);
            Mat E8UC3;
            cvtColor(E,E8UC3,COLOR_GRAY2BGR);
            E8UC3.convertTo(E8UC3,CV_8UC3);
            images.push_back(E8UC3);
            //showMultipleImage_8UC3(images,"Results");
            cout << capt.get(CV_CAP_PROP_POS_FRAMES) << "/" << capt.get(CV_CAP_PROP_FRAME_COUNT) << endl;
            if(waitKey(0)=='\33')
            {
                destroyAllWindows();
                return;

            }
        }
        else
        {
            cout << "ERROR EMPTY FRAME" << endl;
            break;
        }
    }
    if(waitKey(0)=='\33')
    {
        destroyAllWindows();
        return;

    }
}


cv::Mat Chooser::getBackGroundRGB_8UC3(std::string path,QProgressBar* s)
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
        frame = vc.get(CV_CAP_PROP_POS_FRAMES);
        p=(int) frame*100/max;
        s->setValue(p);
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


    //cheat begin
    if(s->value()<100)
    {
        s->setValue(100);
    }
    //cheat end


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

    //colorier les pixel de difference en blanc I.e : la personne sera en blanc (seuilage classique quoi -_- )
    //            for(int i=0;i<dif.rows;i++)
    //            {
    //                for(int j=0;j<dif.cols;j++)
    //                {
    //                    if((dif.at<Vec3b>(i,j)[2])>min)
    //                    {
    //                        imageHSV.at<Vec3b>(i,j)[0]=255;
    //                        imageHSV.at<Vec3b>(i,j)[1]=255;
    //                        imageHSV.at<Vec3b>(i,j)[2]=255;
    //                    }
    //                }
    //            }
    imshow("personnes",imageHSV);
    //chercher les zone d'ombre et les colorier en bleu
    for(int i=0;i<dif.rows;i++)
    {
        for(int j=0;j<dif.cols;j++)
        {
            if((imageHSV.at<Vec3b>(i,j)[0])!=255 && (imageHSV.at<Vec3b>(i,j)[1])!=255 && (imageHSV.at<Vec3b>(i,j)[2])!=255 )
            {
                if(((backGroundHSV.at<Vec3b>(i,j)[2]))>(imageHSV.at<Vec3b>(i,j)[2])) //verifier si fidderence > au seuil 10 alors colorier cette zonne en bleu
                {
                    imageHSV.at<Vec3b>(i,j)[0]=0;
                    imageHSV.at<Vec3b>(i,j)[1]=0;
                    imageHSV.at<Vec3b>(i,j)[2]=0;
                }
            }
        }
    }
    imshow("ombre",imageHSV);

    //detecter les zone d'ombre et les eliminer
    for(int i=0;i<dif.rows;i++)
    {
        for(int j=0;j<dif.cols;j++)
        {
            if((imageHSV.at<Vec3b>(i,j)[0])==0 && (imageHSV.at<Vec3b>(i,j)[1])==0 && (imageHSV.at<Vec3b>(i,j)[2])==0 )
            {
                imageHSV.at<Vec3b>(i,j)[0]=backGroundHSV.at<Vec3b>(i,j)[0];
                imageHSV.at<Vec3b>(i,j)[1]=backGroundHSV.at<Vec3b>(i,j)[1];
                imageHSV.at<Vec3b>(i,j)[2]=backGroundHSV.at<Vec3b>(i,j)[2];
            }
        }
    }
    imshow("elimination",imageHSV);

    //cvtColor(imageHSV,*image,CV_BGR2HSV);
    //apres elimination
    for(int i=0;i<dif.rows;i++)
    {
        for(int j=0;j<dif.cols;j++)
        {
            if((imageHSV.at<Vec3b>(i,j)[0])!=255 && (imageHSV.at<Vec3b>(i,j)[1])!=255 && (imageHSV.at<Vec3b>(i,j)[2])!=255 )
            {
                if(((backGroundHSV.at<Vec3b>(i,j)[2])>(imageHSV.at<Vec3b>(i,j)[2])+10))
                {
                    imageHSV.at<Vec3b>(i,j)[0]=0;
                    imageHSV.at<Vec3b>(i,j)[1]=0;
                    imageHSV.at<Vec3b>(i,j)[2]=0;
                }
            }
        }
    }
    Mat img;
    cvtColor(imageHSV,img,CV_HSV2BGR);
    imshow("apres elim",imageHSV);
    cvtColor(imageHSV,img,CV_HSV2BGR);
    imshow("apres elimBGR",img);
    return (imageHSV);
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





