#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 505;
const int inf = 0x3f3f3f3f;

int g[N][N],dis[N],v[N];
bool vis[N];
int n,m;
void build()
{
    int a,b,c;
    memset(g,0,sizeof(g));
    while(m --)
    {
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] += c;
        g[b][a] += c;
    }
}
void solve()
{
    int i,j,ans = inf;
    int maxx,maxi;
    int s,t;
    s = 0;
    for(i = 0;i < n;i ++)
        v[i] = i;
    while(n > 1)
    {
        int cur,pre;
        memset(dis,0,sizeof(dis));
        memset(vis,false,sizeof(vis));
        for(i = 1;i < n;i ++)
            dis[v[i]] = g[v[0]][v[i]];
        vis[v[0]] = true;
        for(i = 1;i < n;i ++)
        {
            maxx = -1;
            maxi = 0;
            for(j = 0;j < n;j ++)
                if(vis[v[j]] == false && dis[v[j]] > maxx)
                {
                    maxx = dis[v[j]];
                    maxi = j;
                }
            vis[v[maxi]] = true;
            if(i == n - 2)
                s = maxi;
            if(i == n - 1)
                t = maxi;
            for(j = 0;j < n;j ++)
                if(vis[v[j]] == false)
                    dis[v[j]] += g[v[maxi]][v[j]];
        }
        ans = min(ans,dis[v[t]]);
        for(i = 0;i < n;i ++)
        {
            g[v[s]][v[i]] += g[v[t]][v[i]];
            g[v[i]][v[s]] = g[v[s]][v[i]];
        }
        v[maxi] = v[--n];
    }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        build();
        solve();
    }
    return 0;
}
