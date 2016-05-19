#include <stdio.h>
#include <string.h>
#define M 1100
#define inf 1000000

int nx,ny;
int link[M],lx[M],ly[M],slack[M];
int visx[M],visy[M],w[M][M];

int DFS(int x)
{
    visx[x] = 1;
    for (int y = 1;y <= ny;y ++)
    {
        if (visy[y])
            continue;
        int t = lx[x] + ly[y] - w[x][y];
        if (t == 0)       //
        {
            visy[y] = 1;
            if (link[y] == -1||DFS(link[y]))
            {
                link[y] = x;
                return 1;
            }
        }
        else if (slack[y] > t)
            slack[y] = t;
    }
    return 0;
}
long long  KM()
{
    int i,j;
    memset (link,-1,sizeof(link));
    memset (ly,0,sizeof(ly));
    for (i = 1;i <= nx;i ++)
        for (j = 1,lx[i] = -inf;j <= ny;j ++)
            if (w[i][j] > lx[i])
                lx[i] = w[i][j];

    for (int x = 1;x <= nx;x ++)
    {
        for (i = 1;i <= ny;i ++)
            slack[i] = inf;
        while (1)
        {
            memset (visx,0,sizeof(visx));
            memset (visy,0,sizeof(visy));
            if (DFS(x))
                break;

            int d = inf;
            for (i = 1;i <= ny;i ++)
                if (!visy[i]&&d > slack[i])
                    d = slack[i];
            for (i = 1;i <= nx;i ++)
                if (visx[i])
                    lx[i] -= d;
            for (i = 1;i <= ny;i ++)
                if (visy[i])
                    ly[i] += d;
                else
                    slack[i] -= d;
        }
    }
    long long  res = 0;
    for (i = 1;i <= ny;i ++)
    {
        if (link[i] == -1|| w[link[i]][i]==-inf)
            return 0;
        else res += w[link[i]][i];;
    }
    return res;
}

int main()
{
    int cas;
    int n,m;
    scanf("%d",&cas);
    int tot=0;
    while(cas--)
    {
        tot++;
        int i,j,x,y,z;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                w[i][j]=-inf;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(-z>w[x][y])
                w[x][y]=w[y][x]=-z;
        }
        nx=ny=n;
        long long ans=KM();
        if(ans==0)
            printf("Case %d: NO\n",tot);
        else
            printf("Case %d: %lld\n",tot,-ans);
    }
}