#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define PI 3.141592653589793
double DI(double x1,double y1,double x2,double y2)
{
     return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));    
}
int main()
{
  double x1,y1,x2,y2,x3,y3,ans,r,s,p;
  while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
  {
       double a,b,c;
       a=DI(x1,y1,x2,y2);
       b=DI(x1,y1,x3,y3);
       c=DI(x2,y2,x3,y3);
       p=(a+b+c)/2.0;
       s=sqrt(p*(p-a)*(p-b)*(p-c));//æµ·ä¼¦å¬å¼æ±ä¸è§å½¢é¢ç§¯
       r=(a*b*c)/(4.0*s);//å©ç¨ä¸è§å½¢é¢ç§¯åå¤æ¥ååå¾
       ans=2*PI*r;
       cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans<<endl;
  }    
  return 0;
} 