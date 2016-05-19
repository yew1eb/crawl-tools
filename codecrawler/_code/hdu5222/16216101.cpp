#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
#define pb push_back
#define MP make_pair
#define fi  first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define SZ(X) ((int)(v).size())
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define READ freopen("a.in","r",stdin);freopen("a.out","w",stdout)
void read(string t)
{
    freopen((t+".in").c_str(),"r",stdin);
    freopen((t+".out").c_str(),"w",stdout);
}
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int,int> pii;
template <class T>
void Max(T &a, T b) { a=max(a, b); }
#pragma comment(linker, "/STACK:102400000,102400000")

const int N = 1001000;
struct Edge
{
    int v, next;
    Edge() {}
    Edge(int a, int b)
    {
        v = a, next = b;
    }
} e[N<<2];
int head[N], mm;
int n, m, m1, m2;
void init_edge()
{
    mm = 0;
    memset(head, -1, sizeof head);
}
void add(int u, int v)
{
    e[mm] = Edge(v, head[u]);
    head[u] = mm++;
}

bool flag = false;
#include <stack>
stack<int> S;
int cur, scc;
int dfn[N*3], low[N*2], in[N];
bool ins[N];
void dfs(int u)
{
    dfn[u] = low[u] = ++ cur;
    S.push(u);
    ins[u] = 1;
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (dfn[v]==0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            if (ins[v])
                low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u] ) {
        ++ scc; int v;
        do {
            v =  S.top();  S.pop();
            ins[v] = 0;
            in[v] = scc;
        } while (v - u);
    }
}
int fa[N];
int f(int x) { return x==fa[x] ? x : fa[x] = f(fa[x]); }
int C[N];
int main()
{
    int re,ca=1; cin>>re;
    while (re--)
    {
        init_edge();
        cin >> n >> m1 >> m2;
        for (int i=1;i<=n;i++) fa[i] = i;
        flag = false;
        for (int i=0;i<m1;i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            int x = f(u), y = f(v);
            if (x == y) {
                flag = true;
            }
            else fa[x] = y;
        }
        for (int i=0;i<m2;i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u = f(u); v = f(v);
            add(u, v);
            if (u==v) flag = true;
        }
        int tot = 0;
        memset(C,0,sizeof C);
        for (int i=1;i<=n;i++) {
            int t = f(i);
            if (C[t] == 0)
            {
                C[t] = 1;
                tot++;
            }
        }

        memset(dfn, 0 , sizeof dfn);
        memset(low,0,sizeof low);
        memset(ins, 0, sizeof ins);
        memset(in, 0, sizeof in);
        cur = scc = 0;
        while (!S.empty()) S.pop();
        for (int i=1; !flag &&i<=n;i++) {
            int t = f(i);
            if (dfn[t]==0) dfs(t);
        }
        if(scc < tot) flag = true;
        if (flag) puts("YES");
        else puts("NO");
    }
    return  0;
}
