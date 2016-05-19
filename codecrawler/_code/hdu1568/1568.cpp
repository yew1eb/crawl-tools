#include <stdio.h>
 #include <math.h>
 int main()
 {
     const int N=21;
     int f[N]={0,1};
     for (int i=2;i<N;i++) f[i]=f[i-1]+f[i-2];
     int n;
     while (scanf("%d",&n)!=EOF)
     {
         if (n<N)
         {
             printf("%d\n",f[n]);
             continue;
         }
         double e,a;
         e=log10(1/sqrt(5))+n*log10((1+sqrt(5))/2);
         a=pow(10.0,e-floor(e));
         printf("%d\n",(int)(a*1000));
     }
 }