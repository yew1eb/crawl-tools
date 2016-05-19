#include<stdio.h>
#include<math.h>
#define inf 99999999

double a[10005];
int k,n;

bool check(double x)
{
    int i,sum=0;
    for(i=1;i<=n;i++)
        sum=sum+(int)(a[i]/x);
    if(sum<k)
        return false;
    else
        return true;
}

int main()
{
    int i;
    double left,right,mid,max;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if(n==0&&k==0)
            break;
        max=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lf",&a[i]);
            if(a[i]>max)
                max=a[i];
        }
        left=0,right=max;
        for(i=1;i<=50;i++)
        {
            mid=(left+right)/2;
            if(check(mid))
                left=mid;
            else
                right=mid;
        }
        printf("%.2lf\n",left);
    }
    return 0;
}