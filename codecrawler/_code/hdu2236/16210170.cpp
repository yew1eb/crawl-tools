#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int map[maxn][maxn];
int link[maxn];
int vis[maxn];
int n,minv,maxv;
int maxl,minl,l,mid;

int dfs(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&map[u][i]>=l&&map[u][i]<=l+mid)
        {
            vis[i]=1;
            if(link[i]==-1||dfs(link[i]))
            {
                link[i]=u;
                return 1;
            }
        }
    }
    return 0;
}

int hungry()
{
    memset(link,-1,sizeof(link));
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(!dfs(i))
            return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        minv=105,maxv=0;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&map[i][j]);
                if(map[i][j]>maxv)maxv=map[i][j];
                if(map[i][j]<minv)minv=map[i][j];
            }
        maxl=maxv-minv;
        minl=0;
        int flag;
        while(1)
        {
            mid=(maxl+minl)>>1;
            flag=0;
            for(l=minv;l+mid<=maxv;l++)
                if(hungry())
                {
                    flag=1;
                    break;
                }
            if(flag)
                maxl=mid;
            if(minl==mid)
                break;
            if(!flag)
                minl=mid;
        }
        printf("%d\n",maxl);
    }
    return 0;
}
