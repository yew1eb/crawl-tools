#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define max(a,b)    ((a)>(b)?(a):(b))
const int maxn = 33;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, rmb, cost[maxn], dp[505][2];
        int i, j;
        scanf("%d %d", &n, &rmb);
        for (i=0; i<n; i++) scanf("%d", &cost[i]);
        memset(dp, 0, sizeof(dp));
        for (i=0; i<=rmb; i++) dp[i][1] = 1;
        for (i=0; i<n; i++)
        {
            for (j=rmb; j>=cost[i]; j--)
            {
                if (dp[j][0] == dp[j-cost[i]][0] + 1)
                    dp[j][1] = dp[j-cost[i]][1] + dp[j][1];
                else if (dp[j][0] < dp[j-cost[i]][0] + 1)
                {
                    dp[j][0] = dp[j-cost[i]][0] + 1;
                    dp[j][1] = dp[j-cost[i]][1];
                }
            }
        }
        if (dp[rmb][0] != 0)
            printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n", dp[rmb][1], dp[rmb][0]);
        else
            printf("Sorry, you can't buy anything.\n");
    }
    return 0;
}
