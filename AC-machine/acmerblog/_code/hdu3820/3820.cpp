#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define maxn 6000
#define INF 100000
int A[55][55],B[55][55],Count[55][55];
struct Edge
{
	int from, to, cap, flow;
};

int n, m, s, t;
vector<Edge> edges;    // 边数的两倍
vector<int> G[maxn];   // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
bool vis[maxn];        // BFS使用
int d[maxn];           // 从起点到i的距离
int cur[maxn];         // 当前弧指针
int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}
void AddEdge(int from, int to, int cap)
{
	int len;
	Edge temp;
	temp.from=from;temp.to=to;temp.cap=cap;temp.flow=0;
	edges.push_back(temp);
	temp.from=to;temp.to=from;temp.cap=0;temp.flow=0;
    edges.push_back(temp);
    len = edges.size();
    G[from].push_back(len-2);
    G[to].push_back(len-1);
}
bool BFS()
{
	memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while(!Q.empty())
	{
		int x = Q.front(); Q.pop();
		for(int i = 0; i < G[x].size(); i++)
		{
			Edge& e = edges[G[x][i]];
			if(!vis[e.to] && e.cap > e.flow)
			{
				vis[e.to] = 1;
				d[e.to] = d[x] + 1;
				Q.push(e.to);
			}
		}
    }
    return vis[t];
}
int DFS(int x, int a)
{
	if(x == t || a == 0) return a;
    int flow = 0, f;
    for(int& i = cur[x]; i < G[x].size(); i++)
	{
		Edge& e = edges[G[x][i]];
		if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0)
		{
			e.flow += f;
			edges[G[x][i]^1].flow -= f;
			flow += f;
			a -= f;
			if(a == 0) break;
		}
    }
    return flow;
}
int Maxflow()
{
    int flow = 0;
    while(BFS())
	{
		memset(cur, 0, sizeof(cur));
		flow += DFS(s, INF);
    }
    return flow;
}
int main()
{
    int T;
    int gold,silver;
    int i,j;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        cas++;
        int tot=0;
        int now=0;
        scanf("%d%d%d%d",&n,&m,&gold,&silver);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%d",&A[i][j]);
                tot+=A[i][j];
                Count[i][j] = ++now;
            }
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%d",&B[i][j]);
                tot+=B[i][j];
            }
        s=0;t=2*n*m+1;
        for(i=0;i<=t;i++) G[i].clear();
        for(i=1;i<=n*m;i++) AddEdge(i,i+n*m,INF);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                if((i+j)%2==0)
                {
                    AddEdge(s,Count[i][j],A[i][j]);
                    AddEdge(n*m+Count[i][j],t,B[i][j]);
                    if(i-1>0) AddEdge(Count[i][j],n*m+Count[i-1][j],gold);
                    if(i+1<=n) AddEdge(Count[i][j],n*m+Count[i+1][j],gold);
                    if(j-1>0) AddEdge(Count[i][j],n*m+Count[i][j-1],gold);
                    if(j+1<=m) AddEdge(Count[i][j],n*m+Count[i][j+1],gold);
                }
                else
                {
                    AddEdge(s,Count[i][j],B[i][j]);
                    AddEdge(n*m+Count[i][j],t,A[i][j]);
                    if(i-1>0) AddEdge(Count[i][j],n*m+Count[i-1][j],silver);
                    if(i+1<=n) AddEdge(Count[i][j],n*m+Count[i+1][j],silver);
                    if(j-1>0) AddEdge(Count[i][j],n*m+Count[i][j-1],silver);
                    if(j+1<=m) AddEdge(Count[i][j],n*m+Count[i][j+1],silver);
                }
            }
        printf("Case %d: %d\n",cas,tot-Maxflow());
    }
    return 0;
}
