#include <queue>
#include <cstdio>
#include <cstring>
#define N 1005
#define INF 0x7f7f7f7f
using namespace std;
int map[N][N];
int start[N];
int end[N];
int d[N];
int used[N];
int MAX;
int T,S,D;

int SPEA()
{
    int i, u, min;
    for(i=0; i<=MAX; i++) d[i] = INF;
    queue<int> q;
    for(i=0; i<S; i++)
    {
        d[start[i]] = 0;
        q.push(start[i]);
        used[start[i] ] =1;
    }
    while(!q.empty())
    {
        u = q.front(); q.pop();
        used[u] = 0;
        for(i=0; i<=MAX; i++)
        {
            if(d[i] > d[u] + map[u][i])
            {
                d[i] = d[u] + map[u][i];
                if(!used[i])
                {
                    q.push(i);
                    used[i] = 1;
                }
            }
        }
    }
    min = INF;
    for(i=0; i<D; i++)
    if(min>d[end[i]]) min = d[end[i]];
    return min;
}
int main()
{
    int i, j, a, b, len;
    while(~scanf("%d%d%d",&T,&S,&D))
    {
        memset(map,INF,sizeof(map));
        MAX = 0;
        for(i=0; i<T; i++)
        {
            scanf("%d%d%d",&a,&b,&len);
            if(len<map[a][b])
            {
                map[a][b] = map[b][a] = len;
            }
            if(MAX<a) MAX = a;
            if(MAX<b) MAX = b;
        }
        for(i=0; i<S; i++)
        {
            scanf("%d",&start[i]);
        }
        for(i=0; i<D; i++)
        {
            scanf("%d",&end[i]);
        }
        printf("%d\n", SPEA());
    }
    return 0;
}














