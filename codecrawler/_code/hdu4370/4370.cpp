#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
const int maxx = 310;
int edge[maxx][maxx];
int dist[maxx];
int s[maxx];
const int INF = 33686018;
int n;
int dijkstra(int u0,int& cir)
{
    for(int i=1; i<=n; i++)
    {
        dist[i] = edge[u0][i];
        s[i] = 0;
    }
    dist[u0] = 0;
    s[u0] = 1;
    for(int i=2; i<=n; i++)
    {
        int minn = INF;
        int u = u0;
        for(int j=1; j<=n; j++)
        {
            if(!s[j] && dist[j]<minn)
            {
                minn = dist[j];
                u = j;
            }
        }
        s[u] = 1;
        for(int j=1; j<=n; j++)
        {
            if(!s[j] && edge[u][j]<INF && dist[u] + edge[u][j] < dist[j])
                dist[j] = dist[u] + edge[u][j];
            if(j==u0 && u!=u0)
                cir = min(cir,dist[u] + edge[u][j]);
        }
    }
    return dist[n];
}
int main()
{
//    freopen("1001.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanf("%d",&edge[i][j]);
        int cir_u0,cir_n,cir;
        cir_u0 = cir_n = cir = INF;
        int dis = dijkstra(1,cir_u0);
        dijkstra(n,cir_n);
        cir = cir_u0 + cir_n;
        printf("%d\n",min(dis,cir));
    }
}
