#include<stdio.h>
int main()
{
    int n,i;
    int a1,a2,b1,b2,c1,c2;
    int a,b,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
       scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
       c=(c1+c2)%60;
       b=( (c1+c2)/60+b1+b2 )%60;
       a=( ((c1+c2)/60+b1+b2 )/60+a1+a2);
       printf("%d %d %d\n",a,b,c);
     }
    return 0;
}
