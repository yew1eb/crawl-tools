/*
é¢ç®å¤§æï¼
   å»æç»å®çè¾¹ï¼çæ¯ä¸ä¸ªç¹æ¯å¦è½ä»å«çç¹å°è¾¾ï¼
    å¦æè½å¤å°è¾¾ï¼åæ±åºå¯¹äºæ¯ä¸ä¸ªç¹å°å¶ä»ææçç¹æç­è·ç¦»ä¹åï¼å°è¿äºåç¸å å°±æ¯æåçç»æ
è§£æ³ï¼
    å¯¹æ¯ä¸ªé¡¶ç¹æ±ä¸æ¬¡æç­è·¯ï¼ç¶åç¨sum[i]å°åä¸ªé¡¶ç¹çæç­è·¯çåä¿å­èµ·æ¥ï¼
    å¯¹å°è¦å é¤çæ¯ä¸ªé¡¶ç¹ï¼å¦ææ±æç­è·¯uè½å¤å°è¾¾v,ååå°±ä¸év,åå«è®°ä¸ºsum_u,sum_v
    é£ä¹ç­æ¡å³ä¸ºï¼sum[1]+...+sum[n]+sum_u+sum_v-sum[u]-sum[v];
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 250;
const int INF=99999999;
struct Node
{
    int v,next,w;
    bool operator < (const Node &a) const
    {
        return w > a.w;
    }
} Edge[2000002],t1,t2;
int dis[N],vis[N],head[N],cnt,n,m,sum[N],num[3002];
void addEdge(int u,int v,int w)
{
    Edge[cnt].v = v;
    Edge[cnt].next = head[u];
    Edge[cnt].w = w;
    head[u]=cnt++;
}
void dijstra(int  st)
{
    priority_queue<Node> q;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n+1;i++)dis[i]=INF;
    for(int i = head[st] ; i != -1 ; i = Edge[i].next)
    {
        int v = Edge[i].v;
        if(Edge[i].w<dis[v])
        {
            dis[v] = Edge[i].w;
            t1.w = dis[v];
            t1.v =  v;
            q.push(t1);
        }
    }
    dis[st]=0;//æ­¤å¥æ²¡å éäº2æ¬¡ï¼å§~~~
    vis[st] = 1;
    while(!q.empty())
    {
        t1 = q.top();
        q.pop();
        int u = t1.v;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i != -1; i = Edge[i].next)
        {
            int v = Edge[i].v;
            if(!vis[v] && dis[v]>dis[u]+Edge[i].w)
            {
                dis[v] =dis[u]+Edge[i].w;
                t2.v = v;
                t2.w = dis[v];
                q.push(t2);
            }
        }
    }
   return;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        memset(sum,0,sizeof(sum));
        memset(num,-1,sizeof(num));
        cnt=0;
        int ans=0,res;
        int u,v;
        for(j=1; j<=m; j++)
        {
            cin>>u>>v;
            num[j]=cnt;
            addEdge(u,v,1);
            addEdge(v,u,1);
        }
        for(i=1;i<=n;i++)
        {
            dijstra(i);
            for(j=1;j<=n;j++)sum[i]+=dis[j];
            ans+=sum[i];
        }
        for(i=1;i<=m;i++)
        {
            if(ans>=INF)
            {
                printf("INF\n");continue;
            }
            Edge[num[i]^1].w=Edge[num[i]].w=INF;
            res=0;
            dijstra(Edge[num[i]].v);
            for(j=1;j<=n;j++)res+=dis[j];
            if(res>=INF)
            {
                printf("INF\n");
            }else
            {
                 dijstra(Edge[num[i]^1].v);
                 for(j=1;j<=n;j++)res+=dis[j];
                 if(res>=INF)printf("INF\n");
                 else printf("%d\n",ans+res-(sum[Edge[num[i]].v]+sum[Edge[num[i]^1].v]));
            }
            Edge[num[i]^1].w=Edge[num[i]].w=1;
        }
    }
    return 0;
}
/*
5 4
5 1
1 3
3 2
5 4
2 2
1 2
1 2


*/
