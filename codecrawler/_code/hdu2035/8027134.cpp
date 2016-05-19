#include<stdio.h>
int main()
{
    int a, b;
    int i;
    int t;
    while(scanf("%d%d",&a,&b),a+b)
    {
         t =1;
         for(i=1;i<=b;i++)
           t=(t*a)%1000;
         printf("%d\n",t);
    }
    return 0;
}