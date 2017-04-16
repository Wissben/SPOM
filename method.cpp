#include "method.h"
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
#include "mymath.h"
using namespace   std;
using namespace cv;

Method::Method()
{

}


void Method::moyenne_Reccur(string path, float alpha)
{
    int thresh = 30; // variable pour le seuil
    VideoCapture vc(path); // objet de la classe VideoCapture qui permettra de lire la video
    int initX=20; //position initiale sur X
    int initY=500; // position initiale sur Y
    Mat M = Mat::zeros(1, 1, CV_32FC3); // Objet de la classe Mat qui contiendra la moyenne finale
    Mat I = Mat::zeros(1, 1, CV_32FC3); // Objet de la classe Mat qui contiendra l'image courante
    Mat V = Mat::zeros(1,1,CV_64FC3);
    Mat temp; //Objet de la classe Mat qui contiendra une image temporaire
    vc >> M; // on lit le premier frame et on le met dans la matrice M
    M.copyTo(V);
    M.convertTo(M, CV_64FC3);// convertir la matrice pour que chaque element soit de type Vec3d c'est a dire un vecteur de 3 nombre double
    //    M = alpha*M; // ini
    //    M.copyTo(M1);
    if (!vc.isOpened())// check if we succeeded
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    while (vc.get(CV_CAP_PROP_POS_FRAMES)< vc.get(CV_CAP_PROP_FRAME_COUNT))
    {
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
        //V = alpha*V + (1 - alpha)*(M - I)*(M - I);
        //M = alpha*(I-M)+M;
        //M.convertTo(M, CV_32FC3);
        //cvtColor(M, M, COLOR_BGR2HSV);
        //cvtColor(I, I, COLOR_BGR2HSV);
        M.convertTo(temp, CV_8UC3);//convertir la matrice pour que chaque element soit de type Vec3b c'est a dire un vecteur de 3 nombre entier non signés
        imshow("M", M); // afficher l'image
        M.convertTo(M, CV_64FC3); // reconvertir l'image pour la réutilisation dans l'ittération suivante
    }
    //cv::sqrt(V,V);
    //V.convertTo(V,CV_8UC3);
    //cvtColor(V,V,COLOR_BGR2GRAY);
    vc.release(); // dès qu'on termine le parcours de la vidéo on libère l'objet VideoCapture
    Mat original = Mat::zeros(M.rows,M.cols,CV_8UC3);//Matrice qui contiendra l'image original
    M.convertTo(M, CV_8UC3);//conversion
    imshow("backGround", M);
    moveWindow("backGround",initX+original.cols,initY);
    waitKey(0);
    cvtColor(M, M, COLOR_BGR2GRAY);
    VideoCapture v(path);
    while (v.get(CV_CAP_PROP_POS_FRAMES) <= v.get(CV_CAP_PROP_FRAME_COUNT))
    {
        Mat foreground = Mat::zeros(M.rows,M.cols,CV_8UC3);
        v >> original;
        if (original.empty())
            break;
        original.copyTo(I);
        imshow("Original", original);
        moveWindow("Original",initX,initY);
        cvtColor(I, I, COLOR_BGR2GRAY);
        absdiff(I, M, I);
        threshold(I, I, 45, 255, THRESH_BINARY);
        cv::erode(I,I,Mat());
        cv::dilate(I,I,Mat());
        //cv::erode(I,I,Mat());
        //cv::dilate(I,I,Mat());
        original.convertTo(original,CV_8UC3);
        I.convertTo(I,CV_8U);
        for (int i = 0; i < I.rows; i++) {
            for (int j = 0; j < I.cols; j++) {

                if (I.at<uchar>(i,j)==255)
                {
                    foreground.at<Vec3b>(i,j)[0]=original.at<Vec3b>(i,j)[0];
                    foreground.at<Vec3b>(i,j)[1]=original.at<Vec3b>(i,j)[1];
                    foreground.at<Vec3b>(i,j)[2]=original.at<Vec3b>(i,j)[2];

                }

            }
        }
        vector<vector<Point> > contours;
        vector<Vec4i> hierarchy;
        Mat Igray;
        I.copyTo(Igray);
        //cvtColor(finMask, fingray, COLOR_BGR2GRAY);
        Igray.convertTo(Igray, CV_8UC1);
        Canny(Igray, Igray, 30, 30 * 2, 3);
        findContours(Igray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_TC89_KCOS, Point(0,0));
        //cout << contours.at(0) << "\nend\n";
        for (int i = 0; i < contours.size(); ++i)
        {
            Point p=(contours.at(i)).at(0);
            int xMax=p.x;
            int yMax=p.y;
            int xMin=p.x;
            int yMin=p.y;
            for (int j = 0; j < contours.at(i).size(); ++j)
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

            rectangle(foreground,Point(xMin,yMin),Point(xMax,yMax),Scalar(127));
        }
        imshow("forground",foreground);
        //cv::erode(I, I,Mat());
        //Laplacian(temp, neo, CV_16S, 1, 1, 0, BORDER_DEFAULT);
        //convertScaleAbs(neo, neo);
        //imshow("neo", neo);
        //waitKey(1);
        //cvtColor(neo, neo, COLOR_BGR2GRAY);
        //bitwise_and(I, neo, neo);
        imshow("Masque", I);
        //cv::moveWindow("final",initX+2*original.cols,initY);
        waitKey(0);
    }
    v.release();
    destroyAllWindows();
    
}


