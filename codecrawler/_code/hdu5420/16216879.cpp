#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<string.h>
#include<string>
#include<sstream>
#include<bitset>
using namespace std;
#define ll __int64
#define ull unsigned __int64
#define eps 1e-8
#define NMAX 1000000000
#define MOD (1<<30)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1)
template<class T>
inline void scan_d(T &ret)
{
    char c;
    int flag = 0;
    ret=0;
    while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c == '-')
    {
        flag = 1;
        c = getchar();
    }
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
    if(flag) ret = -ret;
}
const int maxn = 100000+10;
const int maxm = 100000*30+10;
struct node
{
    int dep,pos;
    node(){}
    node(int _d, int _p):dep(_d),pos(_p){}
    bool operator < (const node &t) const
    {
        if(dep != t.dep) return dep < t.dep;
        return pos < t.pos;
    }
};

int head[maxm],ecnt;
struct Edge
{
    int v,next;
}e[maxm<<1];

void add_edge(int u, int v)
{
    e[ecnt].v = v; e[ecnt].next = head[u];
    head[u] = ecnt++;
}

int st[maxn],ed[maxn],dep[maxn],dfs_clock,n,nct;
int a[maxn];
void dfs(int u, int d)
{
    st[u] = ++dfs_clock;
    a[dfs_clock] = u;
    dep[u] = d;
    for(int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        dfs(v,d+1);
    }
    ed[u] = dfs_clock;
}

vector<node>v[maxn<<2];
int beg[maxn<<2];

void combin(vector<node> &x, vector<node> &y, vector<node> &z)
{
    int sz1 = x.size(), sz2 = y.size();
    int p = 0, p1 = 0, p2= 0;
    while(p1 < sz1 || p2 < sz2)
    {
        if(p1 == sz1 || (p2 != sz2 && y[p2] < x[p1])) z[p++] = y[p2++];
        else z[p++] = x[p1++];
    }
}

void build(int l, int r, int rt)
{
    v[rt].resize(r-l+1);
    if(l == r)
    {
        v[rt][0] = node(dep[a[l]],a[l]);
        n++;
        add_edge(n,a[l]);
        beg[rt] = n;
        return;
    }
    int mid = l+r >> 1;
    build(lson);
    build(rson);
//    combin(v[rt<<1],v[rt<<1|1],v[rt]);
    merge(v[rt<<1].begin(),v[rt<<1].end(),v[rt<<1|1].begin(),v[rt<<1|1].end(),v[rt].begin());
    beg[rt] = n+1;
    for(int i = 1; i < r-l+1; i++)
        add_edge(n+i+1,n+i);
    for(int i = 0; i < r-l+1; i++)
        add_edge(n+i+1,v[rt][i].pos);
    n += r-l+1;
}

void update(int L, int R, int x, int d, int l, int r, int rt)
{
    if(L <= l && R >= r)
    {
        int pos = lower_bound(v[rt].begin(), v[rt].end(), node(d+1,0))-v[rt].begin()-1;
        if(pos >= 0) add_edge(x,beg[rt]+pos);
        return;
    }
    int mid = l+r >> 1;
    if(L <= mid) update(L,R,x,d,lson);
    if(R > mid) update(L,R,x,d,rson);
}

int pre[maxm],lowlink[maxm],sum[maxm],scc_cnt;
bool sccno[maxm];
stack<int>S;
void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for(int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if(!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u],lowlink[v]);
        }
        else if(!sccno[v])
        {
            lowlink[u] = min(lowlink[u],pre[v]);
        }
    }
    if(lowlink[u] == pre[u])
    {
        ++scc_cnt;
        while(1)
        {
            int x = S.top(); S.pop();
            sccno[x] = 1;
            sum[scc_cnt] += x <= nct;
            if(x == u) break;
        }
    }
}

void find_scc()
{
    dfs_clock = scc_cnt = 0;
    memset(pre,0,sizeof(pre));
    memset(sccno,0,sizeof(sccno));
    memset(sum,0,sizeof(sum));
    for(int i = 1; i <= nct; i++) if(!pre[i])
        dfs(i);
    ll ans = 0;
    for(int i = 1; i <= scc_cnt; i++)
        ans += (ll)sum[i]*(sum[i]-1)/2;
    printf("%I64d\n",ans);
}

int main()
{
#ifdef GLQ
    freopen("input.txt","r",stdin);
//    freopen("o.txt","w",stdout);
#endif
    int _t;
    scanf("%d",&_t);
    while(_t--)
    {
        scanf("%d",&n);
        nct = n;
        memset(head,-1,sizeof(head));
        ecnt = 0;
        for(int i = 2; i <= n; i++)
        {
            int v;
            scanf("%d",&v);
            add_edge(v,i);
        }
        dfs_clock = 0;
        dfs(1,0);
        memset(head,-1,sizeof(head));
        ecnt = 0;
        build(1,nct,1);
        for(int i = 1; i <= nct; i++)
        {
            int x,d;
            scanf("%d%d",&x,&d);
            update(st[x],ed[x],i,dep[x]+d,1,nct,1);
        }
        find_scc();
    }
    return 0;
}
