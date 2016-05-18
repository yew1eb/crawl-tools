#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn=220;
int n;
int t[maxn],d[maxn],ans[maxn];
int dp[maxn][maxn][2];
int w[maxn][maxn][2];
int dist[maxn][maxn];

void find(int l,int r,int p)
{
    if (dp[l][r][p]!=-1) return;
    if (p==0)
    {
        find(l+1,r,0);
        if (dp[l+1][r][0]>0&&t[l]>=dp[l+1][r][0]+dist[l][l+1])
        {
            dp[l][r][p]=dp[l+1][r][0]+dist[l][l+1];
            w[l][r][p]=0;
        }
        else
        dp[l][r][p]=0;

        find(l+1,r,1);
        if (dp[l+1][r][1]>0&&t[l]>=dp[l+1][r][1]+dist[l][r]&&(dp[l][r][p]==0||dp[l][r][p]>dp[l+1][r][1]+dist[l][r]))
        {
            dp[l][r][p]=dp[l+1][r][1]+dist[l][r];
            w[l][r][p]=1;
        }
    }
    else
    {
        find(l,r-1,1);
        if (dp[l][r-1][1]>0&&t[r]>=dp[l][r-1][1]+dist[r-1][r])
        {
            dp[l][r][p]=dp[l][r-1][1]+dist[r-1][r];
            w[l][r][p]=1;
        }
        else
        dp[l][r][p]=0;

        find(l,r-1,0);
        if (dp[l][r-1][0]>0&&t[r]>=dp[l][r-1][0]+dist[l][r]&&(dp[l][r][p]==0||dp[l][r][p]>dp[l][r-1][0]+dist[l][r]))
        {
            dp[l][r][p]=dp[l][r-1][0]+dist[l][r];
            w[l][r][p]=0;
        }
    }
}
void work(int l,int r,int p,int k)
{
    if (p==0) ans[k]=l;
    else ans[k]=r;
    if (k==n) return;
    if (p==0)
    work(l+1,r,w[l][r][p],k+1);
    else
    work(l,r-1,w[l][r][p],k+1);
}
void print()
{
    for (int i=1;i<n;i++)
    printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
}
int main()
{
    //freopen("in.txt","r",stdin);
    while (~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&t[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&d[i]);
        for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
        dist[i][j]=dist[j][i]=d[j]-d[i];
        memset(dp,-1,sizeof(dp));
        for (int i=1;i<=n;i++)
            dp[i][i][0]=dp[i][i][1]=1;
        find(1,n,0);//站在l点，最快多长时间结束；
        if (dp[1][n][0]>0)
        {
            work(1,n,0,1);
            print();
            continue;
        }
        find(1,n,1);//站在r点，最快多长时间结束；
        if (dp[1][n][1]>0)
        {
            work(1,n,1,1);
            print();
            continue;
        }
        printf("Mission Impossible\n");
    }
    return 0;
}
