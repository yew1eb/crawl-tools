#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define prt(k) cout<<#k" = "<<k<<" \n";

const int N = 30010<<2;
int tree[N], add[N];
int n;
#include<map>
map<string, int> city;
int a[N];
struct Edge {
    int to, next, w, id;
    Edge() {}
    Edge(int a, int b, int c=0, int d=1) { to=a, next=b, w=c; id=d; }
}e[N];
int head[N];
int tot;
void addedge(int u,int v,int c, int id)
{
    e[++tot] = Edge(v, head[u], c, id);
    head[u]=tot;
}
int in[N],out[N];
int id[N];
int L[N],R[N];
void update(int,int,int,int,int);
void update(int L,int R)
{
    update(L,R,1,tot,1);
}
void dfs(int u, int fa=-1, int c=0)
{
    for(int i=head[u];~i;i=e[i].next)
    {
        int v=e[i].to;
        if(v-fa) {
            in[i/2]=++tot;
            a[tot] = c^e[i].w;
            dfs(v,u,c^e[i].w);
            out[i/2]=tot;
        }
    }
}
#define ls o*2
#define rs o*2+1
void pushup(int l,int r,int o)
{
    tree[o]=tree[o*2]+tree[o*2+1];
}
void pushdown(int l,int r,int o)
{
    if(add[o]) {
        add[ls] ^= 1;
        add[rs] ^= 1;
        int len = r-l+1;
        int m=(l+r)>>1;
        tree[ls] = m-l+1 -tree[ls];
        tree[rs] = r-m - tree[rs];
        add[o]=0;
    }
}
void build(int l,int r, int o)
{
    add[o]=0;
    if(l==r)
    {
        tree[o] = a[l];
        return;
    }
    int m = (l+r)>>1;
    build(l,m,ls);
    build(m+1,r,rs);
    pushup(l,r,o);
}
void update(int L, int R, int l, int r,int o)
{
    if(L<=l&&r<=R) {
        add[o]^=1;
        tree[o] = r-l+1 - tree[o];
        return;
    }
    pushdown(l,r,o);
    int m=(l+r)/2;
    if(L<=m) update(L,R,l,m,ls);
    if(m+1<=R) update(L,R,m+1,r,rs);
    pushup(l,r,o);
}
int read()
{
    char s[22]; scanf("%s",s);
    return city[string(s)];
}
int main()
{
    ///freopen("H.txt","r",stdin);
    int re; cin>>re ; int ca=1;
    while(re--)
    {
        cin>>n;
        city.clear();
        for(int i=1;i<=n;i++) {
            char s[22]; scanf("%s",s);
            city[string(s)] = i;
        }
        tot=-1;  memset(head,-1,sizeof head);
        for(int i=1;i<n;i++) {
            int u,v,c;
            u=read(); v=read();
            scanf("%d", &c);
            addedge(u,v,c,i); addedge(v,u,c,i);
        }
        tot=0;
        memset(tree,0,sizeof tree);
        memset(add,0,sizeof add);
        dfs(1,-1);
      //  for(int i=1;i<=tot;i++) prt(a[i]);
        build(1, tot, 1);
        int m; cin>>m;
        printf("Case #%d:\n",ca++);
        while(m--) {
            char s[55]; int u;
            scanf("%s",s);
            if(s[0]=='M') {
                scanf("%d", &u);
               // prt(id[u]);
               u--;
                update(in[u], out[u], 1, tot, 1);
            }
            else {
                int x = tree[1];
                printf("%d\n", x*(n-x)*2);
            }
        }
    }
}
