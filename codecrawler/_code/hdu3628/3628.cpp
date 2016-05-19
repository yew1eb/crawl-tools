#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-9;
#define Z(x) (fabs(x)<eps)
double r,w,v,X,E;
double f(double m)
{
 if(Z(r))
 {
 return 0.5*X*v*v*m*m;
 }
 double ret=X*v*sqrt(r*r*w*w+v*v);
 double sq=r*r/v/v;
 double tmp=sqrt(m*m+sq);
 double res=0.5*m*tmp+0.5*sq*log(m+tmp);
 return ret*res;
}
int main()
{
 while(scanf("%lf%lf%lf%lf%lf",&r,&w,&v,&X,&E))
 {
 if(Z(r)&&Z(w)&&Z(v)&&Z(X)&&Z(E))break;
 double m,low=0.0,high=30.0*24.0*3600.0;
 double f0=f(0.0);
 int time=50;
 while(time--)
 {
 m=(low+high)*0.5;
 if(f(m)-f0>=E)high=m;
 else low=m;
 }
 printf("%.4f\n",m+eps);
 }
}