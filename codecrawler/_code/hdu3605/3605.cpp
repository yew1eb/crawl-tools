#include"stdio.h"
#include"string.h"
#define N 100005
#define M 15
bool g[N][M],vis[M];          //存边的权值0、1，记录是否访问过
int lim[M],cnt[M],link[M][N];  
int n,m;
int find(int k)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        if(!vis[i]&&g[k][i])
        {
            vis[i]=1;
            if(cnt[i]<lim[i])
            {
                link[i][cnt[i]++]=k;
                return 1;
            }
            for(j=0;j<cnt[i];j++)
            {
                if(find(link[i][j]))
                {
                    link[i][j]=k;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&g[i][j]);
            }
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&lim[i]);
        }
        memset(link,0,sizeof(link));
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(!find(i))
                break;
        }
        if(i==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
