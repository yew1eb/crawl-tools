#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define B(x) (1<<(x))
using namespace std;
typedef long long ll;
void cmax(int& a,int b){ if(b>a)a=b; }
void cmin(int& a,int b){ if(b<a)a=b; }
void cmax(ll& a,ll b){ if(b>a)a=b; }
void cmin(ll& a,ll b){ if(b<a)a=b; }
void add(int& a,int b,int mod){ a=(a+b)%mod; }
void add(ll& a,ll b,ll mod){ a=(a+b)%mod; }
const int oo=0x3f3f3f3f;
const int MOD=1000000007;
const double eps = 1e-8;
const int maxn = 100005;
const int maxm = 300005;
struct EDGE{
    int v,next;
}E[maxm << 1];
int head[maxn],tol;
int low[maxn],dfn[maxn],instack[maxn],Stack[maxn];
int id[maxn],vis[maxm << 1],col[maxn],Q[maxm],f,r;
int cnt[maxn],num[maxn],s[maxn];
int g_cnt,ID,top,n;

void Init(){
    memset(head,-1,sizeof head);
    memset(low,0,sizeof low);
    memset(dfn,0,sizeof dfn);
    memset(instack,0,sizeof instack);
    memset(vis,0,sizeof vis);
    g_cnt=ID=tol=top=0;
}

void add_edge(int u,int v){
    E[tol].v=v;
    E[tol].next=head[u];
    head[u]=tol++;
}

void Tarjan(int u){
    dfn[u]=low[u]=++g_cnt;
    Stack[++top]=u;
    instack[u]=1;
    int v;
    for(int i=head[u];i!=-1;i=E[i].next){
        v=E[i].v;
        if(vis[i])continue;
        vis[i]=vis[i^1]=1;
        if(!dfn[v]){
            Tarjan(v);
            if(low[v]<low[u])
                low[u]=low[v];
        }else if(instack[v]&&dfn[v]<low[u])
            low[u]=dfn[v];
    }
    if(dfn[u]==low[u]){
        ID++;
        do{
            v=Stack[top--];
            instack[v]=0;
            id[v]=ID;
        }while(u!=v);
    }
}

bool had_odd(){
    memset(col,-1,sizeof col);
    for(int i=1;i<=n;i++){
        if(col[i]!=-1)continue;
        col[i]=1;
        f=r=0;
        Q[r++]=i;
        while(f<r){
            int u=Q[f++];
            for(int i=head[u];i!=-1;i=E[i].next){
                int v=E[i].v;
                if(col[u]==col[v]) return true;
                else if(col[v]==-1){
                    col[v]=1-col[u];
                    Q[r++]=v;
                }
            }
        }
    }
    return false;
}

int Count;
void dfs(int u, int index){
    cnt[u]++;
    if(cnt[u]>1)Count++;
    for(int i=head[u];i!=-1;i=E[i].next){
        int v=E[i].v;
        if(vis[i]) continue;
        vis[i]=vis[i^1]=1;
        if(id[v]!=index) continue;
        dfs(v, index);
    }
}

bool had_even(){
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            Tarjan(i);
    //printf("ID=%d\n",ID);
    if(ID==0)return false;
    memset(cnt,0,sizeof cnt);
    memset(vis,0,sizeof vis);
    memset(num,0,sizeof num);
    memset(s,0,sizeof s);
    for(int i=1;i<=n;i++){
        s[id[i]]=i;
        num[id[i]]++;
    }
    for(int i=1;i<=ID;i++){
        Count=0;
        dfs(s[i],i);
        //printf("fuck: %d %d\n",Count,num[i]);
        if(num[i]==1)continue;
        if(!(Count==1 && num[i]%2==1)) return true;
    }
    return false;
}

int main(){
    //freopen("E:\\read.txt","r",stdin);
    int T,m,u,v;
    scanf("%d", &T);
    while(T--){
        Init();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        if(had_odd()) puts("YES");
        else puts("NO");
        if(had_even()) puts("YES");
        else puts("NO");
    }
    return 0;
}
/*
2
5 6
1 2
2 3
3 1
3 5
3 4
5 4

5 6
1 2
2 1
2 3
3 2
3 4
3 5
*/
