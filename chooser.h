#ifndef CHOOSER_H
#define CHOOSER_H

#include <QWidget>
#include <string>
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "qprogressbar.h"
#include <QTimer>
#include <vector>
#include <QTimer>
#include <map>
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

    static cv::Mat getBackGroundRGB_8UC3(std::string path,Chooser* c ,QProgressBar* s);

    static cv::Mat getForeGroundRGB_8UC3(cv::Mat image , cv::Mat mask);

    static void drawBoxesRGB_8UC3(cv::Mat* image,cv::Mat mask);

    static cv::Mat shadowRemoval_HSV(cv::Mat* image,cv::Mat backGround,Chooser* c);

    static cv::Mat getMultipleImage_8UC3(std::vector<cv::Mat>& images,char* windowName,Chooser* c,bool background=false );

    static cv::Mat hist(cv::Mat gray);


private slots:

    void on_alphaChooserSAP_valueChanged(int value);

    void on_alphaChooserRec_valueChanged(int value);

    void on_recChooser_clicked();

    void on_gradiantChooser_clicked();

    void on_alphaChooserGrad_valueChanged(int value);

    void on_horizontalSlider_sliderReleased();

    void on_horizontalSlider_sliderPressed();

    void on_Chooser_destroyed();

    void on_arithChooser_clicked(bool checked);

    void on_SAPChooser_clicked(bool checked);

    void on_control_clicked();

    void on_controlArith_clicked(bool checked);

    void on_SDChooser_clicked(bool checked);

    void on_controlRec_clicked(bool checked);

    void on_controlSD_clicked(bool checked);

    void on_controlSAP_clicked(bool checked);

    void on_accel_clicked(bool checked);

    void on_deccel_clicked(bool checked);

    void on_speedDown_clicked(bool checked);

    void on_speedUp_clicked(bool checked);

    void on_end_clicked(bool checked);

    void on_begin_clicked(bool checked);

    void on_accel_Arith_clicked(bool checked);

    void on_deccel_Arith_clicked();

    void on_speedUp_Arith_clicked(bool checked);

    void on_speedDown_Arith_clicked(bool checked);

    void on_end_Arith_clicked(bool checked);

    void on_begin_Arith_clicked(bool checked);

    void on_speedUp_Rec_clicked(bool checked);

    void on_speedDown_Rec_clicked(bool checked);

    void on_deccel_Rec_clicked();

    void on_accel_Rec_clicked(bool checked);

    void on_begin_Rec_clicked(bool checked);

    void on_end_Rec_clicked(bool checked);

    void on_begin_SD_clicked(bool checked);

    void on_deccel_SD_clicked(bool checked);

    void on_speedDown_SD_clicked(bool checked);

    void on_speedUp_SD_clicked(bool checked);

    void on_accel_SD_clicked(bool checked);

    void on_end_SD_clicked(bool checked);

    void on_speedUp_SAP_clicked(bool checked);

    void on_speedDown_SAP_clicked(bool checked);

    void on_deccel_SAP_clicked(bool checked);

    void on_accel_SAP_clicked(bool checked);

    void on_begin_SAP_clicked(bool checked);

    void on_end_SAP_clicked(bool checked);

    void on_exit_clicked();



    void on_shadowToggleArith_clicked();

    void on_shadowToggleRec_clicked();

    void on_shadowToggleSD_clicked();

    void on_shadowToggleSAP_clicked();

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
    int speedGrad;

    QTimer* timerArith;
    int speedArith;

    QTimer* timerRec;
    int speedRec;

    QTimer* timerSD;
    int speedSD;

    QTimer* timerSAP;
    int speedSAP;


    bool shadowGrad;
    bool shadowArith;
    bool shadowRec;
    bool shadowSD;
    bool shadowSAP;


    std::map<float,float> grad_Alpha_Map;
    std::map<float , float> SAP_Mul_Map;
    std::map<float,float> rec_Alpha_Map;
    std::map<float,float> SD_N_Map;
    int grad_Stat_Index;
    int SAP_Stat_Index;
    int rec_Stat_Index;
    int SD_Stat_Index;

public slots:
    void updateGrad();
    void updateRec();
    void updateSD();
    void updateSAP();
    void updateArith();
    void updateControlGrad();
    void updateControlArith();
    void updateControlRec();
    void updateControlSD();
    void updateControlSAP();


};

#endif // CHOOSER_H
