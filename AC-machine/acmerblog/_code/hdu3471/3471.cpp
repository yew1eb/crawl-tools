#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>

#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define Len(x) x.length()
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define EPS 1e-4

#define FOR0(i,x) for(i=0;i<x;i++)
#define FOR1(i,x) for(i=1;i<=x;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FORL0(i,a) for(i=a;i>=0;i--)
#define FORL1(i,a) for(i=a;i>=1;i--)
#define FORL(i,a,b)for(i=a;i>=b;i--)

#define rush() int CC;for(scanf("%d",&CC);CC--;)
#define Rush(n) while(scanf("%d",&n)!=-1)
using namespace std;

void RD(int &x){scanf("%d",&x);}
void RD(i64 &x){scanf("%lld",&x);}
void RD(u64 &x){scanf("%I64u",&x);}
void RD(u32 &x){scanf("%u",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(i64 &x,i64 &y){scanf("%lld%lld",&x,&y);}
void RD(u32 &x,u32 &y){scanf("%u%u",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void RD(i64 &x,i64 &y,i64 &z){scanf("%lld%lld%lld",&x,&y,&z);}
void RD(u32 &x,u32 &y,u32 &z){scanf("%u%u%u",&x,&y,&z);}
void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}
void RD(char &x){x=getchar();}
void RD(char *s){scanf("%s",s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(i64 x) {printf("%lld\n",x);}
void PR(i64 x,i64 y) {printf("%lld %lld\n",x,y);}
void PR(u32 x) {printf("%u\n",x);}
void PR(u64 x) {printf("%llu\n",x);}
void PR(double x) {printf("%.2lf\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

const int mod=10007;
const i64 inf=((i64)1)<<40;
const double dinf=1000000000000000000.0;
const int INF=100000000;
const int N=200005;

int sgn(double x)
{
 if(x>EPS) return 1;
 if(x<-EPS) return -1;
 return 0;
}

struct point3
{
 double x,y,z;
 
 point3(){}
 point3(double _x,double _y,double _z)
 {
 x=_x;
 y=_y;
 z=_z;
 }
 
 void get()
 {
 RD(x); RD(y); RD(z);
 }
 
 point3 operator+(point3 a)
 {
 return point3(x+a.x,y+a.y,z+a.z);
 }
 
 point3 operator-(point3 a)
 {
 return point3(x-a.x,y-a.y,z-a.z);
 }
 
 point3 operator*(point3 a)
 {
 return point3(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
 }
 
 point3 operator*(double t)
 {
 return point3(x*t,y*t,z*t);
 }
 
 double operator^(point3 a)
 {
 return x*a.x+y*a.y+z*a.z;
 }
 
 double len()
 {
 return sqrt(x*x+y*y+z*z);
 }
};

point3 S,v,a,b,c,d,e,f,g,h;

point3 lineCrossPlane(point3 p,point3 q,point3 a,point3 b,point3 c)
{
 point3 k=(c-b)*(a-b);
 double t=(k^(a-p))/(k^(q-p));
 return p+((q-p)*t);
}

double len(point3 a)
{
 return a.len();
}

int inside(point3 p,point3 a,point3 b,point3 c,point3 d)
{
 double S=len(a-b)*len(c-b);
 double x1=len((p-a)*(p-b));
 double x2=len((p-b)*(p-c));
 double x3=len((p-c)*(p-d));
 double x4=len((p-d)*(p-a));
 if(!sgn(x1)||!sgn(x2)||!sgn(x3)||!sgn(x4)) return 0;
 return sgn(S-(x1+x2+x3+x4)*0.5)==0;
}

int main()
{
 int num=0;
 rush()
 {
 S.get(); v.get();
 a.get(); b.get(); c.get(); d.get();
 e.get(); f.get(); g.get(); h.get();
 point3 k=(a-d)*(c-d);
 printf("Case %d: ",++num);
 if(!sgn(len(v))||(v^k)<=0||(k^(S-d))>0)
 {
 puts("Intelligent Larrionda!!!");
 continue;
 }
 point3 p=lineCrossPlane(S,S+v,a,b,c);
 if(inside(p,a,b,c,d)) puts("Stupid Larrionda!!!");
 else puts("Intelligent Larrionda!!!");
 }
}