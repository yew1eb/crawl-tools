#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
    int v,w;
};
node g[15][105];
int num[15];
int dp[15][10005];
int main()
{
    int m,n,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        memset(num,0,sizeof(num));
        int i;
        for(i=1;i<=n;i++)
        {
            int j,a,b;
            scanf("%d%d%d",&j,&a,&b);
            g[j][num[j]].w=a;
            g[j][num[j]].v=b;
            num[j]++;
        }
        int j;
        memset(dp,-1,sizeof(dp));
        memset(dp[0],0,sizeof(dp[0]));
        for(i=1;i<=k;i++)
        {
            for(j=0;j<num[i];j++)
            {
                int p;
                for(p=m;p>=g[i][j].w;p--)
                {
                    if(dp[i][p-g[i][j].w]!=-1)
                        dp[i][p]=max(dp[i][p-g[i][j].w]+g[i][j].v,dp[i][p]);
                    if(dp[i-1][p-g[i][j].w]!=-1)
                        dp[i][p]=max(dp[i][p],dp[i-1][p-g[i][j].w]+g[i][j].v);
                }
            }
        }
        if(dp[k][m]==-1)
            printf("Impossible\n");
        else
            printf("%d\n",dp[k][m]);
    }
    return 0;
}
