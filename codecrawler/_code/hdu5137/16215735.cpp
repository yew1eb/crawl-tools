/**
é¢æï¼ä»2~n-1è¿å ä¸ªç¹ä¸­ä»»æå»æä¸ä¸ªç¹ï¼ä½¿å¾ä»1å°nçæç­è·¯å¾æå¤§ï¼å¦æä»»æå»æä¸ä¸ªç¹1~næ éè·¯è¾åºInfã
æè·¯ï¼æä¸¾å»æ2~n-1ä¸ªç¹ï¼ä¾æ¬¡ç¨spfaç®æ³æ±åæç­è·¯ï¼å»æå¤§å³å¯
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int maxm=711;
const int maxn=111;

struct EdgeNode
{
    int to;
    int w;
    int next;
};

EdgeNode edges[maxm];
int n,m;
int head[maxn],edge;
bool vis[maxn];
queue <int> que;
int dis[maxn];

void addedge(int u,int v,int c)
{
    edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
}

void init()
{
    memset(head,-1,sizeof(head));
    edge=0;
}

void spfa(int s,int n)//åæºæç­è·¯(sä¸ºèµ·ç¹ï¼nä¸ºèç¹æ»æ°)
{
    int u;
    for (int i=0; i<=n; i++)
        dis[i]=INF;
    memset(vis,0,sizeof(vis));
    while (!que.empty()) que.pop();
    que.push(s);
    vis[s]=true;
    dis[s]=0;
    while (!que.empty())
    {
        u=que.front();
        que.pop();
        vis[u]=false;
        for (int i=head[u]; i!=-1; i=edges[i].next)
        {
            int v=edges[i].to;
            int w=edges[i].w;
            if (dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if (!vis[v])
                {
                    vis[v]=true;
                    que.push(v);
                }
            }
        }
    }
}
int a[35][35];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        if(n==0&&m==0)
            break;
        for(int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y]=a[y][x]=z;
        }
        int maxx=-1;
        for(int k=2;k<n;k++)
        {
             init();
             for(int i=1;i<=n;i++)
             {
                 for(int j=1;j<=n;j++)
                 {
                     if(a[i][j]==0)
                        continue;
                     if(i==k||j==k)
                        continue;
                     addedge(i,j,a[i][j]);
                   //  printf("%d->%d:%d\n",i,j,a[i][j]);
                 }
             }
             spfa(1,n);
           //  printf("\n%d->%d\n\n",k,dis[n]);
             maxx=max(maxx,dis[n]);
        }
        if(maxx>=INF)
            printf("Inf\n");
        else
            printf("%d\n",maxx);
    }
    return 0;
}