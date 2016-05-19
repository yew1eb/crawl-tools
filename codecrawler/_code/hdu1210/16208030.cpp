#include<stdio.h>
 #include<stdlib.h>
 int main()
 {
     int n,t,k,s;
     while(scanf("%d",&n)!=EOF)
     {
         t=1,s=0;
         while(1)
         {
             if(t<=n)
             {
                 s++;
                 t*=2;
             }
             if(t==n+1)
                 break;
             if(t>n+1)
             {
                 k=t%n;
                 if(k==0)
                 k=n;
                 t=(k-1)*2+1;
                 s++;
             }
             if(t==n+1)
                 break;
         }
         printf("%d\n",s+1);
     }
     return 0;
 }