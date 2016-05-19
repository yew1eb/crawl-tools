#include<queue>
#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
#define MAXN 333333
#define ls ch[rt][0]
#define rs ch[rt][1]
int ch[MAXN][2],fa[MAXN],val[MAXN],add[MAXN],ma[MAXN],mi[MAXN];
int le[MAXN],ri[MAXN];
bool _rt[MAXN];
inline void Add(int rt,int w){
    if(!rt)return ;
    val[rt]+=w,add[rt]+=w,ma[rt]+=w,mi[rt]+=w;
}
inline void down(int rt){
    if(add[rt]){
        Add(ls,add[rt]),Add(rs,add[rt]),add[rt]=0;
    }
}
inline void up(int rt){
    ma[rt]=max(max(ma[ls],ma[rs]),val[rt]);
    mi[rt]=min(min(mi[ls],mi[rs]),val[rt]);
    
    le[rt]=max(le[ls],le[rs]);
    le[rt]=max(max(ma[ls],val[rt])-min(val[rt],mi[rs]),le[rt]);
    
    ri[rt]=max(ri[ls],ri[rs]);
    ri[rt]=max(max(ma[rs],val[rt])-min(val[rt],mi[ls]),ri[rt]);
}
inline void rot(int rt){
    int f=fa[rt],side=ch[f][1]==rt,ll=ch[rt][!side];
    fa[ll]=f,ch[f][side]=ll;
    fa[rt]=fa[f];
    if(_rt[f])_rt[rt]=1,_rt[f]=0;
    else ch[fa[f]][ch[fa[f]][1]==f]=rt;
    fa[f]=rt,ch[rt][!side]=f;
    up(f),up(rt);
}

void _vis(int rt){
    if(!_rt[rt])_vis(fa[rt]);
    down(rt);
}
inline void splay(int rt){
    _vis(rt);
    while(!_rt[rt]){
        int f=fa[rt],ff=fa[f];
        if(_rt[f])rot(rt);
        else if((ch[f][1]==rt)==(ch[ff][1]==f))rot(f),rot(rt);
        else rot(rt),rot(rt);
    }up(rt);
}
int ace(int rt){
    int y=0;
    for(;rt;y=rt,rt=fa[rt]){
        splay(rt);_rt[rs]=1,rs=y,_rt[rs]=0;
        up(rt);
    }return y;
}
inline void lca(int &u,int &v){
    ace(v);v=0;
    for(;u;v=u,u=fa[u]){
        splay(u);
        if(!fa[u])return ;
        _rt[ch[u][1]]=1,ch[u][1]=v,_rt[ch[u][1]]=0;
        up(u);
    }
}
inline void query(int u,int v,int w){
    lca(u,v);
    int ans=max(ri[ch[u][1]],le[v]);
    ans=max(ans,max(val[u],ma[ch[u][1]])-min(mi[v],val[u]));
    printf("%d\n",ans);
    Add(ch[u][1],w);Add(v,w);
    val[u]+=w;up(u);
}
struct edge{int v,next;}e[MAXN<<1];
int head[MAXN],tot;
void _add(int u,int v){e[tot].next=head[u];e[tot].v=v;head[u]=tot++;}
void dfs(int u){
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(fa[v])continue;
        fa[v]=u;
        dfs(v);
    }
}
int n,m,q,u,v,w;
void init(){
    tot=0;scanf("%d",&n);
    for(int rt=0;rt<=n;++rt){
        head[rt]=-1;_rt[rt]=1;
        fa[rt]=add[rt]=ls=rs=0;
    }
    ma[0]=-INT_MAX;mi[0]=INT_MAX;le[0]=ri[0]=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&val[i]);
        mi[i]=ma[i]=val[i];le[i]=ri[i]=0;
    }
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);_add(u,v);_add(v,u);
    }
}
int main(){
    int _;scanf("%d",&_);
    while(_--){
        init();
        fa[1]=-1;dfs(1);fa[1]=0;
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d",&u,&v,&w);
            query(u,v,w);
        }
    }
    return 0;
}