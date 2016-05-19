#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

#define mkp make_pair
#define fst first
#define scd second

using namespace std;
int dis[100011];
int vis[100011];
int lay[100011];
vector<int>vec[100011];
struct Edge_t{
    int to,next,cap;
}edge[500000];
int head[100011],et;

inline void adde(int u,int v,int w){
    edge[et].to=v;
    edge[et].cap=w;
    edge[et].next=head[u];
    head[u]=et++;
}

inline void spfa(int n,int C){
    queue<int>q;
    q.push(1);
    memset(vis,0,sizeof vis);
    memset(dis,-1,sizeof dis);
    dis[1]=0;
    int e,u,v,size,i,k;
    while(!q.empty()){
        u=q.front();q.pop();
        vis[u]=0;
        for(e=head[u];~e;e=edge[e].next){
            v=edge[e].to;
            if(dis[v]<0 || dis[v]>dis[u]+edge[e].cap){
                dis[v]=dis[u]+edge[e].cap;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        if(lay[u]>1){
            size=vec[k=(lay[u]-1)].size();
            for(i=0;i<size;++i){
                v=vec[k][i];
                if(dis[v]<0 || dis[v]>dis[u]+C){
                    dis[v]=dis[u]+C;
                    if(!vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        if(lay[u]<n){
            size=vec[k=lay[u]+1].size();
            for(i=0;i<size;++i){
                v=vec[k][i];
                if(dis[v]<0 || dis[v]>dis[u]+C){
                    dis[v]=dis[u]+C;
                    if(!vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
            
        }
    }
}

int main(){
    int t,tt=0,C;
    int n,m,u,v,i,size,w;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&C);
        memset(head,-1,sizeof head);et=0;
        memset(vis,0,sizeof vis);
        for(i=1;i<=n;++i){
            scanf("%d",&lay[i]);//ç¬¬iä¸ªç¹æä»¥å±ä¸ºlay[i]
            vec[i].clear();
        }
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            adde(u,v,w);adde(v,u,w);
            if(!vis[u]){//æç¹å å¥å±..
                vec[lay[u]].push_back(u);
                vis[u]=1;
            }
            if(!vis[v]){
                vec[lay[v]].push_back(v);
                vis[v]=1;
            }
        }
        if(!vis[1])//å§ç¹åç»äºä¸å®è¦å¨æä¸å±å..
            vec[lay[1]].push_back(1);
        if(!vis[n])
            vec[lay[n]].push_back(n);
        for(i=1;i<=n;++i)//å¦ææä¸å±æ²¡æç¹
            if(vec[lay[i]].empty())
                vec[lay[i]].push_back(i);
        spfa(n,C);
        printf("Case #%d: %d\n",++tt,dis[n]);
    }
    return 0;
}
