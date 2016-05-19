#include<cstdio>
#include<cstring>
typedef long long LL;
const int NS=19;

int n,m;
int g[NS][NS],b[NS+1];
LL dp[1<<NS][NS];
int bit[1<<NS][NS];

void prepare()
{
    b[0]=1;
    for (int i=1;i<=NS;i++)
    b[i]=b[i-1]*2;

    int t,lim=1<<NS;
    for (int i=0;i<lim;i++)
    {
        t=0;
        for (int j=0;j<NS;j++)
        if (i&b[j]) bit[i][++t]=j;
        bit[i][0]=t;
    }
}

int main()
{
    prepare();
    int x,y;
    while (~scanf("%d%d",&n,&m))
    {
        for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        g[i][j]=0;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            --x,--y;
            g[x][y]++,g[y][x]++;
        }

        int t,lim=1<<n;
        for (int i=0;i<lim;i++)
        for (int j=0;j<n;j++)
        dp[i][j]=0;
        for (int i=0;i<n;i++)
        dp[b[i]][i]=g[0][i];

        for (int i=1;i<lim;i++)
        for (int j=1;j<=bit[i][0]&&bit[i][j]<n;j++)
        {
            x=bit[i][j],y=i-b[x];
            for (int k=1;k<=bit[y][0]&&bit[y][k]<n;k++)
            {
                t=bit[y][k];
                if (g[t][x]==0) continue;
                dp[i][x]+=dp[y][t]*g[t][x];
            }
        }
        printf("%I64d\n",dp[lim-1][0]);
    }
    return 0;
}