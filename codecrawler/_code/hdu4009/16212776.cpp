/*
æ¯ä¸ªç¹æ¾å¶æå°çå¥è¾¹In[v] ? å¦ææé¤è·èç¹ä»¥å¤çç¹æ¾ä¸å°å¥è¾¹,åæ è§£ : å¦åç­æ¡ç´¯å In[v]
ççææ²¡æç¯ ? æ ç¯åå·²ç»æ¾å°è§£,è¿åç­æ¡ : å°ç¯ç¼©ç¹
éæ°æå¾,æ¯æ¡è¾¹[u->v]çæå¼åå»In[v],ç¶åéå¤ç¬¬ä¸æ­¥*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define M 1101
#define INF 1000000000
using namespace std;
struct edge
{
    int u , v , w;
}e[M * M];
struct point
{
    int x,y,z;
}home[M];
int pre[M],id[M],vis[M],in[M];
int n,m,X,Y,Z;
int Directed_MST(int root,int NV,int NE)
{
    int ret = 0;
    while(true){
        //æ­¥éª¤1ï¼æ¾å°æå°è¾¹
        for(int i = 0;i < NV;i ++)
            in[i] = INF;
        for(int i = 0;i < NE;i ++){
            int u = e[i].u , v = e[i].v;
            if(e[i].w < in[v] && u != v){
                pre[v] = u;
                in[v] = e[i].w;
            }
        }
        for(int i = 0;i < NV;i ++){
            if(i == root) continue;
            if(in[i] == INF) return -1;//é¤äºæ ¹èç¹ä»¥å¤æç¹æ²¡æå¥è¾¹ï¼åæ ¹æ æ³å°è¾¾ä»
        }
        int cntnode = 0;
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        //æ¾ç¯
        in[root] = 0;
        for(int i = 0;i < NV;i ++){//æ è®°æ¯ä¸ªç¯ï¼ç¼å·
            ret += in[i];
            int v = i;
            while(vis[v] != i && id[v] == -1 && v != root){
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1){
                for(int u = pre[v];u != v;u = pre[u]){
                    id[u] = cntnode;
                }
                id[v] = cntnode ++;
            }
        }
        if(cntnode == 0) break;//æ ç¯
        for(int i = 0;i < NV;i ++)
            if(id[i] == -1){
                id[i] = cntnode ++;
            }
        //æ­¥éª¤3ï¼ç¼©ç¹ï¼éæ°æ è®°
        for(int i = 0;i < NE;i ++){
            int v = e[i].v;
            e[i].u = id[e[i].u];
            e[i].v = id[e[i].v];
            if(e[i].u != e[i].v) e[i].w -= in[v];
        }
        NV = cntnode;
        root = id[root];
    }
    return ret;
}
int dis(int a,int b)
{
    return abs(home[a].x - home[b].x) + abs(home[a].y - home[b].y) + abs(home[a].z - home[b].z);
}
void add_edge(int u,int v,int w)
{
    e[m].u = u , e[m].v = v,e[m].w = w;
    m ++;
}
int main()
{
    while(scanf("%d%d%d%d",&n,&X,&Y,&Z) != EOF && n){
        m = 0;
        for(int i = 1;i <= n;i ++){
            scanf("%d%d%d",&home[i].x,&home[i].y,&home[i].z);
            add_edge(0,i,home[i].z * X);
        }
        for(int i = 1;i <= n;i ++){
            int num , u = i , v , w;
            scanf("%d",&num);
            for(int j = 0;j < num;j ++){
                scanf("%d",&v);
                if(v == i) continue;
                w = dis(u,v) * Y;
                if(home[v].z > home[u].z) w += Z;
                add_edge(u,v,w);
            }
        }
        int ans = Directed_MST(0,n + 1,m);
        printf("%d\n",ans);
    }
    return 0;
}