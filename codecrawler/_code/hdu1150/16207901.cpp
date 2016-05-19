#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int map[105][105];
int vis[105];
int link1[105],n,m,k;
bool can(int i)
{
    int j;
    for(j=0;j<m;j++)
    {
        if(!vis[j]&&map[i][j])
        {
            vis[j]=1;
            if(link1[j]==-1||can(link1[j]))
            {
                link1[j]=i;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d",&n),n!=0)
    {
        scanf("%d%d",&m,&k);
        int i;
        int z;
        memset(map,0,sizeof(map));
        for(i=0;i<k;i++)
        {
            int t1,t2;
            scanf("%d%d%d",&z,&t1,&t2);
            if(t1>0&&t2>0)
                map[t1][t2]=1;
        }
        int s=0;
        memset(link1,-1,sizeof(link1));
        for(i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(can(i))
                s++;
        }
        printf("%d\n",s);
    }
}