#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 1100;
const int MAXM = 10010;
int N,M,father[MAXN];

int find(int x)
{
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];
}
struct EdgeNode
{
    int from;
    int to;
    int w;
}Edges[MAXM];

int cmp(EdgeNode a, EdgeNode b)
{
    return a.w < b.w;
}
void Kruskal()
{
    int ans = 0;
    int Count = 0;
    for(int i = 0; i < M; ++i)
    {
        int u = find(Edges[i].from);
        int v = find(Edges[i].to);
        if(u != v)
        {
            ans += Edges[i].w;
            father[v] = u;
            Count++;
            if(Count == N-1)
                break;
        }
    }
    if(Count == N-1)
        printf("%d\n\n",ans);
    else
        printf("impossible\n\n");
}
int main()
{
    while(~scanf("%d%d",&N,&M))
    {
        memset(Edges,0,sizeof(Edges));
        for(int i = 0; i <= N; ++i)
            father[i] = i;
        for(int i = 0; i < M; ++i)
        {
            scanf("%d%d%d",&Edges[i].from,&Edges[i].to,&Edges[i].w);
        }
        sort(Edges,Edges+M,cmp);
        Kruskal();
    }

    return 0;
}
