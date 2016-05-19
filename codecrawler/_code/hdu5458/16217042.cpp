#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include<set>
#include<stdlib.h>
#define maxm 100005
#define maxn  30005
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

struct E
{
    int a,b;
    E() {}
    E(int aa,int bb):a(aa),b(bb) {}
    bool operator < (const E &c) const
    {
        if(a == c.a)
        {
            return b < c.b;
        }
        return a < c.a;
    }
};

struct Edge
{
    int v,next;
} edge[maxn<<2];

int siz[maxn],top[maxn],son[maxn];
int dep[maxn],tid[maxn],fa[maxn];
int head[maxn],cnt;
int sum[maxn<<2];
int lazy[maxn<<2];

struct node
{
    int kind,a,b,val;
};
node ans[maxm];

int n,m,q;
int tim;
int father[maxn];

int find_fa(int x)
{
    if(father[x]==x) return x;
    return father[x]=find_fa(father[x]);
}

multiset<E> S;
multiset<E> V;

void init()
{
    memset(head,-1,sizeof(head));
    memset(sum,0,sizeof(sum));
    for(int i=1; i<=n; i++)
        father[i]=i;
    S.clear();
    V.clear();
    tim=0;
    cnt=0;
}

void add(int a, int b)
{
    edge[cnt].v = b;
    edge[cnt].next = head[a];
    head[a] = cnt++;
}
//æ é¾ååé¨å
//siz[]æ°ç»ï¼ç¨æ¥ä¿å­ä»¥xä¸ºæ ¹çå­æ èç¹ä¸ªæ°
//top[]æ°ç»ï¼ç¨æ¥ä¿å­å½åèç¹çæå¨é¾çé¡¶ç«¯èç¹
//son[]æ°ç»ï¼ç¨æ¥ä¿å­éå¿å­
//dep[]æ°ç»ï¼ç¨æ¥ä¿å­å½åèç¹çæ·±åº¦
//fa[]æ°ç»ï¼ç¨æ¥ä¿å­å½åèç¹çç¶äº²
//tid[]æ°ç»ï¼ç¨æ¥ä¿å­æ ä¸­æ¯ä¸ªèç¹åååçæ°ç¼å·
//Rank[]æ°ç»ï¼ç¨æ¥ä¿å­å½åèç¹å¨çº¿æ®µæ ä¸­çä½ç½®
void dfs1(int u,int father,int d)
{
    dep[u]=d;
    fa[u]=father;
    siz[u]=1;
    son[u]=-1;
    for(int i=head[u]; ~i; i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==father) continue;
        dfs1(v,u,d+1);
        siz[u]+=siz[v];
        if(son[u]==-1||siz[v]>siz[son[u]])
            son[u]=v;
    }
}
void dfs2(int u,int tp)
{
    top[u]=tp;
    tid[u]=++tim;
  //  Rank[tid[u]]=u;
    if(son[u]!=-1)
        dfs2(son[u],tp);
    for(int i=head[u]; ~i; i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==son[u]||v==fa[u]) continue;
            dfs2(v,v);
    }
}
//çº¿æ®µæ é¨å
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void pushdown(int rt)
{
    if(lazy[rt])
    {
        lazy[rt<<1]=1;
        lazy[rt<<1|1]=1;
        lazy[rt]=0;
        sum[rt<<1]=sum[rt<<1|1]=0;
        return;
    }
}
void build(int l,int r,int rt)
{
    lazy[rt]=0;
    if(l==r)
    {
        sum[rt]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R, int l, int r, int rt)
{
    if (L<=l&&r<=R)
    {
        sum[rt]=0;
        lazy[rt]=1;
        return;
    }
    pushdown(rt);
    int mid= (l+ r)>>1;
    if(L<=mid) update(L,R,lson);
    if(mid<R) update(L,R,rson);
    pushup(rt);
}
int Query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        return sum[rt];
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    int ans=0;
    if(L<=mid) ans+=Query(L,R,lson);
    if(mid<R) ans+=Query(L,R,rson);
    return ans;
}

void Change(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update(tid[top[x]],tid[x],1,tim,1);
        x=fa[top[x]];
    }
    if(x==y) return;
    if(dep[x]>dep[y]) swap(x,y);
    update(tid[x]+1,tid[y],1,tim,1);
}

int query(int x,int y)
{
    int ans=0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);//ä¿è¯xçtopæ´æ·±
        ans+=Query(tid[top[x]],tid[x],1,tim,1);//æ¥è¯¢æ·±çé¾ï¼
        x=fa[top[x]];
    }
    if(x==y) return ans;
    if(dep[x]>dep[y]) swap(x,y);//ä¿è¯xæ´æµ
    ans+=Query(tid[x]+1,tid[y],1,tim,1);
    return ans;
}

int main()
{
    int t;
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&q);
        init();
        for(int i=1;i<=m;i++)
        {
            E tmp;
            scanf("%d%d",&tmp.a,&tmp.b);
            if(tmp.a > tmp.b) swap(tmp.a,tmp.b);
            S.insert(tmp);
        }
        for(int i=1; i<=q; i++)
        {
            scanf("%d%d%d",&ans[i].kind,&ans[i].a,&ans[i].b);
            if(ans[i].a > ans[i].b) swap(ans[i].a,ans[i].b);
            //æ¥è¯¢è¿ç¨ä¸­å é¤çè¾¹åé½å æ
            if(ans[i].kind == 1)
            {
                E tmp;
                tmp.a=ans[i].a,tmp.b=ans[i].b;
                multiset<E>::iterator Pos = S.find(tmp);
                S.erase(Pos);
            }
        }
        //ä»å©ä¸çè¾¹ä¸­éåºä¸æ£µæ æ¥ï¼ç¨å¹¶æ¥éå¤æ­æä¸æç¯
        for(multiset<E>::iterator It = S.begin(); It != S.end(); ++It)
        {
            if(find_fa(It->a) != find_fa(It->b))
            {
                father[find_fa(It->a)] = find_fa(It->b);
                V.insert(*It);
            }
        }
        for(multiset<E>::iterator It = V.begin(); It != V.end(); ++It)
        {
            add(It->a,It->b);
            add(It->b,It->a);
        }
        dfs1(1,0,0);
        dfs2(1,1);
        build(1,tim,1);
        //Sä¸­å©ä¸çè¾¹åæ´æ°äº
        for(multiset<E>::iterator It = S.begin(); It != S.end(); ++It)
            if(V.find(*It) == V.end())
            {
                Change(It->a,It->b);
            }
        //qä¸ªè¯¢é®ä¸æ¬¡æ´æ°æ¥è¯¢å³å¯
        for(int i=q;i>=1;i--)
        {
            if(ans[i].kind == 1)
                Change(ans[i].a,ans[i].b);
            else if(ans[i].kind == 2)
                ans[i].val = query(ans[i].a,ans[i].b);
        }
        printf("Case #%d:\n",cas++);
        for(int i=1; i<=q; i++)
            if(ans[i].kind == 2)
                printf("%d\n",ans[i].val);
    }
    return 0;
}
