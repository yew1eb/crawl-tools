#include<stdio.h>
int main()
{
    int s,n,i;
    double sum,t;
    scanf("%d",&s);
    while(s--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            if(i%2==1)
            {
                sum=sum+(double)(1.0/i);
            }
            if(i%2==0)
            {
                sum=sum-(double)(1.0/i);
            }
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}