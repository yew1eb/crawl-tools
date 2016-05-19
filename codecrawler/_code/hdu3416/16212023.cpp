/*
é¢æï¼ æ n ä¸ªåå¸ï¼ç¥éäºèµ·ç¹åç»ç¹ï¼
æ m æ¡æåè¾¹ï¼é®ä»èµ·ç¹å°ç»ç¹ä¸ç¸äº¤çæç­è·¯ä¸å±æå¤å°æ¡ã
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;
const int N=2002;
const int M = 222222;
const int INF = 1 << 30;
int n,m,t,dis[N];
int vis[N],head[N],Head[N],cnt;
int gap[N],pre[N],cur[N];
int NE,NV,sink,source,Edgeu[M],Edgev[M],Edgew[M];
struct node
{
    int v,next,w;
    bool operator < (const node &a) const
    {
        return w > a.w;
    }
} Edge[M*4],t1,t2;
struct Node
{
    int c,pos,next;
} E[M*4];
void addedge(int u,int v,int w)
{
    Edge[cnt].v = v;
    Edge[cnt].next = Head[u];
    Edge[cnt].w = w;
    Head[u] = cnt++;
}
void addEdge(int u,int v,int c)
{
    E[NE].c = c;
    E[NE].pos = v;
    E[NE].next = head[u];
    head[u] = NE++;
    E[NE].c = 0;
    E[NE].pos = u;
    E[NE].next = head[v];
    head[v] = NE++;
}
#define FF(i,NV) for(int i=0;i<NV;i++)
int sap(int s,int t)
{
    memset(dis,0,sizeof(int)*(NV+1));
    memset(gap,0,sizeof(int)*(NV+1));
    memset(pre,-1,sizeof(int)*(NV+1));
    FF(i,NV) cur[i] = head[i];
    int u = pre[s] = s,maxflow = 0,aug =INF;
    gap[0] = NV;
    while(dis[s] < NV)
    {
loop:
        for(int &i = cur[u]; i != -1; i = E[i].next)
        {
            int v = E[i].pos;
            if(E[i].c && dis[u] == dis[v] + 1)
            {
                aug=min(aug,E[i].c);
                pre[v] = u;
                u = v;
                if(v == t)
                {
                    maxflow += aug;
                    for(u = pre[u]; v != s; v = u,u = pre[u])
                    {
                        E[cur[u]].c -= aug;
                        E[cur[u]^1].c += aug;
                    }
                    aug =INF;
                }
                goto loop;
            }
        }
        if( (--gap[dis[u]]) == 0)   break;
        int mindis = INF;
        for(int i = head[u]; i != -1 ; i = E[i].next)
        {
            int v = E[i].pos;
            if(E[i].c && mindis > dis[v])
            {
                cur[u] = i;
                mindis = dis[v];
            }
        }
        gap[ dis[u] = mindis+1 ] ++;
        u = pre[u];
    }
    return maxflow;
}
void dijstra(int  st,int dis[])
{
    priority_queue<node> q;
    while(!q.empty()) q.top(),q.pop();
    for(int i = Head[st] ; i != -1 ; i = Edge[i].next)
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
        for(int i = Head[u]; i != -1; i = Edge[i].next)
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
}
int main()
{
    int n,m,st,ed,disd[N],dist[N];
    //freopen("//media/å­¦ä¹ /ACM/input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(int)*(n+1));
        memset(Head,-1,sizeof(int)*(n+1));
        int i,j,u,v,w,num=0;
        for(NE=cnt=0,NV=n+2,j=1; j<=m; j++)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(u!=v)
            {
              addedge(v,u,w);
              Edgeu[num]=u,Edgev[num]=v,Edgew[num]=w;
              num++;
             // addedge(v,u,w);
            }
        }
        scanf("%d%d",&st,&ed);
        for(cnt=i=0;i<=n+1;i++) disd[i]=dist[i] = INF;
        memset(vis,0,sizeof(int)*(n+1));  dijstra(ed,disd);
        memset(Head,-1,sizeof(int)*(n+1));
        for(i=0;i<num;i++) addedge(Edgeu[i],Edgev[i],Edgew[i]);
        memset(vis,0,sizeof(int)*(n+1));  dijstra(st,dist);
        for(i=1;i<=n;i++)
        {
            for(j=Head[i];j!=-1;j=Edge[j].next)
            {
                v=Edge[j].v;
                if(dist[i]+disd[v]+Edge[j].w==dist[ed])
                addEdge(i,v,1);
            }
        }
        if(dist[ed]>=INF)puts("0");
        else
        printf("%d\n",sap(st,ed));
    }
    return 0;
}
