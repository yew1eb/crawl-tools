#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define For(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
//#pragma comment(linker, "/STACK:16777216")
const int N = 50010;
const int LL = (N<<2)-1;
const int RR = (N<<2)-2;
const int TMP = (N<<2)-3;
const int inf = 1000000000;
typedef long long ll;

int T,n,m,u,v,c,val,sz,aa,bb,ans,a[N];
int fa[N][16+1],who[N],dep[N],s[N],belong[N],place[N];
int mina[N<<2],maxa[N<<2],lans[N<<2],rans[N<<2], add[N<<2];
vector<int> e[N];

inline void Update(int x,int l,int r)
{
    maxa[x] = max(maxa[l],maxa[r]);
    mina[x] = min(mina[l],mina[r]);

    lans[x] = max(lans[l],lans[r]);
    lans[x] = max(lans[x], maxa[r] - mina[l]);

    rans[x] = max(rans[l],rans[r]);
    rans[x] = max(rans[x], maxa[l] - mina[r]);
}
inline void Down(int x)
{
    if (add[x] == 0) return;
    FOR(i,x+x,x+x+1)
    {
        add[i] += add[x];
        mina[i] += add[x];
        maxa[i] += add[x];
    }
    //Update(x,x+x,x+x+1);
    add[x] = 0;
}
void Init()
{
    scanf("%d",&n);
    For(i,n) scanf("%d",&a[i]);
    For(i,n-1)
    {
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
}
inline int LCA(int x,int y)
{
    if (dep[x]<dep[y])
        swap(x,y);
    int T = dep[x]-dep[y];
    FORD(i,16,0)
        if ((1<<i) <= T)
            T-=1<<i,x=fa[x][i];
    FORD(i,16,0)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    if (x==y) return x;
    else return fa[x][0];
}
void DFS(int x)
{
    For(i,16)
        fa[x][i] = fa[fa[x][i-1]][i-1];
    s[x] = 1;
    int v;
    rep(i,e[x].size())
    {
        v = e[x][i];
        if (v==fa[x][0]) continue;
        dep[v] = dep[x]+1;
        fa[v][0] = x;
        DFS(v);
        s[x]+=s[v];
    }
}
void DFS2(int x,int chain)
{
    place[x] = ++sz;
    who[sz] = x;
    belong[x] = chain;
    int big = 0;
    rep(i,e[x].size())
    {
        v = e[x][i];
        if (dep[v]>dep[x] && s[v]>s[big])
            big = v;
    }
    if (!big) return;
    DFS2(big,chain);
    rep(i,e[x].size())
    {
        v = e[x][i];
        if (dep[v]>dep[x] && v != big)
            DFS2(v,v);
    }
}
void Build(int x,int l,int r)
{
    add[x] = 0;
    if (l==r)
    {
        mina[x] = maxa[x] = a[who[l]];
        lans[x] = rans[x] = 0;
        return;
    }
    int m = (l+r)>>1;
    Build(x+x,l,m);
    Build(x+x+1,m+1,r);
    Update(x,x+x,x+x+1);
}
void Query(int x,int l,int r,int id)
{
    if (aa<=l && r<=bb)
    {
        //if (aa==2 && bb==3)
        //    printf("sth:%d %d %d %d\n",mina[x],maxa[x],lans[x],rans[x]);
        Update(TMP,x,id);
        mina[id] = mina[TMP];
        maxa[id] = maxa[TMP];
        lans[id] = lans[TMP];
        rans[id] = rans[TMP];
        add[x] += val;
        mina[x] += val;
        maxa[x] += val;
        return;
    }
    Down(x);
    int m = (l+r)>>1;
    if (m+1<=bb) Query(x+x+1,m+1,r,id);
    if (aa<=m) Query(x+x,l,m,id);
    Update(x,x+x,x+x+1);
}
int Ask(int x,int l,int r,int p)
{
    if (l==r)
        return mina[x];
    Down(x);
    int m = (l+r)>>1;
    if (p<=m)
        return Ask(x+x,l,m,p);
    else return Ask(x+x+1,m+1,r,p);
}
void Modify(int x,int l,int r)
{
    if (aa<=l && r<=bb)
    {
        add[x] += val;
        mina[x] += val;
        maxa[x] += val;
        return;
    }
    Down(x);
    int m = (l+r)>>1;
    if (aa<=m) Modify(x+x,l,m);
    if (m+1<=bb) Modify(x+x+1,m+1,r);
    Update(x,x+x,x+x+1);
}
void Calc_UP(int x,int root,int id)
{
    mina[id] = inf;
    maxa[id] = -inf;
    lans[id] = rans[id] = 0;
    while (belong[x]!=belong[root])
    {
        aa = place[belong[x]];
        bb = place[x];
        Query(1,1,n,id);
            //if (id == LL) printf("aabb:%d %d\n",aa,bb);

        x = fa[belong[x]][0];
    }
    aa = place[root]+1;
    bb = place[x];
    if (aa>bb) return;
    //if (id == LL) printf("aabb:%d %d\n",aa,bb);
    Query(1,1,n,id);
}
void Work()
{
    scanf("%d%d%d",&u,&v,&val);
    c = LCA(u,v);

    Calc_UP(u,c,LL);
    Calc_UP(v,c,RR);
    //printf("%d %d %d\n",u,v,c);
    //printf("%d %d %d %d\n",rans[LL],lans[RR],maxa[RR],mina[LL]);
    int cint = Ask(1,1,n,place[c]);
    ans = max(rans[LL],lans[RR]);
    ans = max(ans, maxa[RR]-mina[LL]);
    ans = max(ans, cint-mina[LL]);
    ans = max(ans, maxa[RR]-cint);
    printf("%d\n",ans);

    aa = bb = place[c];
    Modify(1,1,n);
}
void Clean()
{
    sz = 0;
    For(i,n) e[i].clear();
}
int main()
{
    //puts("!");
    //freopen("1011.in","r",stdin);
    //freopen("1011-improve.out","w",stdout);
    scanf("%d",&T);
    For(tt,T)
    {
        Init();
        DFS(1);
        DFS2(1,1);
        Build(1,1,n);
        scanf("%d",&m);
        rep(mm,m)
            Work();
        //printf("%d\n",tt);
        Clean();
    }
    return 0;
}