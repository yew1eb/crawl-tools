#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <vector>
#include <math.h>
#include <string.h>
#include <queue>
#include <string>
#include <stdlib.h>
#include <algorithm>
//#define LL __int64
#define LL long long
#define eps 1e-9
#define PI acos(-1.0)
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 55;

vector <int> edge[55];

double dp[55][10010];
int n,m,D;

int main()
{
    int test,u,v;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d",&n,&m,&D);
        D++;

        for(int i = 1; i <= n; i++)
            edge[i].clear();
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        for(int i = 1; i <= n; i++)
        {
            memset(dp,0,sizeof(dp));

            for(int d = 1; d <= D; d++)
            {
                if(d == 1)
                {
                    for(int j = 1; j <= n; j++)
                    {
                        if(j != i)
                            dp[j][d] = 1.0/n;
                    }
                }
                else
                {
                    for(int j = 1; j <= n; j++)
                    {
                        if(j != i)
                        {
                            for(int g = 0; g < (int)edge[j].size(); g++)
                            {
                                int k = edge[j][g];
                                if(k != i)
                                    dp[j][d] += dp[k][d-1]*1.0/edge[k].size();
                            }
                        }
                    }
                }
            }
            double ans = 0;
            for(int j = 1; j <= n; j++)
            {
                if(j != i)
                    ans += dp[j][D];
            }
            printf("%.10lf\n",ans);
        }
    }
    return 0;
}
