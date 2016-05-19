/***************************************************
é¢ç®å¤§æï¼
Nä¸ªç¹åN-1æ¡è¾¹,ä¿è¯æ´ä¸ªå¾è¿é(å ä¸ºè¾¹çéå¶,æä»¥ä¸å¯è½å½¢æç¯);
æ¯æ¡è¾¹é¿åº¦é½ä¸º1,é®è¦å°è¾¾kä¸ªç¹çæç­è·¯å¾(èµ·ç¹å¯ä»¥ä»kä¸ªé¡¶ç¹ä¸­ä»»æä¸ä¸ªåºå);

ç®æ³åæï¼
é¦åå¦ækå°äºç­äºç´å¾é¿åº¦ï¼é£ä¹ç­æ¡ä¸ºkâ1;
å¦ækå¤§äºç´å¾é¿åº¦ï¼è®¾ç´å¾é¿åº¦ä¸ºrï¼é£ä¹ç­æ¡ä¸ºrâ1+(kâr)*2;

æ çç´å¾ï¼æ ä¸çæé¿ç®åè·¯å¾;

å¯ä»¥éä¾¿éæ©ä¸ä¸ªç¹å¼å§è¿è¡bfsæèdfs;
ä»èæ¾å°ç¦»è¯¥ç¹æè¿çé£ä¸ªç¹;
å¯ä»¥è¯æ,ç¦»æ ä¸ä»»æä¸ç¹æè¿çç¹ä¸å®æ¯æ çææ¡ç´å¾çä¸¤ç«¯ç¹ä¹ä¸;
åä»æ¾å°çç¹åºå,æ¾å°æ®è¯¥ç¹çæè¿ç¹,é£ä¹è¿ä¸¤ç¹å°±ç¡®å®äºæ çä¸æ¡ç´å¾,ä¸¤ç¹é´è·å³ä¸ºææ±è·ç¦»;
****************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;
const int INF=0xffffff;

int n,m,k;
struct Edges
{
    int v,next;
} edge[N*2];

int head[N*2];
int e;
int q[N],vis[N],d[N];

void AddEdge(int u, int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;
}

void bfs(int src)
{
    for(int i = 1; i <= n; i++)
    {
        vis[i]=0;
        d[i] = INF;
    }
    int h=0,t=0;//éåå¤´å°¾
    q[t++]=src;
    vis[src]=1;
    d[src]=0;
    while(h<t)
    {
        int u = q[h++];
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if(d[u]+1<d[v])
            {
                d[v]= d[u]+1;
                if(!vis[v])
                {
                    q[t++]=v;
                    vis[v]=1;
                }
            }
        }
    }
}

int main()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    int tcase;
    scanf("%d",&tcase);
    while(tcase--)
    {
        int u,v;
        scanf("%d%d", &n, &m);
        e=0;
        memset(head, -1, sizeof(head));
        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            AddEdge(u,v);
            AddEdge(v,u);
        }

        bfs(1);

        int pos=-1;
        int x=-1;
        for(int i=1; i<=n; i++)
            if(d[i]>x)
            {
                x=d[i];
                pos=i;
            }

        bfs(pos);

        x=-1;
        for(int i=1; i<=n; i++)
        {
            if(d[i]>x)
                x=d[i];
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d",&k);
            if(k<=x+1)
                printf("%d\n", k-1);
            else
                printf("%d\n",x+2*(k-x-1));
        }
    }
    return 0;
}
