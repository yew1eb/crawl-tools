#pragma comment (linker,"/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn = 100000+10;
const int mod = 1000000007;
int ch[maxn][2],pre[maxn];
int Lx[maxn],Rx[maxn],w[maxn],id[maxn],dfs_clock,n,m;
ll mul[maxn<<2],val[maxn];
void dfs(int u)
{
    if(u == 0) return ;
    dfs(ch[u][0]);
    id[u] = ++dfs_clock;
    val[dfs_clock] = w[u];
    if(ch[u][0])
    {
        Lx[u] = Lx[ch[u][0]];
        val[id[u]]  += val[id[ch[u][0]]];
    }
    else Lx[u] = id[u];

    dfs(ch[u][1]);
    if(ch[u][1])
    {
        Rx[u] = Rx[ch[u][1]];
        val[id[u]] += val[id[ch[u][1]]];
    }
    else Rx[u] = id[u];
    val[id[u]] %= mod;
}
inline void PushUp(int rt)
{
    mul[rt] = mul[rt<<1]*mul[rt<<1|1]%mod;
}
void build(int l,int r,int rt)
{
    if(l == r)
    {
        mul[rt] = val[l];
        return ;
    }
    int m = (l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    PushUp(rt);
}
ll Query(int L,int R,int l,int r,int rt)
{
    if(l >= L && r <= R) return mul[rt];
    int m = (l+r)>>1;
    if(m >= R) return Query(L,R,l,m,rt<<1);
    else if(m < L) return Query(L,R,m+1,r,rt<<1|1);
    return Query(L,R,l,m,rt<<1)*Query(L,R,m+1,r,rt<<1|1)%mod;
}
void Update(int p,int l,int r,int rt,ll v)
{
    if(l == r)
    {
        mul[rt] = v;
        return ;
    }
    int m = (l+r)>>1;
    if(m >= p) Update(p,l,m,rt<<1,v);
    else Update(p,m+1,r,rt<<1|1,v);
    PushUp(rt);
}
inline void getInvertval(int x)
{
    if(ch[x][0]) Lx[x] = Lx[ch[x][0]];
    else Lx[x] = id[x];
    if(ch[x][1]) Rx[x] = Rx[ch[x][1]];
    else Rx[x] = id[x];
}
void Rotate(int x,int kind)
{
    int y = ch[x][kind];
    if(y == 0) return ;
    ch[x][kind] = ch[y][kind^1];
    if(ch[y][kind^1]) pre[ch[y][kind^1]] = x;
    if(pre[x]) ch[pre[x]][ch[pre[x]][1] == x] = y;
    pre[y] = pre[x];
    ch[y][kind^1] = x;
    pre[x] = y;

    val[id[x]] = (w[x] + val[id[ch[x][0]]] + val[id[ch[x][1]]])%mod;
    val[id[y]] = (w[y] + val[id[ch[y][0]]] + val[id[ch[y][1]]])%mod;
    Update(id[x],1,n,1,val[id[x]]);
    Update(id[y],1,n,1,val[id[y]]);
    getInvertval(x);
    getInvertval(y);
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t,tcase = 0;
    scanf("%d",&t);
    while(t--)
    {
        int u,v;
        scanf("%d%d",&n,&m);
        memset(ch,0,sizeof(ch));
        memset(pre,0,sizeof(pre));
        w[0] = val[0] = 0;
        for(int i = 1;i <= n;++i)
        {
            scanf("%d%d%d",&w[i],&u,&v);
            ch[i][0] = u;
            ch[i][1] = v;
            if(u) pre[u] = i;
            if(v) pre[v] = i;
        }
        dfs_clock = 0;
        for(int i = 1;i <= n;++i)
            if(pre[i] == 0)
            {
                dfs(i);
                break;
            }
        build(1,n,1);
        printf("Case #%d:\n",++tcase);
        while(m--)
        {
            scanf("%d%d",&u,&v);
            if(u == 0) Rotate(v,0);
            else if(u == 1) Rotate(v,1);
            else
            {
                ll ans = Query(Lx[v],Rx[v],1,n,1);
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}
