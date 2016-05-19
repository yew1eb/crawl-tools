#include<iostream>
#include<cstdio>
#include<set>
#define inf 1000000000000000
#define ll long long
using namespace std;
const ll mod=1000000007;
ll dp[2005][2005];
ll che[2005];
int n,m;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        che[0]=1;
        for(int i=1;i<=n;i++)
            che[i]=che[i-1]*m%mod;
        dp[1][0]=0;
        dp[1][1]=m;
        for(int i=2;i<=n;i++) {
            int k=min(i,m);
            for(int j=0;j<=k;j++) {
                dp[i][j]=0;
                if(j-1>=0) {
                    dp[i][j]=(dp[i][j]+dp[i-1][j-1]*(m-j+1))%mod;
                }
                if(j+1<=min(i-1,k)) {
                    dp[i][j]=(dp[i][j]+dp[i-1][j+1]*(j+1))%mod;
                }
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++) {
            ans=(ans+dp[i][i&1]*(n-i+1)%mod*che[n-i]%mod)%mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}