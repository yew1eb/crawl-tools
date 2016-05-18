//#pragma comment(linker, "/STACK:102400000,102400000")

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define N 1000002
#define P 1000000007ll

ll fac[N], f[N], ff[N], cc[N], ans;
vector<int> g[N];
int n, c[N];

ll PowerMod(ll a, ll b, ll k) {
    ll tmp = a, ret = 1;
    while (b) {
        if (b & 1) ret = ret * tmp % k;
        tmp = tmp * tmp % k;
        b >>= 1;
    }
    return ret;
}

void dfs1(int now, int fa) {
    int u;
    c[now]++;
    for (int i=0; i<g[now].size(); i++)
        if ((u = g[now][i]) != fa) {
            dfs1(u, now);
            c[now] += c[u];
        }

    ff[now] = cc[now] = 1;
    for (int i=0; i<g[now].size(); i++)
        if ((u=g[now][i]) != fa) {
            ff[now] = ff[now]*f[u] % P;
            cc[now] = cc[now]*fac[c[u]] % P;
        }
    f[now] = (ff[now]*fac[c[now]-1]%P) * PowerMod(cc[now], P-2, P) % P;
}

void dfs2(int now, int fa) {
    int u;  ll t;
    if (now != 1) {
        t = f[now]*(n-c[now])%P*cc[now]%P;
        t = PowerMod(t, P-2, P);
        f[now] = f[fa]*ff[now]%P*fac[c[now]]%P*t%P;
        ans = (ans + f[now]*f[now]) % P;
    }
    for (int i=0; i<g[now].size(); i++)
        if ((u = g[now][i]) != fa) dfs2(u, now);
}

int main() {
    int size = 256 << 20; // 256MB
    char *p = (char*)malloc(size) + size;
    __asm__("movl %0, %%esp\n" :: "r"(p));


    fac[0] = 1; for (int i=1; i<N; i++) fac[i] = fac[i-1]*i % P;

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i=0; i<=n; i++) { c[i] = 0; g[i].clear(); }
        for (int i=1, x, y; i<n; i++) {
            scanf("%d%d", &x, &y);
            g[x].push_back(y); g[y].push_back(x);
        }
        dfs1(1, 0);
        ans = f[1] * f[1] % P;
        dfs2(1, 0);

        printf("%I64d\n", ans);
    }

    return 0;
}
