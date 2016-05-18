#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define eps 1e-8
#define pw(x) ((x)*(x))
struct P
{
 double x,y,z;
 P (double x=0,double y=0,double z=0) : x(x) ,y(y) ,z(z) {}
 P operator - (const P & b)
 {
 return P (x-b.x,y-b.y,z-b.z);
 }
 P operator + (const P & b)
 {
 return P (x+b.x,y+b.y,z+b.z);
 }
 P operator * (const P & b)
 {
 return P( y*b.z-z*b.y, z*b.x-x*b.z, x*b.y-y*b.x);
 }
 P operator * (double h)
 {
 return P (x*h ,y*h ,z*h);
 }
 double operator & (const P & b)
 {
 return x*b.x+y*b.y+z*b.z;
 }
 double len()
 {
 return sqrt(x*x+y*y+z*z);
 }
 P turnlen(double h)
 {
 double r=h/len();
 return P (x*r,y*r,z*r);
 }
 void input()
 {
 scanf("%lf%lf%lf",&x,&y,&z);
 }
 void output()
 {
 printf("%.7f %.7f %.7f\n",x,y,z);
 }
}p1,p2,res,c[110];
double r[110];
int sgn(double x)
{
 return x<-eps?-1:x>eps;
}
int ins(P c,double r,P & ret)
{
 double h=((c-p1)*(p2-p1)).len()/(p2-p1).len();
 if(sgn(h-r)>=0) return 0;
 P zz=c+((p1-c)*(p2-c)*(p1-p2)).turnlen(h);
 if(sgn((p2-p1)&(zz-p1))<=0) return 0;
 ret=zz+(p1-p2).turnlen(sqrt(r*r-h*h));
 return 1;
}
P ref(P a,P b,P c)
{
 double d=((c-a)*(b-a)).len()/(b-a).len();
 return c+((a-c)*(b-c)*(a-b)).turnlen(2*d);
}
int main()
{
 int n;
 while(scanf("%d",&n)&&n){
 p1=P(0,0,0);
 p2.input();
 for(int i=0;i<n;i++){
 c[i].input();
 scanf("%lf",r+i);
 }
 while(1){
 int k=-1;
 p2=p1+(p2-p1).turnlen(0.01);
 P ret; double dis;
 for(int i=0;i<n;i++){
 if(ins(c[i],r[i],ret)){
 if(k==-1||(ret-p1).len()<dis) {
 dis=(ret-p1).len();
 res=ret;
 k=i;
 }
 }
 }
 if(k==-1) break;
 p2=ref(c[k],res,p2);
 p1=res;
 }
 printf("%.7f %.7f %.7f\n",res.x,res.y,res.z);
 }
}