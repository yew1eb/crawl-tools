#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
   int n;
   int h,m,s;
   double ans,m1,m2;
   scanf("%d",&n);
   while(n--)
   {
       scanf("%d%d%d",&h,&m,&s);
       if(h>12) h-=12;
       m1=6*m+0.1*s;
       m2=30*h+0.5*m+0.5/60*s;
       ans=fabs(m2-m1);
       if(ans>180) ans=360-ans;
       printf("%d\n",(int)ans);//.0lfä¼è¿ä½
   }
   return 0;
}
