#pragma comment(linker, "/STACK:102400000000,102400000000")
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

//LOOP
#define FF(i, a, b) for(int i = (a); i < (b); ++i)
#define FD(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define FE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FED(i, b, a) for(int i = (b); i>= (a); --i)
#define REP(i, N) for(int i = 0; i < (N); ++i)
#define CLR(A,value) memset(A,value,sizeof(A))
//INPUT
#define RI(n) scanf("%d", &n)
#define RII(n, m) scanf("%d%d", &n, &m)
#define RIII(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define RS(s) scanf("%s", s)
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
const int maxn = 100010;

LL a[maxn];
LL ans[200010];
LL BIT[62];
int n, m;
struct Trie{
    int ch[2 * maxn * 62][2];
    LL val[2 * maxn * 62];
    int num[2 * maxn * 62];
    int tol;
    Trie(){}
    void init()
    {
        tol = 1;
        CLR(ch, 0);
        CLR(val, 0);///
        CLR(num, 0);
    }
    void insert(LL x)
    {
        int u = 0;
        for (int i = 60; i >= 0; i--)
        {
            int v = (x & BIT[i]) > 0;///
            if (!ch[u][v]) ch[u][v] = tol++;
            u = ch[u][v];
            num[u]++;
        }
        val[u] = x;
    }
    bool kth_max(int k, LL v, LL &vmax)///查找和v异或后值为第k大值
    {
        if (k >= n) return 0;
        int u = 0;
        for (int i = 60; i >= 0; i--)
        {
            int r = !((v & BIT[i]) > 0);///
            if (ch[u][r])
            {
                if (num[ch[u][r]] >= k)
                    u = ch[u][r];
                else
                {
                    k -= num[ch[u][r]];
                    u = ch[u][r ^ 1];///
                }
            }
            else
                u = ch[u][r ^ 1];///
        }
        vmax = val[u] ^ v;
        return 1;
    }
}ac;

struct Edge{
    int to, next;
    LL v;
};
Edge adj[maxn << 1];
int tot;
int head[maxn];
void init_adj()
{
    tot = 0;
    CLR(head, -1);
}
void add_edge(int x, int y, LL v)
{
    adj[tot].to = y;
    adj[tot].v = v;
    adj[tot].next = head[x];
    head[x] = tot++;
}

struct query{
    int k, id;
    bool operator <(const query &b) const
    {
        return k < b.k;
    }
}qy[200010];

struct Node{
    int k;
    LL v;
    LL vmax;
    bool operator <(const Node &b) const
    {
        return vmax < b.vmax;
    }
};
priority_queue<Node>q;

void dfs(int u, int fa, LL val)
{
    ac.insert(val);///!!!
    a[u] = val;
    for (int r = head[u]; r != -1; r = adj[r].next)
    {
        int v = adj[r].to;
        if (v == fa) continue;
        dfs(v, u, val ^ adj[r].v);
    }
}

void solve()
{
    int x, y;
    LL vv;
    init_adj();
    REP(i, n - 1)
    {
        scanf("%d%d%I64d", &x, &y, &vv);
        add_edge(x, y, vv);
        add_edge(y, x, vv);
    }
    RI(m);
    REP(i, m)
    {
        RI(qy[i].k);
        qy[i].id = i;
    }
    sort(qy, qy + m);

    ac.init();
    dfs(1, -1, 0);

    while (!q.empty()) q.pop();
    FE(i, 1, n)
    {
        Node now;
        now.k = 1;
        now.v = a[i];
        if (ac.kth_max(now.k, now.v, now.vmax)) q.push(now);
    }
    int rank  = 1;///
    REP(i, m)
    {
        while (!q.empty() && rank < qy[i].k)
        {
            rank++;
            Node now = q.top(); q.pop();
            now.k++;
            if (ac.kth_max(now.k, now.v, now.vmax)) q.push(now);
        }
        if (!q.empty()) ans[qy[i].id] = q.top().vmax;
        else ans[qy[i].id] = -1;
    }
    REP(i, m)
        printf("%I64d\n", ans[i]);
}

int main()
{
    for (int i = 0; i <= 60; i++) BIT[i] = 1ll << i;
    while (~RI(n) && n)
        solve();
    return 0;
}
