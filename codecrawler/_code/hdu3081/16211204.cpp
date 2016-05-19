#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

const int inf = 0x3fffffff;
const int NN = 110;
int father[NN];
int Map[NN][NN];
int src, sink, n, m, f;
struct bg_friend
{
    int b, g;
}bg[10005];

template <int N, int M>
struct Isap
{
    int top;
    int d[N], pre[N], cur[N], gap[N];
    struct Vertex{
        int head;
    } V[N];
    struct Edge{
        int v, next;
        int c, f;
    } E[M];
    void init(){
        memset(V, -1, sizeof(V));
        top = 0;
    }
    void add_edge(int u, int v, int c){
        E[top].v = v;
        E[top].c = c;
        E[top].f = 0;
        E[top].next = V[u].head;
        V[u].head = top++;
    }
    void add(int u,int v, int c){
        add_edge(u, v, c);
        add_edge(v, u, 0);
    }
    void set_d(int t){
        queue<int> Q;
        memset(d, -1, sizeof(d));
        memset(gap, 0, sizeof(gap));
        d[t] = 0;
        Q.push(t);
        while(!Q.empty()) {
            int v = Q.front(); Q.pop();
            ++gap[d[v]];
            for(int i = V[v].head; ~i; i = E[i].next) {
                int u = E[i].v;
                if(d[u] == -1) {
                    d[u] = d[v] + 1;
                    Q.push(u);
                }
            }
        }
    }
    int sap(int s, int t, int num) {
        set_d(t);
        int ans = 0, u = s;
        int flow = inf;
        memcpy(cur, V, sizeof(V));
        while(d[s] < num) {
            int &i = cur[u];
            for(; ~i; i = E[i].next) {
                int v = E[i].v;
                if(E[i].c > E[i].f && d[u] == d[v] + 1) {
                    u = v;
                    pre[v] = i;
                    flow = min(flow, E[i].c - E[i].f);
                    if(u == t) {
                        while(u != s) {
                            int j = pre[u];
                            E[j].f += flow;
                            E[j^1].f -= flow;
                            u = E[j^1].v;
                        }
                        ans += flow;
                        flow = inf;
                    }
                    break;
                }
            }
            if(i == -1) {
                if(--gap[d[u]] == 0)
                    break;
                int dmin = num - 1;
                cur[u] = V[u].head;
                for(int j = V[u].head; ~j; j = E[j].next)
                    if(E[j].c > E[j].f)
                        dmin = min(dmin, d[E[j].v]);
                d[u] = dmin + 1;
                ++gap[d[u]];
                if(u != s)
                    u = E[pre[u] ^ 1].v;
            }
        }
        return ans;
    }
};
Isap<1000, 1000000> Sap;

struct Union_Find
{
    void Init(int x)
    {
        for(int i = 0; i <= x; i++)
            father[i] = i;
    }
    int Find(int x)
    {
        if(x != father[x])
            father[x] = Find(father[x]);
        return father[x];
    }
    void Union(int a, int b)
    {
        int p = Find(a);
        int q = Find(b);
        if(p > q)
            father[p] = q;
        else
            father[q] = p;
    }
} UF;

void build(int mid) //å»ºè¾¹
{
    memset(Map, 0, sizeof(Map));
    Sap.init();
    src = 0; //æºç¹
    sink = 2 * n + 1; //æ±ç¹
    for(int i = 1; i <= n; i++)
    {
        Sap.add(src, i, mid);
        Sap.add(n+i, sink, mid);
    }
    for(int i = 0; i < m; i++)
    {
        int u = bg[i].g, v = bg[i].b;
        for(int j = 1; j <= n; j++)
        {
            if(UF.Find(j) == UF.Find(u))
            {
                if(!Map[j][v])
                {
                    Map[j][v] = 1;
                    Sap.add(j, v+n, 1);
                }
            }
        }
    }
}

int main()
{
    int i, j, T, a, b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&f);
        UF.Init(n);
        for(i = 0; i < m; i++)
        {
            scanf("%d%d",&bg[i].g,&bg[i].b);
        }
        for(i = 0; i < f; i++)
        {
            scanf("%d%d",&a, &b);
            UF.Union(a, b);
        }
        int l = 0, r = n, mid, ans = 0;
        while(l <= r) 
        {
            mid = (l + r) / 2;
            build(mid);
            int res = Sap.sap(src, sink, m + f + n*2);
            if(res == mid * n)
            {
                l = mid + 1;
                ans = mid;
            }
            else
                r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}