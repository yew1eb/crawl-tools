/*ACä»£ç ï¼15ms*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <cstring>
#define INF 1e8
#define MAXN 10005
using namespace std;
struct edge
{
    int u,v,w,next;
}E[200000];
int head[MAXN],ecnt;
int dis[MAXN],D[MAXN],cnt[MAXN];
bool vis[MAXN];
int N,cas;
//d[v]>=d[u]+w(u,v);
void Insert(int u,int v,int w)
{
    E[ecnt].u=u;
    E[ecnt].v=v;
    E[ecnt].w=w;
    E[ecnt].next=head[u];
    head[u]=ecnt++;
}
void Init()
{
    int i,u,v,w;
    char s[20];
    memset(head,-1,sizeof(head));ecnt=0;
    for(i=1;i<=N;i++)
        scanf("%d",&D[i]);
    while(scanf("%s",s)!=EOF)//å»ºå¾
    {
        if(s[0]=='#') break;
        scanf("%d%d",&u,&v);
        if(strcmp(s,"SAS")==0)
            Insert(v,u,0);
        else if(strcmp(s,"SAF")==0)
            Insert(v,u,D[v]);
        else if(strcmp(s,"FAF")==0)
            Insert(v,u,D[v]-D[u]);
        else
            Insert(v,u,-D[u]);
    }
    for(i=1;i<=N;i++)//ä¿è¯æ¯ä¸ªç¹é½è¢«æ©å±å°
        Insert(0,i,0);
}
queue<int>Q;
bool SPFA()
{
    int i,u,v,w;
    while(!Q.empty()) Q.pop();
    memset(vis,false,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<=N;i++)
        dis[i]=-INF;
    Q.push(0);
    dis[0]=0;
    vis[0]=true;
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        vis[u]=false;
        cnt[u]++;
        if(cnt[u]>N) return false;
        for(i=head[u];i!=-1;i=E[i].next)
        {
            v=E[i].v;w=E[i].w;
            if(dis[v]<dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    Q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    return true;
}
void Solve()
{
    int i;
    printf("Case %d:\n",cas++);
    if(!SPFA())
        printf("impossible\n");
    else
    {
        for(i=1;i<=N;i++)
            printf("%d %d\n",i,dis[i]);
    }
    printf("\n");
}
int main()
{
    cas=1;
    while(scanf("%d",&N),N)
    {
        Init();
        Solve();
    }
return 0;
}
/*
2
1
2
SAF 1 2
#


1 2
2 0


*/