//////////////////////////


void Method::laplace(string path)
{
    Mat diff;
    int kernel_size = 1;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    VideoCapture vc(path);

    if (!vc.isOpened())// check if we succeeded
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    for (;;)
    {
        while (vc.get(CV_CAP_PROP_POS_FRAMES) < vc.get(CV_CAP_PROP_FRAME_COUNT))
        {
            vc >> diff;
            cvtColor(diff, diff, COLOR_BGR2GRAY);
            Mat abs;
            Laplacian(diff, abs, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
            convertScaleAbs(abs, abs);
            imshow("", abs);
            waitKey(1);
        }
        vc.release();
    }
    destroyAllWindows();
    
}


/////////////////////////////::


void Method::gradiantOublieux(string pathToVideo , float alphaDeb)
{

    cout << "alpha:" << alphaDeb << endl;
    Mat X, Y, M, m, prev;// = Mat::zeros(1, 1, CV_32FC3), M = Mat::zeros(1, 1, CV_32FC3), m = Mat::zeros(1, 1, CV_32FC3), Y = Mat::zeros(1, 1, CV_32FC3), Prev = Mat::zeros(1, 1, CV_32FC3);
    Mat original;
    int cpt = 0;
    double alpha = alphaDeb;
    bool pause = false;
    while (1)
    {
        alpha = alphaDeb;
        VideoCapture capture(pathToVideo); // open the video specified in the variable pathToVideo
        if (!capture.isOpened())// check if we succeeded
        {
            cout << "Error while opening video " << endl;
            exit(EXIT_FAILURE);
        }
        capture >> original;
        if(original.empty())
            break;
        original.copyTo(X);
        Mat fin;// = Mat::zeros(X.rows, X.cols, CV_8UC3);
        X.copyTo(M);
        X.copyTo(m);
        Mat previous;
        X.copyTo(previous);
        Mat diff;
        while (capture.get(CV_CAP_PROP_POS_FRAMES)<capture.get(CV_CAP_PROP_FRAME_COUNT))
        {
            Mat finMask;
            if (!X.empty() && !M.empty() && !m.empty() && !original.empty() )
            {
                fin = Mat::zeros(X.rows, X.cols, CV_8UC3);
                //begin Successive substraction
                Mat Xgray;
                capture >> Xgray;
                if(Xgray.empty())
                    break;
                diff = Xgray - previous;
                cvtColor(diff, diff, COLOR_BGR2GRAY);
                threshold(diff, diff, 40, 255, THRESH_BINARY);
                imshow("diff", diff);
                moveWindow("diff",100,100);
                Xgray.copyTo(previous);
                //end Successive substraction


                //begin main function
                capture >> original;
                if(original.empty())
                    break;
                //waitKey(1);
                original.copyTo(X);
                X.convertTo(X, CV_32FC3);
                M.convertTo(M, CV_32FC3);
                m.convertTo(m, CV_32FC3);
                Mat maxM;
                maxM = max(X, M);
                M = alpha*X + (1 - alpha)*maxM;
                Mat minm;
                minm = min(X, m);
                m = alpha*X + (1 - alpha)*minm;
                finMask = M - m;
                cvtColor(finMask, finMask, COLOR_BGR2GRAY);
                double min, max;
                cv::minMaxLoc(finMask, &min, &max);
                threshold(finMask, finMask, 40, 255, THRESH_BINARY);
                //vector<Point2f> points = { Point(0,0),Point(1,0),Point(1,1) };
                //cout << points;
                //cv::dilate(finMask, finMask, Mat());
                finMask.convertTo(finMask, CV_8U);
                fin=Method::getForeGroundRGB_8UC3(original,finMask);
                /*for (int i = 0; i < finMask.rows; i++)
                {
                    for (int j = 0; j < finMask.cols; j++)
                    {

                        if (finMask.at<uchar>(i, j) ==255)
                        {
                            fin.at<cv::Vec3b>(i, j)[0] = original.at<Vec3b>(i, j)[0];
                            fin.at<cv::Vec3b>(i, j)[1] = original.at<Vec3b>(i, j)[1];
                            fin.at<cv::Vec3b>(i, j)[2] = original.at<Vec3b>(i, j)[2];

                        }
                    }
                }
                */
                Method::drawBoxesRGB_8UC3(&original,finMask);
                /*
                vector<vector<Point> > contours;
                vector<Vec4i> hierarchy;
                Mat fingray;
                finMask.copyTo(fingray);
                //cvtColor(finMask, fingray, COLOR_BGR2GRAY);
                fingray.convertTo(fingray, CV_8UC1);
                Canny(fingray, fingray, 30, 30 * 2, 3);
                findContours(fingray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_TC89_KCOS, Point(0, 0));
                //cout << contours.at(0) << "\nend\n";
                Mat drawing = Mat::zeros(fin.size(), CV_8UC3);
                RNG rng(12345);
                for (int i = 0; i< contours.size(); i++)
                {
                    Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
                    drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
                }

                for (int var = 0; var < contours.size(); ++var)
                {
                    Point p=(contours.at(var)).at(0);
                    int xMax=p.x;
                    int yMax=p.y;
                    int xMin=p.x;
                    int yMin=p.y;
                    for (int j = 0; j < contours.at(var).size(); ++j)
                    {
                        Point current=(contours.at(var)).at(j);
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

                    rectangle(fin,Point(xMin,yMin),Point(xMax,yMax),Scalar(127));
                }
                */

                //imshow("Contours", drawing);
            }
            else
            {
                cout << "ERROR EMPTY FRAME" << endl;
                break;
            }

            imshow("original", original);
            imshow("fin", finMask);
            imshow("FINAL", fin);
            waitKey(0);
            //QWidget *q = (QWidget*) cvGetWindowHandle("fin");
        }
        capture.release();
    }
    destroyAllWindows();
    
}

//////////////////////

void Method::sigmaDelta(string path)
{
    VideoCapture vc(path);
    Mat X;
    Mat M;
    RNG rng(10);
    int N = 2;
    if (!vc.isOpened())// check if we succeeded
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    vc >> X;
    X.convertTo(X, CV_32FC3);
    X.copyTo(M);
    //// get the average
    while (vc.get(CV_CAP_PROP_POS_FRAMES) < vc.get(CV_CAP_PROP_FRAME_COUNT))
    {
        //cout << vc.get(CV_CAP_PROP_POS_FRAMES) << "/" << vc.get(CV_CAP_PROP_FRAME_COUNT) << endl;
        vc >> X;
        if (!X.empty() && !M.empty())
        {
            X.convertTo(X, CV_32FC3);
            M += X;
            //imshow("final", tmp);
            //waitKey(1);
        }
        else
        {
            cout << "EMTPY FRAME " << endl;
            break;
        }

    }
    M /= vc.get(CV_CAP_PROP_FRAME_COUNT);
    M.convertTo(M,CV_8UC3);
    cvtColor(M, M, COLOR_BGR2GRAY);
    vc.release();
    namedWindow("BackGround",WINDOW_AUTOSIZE);
    imshow("BackGround",M);
    moveWindow("BackGround",100,0);
    waitKey(0);
    M.convertTo(M,CV_8SC3);
    ///////////////////
    VideoCapture capt(path);
    if (!capt.isOpened())
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    Mat delta = Mat::zeros(M.rows, M.cols, CV_8SC1);
    Mat I;
    Mat M0;
    Mat V= Mat::zeros(M.rows,M.cols,CV_8SC1);
    Mat D=Mat::zeros(M.rows,M.cols,CV_8U);
    M.convertTo(M, CV_8SC1);
    capt >> M0;
    cvtColor(M0,M0,COLOR_BGR2GRAY);
    M0.convertTo(M0,CV_8SC1);
    while (capt.get(CV_CAP_PROP_POS_FRAMES) < capt.get(CV_CAP_PROP_FRAME_COUNT))
    {
        capt >> I;
        if (!I.empty())
        {
            imshow("Original",I);
            moveWindow("Originale",500,-250);
            cvtColor(I, I, COLOR_BGR2GRAY);
            //cout << I.channels() << endl;
            I.convertTo(I, CV_8SC1);
            //cout << M.type() << " and " << I.type() << endl;
            delta = M-I;
            delta.convertTo(delta,CV_8U);
            imshow("delta",delta);
            waitKey(0);
            delta.convertTo(delta,CV_8SC1);
            N= 4;
            cout << N << endl;
            for(int i = 0; i < I.rows; i++)
            {
                for (int j = 0; j < I.cols; j++)
                {
                    //cout << delta.at<int8_t>(i, j) <<endl;
                    if (delta.at<int8_t>(i, j) < 0)
                    {
                        M0.at<int8_t>(i,j) = M0.at<int8_t>(i,j) + 1;
                    }
                    if (delta.at<int8_t>(i, j) > 0)
                    {
                        M0.at<int8_t>(i, j) = M0.at<int8_t>(i, j) - 1;
                    }
                    ////////////////
                    if( delta.at<int8_t>(i,j)!=0)
                    {

                        if(V.at<int8_t>(i,j) < N*abs(delta.at<int8_t>(i,j)))
                        {
                            V.at<int8_t>(i,j)+=1;
                        }
                        if(V.at<int8_t>(i,j) > N*abs(delta.at<int8_t>(i,j)))
                        {
                            V.at<int8_t>(i,j)-=1;
                        }
                    }

                    if( abs(delta.at<int8_t>(i,j)) >= V.at<int8_t>(i,j))
                    {
                        //cout << "oui" << endl;
                        D.at<uchar>(i,j) = 255;
                    }
                    else
                    {
                        D.at<uchar>(i,j) = 0;
                    }

                }

            }
            cv::erode(D,D,Mat());
            vector<vector<Point> > contours;
            vector<Vec4i> hierarchy;
            //cvtColor(finMask, fingray, COLOR_BGR2GRAY);
            Mat diffGray;
            D.convertTo(diffGray,COLOR_BGR2GRAY);
            diffGray.convertTo(diffGray, CV_8UC1);
            Canny(diffGray, diffGray, 30, 30 * 2, 3);
            findContours(diffGray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_TC89_KCOS, Point(0,0));
            //cout << contours.at(0) << "\nend\n";
            for (int i = 0; i < contours.size(); ++i)
            {
                Point p=(contours.at(i)).at(0);
                int xMax=p.x;
                int yMax=p.y;
                int xMin=p.x;
                int yMin=p.y;
                for (int j = 0; j < contours.at(i).size(); ++j)
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

                rectangle(D,Point(xMin,yMin),Point(xMax,yMax),Scalar(127));
            }
            //cout << M0 ;
            imshow("M(t)",M0);
            imshow("V",V);
            imshow("D",D);
            waitKey(0);
            cout << capt.get(CV_CAP_PROP_POS_FRAMES) << "/" << capt.get(CV_CAP_PROP_FRAME_COUNT) << endl;
        }
        else
        {
            cout << "ERROR EMPTY FRAME" << endl;
            break;
        }
    }
    destroyAllWindows();
    
}


///////////////////////////

void Method::moyenne_Arith(std::string path )
{
    Mat tmp;
    Mat X;
    Mat foreGround;
    VideoCapture v(path);
    Mat backGroundGray;
    Mat original;
    double Rnorme;
    Mat foreGroundGray;


    tmp = Method::getBackGroundRGB_8UC3(path);
    tmp.convertTo(tmp, CV_8UC3);
    imshow("final2", tmp);
    waitKey(0);
    cvtColor(tmp, backGroundGray, COLOR_BGR2GRAY);
    backGroundGray.convertTo(backGroundGray, CV_32F);
    Mat diff = Mat::zeros(tmp.rows,tmp.cols,CV_32F);
    while (v.get(CV_CAP_PROP_POS_FRAMES) < v.get(CV_CAP_PROP_FRAME_COUNT))
    {
        v >> X;
        if (!X.empty())
        {

            X.copyTo(original);
            cvtColor(X, X, COLOR_BGR2GRAY);
            X.convertTo(X, CV_32F);
            cout << v.get(CV_CAP_PROP_POS_FRAMES) << "/" << v.get(CV_CAP_PROP_FRAME_COUNT) << endl;
            absdiff(X, backGroundGray, diff);
            threshold(diff, diff, 30, 255, THRESH_BINARY);
            cv::erode(diff, diff, Mat());
            cv::dilate(diff, diff, Mat());
            diff.convertTo(diff,CV_8U);
            foreGround = Method::getForeGroundRGB_8UC3(original,diff);
            foreGround.convertTo(foreGround, CV_32FC3);
            cvtColor(foreGround, foreGroundGray, COLOR_BGR2GRAY);
            foreGroundGray.convertTo(foreGroundGray, CV_32F);

            for (int i = 0; i < foreGround.rows; i++)
            {
                for (int j = 0; j < foreGround.cols; j++)
                {
                    double B = foreGround.at<Vec3f>(i, j)[0];
                    double G = foreGround.at<Vec3f>(i, j)[1];
                    double R = foreGround.at<Vec3f>(i, j)[2];
                    Rnorme = (double)(R / (R + G + B));
                    if (Rnorme < 20)
                    {
                        double CD = abs(foreGroundGray.at<float>(i, j) -backGroundGray.at<float>(i, j));
                        //cout << "CD = " << CD << endl;
                        if (CD < 45)
                        {
                            double BD = (double) ((foreGroundGray.at<float>(i, j)*backGroundGray.at<float>(i, j)) / pow(backGroundGray.at<float>(i, j), 2));
                            //cout << "BD = " << BD << endl;
                            if (BD < 1.25f || BD > 1.5f)
                            {
                                foreGround.at<Vec3f>(i, j)[0]=0;
                                foreGround.at<Vec3f>(i, j)[1]=0;
                                foreGround.at<Vec3f>(i, j)[2]=0;
                            }
                        }
                    }
                }
            }

            foreGround.convertTo(foreGround, CV_8UC3);
            Method::drawBoxesRGB_8UC3(&original,diff);
            imshow("original", original);
            imshow("foreground", foreGround);
            diff.convertTo(diff, CV_8U);
            imshow("diff", diff);
            waitKey(0);
            diff.convertTo(diff, CV_32F);

        }
        else
        {
            cout << "ERROR EMPTY FRAME" << endl;
            break;
        }
    }
    v.release();
    destroyAllWindows();
    
}



//////////////////

void Method::SAP(string path, int multiple)
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


    if (!vc.isOpened())// check if we succeeded
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    while (vc.get(CV_CAP_PROP_POS_FRAMES) < vc.get(CV_CAP_PROP_FRAME_COUNT))
    {

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
    imshow("MoyenneCoulour",Moy);
    Moy.convertTo(Moy,CV_32SC3);
    mask = Mat::zeros(Moy.size(),CV_32SC3);
    VideoCapture capt(path);
    if (!capt.isOpened())// check if we succeeded
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    while (capt.get(CV_CAP_PROP_POS_FRAMES) < capt.get(CV_CAP_PROP_FRAME_COUNT))
    {
        capt >> I;
        if (!I.empty())
        {
            //           Mat IGray;
            //Mat Icpy;
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
            cv::dilate(mask,mask,Mat());

            Method::drawBoxesRGB_8UC3(&Icpy,mask);
            /*
            vector<vector<Point> > contours;
            vector<Vec4i> hierarchy;
            vector<Rect> rectangles;
            Mat diffGray;
            mask.convertTo(diffGray,COLOR_BGR2GRAY);
            diffGray.convertTo(diffGray, CV_8UC1);
            threshSum/=mask.cols*mask.rows;
            cout<< threshSum << endl;
            //cout << "here" << endl;
            Canny(mask, diffGray, threshSum, threshSum*2 , 3);
            findContours(diffGray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_TC89_KCOS, Point(0,0));
            //cout << contours.at(0) << "\nend\n";
            for (int i = 0; i < contours.size(); ++i)
            {
                Point p=(contours.at(i)).at(0);
                int xMax=p.x;
                int yMax=p.y;
                int xMin=p.x;
                int yMin=p.y;
                for (int j = 0; j < contours.at(i).size(); ++j)
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
            for (int i = 0; i < rectangles.size(); i++)
            {
                for (int j = 0; j < rectangles.size(); j++)
                {
                   if(i!=j)
                   {
                       bool intersect = ((rectangles.at(i) & rectangles.at(j) ).area()>0);
                       if(intersect)
                       {
                           rectangles.at(i) = rectangles.at(i) | rectangles.at(j) ;
                           //rectangles.erase(rectangles.begin()+j);

                       }
                   }

                }
              rectangle(Icpy,rectangles.at(i),Scalar(0,0,255));
            }
            */
            imshow("original",Icpy);
            imshow("mask",mask);
            Mat non_mask;
            bitwise_not(mask,non_mask);
            threshold(non_mask,non_mask,1,1,THRESH_BINARY);
            //cout << non_mask;
            non_mask.convertTo(non_mask,CV_64FC3);
            imshow("non mask",non_mask);
            //Moy.convertTo(Moy,CV_32FC3);
            I.convertTo(I,CV_64FC3);
            double n=0.10f;
            Moy.convertTo(Moy,CV_64FC3);
            //bitwise_and(I,non_mask,I);
            Moy.copyTo(oldMoy);
            //Moy=(1-n)*Moy+n*I;
            if((int)capt.get(CV_CAP_PROP_POS_FRAMES)%2==0)
            {
                //cout << (int)capt.get(CV_CAP_PROP_POS_FRAMES)%2<<endl;
                for (int i = 0; i < Moy.rows; ++i)
                {
                    for (int j = 0; j < Moy.cols; ++j)
                    {
                        //cout << non_mask.at<double>(i,j) << endl;
                        if(non_mask.at<double>(i,j)==1)
                        {
                            Moy.at<Vec3d>(i,j)[0]=(1-n)*Moy.at<Vec3d>(i,j)[0]+n*myAnd(I.at<Vec3d>(i,j)[0],non_mask.at<double>(i,j));
                            //cout << Moy.at<Vec3d>(i,j)[0] << endl;
                            Moy.at<Vec3d>(i,j)[1]=(1-n)*Moy.at<Vec3d>(i,j)[1]+n*myAnd(I.at<Vec3d>(i,j)[1],non_mask.at<double>(i,j));
                            Moy.at<Vec3d>(i,j)[2]=(1-n)*Moy.at<Vec3d>(i,j)[2]+n*myAnd(I.at<Vec3d>(i,j)[2],non_mask.at<double>(i,j));

                        }

                    }
                }
            }
            Mat diff;
            absdiff(Moy,oldMoy,diff);
            imshow("difference between the backgrounds",diff);
            mask.convertTo(mask,CV_32SC3);
            Moy.convertTo(Moy,CV_8UC3);
            imshow("new back",Moy);
            waitKey(0);
            Moy.convertTo(Moy,CV_32SC3);


        }
        else
        {
            cout << "ERROR EMPTY FRAME" << endl;
            break;
        }
    }
    capt.release();
}



void Method::SD2(std::string path,int mul)
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
    while (capt.get(CV_CAP_PROP_POS_FRAMES) < capt.get(CV_CAP_PROP_FRAME_COUNT))
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

            Method::drawBoxesRGB_8UC3(&original,E);

            imshow("M(t)",M);
            imshow("V",V);
            imshow("D",E);
            imshow("Original",original);
            waitKey(0);
            cout << capt.get(CV_CAP_PROP_POS_FRAMES) << "/" << capt.get(CV_CAP_PROP_FRAME_COUNT) << endl;
        }
        else
        {
            cout << "ERROR EMPTY FRAME" << endl;
            break;
        }
    }
    destroyAllWindows();

}


