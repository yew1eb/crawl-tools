/*HDU 1205 é¸½å·¢åç*/
#include<stdio.h>
__int64 sum;
int main()
{
   int n,i,num,maxn,cas;
   scanf("%d",&cas);
   while(cas--)
   {
       scanf("%d",&n);
      sum=maxn=0;
      for(i=0;i<n;i++)
      {
       scanf("%d",&num);
       if(num>maxn) maxn=num;
         sum+=num;
      }
      if(sum-maxn+1>=maxn) puts("Yes");
      else puts("No");
   }
   return 0;
}