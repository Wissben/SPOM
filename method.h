#ifndef METHOD_H
#define METHOD_H
#include <string>
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "selector.h"
#include "ui_selector.h"
#include "chooser.h"

class Method
{
public:
    Method();

    static void moyenne_Reccur(std::string path, double alpha,Selector* s);

    static void gradiantOublieux(std::string pathToVideo , double alphaDeb,Chooser* c);

    static void sigmaDelta(std::string path);

    static void moyenne_Arith(std::string path ,Selector* s);

    static void SAP(std::string path, int multiple, double alpha,Selector* s);

    static void SD2(std::string path,int mul);

    static cv::Mat getBackGroundRGB_8UC3(std::string path,Selector* s);

    static cv::Mat getForeGroundRGB_8UC3(cv::Mat image , cv::Mat mask);

    static void drawBoxesRGB_8UC3(cv::Mat* image,cv::Mat mask);

    static cv::Mat shadowRemoval_HSV(cv::Mat* image,cv::Mat backGround,Selector* s);

    static void showMultipleImage_8UC3(std::vector<cv::Mat>& images,char* windowName);

};

#endif // METHOD_H
