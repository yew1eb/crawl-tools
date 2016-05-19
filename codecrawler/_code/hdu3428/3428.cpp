#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

#define inff 0x3fffffff
#define maxn 105
int dp[25][15000];
int p[25],w[25];
int n,m;
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int i,j,k;
        for(i=1;i<=n;i++)
            scanf("%d",&p[i]);
        for(i=1;i<=m;i++)
            scanf("%d",&w[i]);
        memset(dp,0,sizeof(dp));
        dp[0][7500]=1;
        for(i=1;i<=m;i++)
            for(k=1;k<=15000;k++)
            {
                if(dp[i-1][k])
                {
                    for(j=1;j<=n;j++)
                        dp[i][k+p[j]*w[i]]+=dp[i-1][k];

                }
            }
        printf("%d\n",dp[m][7500]);
    }
}