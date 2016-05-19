#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#include<set>  
#include<string>  
#include<queue>  
#define inf 1600005  
#define M 40  
#define N 200005  
#define maxn 300005  
#define eps 1e-7
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL unsigned long long  
#define MOD 2012  
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;  
struct Edge{
    int v,w,next;
}e[100005];
int start[105],tot;
bool ext[105];
int p1,p2;
int n,m,ee;
int a[105][105];
int police[105],pep[105];
void add(int u,int v,int w){
    e[tot].v=v;e[tot].w=w;e[tot].next=start[u];
    start[u]=tot++;
}
bool mark;
bool vis[105];
double v_p,v_o=160;
void dfs(int u,int pre){
    if(mark) return;
    if(police[u]*v_p<=pep[u]*v_o) return ;
    vis[u]=true;
    if(ext[u]) {mark=true;return;}
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre||vis[v]) continue;
        dfs(v,u);
        if(mark) return ;
    }
}
bool check(double vv){
    mark=false;
    v_p=vv;
    mem(vis,false);
    dfs(p1,0);
    return mark;
}
void slove(){
    double low=0,mid,high=0;
    for(int i=1;i<=n;i++){
        if(!police[i]) continue;
        high=max(high,(double)pep[i]*v_o/police[i]);
    }
    high+=2*eps;
    double ans=-1;
    while(low+eps<high){
        mid=(low+high)/2;
        if(check(mid)){
            ans=mid;
            high=mid;
        }
        else low=mid;
    }
    if(ans<0) puts("IMPOSSIBLE");
    else printf("%.10f\n",ans);
}
void Spfa(int s,int *dist){
    queue<int>que;
    while(!que.empty()) que.pop();
    bool flag[105];mem(flag,false);
    for(int i=1;i<=n;i++) dist[i]=inf;
    dist[s]=0;flag[s]=true;
    que.push(s);
    while(!que.empty()){
        int u=que.front();
        flag[u]=false;
        que.pop();
        for(int i=start[u];i!=-1;i=e[i].next){
            int v=e[i].v,w=e[i].w;
            if(v==p2) continue;
            int tmp=dist[u]+w;
            if(tmp<dist[v]){
                dist[v]=tmp;
                if(!flag[v]){
                    que.push(v);
                    flag[v]=true;
                }
            }
            
        }
    }
}
int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    while(scanf("%d%d%d",&n,&m,&ee)!=EOF){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=inf;
        tot=0;mem(start,-1);
        while(m--){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);add(v,u,w);
        }  
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]<inf)
                    add(i,j,a[i][j]);
        mem(ext,false);
        for(int i=0;i<ee;i++){
            int k;
            scanf("%d",&k);
            ext[k]=true;
        }
        scanf("%d%d",&p1,&p2);
        Spfa(p1,pep);
        Spfa(p2,police);
        slove();
    }
    return 0;
}