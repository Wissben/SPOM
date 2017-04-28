#include "mymath.h"
#include "math.h"
#include <string>
#include <sstream>

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
