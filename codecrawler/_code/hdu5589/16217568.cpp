#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define Maxn 50010
#define ll long long
using namespace std;

struct edge{
    int to,next,w;
}p[Maxn<<1];
int tot;
int head[Maxn];
int x[Maxn];
void addedge(int u,int v,int w){
    p[tot].to=v;
    p[tot].next=head[u];
    p[tot].w=w;
    head[u]=tot++;
}
void dfs(int u,int fa){
    for(int i=head[u];i!=-1;i=p[i].next){
        int v=p[i].to;
        if(v==fa) continue;
        x[v]=p[i].w^x[u];
        dfs(v,u);
    }
}
int pos[Maxn];
struct query{
    int l,r,id;
    bool operator<(const query &a)const{
        return pos[l]<pos[a.l]||pos[l]==pos[a.l]&&r<a.r;
    }
}q[Maxn];
int sz;
void init(int n,int t){
    sz=(int)sqrt(n);
    for(int i=0;i<n;i++) pos[i]=i/sz;
    sort(q,q+t);
}
int M;
struct trie{
    int ch[Maxn*30][2];
    int val[Maxn*30];
    int sz;
    void init(){
        sz=val[0]=0;
        memset(ch[0],0,sizeof ch[0]);
    }
    void insert(int x){
        int u=0;
        for(int i=17;i>=0;i--){
            int c=x>>i&1;
            if(!ch[u][c]){
                ch[u][c]=++sz;
                val[sz]=0;
                memset(ch[sz],0,sizeof ch[sz]);
            }
            u=ch[u][c];
            val[u]++;
        }
    }
    void del(int x){
        int u=0;
        for(int i=17;i>=0;i--){
            int c=x>>i&1;
            u=ch[u][c];
            val[u]--;
        }
    }
    ll query(int y){
        int u=0;
        ll ans=0;
        for(int i=17;i>=0;i--){
            int c=M>>i&1,d=y>>i&1;
            if(c==1) u=ch[u][d^1];
            else{
                ans+=val[ch[u][d^1]];
                u=ch[u][d];
            }
            if(!u) return ans;
        }
        return ans;
    }
}tr;
ll res[Maxn];
void solve(int t){
    tr.init();
    ll ans=0;
    int l=0,r=-1;
    for(int i=0;i<t;i++){
        while(r<q[i].r) ++r,ans+=tr.query(x[r]),tr.insert(x[r]);
        while(q[i].l<l) --l,ans+=tr.query(x[l]),tr.insert(x[l]);
        while(r>q[i].r) tr.del(x[r]),ans-=tr.query(x[r]),r--;
        while(q[i].l>l) tr.del(x[l]),ans-=tr.query(x[l]),l++;
        res[q[i].id]=ans;
    }
}
int main()
{
    int n,t,u,v,w;
    while(~scanf("%d%d%d",&n,&M,&t)){
        memset(head,-1,sizeof head);
        tot=0;
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            u--,v--;
            addedge(u,v,w);
            addedge(v,u,w);
        }
        x[0]=0;
        dfs(0,-1);
        for(int i=0;i<t;i++){
            scanf("%d%d",&q[i].l,&q[i].r);
            q[i].l--,q[i].r--,q[i].id=i;
        }
        init(n,t);
        solve(t);
        for(int i=0;i<t;i++)
            printf("%I64d\n",res[i]);
    }
    return 0;
}