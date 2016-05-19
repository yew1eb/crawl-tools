#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
int sgn(double x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}

inline double sqr(double x){return x*x;}
struct Point {
    double x, y;
    Point(){}
    Point(double _x, double _y){
        x = _x;
        y = _y;
    }
    void input(){
        scanf("%lf%lf", &x, &y);
    }
    bool operator ==(Point b)const{
        return sgn(x-b.x)==0&&sgn(y-b.y)==0;
    }
    bool operator <(Point b)const{
        return sgn(x-b.x)==0?sgn(y-b.y)<0:x<b.x;
    }
    Point operator -(const Point &b)const{
        return Point(x-b.x, y-b.y);
    }
    double operator ^(const Point &b)const{
        return x*b.y - y*b.x;
    }
    double operator *(const Point &b)const{
        return x*b.x + y*b.y;
    }
    double len(){
        return hypot(x, y);
    }
    double len2(){
        return x*x + y*y;
    }
    double distance(Point p){
        return hypot(x-p.x, y-p.y);
    }
    Point operator +(const Point &b)const{
        return Point(x+b.x, y+b.y);
    }
    Point operator *(const double &k)const{
        return Point(x*k, y*k);
    }
    Point operator /(const double &k)const{
        return Point(x/k, y/k);
    }
};

struct circle{
    Point p;
    double r;
    circle(){}
    circle(double x, double y, double _r){
        p = Point(x, y);
        r  = _r;
    }
    double area(){ return pi*r*r;}
    int relationcircle(circle v){
        double d = p.distance(v.p);
        if(sgn(d-r-v.r)>0) return 5;
        if(sgn(d-r-v.r)==0) return 4;
        double l = fabs(r-v.r);
        if(sgn(d-r-v.r)<0 && sgn(d-l)>0) return 3;
        if(sgn(d-l)==0) return 2;
        if(sgn(d-l)<0) return 1;
    }
    double areacircle(circle v){
        int rel = relationcircle(v);
        if(rel>=4) return 0.0;
        if(rel<=2) return min(area(), v.area());
        double d = p.distance(v.p);
        double hf = (r+v.r+d)/2.0;
        double ss = 2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
        double a1 = acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
        a1 = a1*r*r;
        double a2 = acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
        a2 = a2*v.r*v.r;
        return a1+a2-ss;
    }
};
int main(){
    int T;
    double r, R;
    double x1, y1, x2, y2;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ++ca){
        scanf("%lf%lf", &r, &R);
        scanf("%lf%lf", &x1, &y1);
        scanf("%lf%lf", &x2, &y2);
        circle f1(x1, y1, r), f2(x1, y1, R);
        circle g1(x2, y2, r), g2(x2, y2, R);
        double a = f2.areacircle(g2);
        double b = f1.areacircle(g2);
        double c = f1.areacircle(g1);
        double ans = a - 2*b + c;
        printf("Case #%d: %.6f\n", ca, ans);
    }
    return 0;
}