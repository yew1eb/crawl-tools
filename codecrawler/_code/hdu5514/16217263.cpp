#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;

int N, M, F[maxn], C[maxn];
vector<int> G;

void destory(int n) {
    int m = (int)sqrt(n);
    G.clear();

    for (int i = 1; i <= m; i++) {
        if (n % i == 0) {
            G.push_back(i);
            if (n / i != i)
                G.push_back(n / i);
        }
    }
    sort(G.begin(), G.end());
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int find(int x) { return lower_bound(G.begin(), G.end(), x) - G.begin(); }
ll get(int x, int s) { return 1LL * x * (x + 1) / 2 * s; }

ll solve () {
    memset(F, 0, sizeof(F));
    memset(C, 0, sizeof(C));

    int u;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &u);
        int d = gcd(u, M);
        F[find(d)] = 1;
    }

    int n = G.size();
    for (int i = 0; i < n; i++) {
        if (!F[i]) continue;
        for (int j = i + 1; j < n; j++)
            if (F[j] == 0 && G[j] % G[i] == 0) F[j] = 1;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int v = F[i] - C[i];

        ans = ans + get(M/G[i]-1, G[i]) * v;
        for (int j = i; j < n; j++)
            if (G[j] % G[i] == 0) C[j] += v;
    }
    return ans;
}

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        scanf("%d%d", &N, &M);
        destory(M);
        printf("Case #%d: %lld\n", kcas, solve());
    }
    return 0;
}