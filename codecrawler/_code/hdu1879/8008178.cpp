#include <stdio.h>
#include <string.h>
const int Maxn = 101;
const int inf =0X3f3f3f3f;
int G[Maxn][Maxn];
int n;
int d[Maxn];
bool vis[Maxn];

int Prim(int n)
{
    int i, j, k, min,  sum = 0, s= 1;
    memset(vis,false,sizeof(vis));
    d[s] = 0; vis[s] = true;
    for(i=2; i<=n; i++) d[i] = G[s][i];
    for(i=1;i<n;i++)
    {
        min = inf;
        for(j=1;j<=n;j++)
            if(! vis[j] && min > d[j])
            {
                min = d[j];
                k = j;
            }
        sum += min;
        vis[k] = true;
        for(j=1; j<=n; j++)
            if(! vis[j] && d[j] > G[k][j])
             {
                 d[j] = G[k][j];
             }
    }
    return sum;
}
int main()
{
    int i, j, x, y, z;
    while(scanf("%d",&n)==1,n)
    {
        for(i=1; i<=n*(n-1)/2; i++)
        {
            scanf("%d%d%d%d", &x, &y, &z, &j);
            if(1 == j) z = 0;
            G[x][y] = G[y][x] = z;
        }
        printf("%d\n", Prim(n) );
    }
    return 0;
}
