#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1010];
int a[1010];
int num[1010];

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset ( dp, 0, sizeof(dp) );
        memset (num, 0, sizeof(num) );
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            dp[i] = 1;
            num[i] = 1;
        }
        num[n + 1] = 1;
        dp[n + 1] = 1;
        a[n + 1] =  1000000010;
        for (int i = 1; i <= n + 1; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (a[i] > a[j] && dp[i] < dp[j] + 1)
                {
                    num[i] = 1;
                    dp[i] = dp[j] + 1;
                }
                else if (a[i] > a[j] && dp[i] == dp[j] + 1)
                {
                    num[i]++;
                }
            }
        }
        if (num[n + 1] > 1)
        {
            printf("%d\n", dp[n + 1] - 1);
            continue;
        }
        int k = n + 1, i;
        while (k > 0 && num[k] == 1)
        {
            for (i = k - 1; i >= 1; i--)
            {
                if (dp[k] == dp[i] + 1 && a[k] > a[i])
                {
                    break;
                }
            }
            k = i;
        }
        if (k == 0)
        {
            printf("%d\n", dp[n + 1] - 2);
            continue;
        }
        printf("%d\n", dp[n + 1] - 1);
    }
    return 0;
}