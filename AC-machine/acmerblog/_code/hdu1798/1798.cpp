#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;


int main()
{
    double x1,y1,r1,x2,y2,r2,s,PI;
    PI=2*asin(1.0);                //PI不能写成3.1415926
    while(cin>>x1>>y1>>r1)
   {
      cin>>x2>>y2>>r2;

      double d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
      if(d>=(r1+r2)||!r1||!r2)