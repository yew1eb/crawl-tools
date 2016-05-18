#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<iostream>
#include<map>
using namespace std;
#define inf 0x3f3f3f3f
#define Max 110
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
__int64 dp[220][220][22][2];
int n,m,k;
void init()
{
    int i,j,k;
    memset(dp,0,sizeof(dp));
    dp[1][1][1][1]=1;
    dp[1][0][1][0]=1;
    for(i=1;i<201;i++)
        dp[i][0][1][0]=1;
    for(i=2;i<201;i++)
        for(j=1;j<=i;j++)
            for(k=1;k<=20&&k<=i;k++)
            {
                dp[i][j][k][0]=dp[i-1][j][k][0]+dp[i-1][j][k-1][1];
                dp[i][j][k][1]=dp[i-1][j-1][k][1]+dp[i-1][j-1][k-1][0];
            }
}
int main()
{
    init();
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        printf("%I64d\n",dp[n][m][k][0]+dp[n][m][k][1]);
    }
}