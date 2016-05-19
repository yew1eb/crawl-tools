#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

double min(double a,double b)
{
    if(a>b)
    return b;
    return a;

}

int main()
{
    int n,m,i,j,val[10005];
    double dp[10005],p[10005];
    while(~scanf("%d%d",&n,&m),n+m)
    {
        for(i = 1;i<=m;i++)
        {
            scanf("%d%lf",&val[i],&p[i]);
            p[i] = 1-p[i];
        }
        for(i = 0;i<=n;i++)
        dp[i] = 1.0;
        for(i = 1;i<=m;i++)
        {
            for(j = n;j>=val[i];j--)
            {
                dp[j] = min(dp[j],dp[j-val[i]]*p[i]);
            }
        }
        printf("%.1f%%\n",(1-dp[n])*100);
    }

    return 0;
}
