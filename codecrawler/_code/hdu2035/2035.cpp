#include<stdio.h>
 #include<stdlib.h>
 int main()
 {
     int n,m,mul;
     while(~scanf("%d%d",&n,&m)&&(n||m))
     {
         mul=1;
         while(m--)
             mul=(mul*n)%1000;
             printf("%d\n",mul);
     }
     system("pause");
     return 0;
 }