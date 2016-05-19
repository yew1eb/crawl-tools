#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 1010
#define M 20010
#define inf 100000000
using namespace std;
int a[N],b[N],c[N];
int in[N],pre[N],id[N],vis[N];
struct Edge{
    int u,v,w;
}edge[M];
int m,n,ansi;
int Directed_MST(int root){
    int ret=0,i;
    while(1){
        for(i=0;i<=n;i++)in[i]=inf;
        for(i=0;i<m;i++){
            int u=edge[i].u,v=edge[i].v;
            if(edge[i].w<in[v] && u!=v){
                pre[v]=u;
                in[v]=edge[i].w;
                if(u==root)
                    ansi=i;  //è¿éç¡®å®äºèææ ¹èç¹çåºè¾¹ï¼åè®¾ækä¸ªç¹é½å¯ä»¥åçæ­£æ ¹èç¹ï¼é£ä¹æåè¿kä¸ªç¹ä¸å®å¨ä¸ä¸ªç¯é
            }
        }
        in[root]=0;
        for(i=0;i<=n;i++)
            if(in[i]==inf)return -1;
        int node=0;
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        for(i=0;i<=n;i++){
            ret+=in[i];
            int v=i;
            while(vis[v]!=i && id[v]==-1 && v!=root){
                vis[v]=i;
                v=pre[v];
            }
            if(v!=root && id[v]==-1){
                for(int u=pre[v];u!=v;u=pre[u])
                    id[u]=node;
                id[v]=node++;
            }
        }
        if(node==0)break;
        for(i=0;i<=n;i++)
            if(id[i]==-1)
                id[i]=node++;
        for(i=0;i<m;i++){
            int v=edge[i].v;
            edge[i].u=id[edge[i].u];
            edge[i].v=id[edge[i].v];
            if(edge[i].u!=edge[i].v)
                edge[i].w-=in[v];
        }
        n=node-1;
        root=id[root];
    }
    return ret;
}
int main(){
    int i,j,sum,vv,e;
    int u,v,w;
    while(scanf("%d %d",&vv,&e)==2){
        sum=1;
        for(i=0;i<e;i++){
            scanf("%d %d %d",&u,&v,&w);
            u++,v++;
            edge[i].u=u,edge[i].v=v,edge[i].w=w;
            sum+=w;
        }
        for(i=0;i<vv;i++)
            edge[i+e].u=0,edge[i+e].v=i+1,edge[i+e].w=sum;
        m=vv+e,n=vv;
        int ans=Directed_MST(0);
        if(ans>sum*2)printf("impossible\n\n");
        else printf("%d %d\n\n",ans-sum,ansi-e);
    }
}
