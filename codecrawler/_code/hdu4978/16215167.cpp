#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const double eps = 1e-6;
const double Pi = acos(-1.0);
#define zero(x) (((x) > 0 ? (x) : (-x)) < eps)

int q, n;

struct Point
{
    double x,y;
    Point() {}  Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }  Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }  //åç§¯
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;     //ç¹ç§¯
    }
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;     //ç»åç¹æè½¬è§åº¦Bï¼å¼§åº¦å¼ï¼ï¼åx,yçåå
    }
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }
} P[105], ch[105];

double Distance(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double xmult(Point p1, Point p2, Point p){
    return (p1.x-p.x)*(p2.y-p.y) - (p1.y-p.y)*(p2.x-p.x);
}
int dcmp(double x){
    return fabs(x)<eps?0:(x<0?-1:1);
}
bool cmp(Point a, Point b){
    if(dcmp(xmult(a, b, P[0])) == 0){
        return Distance(a, P[0]) < Distance(b, P[0]);
    }
    else {
        return dcmp(xmult(a, b, P[0])) > 0;
    }
}
int Graham(int n){
    int s = 0, top = 1;
    for(int i = 0; i < n; ++i){
        if(P[i].y < P[s].y || (P[i].y == P[s].y && P[i].x < P[s].x)){
            s = i;
        }
    }
    if(s != 0){
        Point tmp = P[0];
        P[0] = P[s];
        P[s] = tmp;
    }
    sort(P+1, P+n, cmp);
    ch[0] = P[0], ch[1] = P[1];
    for(int i = 2; i < n; ++i){
        while(top > 0 && dcmp(xmult(ch[top], P[i], ch[top-1])) < 0){
            top--;
        }
        ch[++top] = P[i];
    }
    return top+1;
}


int T;
double d;

int main()
{
    //freopen("1008.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    int icase = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d%lf", &n, &d);
        for(int i = 0; i < n; ++i){
            scanf("%lf%lf", &P[i].x, &P[i].y);
        }
        printf("Case #%d: ", icase++);
        if(n >= 3){
            int t = Graham(n);
            //printf("%d\n", t);
            double sum = Distance(ch[0], ch[t-1]);
            for(int i = 0; i < t-1; ++i){
                sum += Distance(ch[i], ch[i+1]);
            }
            //printf("q = %d\n", q);
            //printf("%lf\n", Area());
            //printf("%lf\n" ,sum);
            printf("%.4lf\n", sum/(Pi*(d)));
        }
        else if(n == 2){
            double dis = Distance(P[0], P[1]);
            printf("%.4lf\n", 2*dis/(Pi*d));
        }
        else {
            printf("0.0000\n");
        }
        //printf("%lf %lf\n", Min.y, Max.y);
    }

    return 0;
}

/*
100
3 3
0 1
1 0
-1 0
*/