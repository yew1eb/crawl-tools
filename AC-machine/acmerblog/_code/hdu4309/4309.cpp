#include <cstdio>
#include <cstring>
const int MAXN = 205;
const int MAXM = 2505;
const int INF = 1000000000;

struct Edge
{
    int u, v, next, flow;
}edge[MAXM], redge[MAXM];
int edgeNumber, head[MAXN], rhead[MAXN];
int source = MAXN - 1;
int destination = MAXN - 2;
int depth[MAXN];

inline int min(int x, int y)
{
    return x < y ? x : y;
}

void addEdgeSub(int u, int v, int flow)
{
    edge[edgeNumber].u = u;
    edge[edgeNumber].v = v;
    edge[edgeNumber].flow = flow;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

void addEdge(int u, int v, int flow)
{
    addEdgeSub(u, v, flow);
    addEdgeSub(v, u, 0);
}

int n, m;
int bridgePosition[MAXN];
int bridgeCost[MAXN];
int bridgeNumber;

bool bfs(int start, int end)
{
    int front = 0, rear = 0;
    int queue[MAXN];
    memset(depth, -1, sizeof(depth));
    queue[front++] = start;
    depth[start] = 0;
    while(rear < front)
    {
        int k = queue[rear++];
        for(int i=head[k];i!=-1;i=edge[i].next)
        {
            int to = edge[i].v;
            if(-1 == depth[to] && edge[i].flow > 0)
            {
                depth[to] = depth[k] + 1;
                queue[front++] = to;
            }
        }
    }
    return -1 != depth[end];
}

int dinic(int start, int end, int sum)
{
    if(start == end)
    {
        return sum;
    }
    int temp = sum;
    for(int i=head[start];i!=-1 && sum;i=edge[i].next)
    {
        if(edge[i].flow > 0 && depth[edge[i].v] == depth[start] + 1)
        {
            int a = dinic(edge[i].v, end, min(sum, edge[i].flow));
            edge[i].flow -= a;
            edge[i^1].flow += a;
            sum -= a;
        }
    }
    return temp - sum;
}

int maxFlow(int start, int end)
{
    int result = 0;
    while(bfs(start, end))
    {
        result += dinic(start, end, INF);
    }
    return result;
}

int main()
{
    int u, v, w, p;
    while(~scanf("%d%d", &n, &m))
    {
        int pointNumber = n + 1;
        edgeNumber = 0;
        bridgeNumber = 0;
        memset(head, -1, sizeof(head));
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &w);
            addEdge(source, i, w);
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d%d",&u,&v,&w,&p);
            if(p < 0)
            {
                addEdge(u, pointNumber, INF);
                addEdge(pointNumber, v, INF);
                addEdge(pointNumber, destination, w);
                ++ pointNumber;
            }
            else if(p == 0)
            {
                addEdge(u, v, INF);
            }
            else
            {
                bridgePosition[bridgeNumber] = edgeNumber;
                bridgeCost[bridgeNumber] = w;
                addEdge(u, v, 1);
                ++ bridgeNumber;
            }
        }
        memcpy(redge, edge, sizeof(redge));
        memcpy(rhead, head, sizeof(rhead));
        int minCost = INF, maxPeople = - INF;
        for(int i=0;i<(1<<bridgeNumber);++i)
        {
            memcpy(edge, redge, sizeof(edge));
            memcpy(head, rhead, sizeof(head));
            int cost = 0;
            for(int j=0;j<bridgeNumber;++j)
            {
                if(i&(1 << j))
                {
                    cost += bridgeCost[j];
                    edge[bridgePosition[j]].flow = INF;
                }
            }
            int people = maxFlow(source, destination);
            if(people > maxPeople)
            {
                maxPeople = people;
                minCost = cost;
            }
            else if(people == maxPeople)
            {
                minCost = min(minCost, cost);
            }
        }
        if(maxPeople > 0)
        {
            printf("%d %d\n", maxPeople, minCost);
        }
        else
        {
            printf("Poor Heaven Empire\n");
        }
    }
    return 0;
}
