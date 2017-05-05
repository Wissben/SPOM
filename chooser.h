#ifndef CHOOSER_H
#define CHOOSER_H

#include <QWidget>
#include <string>
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "selector.h"
#include "qprogressbar.h"
#include <QTimer>;
#include <vector>
#include <QTimer>
namespace Ui {
class Chooser;
}

class Chooser : public QWidget
{
    Q_OBJECT

public:
    explicit Chooser(QWidget *parent = 0);
    ~Chooser();
    static void moyenne_Reccur(std::string path, double alpha,Chooser* c);

    static void gradiantOublieux(std::string pathToVideo , double alphaDeb,Chooser* c);

    static void sigmaDelta(std::string path);

    static void moyenne_Arith(std::string path ,Chooser* c);

    static void SAP(std::string path, int multiple, double alpha,Chooser* c);

    static void SD2(std::string path,int mul,Chooser* c);

    static cv::Mat getBackGroundRGB_8UC3(std::string path,QProgressBar* s);

    static cv::Mat getForeGroundRGB_8UC3(cv::Mat image , cv::Mat mask);

    static void drawBoxesRGB_8UC3(cv::Mat* image,cv::Mat mask);

    static cv::Mat shadowRemoval_HSV(cv::Mat* image,cv::Mat backGround,Chooser* c);

    static cv::Mat getMultipleImage_8UC3(std::vector<cv::Mat>& images,char* windowName,Chooser* c,bool background=false );

    static cv::Mat hist(cv::Mat gray);


private slots:
    void on_gradiantMorph_clicked();

    void on_pushButton_clicked();

    void on_alphaChooserSAP_valueChanged(int value);

    void on_NChooser_valueChanged(int arg1);

    void on_alphaChooserRec_valueChanged(int value);

    void on_recChooser_clicked();

    void on_gradiantChooser_clicked();

    void on_alphaChooserGrad_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_sliderReleased();

    void on_horizontalSlider_sliderPressed();

    void on_Chooser_destroyed();

    void on_arithChooser_clicked();

    void on_arithChooser_clicked(bool checked);

    void on_SAPChooser_clicked(bool checked);

    void on_pushButton_clicked(bool checked);

    void on_control_clicked(bool checked);

    void on_controlArith_clicked(bool checked);

    void on_SDChooser_clicked(bool checked);

    void on_controlRec_clicked(bool checked);

    void on_controlSD_clicked(bool checked);

    void on_controlSAP_clicked(bool checked);

public:
    Ui::Chooser *ui;
    bool valueChanged;
    bool onPause;

    std::vector<cv::Mat> gradFramesFore;
    std::vector<cv::Mat> gradFramesMask;
    std::vector<cv::Mat> gradFramesOriginal;
    int gradIndex;

    std::vector<cv::Mat> arithFramesFore;
    std::vector<cv::Mat> arithFramesMask;
    std::vector<cv::Mat> arithFramesOriginal;
    std::vector<cv::Mat> arithFramesBack;
    int arithIndex;

    std::vector<cv::Mat> recFramesFore;
    std::vector<cv::Mat> recFramesMask;
    std::vector<cv::Mat> recFramesOriginal;
    std::vector<cv::Mat> recFramesBack;
    int recIndex;

    std::vector<cv::Mat> SDFramesFore;
    std::vector<cv::Mat> SDFramesMask;
    std::vector<cv::Mat> SDFramesOriginal;
    int SDIndex;

    std::vector<cv::Mat> SAPFramesFore;
    std::vector<cv::Mat> SAPFramesMask;
    std::vector<cv::Mat> SAPFramesOriginal;
    std::vector<cv::Mat> SAPFramesBack;
    int SAPIndex;


    QTimer* timerGrad;
    QTimer* timerArith;
    QTimer* timerRec;
    QTimer* timerSD;
    QTimer* timerSAP;
    QImage original;

public slots:
    void updateGrad();
    void updateRec();
    void updateSD();
    void updateSAP();
    void updateArith();


};

#endif // CHOOSER_H
