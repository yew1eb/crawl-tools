#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<cstdio>
using namespace std;
const int M=202;
const int MAXN=8802;
const int inf=1<<19;
int pre[MAXN];          // pre[v] = kï¼å¨å¢å¹¿è·¯ä¸ï¼å°è¾¾ç¹vçè¾¹çç¼å·ä¸ºk
int dis[MAXN];          // dis[u] = dï¼ä»èµ·ç¹så°ç¹uçè·¯å¾é¿ä¸ºd
int vis[MAXN];         // inq[u]ï¼ç¹uæ¯å¦å¨éåä¸­
int path[MAXN];
int head[MAXN];
int n,m,NE,sink,tot,ans,max_flow,in[M],out[M];
struct node
{
    int u,v,cap,cost,next;
} Edge[MAXN];
void addEdge(int u,int v,int cap,int cost)
{
    Edge[NE].u=u;
    Edge[NE].v=v;
    Edge[NE].cap=cap;
    Edge[NE].cost=cost;
    Edge[NE].next=head[u];
    head[u]=NE++;
    Edge[NE].v=u;
    Edge[NE].u=v;
    Edge[NE].cap=0;
    Edge[NE].cost=-cost;
    Edge[NE].next=head[v];
    head[v]=NE++;
}
int SPFA(int s,int t)                   //  æºç¹ä¸º0ï¼æ±ç¹ä¸ºsinkã
{
    int i;
    for(i=s;i<=t;i++) dis[i]=inf;
    memset(vis,0,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    dis[s] = 0;
    queue<int>q;
    q.push(s);
    vis[s] =1;
    while(!q.empty())        //  è¿éæå¥½ç¨éåï¼æå¹¿æçææï¼å æ åæ·±æã
    {
        int u =q.front();
        q.pop();
        for(i = head[u]; i != -1; i = Edge[i].next)
        {
            int v = Edge[i].v;
            if(Edge[i].cap >0&& dis[v] > dis[u] + Edge[i].cost)
            {
                dis[v] = dis[u] + Edge[i].cost;
                pre[v] = u;
                path[v]=i;
                if(!vis[v])
                {
                    vis[v] =1;
                    q.push(v);
                }
            }
        }
        vis[u] =0;
    }
    if(pre[t]==-1)
        return 0;
    return 1;
}
void end(int s,int t)
{
    int u, p,sum = inf;
    for(u=t; u!=s; u=pre[u])
    {
        sum = min(sum,Edge[path[u]].cap);
    }
    max_flow+=sum;
    for(u = t; u != s; u=pre[u])
    {
        Edge[path[u]].cap -= sum;
        Edge[path[u]^1].cap += sum;
        ans += sum*Edge[path[u]].cost;     //  costè®°å½çä¸ºåä½æµéè´¹ç¨ï¼å¿é¡»å¾ä¹ä»¥æµéã
    }
}
int main()
{
    int i,j,k,cas,s,t,u,v,a,b,tt=1;
    cin>>cas;
    while(cas--)
    {
        scanf("%d%d%d%d",&n,&m,&s,&t);
        NE=0,tot=0,ans=0;
        max_flow=0;
        int S=0,T=n+1,sum=0;
        memset(head,-1,sizeof(head));
        memset(in,0,sizeof(in));
        in[s]++,--in[t];
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&u,&v,&a,&b);
            if(a<=b)
            {
                in[u]--,in[v]++;
                addEdge(v,u,1,b-a);
                sum+=a;
            }
            else addEdge(u,v,1,a-b),sum+=b;
        }
        for(i=1;i<=n;i++)
        {
            if(in[i]>0) addEdge(S,i,in[i],0);
            if(in[i]<0) addEdge(i,T,-in[i],0),tot+=-in[i];
        }
        while(SPFA(S,T))
        {
            end(S,T);
        }
        if(max_flow==tot)
        printf("Case %d: %d\n",tt++,sum+ans);
        else printf("Case %d: impossible\n",tt++);
    }
    return 0;
}
