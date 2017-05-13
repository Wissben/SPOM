#include "mymath.h"
#include "math.h"
#include <string>
#include <sstream>
#include <iostream>
#include <QDebug>
#include <map>
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
void updateTableWidget(QTableWidget *tw , std::map<float,float> map)
{
    bool found=false;
    for (std::map<float,float>::iterator it = map.begin();it!=map.end();++it)
      {
        found=false;
        for (int i=0; i<tw->rowCount();i++)
        {
            qDebug() << tw->item(i,0)->text().toFloat();
            float col1=tw->item(i,0)->text().toFloat();
            //float col2=tw->item(i,1)->text().toFloat();
            if(it->first==col1)
            {
                found = true;
                qDebug()<<found << "/" << it->first <<"/" << col1 << endl;
                tw->setItem(i, 0, new QTableWidgetItem(QString::number(it->first)));
                tw->setItem(i, 1, new QTableWidgetItem(QString::number(it->second)));
            }
        }
        if(found == false)
        {
            qDebug() << "false " <<it->first << "/" << it->second << endl;
            int insertRow;
            insertRow=tw->rowCount();
            tw->insertRow(insertRow);
            tw->setItem(insertRow, 0, new QTableWidgetItem(QString::number(it->first)));
            tw->setItem(insertRow, 1, new QTableWidgetItem(QString::number(it->second)));

        }
      }
}
