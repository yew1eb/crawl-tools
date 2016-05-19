#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define INF 0x3fffffff
const int N = 1010;

int n, C, R;
int first[N], dis[N];
struct edge
{
    int u, v, w, h, next;
}e[N*N];

void AddEdge(int u, int v, int w, int h)
{
    e[n].u = u;
    e[n].v = v;
    e[n].w = w;
    e[n].h = h;
    e[n].next = first[u];
    first[u] = n++;
}

void SPFA(int start, int limit)
{
    queue<int> q;
    bool inq[N];
    for(int i = 1; i <= C; i++)
        dis[i] = INF, inq[i] = false;
    dis[start] = 0;
    q.push(start);
    inq[start] = true;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        inq[x] = false;
        for(int i = first[x]; i != -1; i = e[i].next)
        {
            if(e[i].h < limit)
                continue;
            if(dis[x] + e[i].w < dis[e[i].v])
            {
                dis[e[i].v] = dis[x] + e[i].w;
                if(!inq[e[i].v])
                {
                    q.push(e[i].v);
                    inq[e[i].v] = true;
                }
            }
        }
    }
}

int main()
{
    int u, v, h, l, i, j, cas = 1;
    while(~scanf("%d%d",&C,&R) && (C + R))
    {
        if(cas > 1)
            printf("\n");
        n = 0;
        memset(first, -1, sizeof(first));
        for(i = 0; i < R; i++)
        {
            scanf("%d%d%d%d",&u, &v, &h, &l);
            if(h == -1)    h = INF;
            AddEdge(u, v, l, h);
            AddEdge(v, u, l, h);  //å¤´ææ³æ·»å ååè¾¹
        }
        int st, ed, limhet;
        scanf("%d%d%d",&st, &ed, &limhet);
        int l = 0, r = limhet, ans = INF, mid;
        while(l <= r)  //äºåæä¸¾é«åº¦ï¼ä½¿é«åº¦å°½éå¤§
        {
            mid = (l + r) / 2;
            SPFA(st, mid);
            if(dis[ed] != INF)
            {
                l = mid + 1;
                ans = dis[ed];
            }
            else
                r = mid - 1;
        }
        printf("Case %d:\n",cas++);
        if(ans != INF)
        {
            printf("maximum height = %d\n", r);
            printf("length of shortest route = %d\n",ans);
        }
        else
            printf("cannot reach destination\n");
    }
    return 0;
}