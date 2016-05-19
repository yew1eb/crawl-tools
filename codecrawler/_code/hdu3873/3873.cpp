#include <cstdio>
#include <cstring>
const int MAXN = 3000 + 123;
const int MAXM = 70000 + 1234;
const int MAXMM = 3000 * 1510;
struct EDGE
{
    int v, next, val;
}edge[MAXM];
struct EDGE2
{
    int v, next;
}pro[MAXMM];
int head[MAXN];
int first[MAXN];
int rest[MAXN];
int d[MAXN];
int f[MAXN];
bool vis[MAXN];
int cnt;
int num;
int n, m;
void addedge(int u, int v, int val)
{
    edge[cnt].v = v;
    edge[cnt].val = val;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void addedge2(int u, int v)
{
    rest[v]++;
    pro[num].v = v;
    pro[num].next = first[u];
    first[u] = num++;
}
void init()
{
    cnt = 0;
    num = 0;
    memset(head, -1, sizeof(head));
    memset(first, -1, sizeof(first));
    memset(rest, 0, sizeof(rest));
    memset(vis, 0, sizeof(vis));
    memset(f, 0, sizeof(f));
    memset(d, 60, sizeof(d));
}
void dij()
{
    d[1] = 0;
    f[1] = 0;
    int minp = 1;
    for(int k= 1; k < n ; k++)
    {
        vis[minp] = 1;
        for(int p = first[minp]; p != -1; p = pro[p].next)
        {
            //printf("i=%d\n",i);
            rest[pro[p].v] --;
            if(d[minp] > f[pro[p].v])  f[pro[p].v] = d[minp];
        }

        for(int p = head[minp]; p != -1; p = edge[p].next)
        {
            int j = edge[p].v;
            if(edge[p].val + d[minp] < d[j])
            {
                d[j] = edge[p].val + d[minp];
                //d[j] = f[j] > d[j] ? f[j] : d[j];
            }
        }

        for(int j = 1; j <= n; j++)  //wa 了 n  次
        {
            d[j] = f[j] > d[j] ? f[j] : d[j];
        }

        //for(int i = 1; i <= n; i++)  printf("d[%d]= %I64d\n", i, d[i]);
        minp = 0;
        for(int j = 2; j <= n; j++)
        if(rest[j] == 0 && !vis[j])
        {
            if (d[j] < d[minp]) minp=j;
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        init();
        int a, b, c;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&a, &b, &c);
            addedge(a, b, c);
        }

        int x;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            for(int j = 1; j <= x; j++)
            {
                scanf("%d", &a);
                addedge2(a,i);
            }
        }
        dij();
        printf("%d\n", d[n]);
    }
    return 0;
}
