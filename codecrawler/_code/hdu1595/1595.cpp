/*ID:cxlove
PROB:HDU 1595
DATA:2012.4.4
HINT:最短路径+枚举最短路径上的边
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#define inf 1<<30
using namespace std;
struct Node{
    int u,v,w,next;
}edge[1000005];
struct EDGE{
    int u,v,w,idx1,idx2;
}path[1005];
int start[1005],pre[1005],dist[1005];
int n,m,cnt,tot;
void addedge(int u,int v,int w){
    edge[cnt].u=u;edge[cnt].v=v;edge[cnt].w=w;
    edge[cnt].next=start[u];start[u]=cnt++;
}
void Init(){
    int u,v,w;
    cnt=0;tot=0;
    memset(start,-1,sizeof(start));
    memset(pre,-1,sizeof(pre));
    while(m--){
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
}
void spfa(){
    bool flag[1005];
    for(int i=1;i<=n;i++)
        dist[i]=inf;
    memset(flag,false,sizeof(flag));
    queue<int >que;
    que.push(1);
    flag[1]=true;
    dist[1]=0;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        flag[u]=false;
        for(int i=start[u];i!=-1;i=edge[i].next){
            int v=edge[i].v,w=edge[i].w;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pre[v]=u;
                if(!flag[v]){
                    flag[v]=true;
                    que.push(v);
                }
            }
        }
    }
}
void find_path(){
    int v=n;
    while(pre[v]!=-1){
        path[tot].u=pre[v];
        path[tot].v=v;
        path[tot].w=dist[v]-dist[pre[v]];
        int k=start[pre[v]];
        while(edge[k].v!=v)
            k=edge[k].next;
        path[tot].idx1=k;
        k=start[v];
        while(edge[k].v!=pre[v])
            k=edge[k].next;
        path[tot++].idx2=k;
        v=pre[v];
    }
}
void slove(){
    int ans=0;
    for(int i=0;i<tot;i++){
        int idx1=path[i].idx1,idx2=path[i].idx2;
        int t1=edge[idx1].w,t2=edge[idx2].w;
        edge[idx1].w=inf;edge[idx2].w=inf;
        spfa();
        ans=max(ans,dist[n]);
        edge[idx1].w=t1;edge[idx2].w=t2;
    }
    printf("%d\n",ans);
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        Init();
        spfa();;
        find_path();
        slove();
    }
    return 0;
}