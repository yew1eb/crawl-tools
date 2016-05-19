#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=50100;
const double oo=1e10;
const double eps=1e-8;
struct Point{
    double x,y;
    double angle,dis;
    Point(){
    }
    Point(double x,double y):x(x),y(y){
    }
};
struct Line{
    Point p1,p2;
    Line(){
    }
    Line(Point p1,Point p2):p1(p1),p2(p2){
    }
};
typedef vector<Point> Polygon;
typedef vector<Point> Points;
bool ZERO(double x){
    return fabs(x)<eps;
}
bool ZERO(Point p){
    return ZERO(p.x)&&ZERO(p.y);
}
bool EQ(double x,double y){
    return fabs(x-y)<eps;
}
bool NEQ(double x,double y){
    return fabs(x-y)>=eps;
}
bool LT(double x,double y){
    return NEQ(x,y)&&x<y;
}
bool GT(double x,double y){
    return NEQ(x,y)&&x>y;
}
bool LEQ(double x,double y){
    return EQ(x,y)||x<y;
}
bool GEQ(double x,double y){
    return EQ(x,y)||x>y;
}
double sqr(double x){
    return x*x;
}
bool operator==(const Point& p1,const Point& p2){
    return EQ(p1.x,p2.x)&&EQ(p1.y,p2.y);
}
bool operator!=(const Point& p1,const Point& p2){
    return NEQ(p1.x,p2.x)||NEQ(p1.y,p2.y);
}
bool operator<(const Point& p1,const Point& p2){
    if(NEQ(p1.x,p2.x)){
        return p1.x<p2.x;
    }else{
        return p1.y<p2.y;
    }
}
Point operator+(const Point& p1,const Point& p2){
    return Point(p1.x+p2.x,p1.y+p2.y);
}
Point operator-(const Point& p1,const Point& p2){
    return Point(p1.x-p2.x,p1.y-p2.y);
}
double operator*(const Point& p1,const Point& p2){
    return p1.x*p2.y-p1.y*p2.x;
}
double operator&(const Point& p1,const Point& p2){
    return p1.x*p2.x+p1.y*p2.y;
}
double Norm(const Point& p){
    return sqrt(sqr(p.x)+sqr(p.y));
}
bool comp(const Point& left,const Point& right){
    if(EQ(left.angle,right.angle)){
        return left.dis<right.dis;
    }else{
        return left.angle<right.angle;
    }
}
void Scan(Points& points,Polygon& result){
    int i,k,n;
    Point p;
    n=points.size();
    result.clear();
    if(n<3){
        result=points;
        return;
    }
    k=0;
    for(i=1;i<n;i++){
        if(EQ(points[i].y,points[k].y)){
            if(points[i].x<=points[k].x){
                k=i;
            }
        }else if(points[i].y<points[k].y){
            k=i;
        }
    }
    swap(points[0],points[k]);
    for(i=1;i<n;i++){
        points[i].angle=atan2(points[i].y-points[0].y,points[i].x-points[0].x);
        points[i].dis=Norm(points[i]-points[0]);
    }
    sort(points.begin()+1,points.end(),comp);
    result.push_back(points[0]);
    for(i=1;i<n;i++){
        if((i+1<n)&&EQ(points[i].angle,points[i+1].angle)){
            continue;
        }
        if(result.size()>=3){
            p=result[result.size()-2];
            while(GEQ((points[i]-p)*(result.back()-p),0)){
                result.pop_back();
                p=result[result.size()-2];
            }
        }
        result.push_back(points[i]);
    }
}
Point center(const Polygon& poly){
    Point p,p0,p1,p2,p3;
    double m,m0;
    p1=poly[0];
    p2=poly[1];
    p.x=p.y=m=0;
    for(int i=2;i<(int)poly.size();i++){
        p3=poly[i];
        p0.x=(p1.x+p2.x+p3.x)/3.0;
        p0.y=(p1.y+p2.y+p3.y)/3.0;
        m0=p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x;
        if(ZERO(m+m0)){
            m0+=eps;
        }
        p.x=(m*p.x+m0*p0.x)/(m+m0);
        p.y=(m*p.y+m0*p0.y)/(m+m0);
        m+=m0;
        p2=p3;
    }
    return p;
}
bool isconter(const Points pts){
    double res=0.0;
    int n=pts.size();
    for(int i=0;i<n;i++){
        res+=(pts[i]*pts[(i+1)%n]);
    }
    return res>0;
}
bool check(const Point& p,const Line& l){
    return LT((l.p1-p)&(l.p2-l.p1),0)&<((l.p2-p)&(l.p1-l.p2),0);
}
Points pts,poly;
int main(){
    int t;
    int n,ret;
    Point p;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ret=0;
        pts.clear();
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p.x,&p.y);
            pts.push_back(p);
        }
        if(!isconter(pts)){
            reverse(pts.begin(),pts.end());
        }
        p=center(pts);
        Scan(pts,poly);
        n=poly.size();
        poly.push_back(poly[0]);
        for(int i=0;i<n;i++){
            if(check(p,Line(poly[i],poly[i+1]))){
                ret++;
            }
        }
        printf("%d/n",ret);
    }
    return 0;
}

 
 
参考：http://blog.csdn.net/lyhypacm/article/details/5978389
						                        





(adsbygoogle = window.adsbygoogle || []).push({});

 


window._bd_share_config={"common":{"bdSnsKey":{},"bdText":"","bdMini":"2","bdMiniList":false,"bdPic":"","bdStyle":"0","bdSize":"24"},"share":{}};with(document)0[(getElementsByTagName('head')[0]||body).appendChild(createElement('script')).src='http://bdimg.share.baidu.com/static/api/js/share.js?v=89860593.js?cdnversion='+~(-new Date()/36e5)];

					