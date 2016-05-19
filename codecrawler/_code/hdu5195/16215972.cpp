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
#define ull unsigned long long
#define eps 1e-8
#define NMAX 1000000000
#define MOD 1000000
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
template<class T> inline T Max(T a, T b){ return a > b ? a : b; }
template<class T> inline T Min(T a, T b){ return a < b ? a : b; }

const int maxn = 100000+10;
int T[maxn<<2],a[maxn],head[maxn],nct;
int du[maxn];
struct Edge
{
    int v,next;
}e[maxn];

void add(int u, int v)
{
    e[nct].v = v; e[nct].next = head[u];
    head[u] = nct++;
}

inline void pushup(int rt)
{
    T[rt] = min(T[rt<<1],T[rt<<1|1]);
}

void build(int l, int r, int rt)
{
    if(l == r)
    {
        T[rt] = du[l];
        return;
    }
    int mid = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

int query(int k, int l, int r, int rt)
{
    if(l == r)
    {
        T[rt] = 100000+10;
        return l;
    }
    int mid = (l+r)>>1,m;
    if(T[rt<<1|1] <= k) m = query(k,rson);
    else m = query(k,lson);
    pushup(rt);
    return m;
}

void update(int L, int k, int l, int r, int rt)
{
    if(l == r)
    {
        T[rt] -= k;
        return;
    }
    int mid = (l+r)>>1;
    if(L <= mid) update(L,k,lson);
    else update(L,k,rson);
    pushup(rt);
}

int main()
{
#ifdef GLQ
    freopen("input.txt","r",stdin);
//    freopen("o.txt","w",stdout);
#endif
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        nct = 0;
        memset(du,0,sizeof(du));
        memset(head,-1,sizeof(head));
        for(int i = 1; i <= m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
            du[v]++;
        }
        build(1,n,1);
        for(int i = 1; i <= n; i++)
        {
            int w = query(k,1,n,1);
            printf("%d%c",w,(i==n)?'\n':' ');
            k -= du[w];
            du[w] = 0;
            for(int j = head[w]; j != -1; j = e[j].next)
            {
                int v = e[j].v;
                if(du[v])
                {
                    du[v]--;
                    update(v,1,1,n,1);
                }
            }
        }
    }
    return 0;
}
