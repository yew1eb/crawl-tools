#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define Maxn 1005
#define Maxm 80005

int uE[Maxm];
int vE[Maxm];
int cap[Maxm];
int flow[Maxm];
int cost[Maxm];
int next[Maxm];

int first[Maxn];
int pre[Maxn];
int dist[Maxn];//最小花费
int inq[Maxn];
int a[Maxn];//残留网络

int e;
int n,m,c,p;

void init()
{
    memset(first,-1,sizeof(first));
    memset(next,-1,sizeof(next));
}
void addEdge(int x,int y,int a,int b)
{
    uE[e] = x,vE[e] = y,cap[e] = a,cost[e] = b;
    next[e] = first[x];
    first[x] = e;
    e++;
}
int BellmanFord_EdmondsKarp(int s,int t)
{
    int f = 0;
    memset(flow,0,sizeof(flow));
    queue<int> q;
    for(;;)
    {
        memset(inq,0,sizeof(inq));
        memset(a,0,sizeof(a));
        memset(dist,0x3f,sizeof(dist));
        q.push(s);
        inq[s] = 1,dist[s] = 0,a[s] = INF,pre[s] = -1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for(int i=first[u]; i!=-1; i=next[i])
            {
                int v = vE[i];
                if(flow[i]<cap[i] && dist[u] + cost[i]<dist[v])
                {
                    a[v] = a[u] < cap[i] - flow[i] ? a[u] : cap[i] - flow[i];
                    dist[v] = dist[u] + cost[i];
                    pre[v] = i;//注意此时pre[]的意义是某点的前向边
                    if(!inq[v])
                    {
                        inq[v] = 1,q.push(v);
                    }
                }
            }
        }
        if(dist[t] == INF || a[t] == 0) return f;
        //注意此处转换成long long ,防止数据超出范围,得出相反结论
        if((long long)a[t] * dist[t]<=(long long)c)
        {
            for(int i=pre[t];i!=-1;i=pre[uE[i]])
            {
                flow[i] += a[t];
                flow[i^1] -= a[t];
            }
            f += a[t];
            c -= a[t]*dist[t];
        }
        else
        {
            return f + c/dist[t];
        }
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T;

    int x,y,c1,c2;
    int s,t;
    scanf(" %d",&T);
    while(T--)
    {
        init();
        scanf(" %d %d %d %d",&n,&m,&c,&p);
        e = 0,s = n,t = 1;
        addEdge(s,0,INF,p),addEdge(0,s,0,-p);
        for(int i=0; i<m; i++)
        {
            scanf(" %d %d %d %d",&x,&y,&c1,&c2);
            addEdge(x,y,c1,0),addEdge(y,x,0,0),addEdge(x,y,INF,c2),addEdge(y,x,0,-c2);
            addEdge(y,x,c1,0),addEdge(x,y,0,0),addEdge(y,x,INF,c2),addEdge(x,y,0,-c2);
        }
        int ans = BellmanFord_EdmondsKarp(s,t);
        printf("%d\n",ans);
    }
    return 0;
}