#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define LL long long
#define maxn 1005
#define INF 999999999
using namespace std;

int f[maxn][maxn];
int vis[maxn];
int flag[maxn];
int n,m;

bool DFS(int a)
{
    for(int i=1;i<=n;i++)
    {
        if(f[a][i] && !vis[i])
        {
            vis[i]=1;
            if(flag[i]==0 || DFS(flag[i]))
            {
                flag[i]=a;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(f,0,sizeof(f));
        for(int i=1;i<=m;i++)
        {
            int w;
            scanf("%d",&w);
            while(w--)
            {
                int p;
                scanf("%d",&p);
                f[i][p]=1;
            }
        }
        memset(flag,0,sizeof(flag));
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            memset(vis,0,sizeof(vis));
            if(DFS(i))
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}