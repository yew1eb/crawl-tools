#include <cstdio>
#include <cstring>
#include <cmath>
#define M 50005
#define K 205
int mod[M], sum[M], dp[M][K], p[200005];
int n, k;
void POW()
{
    p[0] = 1;
    for(int i = 1; i <= 4*n; ++i) p[i] = (p[i-1]*10)%k;
}
int main ()
{
    //freopen("in.txt","r",stdin);
    //freopen("ou.txt","w",stdout);
    while(scanf("%d%d",&n, &k)!=EOF)
    {
        POW();
        for(int i=0; i<=n; ++i)
            for(int j=0; j<=k; ++j) dp[i][j]=0;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d",&sum[i]);
            mod[i] =1+ log10(sum[i]*1.0);
        }
        int cnt=mod[1],s=sum[1]%k;
        ++dp[1][s];
        for(int i = 2; i <= n; ++i)
        {
            s = (sum[n-i+2]*p[cnt]+s)%k;
            ++dp[1][s];
            cnt+=mod[n-i+2];
        }
        int ans = dp[1][0];
        for(int i = 2; i <= n; ++i)
        {
            ++dp[i][sum[i]%k];
            for(int j = 0; j < k; ++j)
                if(dp[i-1][j])
                {
                    int t = (j*p[mod[i]]+sum[i])%k;
                    dp[i][t] += dp[i-1][j];
                }
            s=(s*p[mod[i]]+sum[i])%k;
            dp[i][s]-=1;
            ans+=dp[i][0];
            s=(s-(sum[i]*p[cnt])%k+k)%k;
        }
        printf("%d\n",ans);
    }
    return 0;
}