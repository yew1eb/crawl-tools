#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define read freopen("q.in","r",stdin)
#define LL long long
#define maxn 105
using namespace std;
int mp[maxn][maxn];
int dp[maxn][maxn][maxn];

int main()
{
    int n,m,c;
    while(~scanf("%d%d%d",&n,&m,&c))
    {
        int i,j;
        memset(dp,0,sizeof(dp));
        memset(mp,0,sizeof(mp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)scanf("%d",&mp[i][j]);
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                for(int k=0;k<=c;k++)
                {
                    if(k>=mp[i][j])dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),max(dp[i-1][j][k-mp[i][j]]+mp[i][j],dp[i][j-1][k-mp[i][j]]+mp[i][j]));

                }

            }

        }
        cout<<dp[n][m][c]<<endl;
    }
}
