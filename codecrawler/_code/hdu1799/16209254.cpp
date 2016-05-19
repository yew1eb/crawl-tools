#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
const int maxn=2002;
const int mod=1007;
int dp[maxn][maxn];
void init()
{
    memset(dp,0,sizeof(dp));
    int i,j,k;
    for(i=1;i<maxn;i++)
        dp[i][1]=i%mod;
    //m>næ¶ï¼dp=0
    for(i=2;i<maxn;i++)//n
    {
        dp[i][i]=1;
        for(j=2;j<i;j++)//m
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,i,j,k;
        scanf("%d%d",&m,&n);
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
/*
    å¨æè§åï¼
    dp[i][j]è¡¨ç¤ºjå±ï¼ç»æ­¢å¼ä¸ºiçè®¡ç®éã
    ådp[i][j]=âdp[k][j](0<=k<=n-1)=dp[i-1][j]+dp[i-1][j-1];
*/
