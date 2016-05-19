#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int MOD = 1000000007;
char x[maxn],y[maxn];
int dp[maxn][maxn];
int f[maxn][maxn];
int pre[maxn][27];
int tmp[27];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",x);
        scanf("%s",y);
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        memset(tmp,0,sizeof(tmp));
        int n = strlen(x),m = strlen(y);

        for(int i=1;i<=m;i++)
        {
            tmp[ y[i-1] - 'a' ] = i;
            for(int j=0;j<26;j++)
                pre[i][j] = tmp[j];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if( x[i-1] == y[j-1] )
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                else dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
            }
        }
        memset(f,0,sizeof(f));
        for(int i = 0; i <= n; i++ )
        {
            for(int j = 0; j <= m; j++ )
            {
                if( dp[i][j] == 0 )
                {
                    f[i][j] = 1;
                }
                else {
                    if( dp[i-1][j] == dp[i][j] )
                        f[i][j] = ( f[i][j] + f[i-1][j]) % MOD;
                    if( pre[j][ x[i-1]-'a'] )
                    {
                        int p = pre[j][ x[i-1]-'a'];
                        if( dp[i-1][p-1] + 1 == dp[i][j] )
                        f[i][j] = ( f[i][j] + f[i-1][p-1] ) % MOD;
                    }
                }
            }
        }
       printf("%d\n",f[n][m]);
    }
    return 0;
}
