/*hdu 3668
����:�������ཻ��Բ����(���м��ཻ,���ཻ��Գ�)�������
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int main()
{
 int r,h;
 while(scanf("%d%d",&r,&h)!=EOF)
 {
 double v=pi*r*r*h;
 double t;
 if(r*2<h) t=16.0/3*r*r*r;
 else
 {
 double k=1.0*h/2;
 double x0=sqrt(0.0+r*r-k*k);
 double s1,s2;
 s1=(r*r*r-r*r*x0-1.0/3*r*r*r+1.0/3*x0*x0*x0);
 s2=k*k*x0;
 t=(s1+s2)*8;
 }
 double cnt=2*v-t;
 printf("%.4lf\n",cnt);
 }
 return 0;
}