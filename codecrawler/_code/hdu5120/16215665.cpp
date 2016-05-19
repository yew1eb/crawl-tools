#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#define LL __int64
#define eps 1e-8
#define pi acos(-1)
using namespace std;
struct point{
    double x,y;
};
struct circle{ 
    point c;
    double r;
};
double CS(circle a,circle b){    //æ±ä¸¤åç¸äº¤é¢ç§¯ 
    double d=sqrt((a.c.x-b.c.x)*(a.c.x-b.c.x)+(a.c.y-b.c.y)*(a.c.y-b.c.y));
    if (a.r<b.r){
        circle g;
        g=a;
        a=b;
        b=g;
    }
    if (a.r+b.r<=d) return 0; //ä¸¤åç¸ç¦» 
    if (a.r-b.r>=d){
        return (pi*b.r*b.r);
    }  //å¤§ååå«å°å 
    double a1=acos((d*d+a.r*a.r-b.r*b.r)/(2*a.r*d));
    double b1=acos((d*d+b.r*b.r-a.r*a.r)/(2*b.r*d));
    double s=a1*a.r*a.r+b1*b.r*b.r;
    double s1=a.r*d*sin(a1);
    return s-s1;
}
int main(){
    int T;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        circle a,b;
        scanf("%lf%lf",&a.r,&b.r);
        scanf("%lf%lf",&a.c.x,&a.c.y);
        scanf("%lf%lf",&b.c.x,&b.c.y);
        circle c=a;
        c.r=b.r;
        circle d=b;
        d.r=a.r;
        double s1=CS(c,b);
        double s2=CS(a,b);
        double s3=CS(a,d);
        printf("Case #%d: %f\n",cas,s1-2*s2+s3);
    }
    return 0;
}