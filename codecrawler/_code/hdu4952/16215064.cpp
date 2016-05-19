#include<stdio.h>
int main()
{
   __int64  k,i,y,x,a,b,cnt=1,z;
   while(scanf("%I64d%I64d",&x,&k)!=EOF)
   {
     if(x==0&&k==0)
       break;
      printf("Case #%I64d: ",cnt++);
      for(i=2;i<=k;i++)
      {
         y=x;
         if(x%i!=0)
         {
           z=x/i;
           z++;
           x=z*i;
         }
         a=x-y;
         b=x/i;
         if(a==b)
           break;
      }
      if(i<=k)
         x+=(k-i)*b;
     printf("%I64d\n",x);
   }
   return 0;
}
