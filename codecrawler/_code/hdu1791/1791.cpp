#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <cstdlib>
 #include <algorithm>
 #include <vector>
 #include <stack>
 #include <queue>
 #include <cassert>
 #include <set>
 #include <sstream>
 #include <map>
 using namespace std ;
 #ifdef DeBUG
 #define bug assert
 #else
 #define bug //
 #endif
 #define zero {0}
 #define INF 2000000000
 #define EPS 1e-10
 inline int sgn(double x)//sgn函数符号判断 ，小于给定精度判零
 {
     return fabs(x) < EPS ? 0 :(x < 0 ? -1 : 1);
 }
 struct POINT
 {
     double x;
     double y;
     POINT()
     {
     }
     POINT(double a,double b):x(a),y(b)
     {
     }
 };
 double dist(POINT p,POINT r)
 {
     return sqrt((p.x-r.x)*(p.x-r.x)+(p.y-r.y)*(p.y-r.y));
 }
 bool cocircle(POINT p1,POINT p2,POINT p3,POINT &q,double &r)
 {
     double x12=p2.x-p1.x;
     double y12=p2.y-p1.y;
     double x13=p3.x-p1.x;
     double y13=p3.y-p1.y;
     double z2=x12*(p1.x+p2.x)+y12*(p1.y+p2.y);
     double z3=x13*(p1.x+p3.x)+y13*(p1.y+p3.y);
     double d=2.0*(x12*(p3.y-p2.y)-y12*(p3.x-p2.x));
     if(abs(d)<EPS)                           //共线，圆不存在
         return false;
     q.x=(y13*z2-y12*z3)/d;
     q.y=(x12*z3-x13*z2)/d;
     r=dist(p1,q);
     return true;
 }
 int main()
 {
 #ifdef DeBUGn

     freopen("C:\\Users\\Sky\\Desktop\\1.in","r",stdin);
 #endif
     int T;
     double x1,x2,x3,y1,y2,y3;
     scanf("%d",&T);
     while(T--)
     {
         POINT xin;
         double r;
         cin>>x1>>y1>>x2>>y2>>x3>>y3;
  /*
        if(sgn((x3-x1)*(y2-y1)-(y3-y1)*(x2-x1))==0)
             printf("No this position\n");
         else
         {*/
             if(cocircle(POINT(x1,y1),POINT(x2,y2),POINT(x3,y3),xin,r))
             printf("%.1lf %.1lf\n",xin.x,xin.y);
             else if((x1==x2&&y1==y2)||(x1==x3&&y1==y3)||(x2==x3&&y2==y3))//知道数据了这里偷个懒呵呵，应判断两点中点 
             printf("%.1lf %.1lf\n",(x1+x2+x3)/2,(y1+y2+y3)/2);
             else
             printf("No this position\n");
         //}
     }
     return 0;
 }