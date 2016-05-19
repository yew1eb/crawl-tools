#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define MAXN 205
#define MAXK 35
#define INF 0x7fffffff
using namespace std;
int a[MAXN];
int dp[MAXK][MAXN];
int cost[MAXN][MAXN];

int main()
{
    int n, m, k, i, j, min, cnt = 0;

    while(scanf("%d%d",&n,&m),n+m)
    {
        for(i=1; i<=n; i++) scanf("%d",&a[i]);
        for(i=1; i<=n; i++)
        for(j=i+1; j<=n; j++)
        {
            cost[i][j] = 0;
            for(k=i; k<=j; k++)
                cost[i][j] +=(int)abs(a[k] - a[(i+j)/2]);
        }
        for(i=1; i<=n; i++)
            dp[1][i] = cost[1][i];
        for(i=2; i<=m; i++)
        for(j=i+1; j<=n; j++)
        {
            min = INF;
            for(k=i; k<=j; k++)
            if(min>dp[i-1][k-1]+cost[k][j])
                min = dp[i-1][k-1]+cost[k][j];
            dp[i][j] = min;
        }
        printf("Chain %d\nTotal distance sum = %d\n\n", ++cnt, dp[m][n]);

    }
    return 0;
}
