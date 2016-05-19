#include <stdio.h>
 
 __int64 num;
 
 int main()
 {
     __int64 sum=0;
     int T,n;
     scanf("%d",&T);
     while(T--)
     {
         int flag = 0;
         sum=0;
         scanf("%d",&n);
         __int64 max = 0;
         for(int i=0;i<n;i++) 
         {
             scanf("%I64d",&num);
             sum += num;
             if(max < num) max = num;
         }
         printf(sum-max+1>=max ? "Yes\n" : "No\n");
     }
     return 0;
 }