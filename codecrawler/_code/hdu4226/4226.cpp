#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>


using namespace std;


const int maxn = 1111;
const double PI = 3.14159265358979323846;
const double oo = (1 << 30) * 1.0;
char kind[maxn];
double len[maxn];
double dp[maxn][12];
int n, m;


// 计算从第a段的第b条跑道的起点走到第c条跑道的终点所需的最短路程
double calc(int a, int b, int c)
{
    if (kind[a] == 'R' || kind[a] == 'L')
    {
        if (b == c)
        {
            double r;
            if (kind[a] == 'R') // 这里要根据不同的弯道确定半径
                r = (b - 1) * 10.0 + 5 + len[a];
            else r = (m - b) * 10.0 + 5 + len[a];
            return (PI / 2.0 * r);
        }
        else return oo; // 不可达，返回无穷大
    }
    else
    {
        if (len[a] < abs((c - b)) * 100.0) // 最初写的是len[a] < 100.0,就是WA在了这里，题目没看清
            return oo;
        else
            return (sqrt(len[a] * len[a] + (b - c) * 10 * (b - c) * 10));
    }
}


double DP()
{
    for (int i = 0; i <= m; ++i)
        dp[0][i] = 0.0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = oo;
            for (int k = 1; k <= m; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i-1][k] + calc(i, k, j));
            }
        }
    }
    double ans = oo;
    for (int i = 1; i <= m; ++i)
        ans = min(ans, dp[n][i]);
    return ans;
}


int main()
{
    while (scanf("%d %d", &n, &m))
    {
        if (n == 0 && m == 0)
            break;
        char ch;
        for (int i = 1; i <= n; ++i)
        {
            scanf("\n%c %lf", &kind[i], &len[i]);
        }
        printf("%.2lf\n", DP());
    }
    return 0;
}
