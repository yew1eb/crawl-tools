#include "stdio.h"
#include "string.h"

double Max(double a,double b)
{
    if (a<b) return b;else return a;
}
double ans,dp[1010][1050],a[1010][1010];
int main()
{
    int Case,ii,i,j,aim,k,n,m,peo;

    scanf("%d",&Case);
    for (ii=1;ii<=Case;ii++)
    {
        scanf("%d%d",&n,&m);
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                scanf("%lf",&a[i][j]);

        printf("Case #%d: ",ii);

        aim=(1<<n)-1;
        for (i=0;i<=m;i++)
            for (j=0;j<=aim;j++)
                dp[i][j]=-1;

        dp[0][0]=0;

        for (j=1;j<=m;j++)
            for (i=0;i<=aim;i++)
                if (dp[j-1][i]!=-1)
                    for (k=1;k<=n;k++)
                    {
                        peo=1<<(k-1);
                        if ((i&peo)==peo) continue;
                        peo|=i;
                        if (peo==aim) peo=0;

                        dp[j][peo]=Max(dp[j][peo],dp[j-1][i]+a[k][j]);
                    }
        ans=0;
        for (i=0;i<=aim;i++)
            ans=Max(ans,dp[m][i]);

        printf("%.5lf\n",ans);
    }
}
