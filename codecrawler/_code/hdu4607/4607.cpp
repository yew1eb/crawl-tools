/***************************************************
题目大意：
N个点和N-1条边,保证整个图连通(因为边的限制,所以不可能形成环);
每条边长度都为1,问要到达k个点的最短路径(起点可以从k个顶点中任意一个出发);

算法分析：
首先如果k小于等于直径长度，那么答案为k−1;
如果k大于直径长度，设直径长度为r，那么答案为r−1+(k−r)*2;

树的直径：树上的最长简单路径;

可以随便选择一个点开始进行bfs或者dfs;
从而找到离该点最远的那个点;
可以证明,离树上任意一点最远的点一定是树的某条直径的两端点之一;
再从找到的点出发,找到据该点的最远点,那么这两点就确定了树的一条直径,两点间距即为所求距离;
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
    int h=0,t=0;//队列头尾
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
