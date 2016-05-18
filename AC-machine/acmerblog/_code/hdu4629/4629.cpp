//大白p263
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const double eps=1e-9;//精度
const int INF=1<<29;
const double PI=acos(-1.0);
int dcmp(double x){//判断double等于0或。。。
    if(fabs(x)<eps)return 0;else return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator+(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}//向量+向量=向量
Vector operator-(Point a,Point b){return Vector(a.x-b.x,a.y-b.y);}//点-点=向量
Vector operator*(Vector a,double p){return Vector(a.x*p,a.y*p);}//向量*实数=向量
Vector operator/(Vector a,double p){return Vector(a.x/p,a.y/p);}//向量/实数=向量
bool operator<( const Point& A,const Point& B ){return dcmp(A.x-B.x)<0||(dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)<0);}
bool operator==(const Point&a,const Point&b){return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}
bool operator!=(const Point&a,const Point&b){return a==b;}
struct Segment{
    Point a,b;
    Segment(){}
    Segment(Point _a,Point _b){a=_a,b=_b;}
    bool friend operator<(const Segment& p,const Segment& q){return p.a<q.a||(p.a==q.a&&p.b<q.b);}
    bool friend operator==(const Segment& p,const Segment& q){return (p.a==q.a&&p.b==q.b)||(p.a==q.b&&p.b==q.a);}
};
struct Circle{
    Point c;
    double r;
    Circle(){}
    Circle(Point _c, double _r):c(_c),r(_r) {}
    Point point(double a)const{return Point(c.x+cos(a)*r,c.y+sin(a)*r);}
    bool friend operator<(const Circle& a,const Circle& b){return a.r<b.r;}
};
struct Line{
    Point p;
    Vector v;
    double ang;
    Line() {}
    Line(const Point &_p, const Vector &_v):p(_p),v(_v){ang = atan2(v.y, v.x);}
    bool operator<(const Line &L)const{return  ang < L.ang;}
};
double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}//|a|*|b|*cosθ 点积
double Length(Vector a){return sqrt(Dot(a,a));}//|a| 向量长度
double Angle(Vector a,Vector b){return acos(Dot(a,b)/Length(a)/Length(b));}//向量夹角θ
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}//叉积 向量围成的平行四边形的面积
double Area2(Point a,Point b,Point c){return Cross(b-a,c-a);}//同上 参数为三个点
double DegreeToRadius(double deg){return deg/180*PI;}
double GetRerotateAngle(Vector a,Vector b){//向量a顺时针旋转theta度得到向量b的方向
    double tempa=Angle(a,Vector(1,0));
    if(a.y<0) tempa=2*PI-tempa;
    double tempb=Angle(b,Vector(1,0));
    if(b.y<0) tempb=2*PI-tempb;
    if((tempa-tempb)>0) return tempa-tempb;
    else return tempa-tempb+2*PI;
}
Vector Rotate(Vector a,double rad){//向量旋转rad弧度
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
Vector Normal(Vector a){//计算单位法线
    double L=Length(a);
    return Vector(-a.y/L,a.x/L);
}
Point GetLineProjection(Point p,Point a,Point b){//点在直线上的投影
    Vector v=b-a;
    return a+v*(Dot(v,p-a)/Dot(v,v));
}
Point GetLineIntersection(Point p,Vector v,Point q,Vector w){//求直线交点 有唯一交点时可用
    Vector u=p-q;
    double t=Cross(w,u)/Cross(v,w);
    return p+v*t;
}
int ConvexHull(Point* p,int n,Point* ch){//计算凸包
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++){
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--){
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>0) m--;
    return m;
}
double Heron(double a,double b,double c){//海伦公式
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){//线段规范相交判定
    double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1);
    double c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