cv::Mat Method::getBackGroundRGB_8UC3(std::string path)
{
    VideoCapture vc(path);
    Mat X;
    Mat M;
    if (!vc.isOpened())// check if we succeeded
    {
        cout << "Error while opening video " << endl;
        exit(EXIT_FAILURE);
    }
    vc >> X;
    X.convertTo(X, CV_32FC3);
    X.copyTo(M);
    //// get the average
    while (vc.get(CV_CAP_PROP_POS_FRAMES) < vc.get(CV_CAP_PROP_FRAME_COUNT))
    {
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
    M /= vc.get(CV_CAP_PROP_FRAME_COUNT);
    M.convertTo(M,CV_8UC3);
    vc.release();
    return M;
}


cv::Mat Method::getForeGroundRGB_8UC3(cv::Mat image , cv::Mat mask)
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

void Method::drawBoxesRGB_8UC3(cv::Mat* image,cv::Mat mask)
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
    for (int i = 0; i < contours.size(); ++i)
    {
        Point p=(contours.at(i)).at(0);
        int xMax=p.x;
        int yMax=p.y;
        int xMin=p.x;
        int yMin=p.y;
        for (int j = 0; j < contours.at(i).size(); ++j)
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
    for (int i = 0; i < rectangles.size(); i++)
    {
        for (int j = 0; j < rectangles.size(); j++)
        {
           if(i!=j)
           {
               bool intersect = ((rectangles.at(i) & rectangles.at(j) ).area()>0);
               if(intersect)
               {
                   rectangles.at(i) = rectangles.at(i) | rectangles.at(j) ;
                   //rectangles.erase(rectangles.begin()+j);

               }
           }

        }
      rectangle(*image,rectangles.at(i),Scalar(0,0,255));
    }

}

