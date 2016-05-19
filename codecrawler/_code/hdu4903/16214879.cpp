#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for(int i = pos[x]; i; i = g[i].nex)
using namespace std;
typedef long long LL;
const int N = 15, mod = 1000000007;
int T, n, L, m, l, d[N]; LL ans, u[N], C[N][N];
void Find(int x, LL y) {
    LL n1 = 1, num = 1, n3, n2 = 1, t = 0, num0;
    Rep(j, 1, l) n1 = n1 * (L - (x - d[j] - 1)) % mod, n2 = n2 * (L - (x - d[j])) % mod;
    n3 = n1, n1 = (n1 - n2 + mod) % mod;
    if (x == m) {
        Rep(j, l + 1, n - 1) num = (num * n3 % mod) * u[j - l - 1] % mod;
        (num *= u[n - l - 1]) %= mod;
        (ans += (n1 * num % mod) * y) %= mod;
        return ;
    }
    Find(x + 1, y);
    while (l < n - 1) {
        d[++ l] = x, num = (num * n1 % mod) * u[t] % mod; t ++; num0 = num;
        if (l != n - 1) num0 = num0 * C[n - l + t - 1][t] % mod;
        Find(x + 1, y * num0 % mod);
    }
    while (d[l] == x) l --;
}
int main()
{
    scanf ("%d", &T);
    C[0][0] = 1;
    Rep(i, 1, 12) {
        C[i][0] = 1;
        Rep(j, 1, 12) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    while (T --) {
        scanf ("%d%d%d", &n, &m, &L);
        ans = 0; u[0] = 1;
        Rep(i, 1, n) u[i] = u[i - 1] * L % mod;
        d[l = 1] = 0; Find(1, 1);
        printf("%I64d\n", ans);
    }

    return 0;
}
