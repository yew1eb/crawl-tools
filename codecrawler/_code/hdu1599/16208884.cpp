#include <iostream>

using namespace std;

const int N=110;

int dis[N][N],g[N][N];

const int MAX=0xfffffff;

int gmin(int x,int y)
{
    if (x>y) return y;
    else return x;
}

int main()
{
    int n,m,i,j,k;
    int Max=MAX/10;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int x,y,z,ans=Max;
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                g[i][j]=Max;
        while (m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            if (z<g[x][y]) g[x][y]=g[y][x]=z;
        }
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                dis[i][j]=g[i][j];
        for (k=1;k<=n;k++)
        {
            for (i=1;i<k;i++)
                for (j=i+1;j<k;j++)
                    ans=gmin(ans,dis[i][j]+g[k][i]+g[k][j]);
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++)
                    dis[i][j]=gmin(dis[i][j],dis[i][k]+dis[k][j]);
        }
        if (ans==Max) printf("It's impossible.\n");
        else printf("%d\n",ans);
    }
    return 0;
}

