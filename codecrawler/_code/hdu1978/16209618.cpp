#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m,dp[105][105],a[105][105];

int check(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m)
        return 1;
    return 0;
}

int dfs(int x,int y)
{
    if(dp[x][y]>=0) return dp[x][y];
    dp[x][y] = 0;
    int i,j;
    for(i = 0; i<=a[x][y]; i++)
        for(j = 0; j<=a[x][y]-i; j++)
        {
            if(check(x+i,y+j))
                continue;
            dp[x][y] = (dp[x][y]+dfs(x+i,y+j))%10000;
        }
    return dp[x][y];
}

int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i = 1; i<=n; i++)
            for(j = 1; j<=m; j++)
                scanf("%d",&a[i][j]);
        memset(dp,-1,sizeof(dp));
        dp[n][m] = 1;
        printf("%d\n",dfs(1,1));
    }

    return 0;
}
