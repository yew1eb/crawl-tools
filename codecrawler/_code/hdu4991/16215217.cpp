#define DeBUG
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <sstream>
#include <map>
#include <list>
#include <bitset>
using namespace std ;
#define zero {0}
#define INF 0x3f3f3f3f
#define EPS 1e-6
#define TRUE true
#define FALSE false
typedef long long LL;
const double PI = acos(-1.0);
//#pragma comment(linker, "/STACK:102400000,102400000")
inline int sgn(double x)
{
    return fabs(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}
#define N 100005
const int mod = 123456789;
int dp[10005][105];
int a[10005];
int b[10005];
std::map<int, int> mp;
int t[100000];
int n, m;
int Sum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum = (sum + t[x]) % mod;
        x -= (x & (-x));
    }
    return sum;
}
void Add(int x, int d)
{
    while (x <= n)
    {
        t[x] = (t[x] + d) % mod;
        x += (x & (-x));
    }
    return;
}
int main()
{
#ifdef DeBUGs
    freopen("1.in", "r", stdin);
#endif

    while (scanf("%d%d", &n, &m) + 1)
    {
        mp.clear();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        int len = unique(b + 1, b + n + 1) - b - 1;
        for (int i = 1; i <= n; i++)
        {
            mp[b[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] = mp[a[i]];
            // printf("%d ", a[i]);
        }

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            dp[i][1] = 1;
        Add(a[1], 1);
        for (int j = 2; j <= m; j++)
        {
            memset(t, 0, sizeof(t));
            for (int i = 1; i <= n; i++)
            {
                // for (int k = 1; k < i; k++)
                //     if (a[i] > a[k])
                //     {
                //         dp[i][j] += dp[k][j - 1];
                //     }
                dp[i][j] = Sum(a[i] - 1);
                Add(a[i], dp[i][j - 1]);
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans + dp[i][m]) % mod;
        }
        printf("%d\n", ans);
    }

    return 0;
}
