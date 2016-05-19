#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 400080
#define maxm 800010
#define lson id<<1,l,mid
#define rson id<<1|1,mid+1,r
#define inf 0x3f3f3f3f
int Size[maxn],Son[maxn],dep[maxn],Pos[maxn],fPos[maxn],Top[maxn],fa[maxn],out[maxn];
int first[maxn],nxt[maxm],vv[maxm];
int e,pos;
struct Edge
{
    int u,v,z;
    Edge(){}
    Edge(int uu,int vv,int zz)
    {
        u = uu,v = vv,z = zz;
    }
};
vector <Edge> ans;
vector <int> fuck[maxn];
void init(int n)
{
    e = pos = 0;
    memset(first,-1,sizeof(first));
    memset(Son,-1,sizeof(Son));
    ans.clear();
    for(int i = 1;i <= n+1;i++)
        fuck[i].clear();
}
void addedge(int u,int v)
{
    vv[e] = v;    nxt[e] = first[u];    first[u] = e++;
    vv[e] = u;    nxt[e] = first[v];    first[v] = e++;
}
struct ST
{
    int l,r,key,keynum;
}st[maxn<<2];

void PushUp(int id)
{
    if(st[id<<1|1].key > st[id<<1].key)
        st[id].keynum = st[id<<1|1].keynum;
    else st[id].keynum = st[id<<1].keynum;
    st[id].key = max(st[id<<1].key,st[id<<1|1].key);
}

void buildtree(int id,int l,int r)
{
    st[id].l = l,st[id].r = r;
    st[id].key = 0;
    if(l == r)    
    {
        st[id].keynum = l;
        return;
    }
    int mid = (l+r) >> 1;
    buildtree(lson);
    buildtree(rson);
    PushUp(id);
}
void Update(int id,int pos,int add)
{
    if(st[id].l == pos && st[id].r == pos)
    {
        st[id].key += add;
        return;
    }
    if(st[id<<1].r >= pos)
        Update(id<<1,pos,add);
    else Update(id<<1|1,pos,add);
    PushUp(id);
}

void dfs(int u,int pre)
{
    dep[u] = dep[pre]+1;
    Size[u] = 1;
    for(int i = first[u];i != -1;i = nxt[i])
    {
        int v = vv[i];
        if(v == pre)    continue;
        fa[v] = u;
        dfs(v,u);
        Size[u] += Size[v];
        if(Son[u] == -1 || Size[v] > Size[Son[u]])
            Son[u] = v;
    }
}

void dfs2(int u,int t)
{
    Pos[u] = ++pos;
    fPos[pos] = u;
    Top[u] = t;
    if(Son[u] != -1)
        dfs2(Son[u],t);
    for(int i = first[u];i != -1;i = nxt[i])
    {
        int v = vv[i];
        if(v != fa[u] && v != Son[u])
            dfs2(v,v);
    }
}

void Get_Edge(int u,int v,int z)
{
    int f1 = Top[u],f2 = Top[v];
    while(f1 != f2)
    {
        if(dep[f1] < dep[f2])
        {
            swap(u,v);
            swap(f1,f2);
        }
        ans.push_back(Edge(Pos[f1],Pos[u],z));
        u = fa[f1];    f1 = Top[u];
    }
    if(dep[u] > dep[v])    swap(u,v);
    ans.push_back(Edge(Pos[u],Pos[v],z));
}

void scanf_f(int & a)
{
    a = 0;
    char c;
    while((c = getchar()) < '0' || c > '9');
    a = c - '0';
    while((c = getchar()) >= '0' && c <= '9')
        a = a*10 + c - '0';
}

int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m)==2 && (n|m))
    {
        init(n);
        for(int i = 1;i < n;i++)
        {
            int u,v;
            //scanf("%d%d",&u,&v);
            scanf_f(u);
            scanf_f(v);
            addedge(u,v);
        }
        dep[1] = 0;
        dfs(1,1);
        dfs2(1,1);
        int maxz = 1;
        for(int i = 1;i <= m;i++)
        {
            int x,y,z;
            //scanf("%d%d%d",&x,&y,&z);
            scanf_f(x);
            scanf_f(y);
            scanf_f(z);
            Get_Edge(x,y,z);
            maxz = max(maxz,z);
        }
        int len = ans.size();
        for(int i = 0;i < len;i++)
        {
            int u = ans[i].u,v = ans[i].v,z = ans[i].z;
            fuck[u].push_back(z);
            fuck[v+1].push_back(-z);
        }
        for(int i = 1;i <= n;i++)
            sort(fuck[i].begin(),fuck[i].end());
        buildtree(1,1,maxz);
        for(int i = 1;i <= n;i++)
        {
            int sz = fuck[i].size();
            for(int j = 0;j < sz;j++)
            {
                int k = fuck[i][j];
                if(k < 0)
                {
                    Update(1,-k,-1);
                }
                else 
                {
                    Update(1,k,1);
                }
            }
            out[fPos[i]] = st[1].keynum;
            if(st[1].key == 0)    out[fPos[i]] = 0;
        }
        for(int i = 1;i <= n;i++)
            printf("%d\n",out[i]);
    }
    return 0;
}