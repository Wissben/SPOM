#ifndef MYMATH_H
#define MYMATH_H
#include <string>
#include <sstream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include <QString>
#include <QTableWidget>
#include <map>

double myAnd(double a , double b);
std::string toString(int val);
template <typename T> std::string tostr(const T& t);
cv::Point center(cv::Rect rec);
QString framesToTime(int frames);
void updateTableWidget(QTableWidget *tw,std::map<float,float> map);
#endif // MYMATH_H
