#include<stdio.h>
 int main()
 {
     int A,B;
     while(scanf("%d%d",&A,&B)!=EOF)
     {
         printf("%d %d\n",A*B-A-B,(A-1)*(B-1)/2);
     }    
     return 0;
 }