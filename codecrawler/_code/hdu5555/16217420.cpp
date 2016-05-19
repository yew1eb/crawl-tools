#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1050;
const int mod = 105225319;

int N, L[maxn], R[maxn];
int dp[maxn][maxn], G[maxn][maxn];
vector<int> B[maxn];

int find(int id, int x) {
    for (int i = 0; i < B[id].size(); i++)
        if (B[id][i] == x) return i;
    return -1;
}

bool init () {
    memset(G, 0, sizeof(G));
    for (int i = 1; i < N; i++) {
        int n = B[i].size(), m = B[i+1].size();
        if (n > 10) return false;

        for (int j = 0; j < m; j++) {
            int mv = find(i, B[i+1][j]);
            for (int s = 0; s < (1<<n); s++) {
                if (mv == -1 || (s&(1<<mv)))
                    G[i][s] |= (1<<j);
            }
        }

    }
    for (int i = 1; i <= N; i++) {
        int n = B[i].size();
        for (int s = 0; s < (1<<n); s++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                int v = B[i][j];
                if (s&(1<<j) && R[v] == i) c++;
            }
            G[i][s] = (c ? -1 : G[i][s]);
        }
    }
    return B[N].size() <= 10;;
}

int solve (int k) {
    if (!init()) return 0;
    memset(dp, 0, sizeof(dp));
    dp[1][(1<<B[1].size())-1] = 1;

    for (int i = 1; i <= N; i++) {
        int n = B[i].size();
        for (int s = 0; s < (1<<n); s++) {
            if (dp[i][s] == 0) continue;

            for (int j = 0; j < n; j++) if (s&(1<<j)) {
                int v = G[i][s^(1<<j)];
                if (v != -1)
                    dp[i+1][v] = (dp[i+1][v] + dp[i][s]) % mod;
            }
            int u = G[i][s];
            if (u != -1)
                dp[i+1][u] = (dp[i+1][u] + dp[i][s]) % mod;
    //      printf("%d ", dp[i][s]);
        }
    //  printf("\n");
    }
    int ans = dp[N+1][0];
    for (int i = 1; i <= k; i++)
        ans = (1LL * ans * i) % mod;
    return ans;
}

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) scanf("%d", &L[i]);
        for (int i = 1; i <= N; i++) scanf("%d", &R[i]);

        int cnt = 0;
        for (int i = 1; i <= N; i++) B[i].clear();
        for (int i = 1; i <= N; i++) if (R[i] - L[i] + 1 != N) {
            for (int j = L[i]; j <= R[i]; j++) B[j].push_back(i);
            cnt++;
        }

        printf("Case #%d: %d\n", kcas, solve(N - cnt));
    }
    return 0;
}