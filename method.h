#ifndef METHOD_H
#define METHOD_H
#include <string>
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"

class Method
{
public:
    Method();

    static void moyenne_Reccur(std::string path, double alpha);

    static void laplace(std::string path);

    static void gradiantOublieux(std::string pathToVideo , double alphaDeb);

    static void sigmaDelta(std::string path);

    static void moyenne_Arith(std::string path );

    static void SAP(std::string path, int multiple, double alpha);

    static void SD2(std::string path,int mul);

    static cv::Mat getBackGroundRGB_8UC3(std::string path);

    static cv::Mat getForeGroundRGB_8UC3(cv::Mat image , cv::Mat mask);

    static void drawBoxesRGB_8UC3(cv::Mat* image,cv::Mat mask);


};

#endif // METHOD_H
