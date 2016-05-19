#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define eps 1e-12
///#define M 1000100
#define LL __int64
///#define LL long long
///#define INF 0x7ffffff
#define INF 0x3f3f3f3f
#define PI 3.1415926535898
#define zero(x) ((fabs(x)<eps)?0:x)

using namespace std;

const int maxn = 10010;

double dp[55][maxn];
double ans[55];
vector<int>g[55];

int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        int n, m, d;
        scanf("%d %d %d",&n, &m, &d);
        for(int i = 1; i <= n; i++) g[i].clear();
        int x, y;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d",&x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int p = 1; p <= n; p++)
        {
            memset(dp, 0, sizeof(dp));
            for(int i = 1; i <= n; i++) dp[i][0] = 1.0/n;
            for(int i = 0; i < d; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    if(j == p) continue;
                    int N = g[j].size();
                    for(int k = 0; k < N; k++)
                    {
                        int u = g[j][k];
                        dp[u][i+1] += dp[j][i]*(1.0/N);
                    }
                }
            }
            ans[p] = 0.0;
            for(int i = 1; i <= n; i++)
            {
                if(i == p) continue;
                ans[p] += dp[i][d];
            }
            printf("%.9lf\n",ans[p]);
        }
    }
    return 0;
}
