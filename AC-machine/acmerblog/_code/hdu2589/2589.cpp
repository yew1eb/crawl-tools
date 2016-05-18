#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int map[21][21];
int a[21][21];
bool used[21][21];
int n,m;
bool dfs()
{
    int i,j;
    int x,y,r;
    int flag=0;
    for(i=1;i<=n;i++)
    {
        if(flag) break;
        for(j=1;j<=n;j++)
            if(!used[i][j])
            {
                x=i;y=j;
                flag=1;
                break;
            }
    }
    int x1,y1;
    for(r=0;;r++)
    {
        x1=x+r;y1=y+r;
        if(x1>n||y1>n) break;
        if(a[x1][y1]-a[x1][y-1]-a[x-1][y1]+a[x-1][y-1]>1) break;
        if(a[x1][y1]-a[x1][y-1]-a[x-1][y1]+a[x-1][y-1]==1)
        {
            for(i=x;i<=x1;i++)
                for(j=y;j<=y1;j++)
                    used[i][j]=1;
            if(dfs()) return 1;
            for(i=x;i<=x1;i++)
                for(j=y;j<=y1;j++)
                    used[i][j]=0;
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(!used[i][j])
                return 0;
    return 1;
}
int main()
{
    int cas,x,y;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(map,0,sizeof(map));
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=1;
        }
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+map[i][j];
        memset(used,0,sizeof(used));
        int c=dfs();
        if(c==1) printf("YES\n");
        if(c==0) printf("NO\n");
    }
    return 0;
}