double CutConvex(const int n,Point* poly, const Point a,const Point b, vector<Point> result[3]){//有向直线a b 切割凸多边形
    vector<Point> points;
    Point p;
    Point p1=a,p2=b;
    int cur,pre; 
    result[0].clear(); 
    result[1].clear(); 
    result[2].clear();
    if(n==0) return 0;
    double tempcross;
    tempcross=Cross(p2-p1,poly[0]-p1);
    if(dcmp(tempcross)==0) pre=cur=2;
    else if(tempcross>0) pre=cur=0;
    else pre=cur=1;
    for(int i=0;i<n;i++){
        tempcross=Cross(p2-p1,poly[(i+1)%n]-p1);
        if(dcmp(tempcross)==0) cur=2;
        else if(tempcross>0) cur=0;
        else cur=1;
        if(cur==pre){
            result[cur].push_back(poly[(i+1)%n]); 
        }
        else{
            p1=poly[i]; 
            p2=poly[(i+1)%n];
            p=GetLineIntersection(p1,p2-p1,a,b-a);
            points.push_back(p); 
            result[pre].push_back(p); 
            result[cur].push_back(p); 
            result[cur].push_back(poly[(i+1)%n]); 
            pre=cur;
        }
    }
    sort(points.begin(),points.end());
    if(points.size()<2){
        return 0; 
    }
    else{
        return Length(points.front()-points.back());
    }
}
double DistanceToSegment(Point p,Segment s){//点到线段的距离
    if(s.a==s.b) return Length(p-s.a);
    Vector v1=s.b-s.a,v2=p-s.a,v3=p-s.b;
    if(dcmp(Dot(v1,v2))<0) return Length(v2);
    else if(dcmp(Dot(v1,v3))>0) return Length(v3);
    else return fabs(Cross(v1,v2))/Length(v1);
}
bool isPointOnSegment(Point p,Segment s){//点在线段上
    return dcmp(DistanceToSegment(p,s))==0;
}
int isPointInPolygon(Point p, Point* poly,int n){//点与多边形的位置关系
    int wn=0;
    for(int i=0;i<n;i++){
        Point& p2=poly[(i+1)%n];
        if(isPointOnSegment(p,Segment(poly[i],p2))) return -1;//点在边界上
        int k=dcmp(Cross(p2-poly[i],p-poly[i]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(p2.y-p.y);
        if(k>0&&d1<=0&&d2>0)wn++;
        if(k<0&&d2<=0&&d1>0)wn--;
    }
    if(wn) return 1;//点在内部
    else return 0;//点在外部
}
double PolygonArea(vector<Point> p){//多边形有向面积
    double area=0;
    int n=p.size();
    for(int i=1;i<n-1;i++)
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}
int GetLineCircleIntersection(Line L,Circle C,Point& p1,Point& p2){//圆与直线交点 返回交点个数
    double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y-C.c.y;
    double e = a*a + c*c, f = 2*(a*b+c*d), g = b*b + d*d -C.r*C.r;
    double delta = f*f - 4*e*g;
    if(dcmp(delta) < 0)  return 0;//相离
    if(dcmp(delta) == 0) {//相切
        p1=p1=C.point(-f/(2*e));
        return 1;
    }//相交
    p1=(L.p+L.v*(-f-sqrt(delta))/(2*e));
    p2=(L.p+L.v*(-f+sqrt(delta))/(2*e));
    return 2;
}
//--------------------------------------
//--------------------------------------
//--------------------------------------
//--------------------------------------
//--------------------------------------
Point parr[9999];
Segment sarr[1600];
bool smark[1600];
int pidx,sidx;
struct Segforcmp{
	Segment s;
	bool mark;
	bool friend operator<(Segforcmp a,Segforcmp b){
		return a.s<b.s;
	}
}temps[2000];
bool isintri(Point m,Point a,Point b){
	Point p=GetLineProjection(m,a,b);
	if(m.y>p.y) return true;
	else return false;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--){
		sidx=pidx=0;
		scanf("%d",&n);
		double ans[100];
		memset(ans,0,sizeof ans);
		//输入处理
		for(int i=0;i<n;i++){
			Point a,b,c,m;
			scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
			m.x=(a.x+b.x+c.x)/3;
			m.y=(a.y+b.y+c.y)/3;
			if(dcmp(Cross(a-b,b-c))==0) continue;//共线舍去
			parr[pidx++]=a;parr[pidx++]=b;parr[pidx++]=c;//端点放入数组
			if(a.x<b.x) sarr[sidx]=Segment(a,b);
			else sarr[sidx]=Segment(b,a);
			smark[sidx++]=isintri(m,a,b);//边放入数组 并标记出入边
			if(a.x<c.x) sarr[sidx]=Segment(a,c);
			else sarr[sidx]=Segment(c,a);
			smark[sidx++]=isintri(m,a,c);
			if(b.x<c.x) sarr[sidx]=Segment(b,c);
			else sarr[sidx]=Segment(c,b);
			smark[sidx++]=isintri(m,c,b);
		}
		//两两边求交点
		for(int i=0;i<sidx;i++){
			for(int j=i+1;j<sidx;j++){
				if(SegmentProperIntersection(sarr[i].a,sarr[i].b,sarr[j].a,sarr[j].b))
					parr[pidx++]=GetLineIntersection(sarr[i].a,sarr[i].b-sarr[i].a,sarr[j].a,sarr[j].b-sarr[j].a);
			}
		}
		sort(parr,parr+pidx);
		Point pre=parr[0],cur;
		for(int i=1;i<pidx;i++)if(dcmp(parr[i].x-pre.x)!=0){
			cur=parr[i];
			int tempscount=0;
			for(int j=0;j<sidx;j++)if(sarr[j].a.x<=pre.x&&sarr[j].b.x>=cur.x){
				Point a=GetLineIntersection(pre,Vector(0,1),sarr[j].a,sarr[j].b-sarr[j].a);//左边扫描线与线段交点
				Point b=GetLineIntersection(cur,Vector(0,1),sarr[j].a,sarr[j].b-sarr[j].a);//右边。。。。
				Segment temp(a,b);
				temps[tempscount].s=temp;
				temps[tempscount++].mark=smark[j];
			}
			sort(temps,temps+tempscount);
			int deep=temps[0].mark;
			for(int j=1;j<tempscount;j++){//遍历区间中的线段求面积
				double h=temps[j].s.b.x-temps[j].s.a.x;
				double base=fabs(temps[j-1].s.a.y-temps[j].s.a.y)+fabs(temps[j-1].s.b.y-temps[j].s.b.y);
				if(deep) ans[deep]+=base/2*h;
				if(temps[j].mark) deep++;
				else deep--;
			}
			pre=cur;
		}
		for(int i=1;i<=n;i++)
			printf("%.10lf\n",ans[i]);
	}
	return 0;
}