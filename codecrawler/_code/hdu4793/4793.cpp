#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define PI acos(-1.0)
#define maxn 100005
#define INF 0x7fffffff
#define eps 1e-8
using namespace std;
int cmp(double x) {
	if(fabs(x)<eps)
		return 0;
	if(x>0)
		return 1;
	return -1;
}
inline int sgn(double n) {
	return fabs(n)<eps?0:(n<0?-1:1);
}
inline double sqr(double x) {
	return x*x;
}
struct point{
	double x,y;
	point() {}
	point(double a,double b):x(a),y(b) {}
	void input() {
		scanf("%lf%lf",&x,&y);
	}
	friend point operator + (const point &a,const point &b) {
		return point(a.x+b.x,a.y+b.y);
	}
	friend point operator - (const point &a,const point &b) {
		return point(a.x-b.x,a.y-b.y);
	}
	friend bool operator == (const point &a,const point &b) {
		return cmp(a.x-b.x)==0 &&cmp(a.y-b.y)==0;
	}
	friend point operator * (const point &a,const double &b) {
		return point(a.x*b,a.y*b);
	}
	friend point operator * (const double &a,const point &b) {
		return point(a*b.x,a*b.y);
	}
	friend point operator / (const point &a,const double &b) {
		return point(a.x/b,a.y/b);
	}
	double norm() {
		return sqrt(sqr(x)+sqr(y));
	}//到原点距离
	void out () const {
		printf("%.2f %.2f",x,y);
	}
};
double det (const point &a,const point &b) {
	return a.x*b.y-a.y*b.x;
}//叉积
double dot (const point &a,const point &b) {
	return a.x*b.x+a.y*b.y;
}//点乘
double dist (const point &a,const point &b) {
	return (a-b).norm();
}//距离
point rotate_point(const point &p,double A) {
	double tx=p.x,ty=p.y;
	return point (tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}//旋转，A是弧度
struct line {
	point a,b;
	line() {}
	line(point x,point y):a(x),b(y) {}
	point dire()const {
		return b-a;
	}//向量
	double len() {
		return dire().norm();
	}
};
bool parallel(line a,line b) {
	return !cmp(det(a.a-a.b,b.a-b.b));
}
bool line_make_point (line a,line b,point &res) {
	if(parallel(a,b))
		return false;
	double s1=det(a.a-b.a,b.b-b.a);
	double s2=det(a.b-b.a,b.b-b.a);
	res=(s1*a.b-s2*a.a)/(s1-s2);
	return true;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/rainto96/in.txt","r",stdin);
#endif
	double Rm,R,r,x,y,vx,vy;
	while(~scanf("%lf%lf%lf%lf%lf%lf%lf",&Rm,&R,&r,&x,&y,&vx,&vy)){
                point s=point(x,y);
                point dir=point(vx,vy);
                if(dot(s,dir)>=0){
                        printf("0.000\n");
                        continue;
                }
                point tmp=point(vy,-vx);
                line l1=line(point(0,0),tmp);
                line l2=line(s,point(s.x+vx,s.y+vy));
                point ans;
                line_make_point(l1,l2,ans);
                double h=ans.norm();
                double h1=R+r;
                double h2=Rm+r;
                double speed=sqrt(vx*vx+vy*vy);
                if(h>=h1){
                        printf("0.000\n");
                        continue;
                }
                if(h>=h2){
                        double time=sqrt(h1*h1-h*h)/speed*2;
                        printf("%f\n",time);
                        continue;
                }else{
                        double time=sqrt(h1*h1-h*h)-sqrt(h2*h2-h*h);
                        time=time/speed*2;
                        printf("%f\n",time);
                        continue;
                }
	}
	return 0;
}
