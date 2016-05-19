#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define mp make_pair
#define rep(i, n) for (int i = 0; i < n; ++i)

struct myHash {
 const static int mod = 10007;
 const static int size = 100007;
 int head[mod], nxt[size], cs;
 int s1[size], s2[size], cnt[size], diff[size];
 int getHash(int x1, int x2, int d) { 
 return abs((x1 * x2 + x1 + x2) * (d + 65) + d + 64) % mod; 
 }
 void clear() { 
 cs = 0, memset(head, -1, sizeof(head)); 
 }
 int find(int x1, int x2, int d) {
 int u = getHash(x1, x2, d);
 for (int i = head[u]; i != -1; i = nxt[i])
 if (s1[i] == x1 && s2[i] == x2 && diff[i] == d) return i;
 return -1;
 }
 void insert(int x1, int x2, int d) {
 int u = getHash(x1, x2, d);
 s1[cs] = x1, s2[cs] = x2, diff[cs] = d, cnt[cs] = 0;
 nxt[cs] = head[u], head[u] = cs++;
 }
 int push(int x1, int x2, int d, int c) {
 int t = find(x1, x2, d);
 if (t == -1) {
 insert(x1, x2, d);
 t = cs - 1;
 }
 cnt[t] += c;
 return t;
 }
};

const char *base = "ox.";
const int maxn = 10;
const int maxs = 2000000;
int n, m, sg[maxn][maxn];
int v[maxn][maxn];
char g[maxn][maxn];
int state[maxn], cp, np, tot;
int pre[maxs];
int ynn[2][maxn][maxn];
int result, flag, tool[maxn], rd;
myHash dp[2];
vector<int> beg;

inline int get(int s, int p) {
 return (s >> p) & 1;
}

void expand(int s) {
 for (int i = 0; i < m; ++i) {
 state[i] = s & 7;
 s >>= 3;
 }
}
int encode() {
 int s = 0;
 for (int i = m - 1; i >= 0; --i) {
 s = (s << 3) | state[i];
 }
 return s;
}

void preWork() {
 dp[0].clear(); beg.clear();
 int tot = 1 << m, j, k;
 for (int s = 0; s < tot; ++s) {
 for (j = 0; j < m; ++j) {
 if (sg[0][j] != 2 && sg[0][j] != ((s>>j)&1)) break;
 }
 if (j < m) continue;
 for (k = 1, j = state[0] = 0; k < m; ++k) {
 if (((s>>k)&1) != ((s>>(k-1))&1)) ++j;
 state[k] = j;
 }
 int cc = 0;
 for (int j = 0; j < m; ++j) {
 if (s & (1 << j)) cc += v[0][j];
 else cc -= v[0][j];
 }
 int t = dp[0].push(s, encode(), cc, 1);
 beg.push_back(s);
 pre[t] = -1;
 }
}

bool checkl(int s, int x) { 
 expand(s);
 for (int i = 0; i < m; ++i) {
 if (i != x && state[i] == state[x]) return false;
 }
 return true;
}

void weihu() {
 memset(tool, -1, sizeof(tool));
 for (int i = 0, j = 0; i < m; ++i) {
 if (tool[state[i]] == -1) {
 tool[state[i]] = j++;
 }
 }
 for (int i = 0; i < m; ++i) state[i] = tool[state[i]];
}

void un(int s, int a, int b) {
 expand(s);
 b = state[b], a = state[a];
 for (int i = 0; i < m; ++i) {
 if (state[i] == b) state[i] = a;
 }
}

void create(int s, int a) {
 expand(s);
 int j = -1;
 for (int i = 0; i < m; ++i) {
 if (i != a && state[i] > j) j = state[i];
 }
 state[a] = j + 1;
}

bool checkc(int s, int x) {
 for(int i = 0; i < m; ++i) {
 if (i != x && get(s, i) == get(s, x)) return true;
 }
 return false;
}
int ans[maxn*maxn];

void dfs(int u, int p) {
 int c = pre[p]&1;
 if (pre[p] == -1) {
 int s1 = beg[p];
 for (int i = 0; i < m; ++i) {
 ans[i] = (s1 >> i) & 1;
 }
 } else {
 ans[u + m - 1] = c;
 dfs(u - 1, pre[p]>>1);
 }
}

void output(int u, int p, int c) {
 for (int i = u + 1; i < n * m; ++i) ans[i] = c;
 dfs(u, p);
}

int clac(int x, int y, int c) {
 int cc = 0;
 for (int j = y; j < m; ++j) {
 if (c) cc += v[x][j];
 else cc -= v[x][j];
 }
 for (int i = x + 1; i < n; ++i) {
 for (int j = 0; j < m; ++j) {
 if (c) cc += v[i][j];
 else cc -= v[i][j];
 }
 }
 return cc;
}

