#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,k,dp[105][105],a[105][105];
int to[4][2] = {1,0,-1,0,0,1,0,-1};

int check(int x,int y)
{
    if(x<1 || y<1 || x>n || y>n)
        return 1;
    return 0;
}

int dfs(int x,int y)
{
    int i,j,l,ans = 0;
    if(!dp[x][y])
    {
        for(i = 1; i<=k; i++)
        {
            for(j = 0; j<4; j++)
            {
                int xx = x+to[j][0]*i;
                int yy = y+to[j][1]*i;
                if(check(xx,yy))
                    continue;
                if(a[xx][yy]>a[x][y])
                    ans = max(ans,dfs(xx,yy));
            }
        }
        dp[x][y] = ans+a[x][y];
    }
    return dp[x][y];
}

int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&k),n>0&&k>0)
    {
        for(i = 1; i<=n; i++)
            for(j = 1; j<=n; j++)
                scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        printf("%d\n",dfs(1,1));
    }

    return 0;
}
