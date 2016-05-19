#include "stdio.h"
#include "string.h"

const int inf=0x3f3f3f3f;
int dp[210][210];
int Min(int a,int b)
{
    if (a<b) return a;
    else return b;
}
int a[210],b[210];

int main()
{
    int t,i,n,l,k,ii,j;
    scanf("%d",&t);
    for (ii=1;ii<=t;ii++)
    {
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (i=1;i<=n;i++)
            scanf("%d",&b[i]);
        a[0]=b[0]=a[n+1]=b[n+1]=0;
        memset(dp,inf,sizeof(dp));
        for (i=1;i<=n;i++)
            dp[i][i]=a[i]+b[i-1]+b[i+1];

        for (j=2;j<=n;j++)
        {
            for (i=1;i<=n-j+1;i++)
            {
                k=i+j-1;
                dp[i][k]=Min(dp[i+1][k]+a[i]+b[i-1]+b[k+1],dp[i][k-1]+a[k]+b[k+1]+b[i-1]);
                for (l=i+1;l<k;l++)
                    dp[i][k]=Min(dp[i][k],dp[i][l-1]+dp[l+1][k]+a[l]+b[i-1]+b[k+1]);

            }

        }



        printf("Case #%d: %d\n",ii,dp[1][n]);


    }
    return 0;
}
