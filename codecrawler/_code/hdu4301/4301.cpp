#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define mod 100000007
#define maxn 1010
int dp[maxn][2030][2];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[1][1][0]=1;
    dp[1][1][1]=0;
    dp[1][2][1]=1;
    dp[1][2][0]=0;
    for(int i=2;i<maxn;i++)
    {
        for(int j=1;j<2*maxn;j++)
        {
            dp[i][j][0]=(dp[i-1][j][0]+2*dp[i-1][j][1]+dp[i-1][j-1][0]+dp[i-1][j-1][1])%mod;
            if(j>=2)
                dp[i][j][1]=(2*dp[i-1][j-1][0]+dp[i-1][j][1]+2*dp[i-1][j-1][1]+dp[i-1][j-2][0]+dp[i-1][j-2][1])%mod;
            else
                dp[i][j][1]=(2*dp[i-1][j-1][0]+dp[i-1][j][1]+2*dp[i-1][j-1][1])%mod;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        printf("%d\n",(dp[n][k][0]+dp[n][k][1])%mod);
    }
    return 0;
}
