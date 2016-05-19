#include <stdio.h>
#include <string.h>
#define max(a,b) (a)>(b)?(a):(b)
int main()
{
   int T, n;
   double ans, x;
   scanf("%d",&T);
   while(T--)
   {
      scanf("%d",&n);
      ans = -1000000.0;
      while(n--)
      {
           scanf("%lf",&x);
           ans = max(ans, x);
      }
      printf("%.2f\n",ans);
    } 
   return 0;
}