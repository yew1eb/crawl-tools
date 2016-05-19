#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int map[505][505];
int link1[505];
int vis[505],t;
int dfs(int i)
{
    int j;
    for(j=0;j<t;j++)
    {
        if(map[i][j]&&!vis[j])
        {
            vis[j]=1;
            if(link1[j]==-1||dfs(link1[j]))
            {
                link1[j]=i;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{

    while(scanf("%d",&t)!=EOF)
    {
        int i;
        memset(map,0,sizeof(map));
        for(i=0;i<t;i++)
        {
            int n1,n2;
            scanf("%d: (%d)",&n1,&n2);
            int j;
            for(j=0;j<n2;j++)
            {
                int k;
                scanf("%d",&k);
                map[n1][k]=1;
            }
        }
        int s=0;
        memset(link1,-1,sizeof(link1));
        for(i=0;i<t;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))
                s++;
        }
        printf("%d\n",t-s/2);
    }
}