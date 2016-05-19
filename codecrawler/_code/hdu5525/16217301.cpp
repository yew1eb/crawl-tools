#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL base = 1e9 + 7;
const LL mod = 1e9 + 6;
const int maxn = 100005;
int n, a[maxn], f[maxn], p[maxn], tot = 0, x;
LL ans[maxn], qur, L[maxn], R[maxn];

struct point
{
    int x, y;
    point(int x = 0, int y = 0) :x(x), y(y){}
};
vector<point> map[maxn];

void pre()
{
    for (int i = 2; i < maxn; i++)
    {
        if (!f[i]) { map[i].push_back(point(tot, 1)); f[i] = tot; p[tot++] = i; }
        else
        {
            for (int j = 0; j < tot; j++)
            if (i%p[j] == 0)
            {
                int u = i / p[j], v = 1;
                for (int k = 0; k < map[u].size(); k++)
                    if (map[u][k].x != j) map[i].push_back(map[u][k]);
                    else v += map[u][k].y;
                map[i].push_back(point(j, v));
                break;
            }
        }
        for (int j = 0; j < tot&&i*p[j] < maxn; j++)
        {
            f[i*p[j]] = -1;
            if (i%p[j] == 0) break;
        }
    }
}

LL get(LL x, LL y)
{
    LL ans = 1;
    for (x %= base; y; y >>= 1)
    {
        if (y & 1) ans = ans*x%base;
        x = x*x%base;
    }
    return ans;
}

int main()
{
    pre();
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i <= tot; i++) ans[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            for (int j = 0; j < map[i].size(); j++)
            {
                ans[map[i][j].x] += (LL)map[i][j].y*x;
            }
        }
        for (int i = 0; i < tot; i++)
        {
            L[i] = (ans[i] + 1) % mod;
            if (i) L[i] = L[i] * L[i - 1] % mod;
        }
        for (int i = tot; i; i--)
        {
            R[i] = (ans[i] + 1) % mod;
            if (i < tot) R[i] = R[i] * R[i + 1] % mod;
        }
        qur = 1;
        for (int i = 0; i < tot; i++)
        {
            LL u = ans[i], v = ans[i] + 1;
            if (u % 2 == 0) u = u / 2; else v = v / 2;
            u = (u%mod)*(v%mod) % mod;
            if (i) u = u*L[i - 1] % mod;
            u = u*R[i + 1] % mod;
            qur = qur*get(p[i], u) % base;
        }
        printf("%I64d\n", qur);
    }
    return 0;
}