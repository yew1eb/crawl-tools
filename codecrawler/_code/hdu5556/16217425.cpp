#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
const int maxn = 105;
const int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N, M, K, ans, idx[maxn][maxn];
bool used[maxn], xset[maxn];
char str[maxn][maxn];
vector<int> G[maxn];
vector<pii> T[20];

void init () {
    K = 0;
    memset(idx, 0, sizeof(idx));
    memset(xset, false, sizeof(xset));
    for (int i = 0; i < 10; i++) T[i].clear();

    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", str[i]);
        for (int j = 0; j < M; j++) {
            if (str[i][j] == '.') {
                idx[i][j] = ++K;
                if ((i+j) % 2 == 1)
                    xset[K] = true;
            } else
                T[str[i][j] - '0'].push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (str[i][j] == '.' && ((i+j)&1)) {
                int u = idx[i][j];
                G[u].clear();
                for (int d = 0; d < 4; d++) {
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];
                    if (x < 0 || x >= N || y < 0 || y >= M || idx[x][y] == 0) continue;
                    G[u].push_back(idx[x][y]);
                }
            }
        }
    }
}

void draw(int u) {
    for (int i = 0; i < T[u].size(); i++) {
        int x = T[u][i].first, y = T[u][i].second;
        for (int d = 0; d < 4; d++) {
            int p = x + dir[d][0], q = y + dir[d][1];
            if (p < 0 || p >= N || q < 0 || q >= M || idx[p][q] == 0) continue;
            used[idx[p][q]] = true;
        }
    }
}

int distance(int a, int b) {
    int ret = 0x3f3f3f3f;
    for (int i = 0; i < T[a].size(); i++) {
        for (int j = 0; j < T[b].size(); j++)
            ret = min(ret, abs(T[a][i].first-T[b][j].first) + abs(T[a][i].second-T[b][j].second));
    }
    return ret;
}

bool judge (int s, int u) {
    for (int i = 0; i < u; i++) {
        if ((s&(1<<i)) && distance(i, u) <= 1)
            return false;
    }
    return true;
}

int L[maxn];
bool t[maxn];

bool match(int u) {
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (used[v]) continue;
        if (!t[v]) {
            t[v] = true;
            if (!L[v] || match(L[v])) {
                L[v] = u;
                return true;
            }
        }
    }
    return false;
}

int KM () {
    int ret = 0;
    memset(L, 0, sizeof(L));
    for (int i = 1; i <= K; i++) {
        if (used[i] || !xset[i]) continue;
        memset(t, false, sizeof(t));
        if (match(i)) ret++;
    }
    return ret;
}

int solve (int ti) {
    int n = 0;
    for (int i = 1; i <= K; i++) if (used[i]) n++;
    return K - n - KM();
}

void dfs (int d, int s, int add) {

    if (d >= 10) {
        ans = max(ans, solve(add) + add);
        return;
    }

    bool tmp[maxn];
    memcpy(tmp, used, sizeof(used));

    if (T[d].size() && judge(s, d)) {
        draw(d);
        dfs(d + 1, s|(1<<d), add + 1);
        memcpy(used, tmp, sizeof(tmp));
    }

    dfs(d + 1, s, add);
    memcpy(used, tmp, sizeof(tmp));
}

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        init();

        ans = 0;
        memset(used, 0, sizeof(used));
        dfs(0, 0, 0);

        printf("Case #%d: %d\n", kcas, ans);
    }
    return 0;
}