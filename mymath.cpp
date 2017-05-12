#include "mymath.h"
#include "math.h"
#include <string>
#include <sstream>
#include <iostream>
#include <QDebug>
using namespace std;

double myAnd(double a, double b)
{
    if(b==1)
        return a;
    if(b==0)
        return 0;

}

std::string toString(int val)
{
    std::string khobz2 ="";
    if(val == 0) return "0";
    for(;val>0;)
    {
        int k=val%10;
        khobz2 += " ";
        khobz2[khobz2.size()-1] = k+'0';
        val /= 10;
    }
    std::string khobz = std::string(khobz2);
    for(int i=0;i<khobz.size();i++)
        khobz[i] = khobz2[khobz.size()-1-i];
    return khobz;
}

template <typename T> std::string tostr(const T& t) {
   std::ostringstream os;
   os<<t;
   return os.str();
}

cv::Point center(cv::Rect rec)
{
    cv::Point res;
    int x = (int) (rec.tl().x+rec.br().x)/2;
    int y = (int) (rec.tl().y+rec.br().y)/2;
    res.x=x;
    res.y=y;
    return res;
}


QString framesToTime(int frames)
{
    std::string str="";
    int secs;
    int mins;
    mins = (int) frames/60;
    secs=frames%60;
    str+=std::to_string(mins)+":"+std::to_string(secs);
    QString res(str.c_str());
    //qDebug() << res;
    return res;
}
