#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
#define BUG printf("here!\n")
using namespace std;
const int MAXN=505;
int map[MAXN][MAXN];
int linkx[MAXN],linky[MAXN];
int vis[MAXN];
bool dfs(int u,int n)
{
    int v;
    for(v=1;v<=n;v++)
    {
        if(!vis[v]&&map[u][v])
        {
            vis[v]=1;
            if(linky[v]==-1||dfs(linky[v],n))
            {
                linkx[u]=v;
                linky[v]=u;
                return true;
            }
        }
    }
    return false;
}
int match(int n,int m)
{
    int sum=0;
    memset(linky,-1,sizeof(linky));
    memset(linkx,-1,sizeof(linkx));
    int i;
    for(i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i,m))
            sum++;
    }
    return sum;
}
int like[505],dislike[505];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int c,d,m;
        scanf("%d%d%d",&c,&d,&m);
        int i;
        getchar();
        char a1,a2;
        int b1,b2;
        for(i=1;i<=m;i++)
        {
            scanf("%c%d %c%d",&a1,&b1,&a2,&b2);
            getchar();
            if(a1=='D')
                like[i]=1*1000+b1;
            else
                like[i]=2*1000+b1;

            if(a2=='D')
                dislike[i]=1*1000+b2;
            else
                dislike[i]=2*1000+b2;
        }
        memset(map,0,sizeof(map));
        int j;
        for(i=1;i<=m;i++)
        {
            for(j=i+1;j<=m;j++)
            {
                if(like[i]==dislike[j])
                    map[i][j]=map[j][i]=1;
                if(dislike[i]==like[j])
                    map[i][j]=map[j][i]=1;
            }
        }
        int res=match(m,m);
        printf("%d\n",m-res/2);
    }

    return 0;
}