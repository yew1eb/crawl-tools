#include<stdio.h>
int main()
{
    int a, b;
    int i, n, sum;
    int x;
    int t;
    while(scanf("%d",&n)!=EOF)
    {
           sum =0;
           for(i=1;i<=n;i++)
           {
                scanf("%d",&x);
                sum+=x;
           }                
           printf("%d\n",sum);
    }
    return 0;
} 