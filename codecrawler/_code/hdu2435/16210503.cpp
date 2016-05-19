#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=100,maxm=10000;

struct edge{
    int u,v,f,next;
}e[maxm+10];

int src,sink,cnt,head[maxn+10];
int visited[maxn+10],marked;
int dist[maxn+10];
int n,m;

void adde(int u,int v,int f){
    e[cnt].u=u,e[cnt].v=v,e[cnt].f=f,e[cnt].next=head[u],head[u]=cnt++;
    e[cnt].u=v,e[cnt].v=u,e[cnt].f=0,e[cnt].next=head[v],head[v]=cnt++;
}

void bfs(){
    marked++;
    for(int i=0;i<=sink;i++) dist[i]=0;
    queue <int> q;
    visited[src]=marked;
    q.push(src);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(int i=head[s];i!=-1;i=e[i].next){
            int d=e[i].v;
            if(e[i].f>0 && visited[d]!=marked ){
                q.push(d);
                dist[d]=dist[s]+1;
                visited[d]=marked;
            }
        }
    }
}

int dfs(int u,int delta){
    if(u==sink) return delta;
    else{
        int ret=0;
        for(int i=head[u];delta && i!=-1;i=e[i].next){
            if(e[i].f>0 && dist[e[i].v]==dist[u]+1){
                int d=dfs(e[i].v,min(e[i].f,delta));
                e[i].f-=d;
                e[i^1].f+=d;
                delta-=d;
                ret+=d;
            }
        }
        return ret;
    }
}

int maxflow(){
    int ret=0;
    while(true){
        bfs();
        if(visited[sink]!=marked) return ret;
        ret+=dfs(src,INF);
    }
    return ret;
}

void initial(){
    cnt=0;
    memset(head,-1,sizeof(head));
    marked++;
}

void input(){
    scanf("%d%d",&n,&m);
    src=1,sink=n;
    while(m-- >0){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adde(u,v,w);
    }
}

void solve(){
    int ans=maxflow();
    bool f[maxn+10];
    memset(f,false,sizeof(f));
    queue <int> q;
    q.push(src);
    f[src]=true;
    while(!q.empty() ){
        int s=q.front();
        q.pop();
        for(int i=head[s];i!=-1;i=e[i].next){
            int d=e[i].v;
            if(e[i].f>0 && !f[d]){
                q.push(d);
                f[d]=true;
            }
        }
    }

    vector <edge> v;
    for(int i=0;i<cnt;i++) v.push_back(e[i]);

    int tmp=0;
    for(int i=2;i<=n-1;i++){
        for(int j=2;j<=n-1;j++){
            if( f[i]  &&  ( ! f[j] ) ){
                int headu=head[i],headv=head[j];

                adde(i,j,INF);
                int flow=maxflow();
                if(flow>tmp) tmp=flow;

                cnt-=2;
                head[i]=headu,head[j]=headv;
                for(int t=0;t<cnt;t++) e[t]=v[t];
            }
        }
    }
    cout<<ans+tmp<<endl;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t-- >0){
        initial();
        input();
        solve();
    }
    return 0;
}
