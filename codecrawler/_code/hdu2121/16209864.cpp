#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;
const int MAXN = 1100;
const int MAXM = 11010;

struct Node
{
    int from;
    int to;
    int w;
}Edges[MAXM];

int pre[MAXN],vis[MAXN],flag[MAXN],In[MAXN],sum,pos;

int ZhuLiu(int root,int N,int M)
{
    sum = 0;
    while(true)
    {
        for(int i = 0; i < N; ++i)
            In[i] = INT_MAX;
        for(int i = 0; i < M; ++i)
        {
            int u = Edges[i].from;
            int v = Edges[i].to;
            if(Edges[i].w < In[v] && u != v)
            {
                pre[v] = u;
                In[v] = Edges[i].w;
                if(u == root)
                    pos = i;
            }
        }

        for(int i = 0; i < N; ++i)
        {
            if(i == root)
                continue;
            if(In[i] == INT_MAX)
                return -1;
        }
        int CntNode = 0;
        memset(flag,-1,sizeof(flag));
        memset(vis,-1,sizeof(vis));
        In[root] = 0;
        for(int i = 0; i < N; ++i)
        {
            sum += In[i];
            int v = i;
            while(vis[v] != i && flag[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }

            if(v != root && flag[v] == -1)
            {
                for(int u = pre[v]; u != v; u = pre[u])
                    flag[u] = CntNode;
                flag[v] = CntNode++;
            }
        }
        if(CntNode == 0)
            break;
        for(int i = 0; i < N; ++i)
        {
            if(flag[i] == -1)
                flag[i] = CntNode++;
        }
        for(int i = 0; i < M; ++i)
        {
            int v = Edges[i].to;
            Edges[i].from = flag[Edges[i].from];
            Edges[i].to = flag[Edges[i].to];
            if(Edges[i].from != Edges[i].to)
                Edges[i].w -= In[v];
        }
        N = CntNode;
        root = flag[root];
    }
    return sum;
}
int main()
{
    int N,M;
    while(~scanf("%d%d",&N,&M))
    {
        int Sum = 0;
        for(int i = 0; i < M; ++i)
        {
            scanf("%d%d%d",&Edges[i].from,&Edges[i].to,&Edges[i].w);
            Sum += Edges[i].w;
        }
        Sum++;
        for(int i = 0; i < N; ++i)
        {
            Edges[M+i].from = N;
            Edges[M+i].to = i;
            Edges[M+i].w = Sum;
        }
        int ans = ZhuLiu(N,N+1,M+N);
        if(ans >= 2*Sum)
            printf("impossible\n\n");
        else
            printf("%d %d\n\n",ans - Sum, pos - M);
    }

    return 0;
}
