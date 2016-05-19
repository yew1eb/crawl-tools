#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 2000000000

int a[205];
int w[205][205];
int dp[205][35];

int main()
{
    int i,j,n,m,k,ans,s,cnt=1;
    while(1)
    {
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        if (n==0 && m==0) break;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=n-1;i>=0;i--)
        {
            a[i]=a[i]-a[0]+1;
        }
        for (i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                w[i][j]=0;
                for (k=i;k<=j;k++)
                {
                    w[i][j]+=min(a[k]-a[i],a[j]-a[k]);
                }
            }
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<=i;j++)
            {
                dp[i][1]+=a[i]-a[j];
            }
        }
        for (j=2;j<=m;j++)
        {
            for (i=j-1;i<n;i++)
            {
                dp[i][j]=INF;
                for (k=j-2;k<i;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[k][j-1]+w[k][i]);
                }
            }
        }
        printf("Chain %d\n",cnt++);
        printf("Total distance sum = ");
        ans=INF;
        for (i=0;i<n;i++)
        {
            s=0;
            for (j=i+1;j<n;j++)
            {
                s+=a[j]-a[i];
            }
            ans=min(ans,s+dp[i][m]);
        }
        printf("%d\n\n",ans);
    }
    return 0;
}
