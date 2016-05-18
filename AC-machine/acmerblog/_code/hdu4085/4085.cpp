#include<cstdio>
#include<cstring>
#include<queue>
#define M 1100
#define N 55
#define INF 100000000
using namespace std;
struct Edge{
    int v,w,next;
}edge[M*2];
int head[N],cnt;
int n,m,k,K;
int st[N];
int dp[N][1100];
bool vis[N][1100];
int ans[1100];
queue<int>q;
void addedge(int u,int v,int w){
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].v=u;
    edge[cnt].w=w;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}
void init(){
    int i,j;
    K=1<<(2*k);
    cnt=0;
    memset(head,-1,sizeof(head));
    memset(st,0,sizeof(st));
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
        for(j=0;j<K;j++)
            dp[i][j]=INF;
    for(i=1;i<=k;i++){
        st[i]=1<<(i-1);
        dp[i][st[i]]=0;
    }
    for(i=1;i<=k;i++){
        st[n-k+i]=1<<(k+i-1);
        dp[n-k+i][st[n-k+i]]=0;
    }
}
void SPFA(){
    int i;
    while(!q.empty()){
        int x=q.front()%10000,y=q.front()/10000;
        vis[y][x]=0;
        q.pop();
        for(i=head[y];i!=-1;i=edge[i].next){
            if(dp[edge[i].v][st[edge[i].v]|x]>dp[y][x]+edge[i].w){
                dp[edge[i].v][st[edge[i].v]|x]=dp[y][x]+edge[i].w;
                if(!vis[edge[i].v][st[edge[i].v]|x] && (st[edge[i].v]|x)==x){ //st[edge[i].v]有可能为0
                    vis[edge[i].v][st[edge[i].v]|x]=1;
                    q.push(edge[i].v*10000+x);
                }
            }
        }
    }
}
void Steiner_Tree(){
    int i,j,x;
    for(i=0;i<K;i++){
        for(j=1;j<=n;j++){
            if(st[j] && (st[j]&i))continue;
            for(x=(i-1)&i;x;x=(x-1)&i)
                dp[j][i]=min(dp[j][i],dp[j][x|st[j]]+dp[j][(i-x)|st[j]]);
            if(dp[j][i]!=INF){
                q.push(j*10000+i);
                vis[j][i]=1;
            }
        }
        SPFA();
    }
}
bool check(int u){
    int r=0,i;
    for(i=0;i<k;i++){
        if(u&(1<<i))r++;
        if(u&(1<<(i+k)))r--;
    }
    return !r;
}
int main(){
    int t,T,i,j;
    int u,v,w;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d %d %d",&n,&m,&k);
        init();
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&u,&v,&w);
            addedge(u,v,w);
        }
        Steiner_Tree();
        for(i=0;i<K;i++){
            ans[i]=INF;
            for(j=1;j<=n;j++)
                ans[i]=min(ans[i],dp[j][i]);
        }
        for(i=0;i<K;i++)
            if(check(i))
                for(j=(i-1)&i;j;j=(j-1)&i)
                    if(check(j))
                        ans[i]=min(ans[i],ans[j]+ans[i-j]);
        if(ans[K-1]==INF)printf("No solution\n");
        else printf("%d\n",ans[K-1]);
    }
    return 0;
}
