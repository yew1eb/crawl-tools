#include<stdio.h>
#include<math.h>

int main()
{
    int n,i,m;
    double sum;
    scanf("%d",&n);
    while(n--)
    {
       sum=0;
       scanf("%d",&m);
       for(i=1;i<=m;i++)
           sum+=log10((double)i);
       printf("%d\n",(int)sum+1);
    }
    return 0;
}