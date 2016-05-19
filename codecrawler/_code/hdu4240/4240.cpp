/**
[最大流] hdu 4240 Route Redundancy
题意：除了要求出最大流之外，还要求另一个最小车辆的最大值M，
最小车辆的定义是 在一条可行流的路径上最小的边权(初始边权)

技巧在与求增广路径的方法，主要是第一次找的方法，因为M == 第一次可行的具有最大压入流量的增广路径的压入的流量
lowc[i]表示以i为终点的包含M的压入量，注意更新的方式，类似prim或是dijkstra算法
*/
#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

typedef pair<int,int >  Pii;
#define MK make_pair
const int N = 101,INF = 100000000;
int g[N][N],pre[N],n;

int path(int s,int t)
{
    int lowc[N],vis[N],i,u,v,dd = INF;
    priority_queue < Pii > que;
    Pii p;
    memset(vis,0,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    for(i = 0; i < n; ++i)
        lowc[i] = INF;
    que.push(MK(INF,s));
    while(!que.empty())
    {
        u = que.top().second;
        dd = que.top().first;
        que.pop();
        if(u == t)
            return lowc[t];
        if(vis[u])
            continue;
        vis[u] = 1;
        for(i = 0; i < n; ++i)
        if(!vis[i] && g[u][i] > 0)
        {

            if(lowc[i] == INF)
                lowc[i] = min(lowc[u],g[u][i]);
            else
            {
                if(g[u][i] < lowc[u])
                    lowc[i] = max(lowc[i],g[u][i]);
                else
                    lowc[i] = lowc[u];
            }
            pre[i] = u;
            que.push(MK(lowc[i],i));
        }
    }
    return 0;
}
void maxFlow(int s,int t)
{
    int first = 1,res = 0,minc = INF,i,d;
    while(1)
    {

        d = path(s,t);
        if(!d)
            break;
        if(first)
        {
            minc = d;
            first = 0;
        }
        res += d;
        for(i = t; i != s; i = pre[i])
        {
            g[pre[i]][i] -= d;
            g[i][pre[i]] += d;
        }
    }
    printf("%.3lf\n",res * 1.0 / minc);
}
int main()
{
    int cas,a,b,i,j,cp,tt,e;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d%d%d%d",&cas,&n,&e,&a,&b);
        memset(g,0,sizeof(g));
        while(e--)
        {
            scanf("%d%d%d",&i,&j,&cp);
            g[i][j] += cp;
        }
        printf("%d ",cas);
        maxFlow(a,b);
    }
    return 0;
}
