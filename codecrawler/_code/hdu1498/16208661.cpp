#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<string>
#include<stack>
#include <map>
#include <set>
using namespace std;

const int maxn=500 + 10;
int n,m;
int g[maxn][maxn];
set<int>Set;
int vis[maxn],link[maxn];

bool path(int u,int x)
{
    for(int i = 0; i < n; i++)
        if(g[u][i] == x && !vis[i])    // è·ä»¥åçæå°ç¹è¦ççåæ³ä¸ä¸æ ·çå°æ¹ï¼å°ç­äº1æ¢æç­äºå½åé¢è²çæ°çã
        {
            vis[i] = 1;
            if(link[i] == -1 || path(link[i],x))
            {
                link[i] = u;
                return true;
            }
        }
    return false;
}
int dfs(int x)
{
    memset(link,-1,sizeof(link));
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        memset(vis,0,sizeof(vis));
        if(path(i,x))ans++;
    }
    return ans;
}
int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    while(~scanf("%d%d",&n,&m) && (n || m))
    {
        Set.clear();
        memset(g,0,sizeof(g));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j++)
            {
                scanf("%d",&g[i][j]);
                Set.insert(g[i][j]);
            }
        set<int>::iterator it;
        int falg = 1,findl = 1;
        for(it = Set.begin(); it != Set.end(); it++)
        {
            if(dfs(*it) > m)
            {
                findl = 0;
                if(falg)printf("%d",*it),falg = 0;
                else printf(" %d",*it);
            }
        }
        if(findl)printf("-1");
        printf("\n");
    }
    return 0;
}
