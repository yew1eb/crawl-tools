/* ***********************************************
Author :_rabbit
Created Time :2014/5/4 15:03:55
File Name :20.cpp
************************************************ */
#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <string>
#include <time.h>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define INF 10000000000400.0
#define eps 1e-8
#define pi acos(-1.0)
typedef long long ll;
int dcmp(double x){
    if(fabs(x)<eps)return 0;
    return x>0?1:-1;
}
struct Point{
    double x,y;
    Point(double _x=0,double _y=0){
        x=_x;y=_y;
    }
};
Point operator + (const Point &a,const Point &b){
    return Point(a.x+b.x,a.y+b.y);
}
Point operator - (const Point &a,const Point &b){
    return Point(a.x-b.x,a.y-b.y);
}
Point operator * (const Point &a,const double &p){
    return Point(a.x*p,a.y*p);
}
Point operator / (const Point &a,const double &p){
    return Point(a.x/p,a.y/p);
}
bool operator < (const Point &a,const Point &b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
bool operator == (const Point &a,const Point &b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double Dot(Point  a,Point b){
    return a.x*b.x+a.y*b.y;
}
double Length(Point a){
    return sqrt(Dot(a,a));
}
double Angle(Point a,Point b){
    return acos(Dot(a,b)/Length(a)/Length(b));
}
double angle(Point a){
    return atan2(a.y,a.x);
}
double Cross(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}
Point vecunit(Point a){
    return a/Length(a);
}
Point Normal(Point a){
    return Point(-a.y,a.x)/Length(a);
}
Point Rotate(Point a,double rad){
    return Point(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
double Area2(Point a,Point b,Point c){
    return Length(Cross(b-a,c-a));
}
struct Line{
    Point p,v;
    double ang;
    Line(){};
    Line(Point p,Point v):p(p),v(v){
        ang=atan2(v.y,v.x);
    }
    bool operator < (const Line &L) const {
        return ang<L.ang;
    }
};
bool OnLeft(const Line &L,const Point &p){
    return dcmp(Cross(L.v,p-L.p))>0;
}
Point GetLineIntersection(Point p,Point v,Point q,Point w){
    Point u=p-q;
    double t=Cross(w,u)/Cross(v,w);
    return p+v*t;
}
Point GetLineIntersection(Line a,Line b){
    return GetLineIntersection(a.p,a.v,b.p,b.v);
}
vector<Point> HPI(vector<Line> L){
    int n=L.size();
    sort(L.begin(),L.end());//å°ææåå¹³é¢æç§æè§æåºã
    /*for(int i=0;i<n;i++){
        cout<<"han  "<<i<<" ";
        printf("%.2lf  %.2lf  %.2lf  %.2lf  %.2lf\n",L[i].p.x,L[i].p.y,L[i].v.x,L[i].v.y,L[i].ang);
    }*/
    int first,last;
    vector<Point> p(n);
    vector<Line> q(n);
    vector<Point> ans;
    q[first=last=0]=L[0];
    for(int i=1;i<n;i++){
        while(first<last&&!OnLeft(L[i],p[last-1]))last--;//å é¤é¡¶é¨çåå¹³é¢
        while(first<last&&!OnLeft(L[i],p[first]))first++;//å é¤åºé¨çåå¹³é¢
        q[++last]=L[i];//å°å½åçåå¹³é¢åå¦åç«¯éåé¡¶é¨ã
        if(fabs(Cross(q[last].v,q[last-1].v))<eps){//å¯¹äºæè§ç¸åçï¼éæ©æ§ä¿çä¸ä¸ªã
            last--;
            if(OnLeft(q[last],L[i].p))q[last]=L[i];
        }
        if(first<last)p[last-1]=GetLineIntersection(q[last-1],q[last]);//è®¡ç®éåé¡¶é¨åå¹³é¢äº¤ç¹ã
    }
    while(first<last&&!OnLeft(q[first],p[last-1]))last--;//å é¤éåé¡¶é¨çæ ç¨åå¹³é¢ã
    if(last-first<=1)return ans;//åå¹³é¢éå
    p[last]=GetLineIntersection(q[last],q[first]);//è®¡ç®éåé¡¶é¨ä¸é¦é¨çäº¤ç¹ã
    for(int i=first;i<=last;i++)ans.push_back(p[i]);//å°éåä¸­çç¹å¤å¶ã
    return ans;
}
double PolyArea(vector<Point> p){
    int n=p.size();
    double ans=0;
    for(int i=1;i<n-1;i++)
        ans+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return fabs(ans)/2;
}
int main()
{
     //freopen("data.in","r",stdin);
     //freopen("data.out","w",stdout);
     int T,n;
     cin>>T;
     while(T--){
         cin>>n;
         vector<Line> L;
         L.push_back(Line(Point(INF,INF),Point(-1,0)));
         L.push_back(Line(Point(0,INF),Point(0,-1)));
         while(n--){
             double a,b;
             scanf("%lf%lf",&a,&b);
             L.push_back(Line(Point(0,a),Point(1,b)));
         }
         vector<Point> ans=HPI(L);
        // for(int i=0;i<ans.size();i++)cout<<ans[i].x<<" "<<ans[i].y<<endl;
         printf("%d\n",ans.size()-2);
     }
     return 0;
}



