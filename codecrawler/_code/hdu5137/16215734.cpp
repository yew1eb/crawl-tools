#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 31
#define MAXE 1010
#define INF 1e9+7
using namespace std;
int head[MAXN];
struct Edge{
    int to,cost,next;
}edge[MAXE*2];
struct node{
    int ct;
    int cost;
    node(int _ct,int _cost):ct(_ct),cost(_cost){}
    bool operator<(const node& b)const{///æ³¨æä¼åæéå:<ä»£è¡¨å¤§é¡¶å ,>ä»£è¡¨å°é¡¶å 
        return cost>b.cost;
    }
};
int tol;
void addEdge(int x,int y,int cost){
    edge[tol].to=y;
    edge[tol].cost=cost;
    edge[tol].next=head[x];
    head[x]=tol++;

    edge[tol].to=x;
    edge[tol].cost=cost;
    edge[tol].next=head[y];
    head[y]=tol++;
}
int n,m;
int dis[MAXN];
bool vis[MAXN];
void bfs(int nt){
    memset(vis,false,sizeof(vis));
    vis[nt]=true;
    for(int i=1;i<=n;++i)
        dis[i]=INF;
    dis[1]=0;
    priority_queue<node> pq;
    while(!pq.empty()) pq.pop();
    pq.push(node(1,0));
    while(!pq.empty()){
        node tmp=pq.top();
        pq.pop();
        int u=tmp.ct;
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            int cost=edge[i].cost;
            if(!vis[v]&&dis[v]>dis[u]+cost){
                dis[v]=dis[u]+cost;
                pq.push(node(v,dis[v]));
            }
        }
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&(n!=0||m!=0)){
        tol=0;
        memset(head,-1,sizeof(head));
        int x,y,cost;
        for(int i=1;i<=m;++i){
            scanf("%d%d%d",&x,&y,&cost);
            addEdge(x,y,cost);
        }
        int ans=0;
        for(int i=2;i<n;++i){
            bfs(i);
            ans=max(ans,dis[n]);
        }
        if(ans<INF)
            printf("%d\n",ans);
        else
            printf("Inf\n");
    }
    return 0;
}