int bfs() {
 preWork();
 int u = tot = 0;
 cp = 0, np = 1;
 for (int i = 0; i < n; ++i) {
 for (int j = ((!i)?(m-1):(0)); j < m; ++j) {
 if (i == n - 1 && j == m - 1) return u;
 dp[np].clear();
 tot += dp[cp].cs;
 for (int st = 0; st < dp[cp].cs; ++st) {
 for (int c = 0; c < 2; ++c) {
 int x = i, y = j, s1 = dp[cp].s1[st], s2 = dp[cp].s2[st];
 int x1 = get(s1, j), x2 = get(s1, j + 1), x3 = get(s1, m);
 if (j == m - 1) {
 s1 ^= x3 << m;
 x1 = x3 = -1, x2 = get(s1, 0); ++x, y = -1;
 }
 if (sg[x][y+1] != 2 && sg[x][y+1] != c) continue;
 if (x == n - 1 && y + 1 == m - 1 && x1 != c && x2 != c && x3 == c) continue;
 if (x1 == c && x2 == c && x3 == c) continue;
 if (x2 != c && checkl(s2, y + 1)) {
 if (checkc(s1, y + 1) || ynn[!c][x][y+1]) continue;
 if (x < n - 1 || (y + 1) < m - 2) continue;
 
 int ccc = abs(dp[cp].diff[st] + clac(x, y + 1, c));
 if (ccc < rd) { 
 rd = abs(ccc);
 result = dp[cp].cnt[st];
 output(u, tot + st - dp[cp].cs, c);
 } else if (ccc == rd) {
 result += dp[cp].cnt[st];
 }
 continue;
 }
 if (x3 != -1) s1 ^= (x3 << m);
 s1 ^= (x2 << (y + 1));
 s1 |= (x2 << m) | (c << (y + 1));
 if (x1 == c && x2 == c) un(s2, y, y + 1);
 else if (x1 != c && x2 != c) create(s2, y + 1);
 else if (x1 == c && x2 != c) {
 expand(s2);
 state[y + 1] = state[y];
 } else if (x1 != c && x2 == c) expand(s2);
 weihu();
 int ccc = dp[cp].diff[st];
 if (c) ccc += v[x][y+1];
 else ccc -= v[x][y+1];
 int t = dp[np].push(s1, encode(), ccc, dp[cp].cnt[st]) + tot;
 pre[t] = ((tot + st - dp[cp].cs)<<1)|c;
 }
 }
 ++u;
 np = 1 - np;
 cp = 1 - cp;
 }
 }
 return -1;
}

void calc(int u) {
 memset(tool, -1, sizeof(tool));
 for (int st = 0;st < dp[cp].cs; ++st) {
 expand(dp[cp].s2[st]);
 int c = 0;
 for (int i = 0; i < m; ++i) {
 if (tool[state[i]] != -st) {
 tool[state[i]] = -st, ++c;
 }
 }
 if (c <= 2) {
 if (abs(dp[cp].diff[st]) < rd) {
 rd = abs(dp[cp].diff[st]);
 result = dp[cp].cnt[st];
 output(u, tot + st, pre[st]&1);
 } else if (abs(dp[cp].diff[st]) == rd) {
 result += dp[cp].cnt[st];
 }
 }
 }
}

void solved(int nT) {
 scanf("%d %d", &n, &m);
 rep(i, n) {
 scanf("%s", g[i]);
 rep(j, m) sg[i][j] = find(base, base + 3, g[i][j]) - base;
 }
 rep(i, n) rep(j, m) scanf("%d", &v[i][j]);
 int t[2] = {0, 0};
 for (int i = n - 1; i >= 0; --i) {
 for (int j = m - 1; j >= 0; --j) {
 for (int u = 0; u <= 1; ++u) {
 ynn[u][i][j] = sg[i][j] == u || t[u];
 t[u] = ynn[u][i][j];
 }
 }
 }
 result = flag = 0, rd = 10086;
 calc(bfs());
 if (rd == 10086) rd = 0;
 printf("Case %d: %d %d\n", nT, rd, result);
 if (result) {
 for (int i = 0, c = 0; i < n; ++i) {
 for (int j = 0; j < m; ++j, ++c) {
 putchar(ans[c]?'x':'o');
 } puts("");
 }
 }
 puts("");
}

int main() {
 int T = 1;
 scanf("%d", &T);
 for (int nT = 1; nT <= T; ++nT) {
 solved(nT);
 }
 return 0;
}