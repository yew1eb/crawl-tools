#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#define MAXN 1005
#define INF 0x7f7f7f7f
typedef __int64 type;
struct node//è¾¹çæåé¡¶ç¹
{
    int u, v;
    type w;
}edge[MAXN * MAXN];
int pre[MAXN], id[MAXN], vis[MAXN], n, m, pos;
type in[MAXN];//å­æå°å¥è¾¹æ,pre[v]ä¸ºè¯¥è¾¹çèµ·ç¹
type Directed_MST(int root, int V, int E)
{
    type ret = 0;//å­æå°æ å½¢å¾æ»æå¼
    while(true)
    {
        int i;
        //1.æ¾æ¯ä¸ªèç¹çæå°å¥è¾¹
        for( i = 0; i < V; i++)
            in[i] = INF;//åå§åä¸ºæ ç©·å¤§
        for( i = 0; i < E; i++)//éåæ¯æ¡è¾¹
        {
            int u = edge[i].u;
            int v = edge[i].v;
            if(edge[i].w < in[v] && u != v)//è¯´æé¡¶ç¹vææ¡æå¼è¾å°çå¥è¾¹  è®°å½ä¹
            {
                pre[v] = u;//èç¹uæåv
                in[v] = edge[i].w;//æå°å¥è¾¹
                if(u == root)//è¿ä¸ªç¹å°±æ¯å®éçèµ·ç¹
                    pos = i;
            }
        }
        for( i = 0; i < V; i++)//å¤æ­æ¯å¦å­å¨æå°æ å½¢å¾
        {
            if(i == root)
                continue;
            if(in[i] == INF) 
                return -1;//é¤äºæ ¹ä»¥å¤æç¹æ²¡æå¥è¾¹,åæ ¹æ æ³å°è¾¾å®  è¯´æå®æ¯ç¬ç«çç¹ ä¸å®ä¸è½æææ å½¢å¾
        }
        //2.æ¾ç¯
        int cnt = 0;//è®°å½ç¯æ°
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
        for( i = 0; i < V; i++) //æ è®°æ¯ä¸ªç¯
        {
            ret += in[i];//è®°å½æå¼
            int v = i;
            while(vis[v] != i && id[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1)
            {
                for(int u = pre[v]; u != v; u = pre[u])
                    id[u] = cnt;//æ è®°èç¹uä¸ºç¬¬å ä¸ªç¯
                id[v] = cnt++;
            }
        }
        if(cnt == 0)
            break; //æ ç¯   åbreak
        for( i = 0; i < V; i++)
            if(id[i] == -1)
                id[i] = cnt++;
            //3.å»ºç«æ°å¾   ç¼©ç¹,éæ°æ è®° 
            for( i = 0; i < E; i++)
            {
                int u = edge[i].u;
                int v = edge[i].v;
                edge[i].u = id[u];
                edge[i].v = id[v];
                if(id[u] != id[v])
                    edge[i].w -= in[v];
            }
            V = cnt;
            root = id[root];
    }
    return ret;
}
int main()
{
    int i;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        type sum = 0;
        for( i = 0; i < m; i++)
        {
            scanf("%d%d%I64d", &edge[i].u, &edge[i].v, &edge[i].w);
            edge[i].u++; edge[i].v++;
            sum += edge[i].w;
        }
      sum ++;
        for( i = m; i < m + n; i++)//å¢å è¶çº§èç¹0,èç¹0å°å¶ä½åä¸ªèç¹çè¾¹æç¸åï¼æ­¤é¢ä¸­ è¾¹æè¦å¤§äºåå¾çæ»è¾¹æå¼ï¼
        {
            edge[i].u = 0;
            edge[i].v = i - m + 1;
            edge[i].w = sum;
        }
        type ans = Directed_MST(0, n + 1, m + n);
        //n+1ä¸ºæ»ç»ç¹æ°,m+nä¸ºæ»è¾¹æ°
        //ansä»£è¡¨ä»¥è¶çº§èç¹0ä¸ºæ ¹çæå°æ å½¢å¾çæ»æå¼,
        //å°ansåå»sum,å¦æå·®å¼å°äºsum,è¯´æèç¹0çåºåº¦åªæ1,è¯´æåå¾æ¯è¿éå¾
        //å¦æå·®å¼>=sum,é£ä¹è¯´æèç¹0çåºåº¦ä¸æ­¢ä¸º1,è¯´æåå¾ä¸æ¯è¿éå¾
        if(ans == -1 || ans - sum >= sum)
            puts("impossible");
        else
            printf("%I64d %d\n",ans - sum, pos - m);
        puts("");
    }
    return 0;
}
