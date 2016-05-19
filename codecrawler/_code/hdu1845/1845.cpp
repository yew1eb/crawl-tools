#include <iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=5001;
vector<int> g[MAXN];
int uN,vN;  //u,v数目
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    int v;
    for(int i=0;i<g[u].size();i++)
        {v=g[u][i];
            if(!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
        }
    return false;
}
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=1;u<=uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u))  res++;
    }
    return res;
}
int main()
{
    int t,n,i,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<=n;i++)
        g[i].clear();
        for(i=0;i<n*3/2;i++)
        {
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        uN=n;
        printf("%d\n",hungary()/2);
    }
    return 0;
}