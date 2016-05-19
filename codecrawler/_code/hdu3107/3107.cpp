#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define cc(x,y) memset((x),(y),sizeof((x)))
#define rep(x,y) for(int (x) = 0;(x) < (y) ; (x) ++)
#define foreach for(Edge* p=adj[now];p;p=p->next)
using namespace std;
const int N = 50010;
const int inf = 10000000;
struct Edge
{
    int v;
    Edge* next;
} *adj[N],*pp,pool[2*N];
void init()
{
    cc(adj,0);
    pp = pool;
}
void addedge(int u,int v)
{
    pp->v =v;
    pp->next = adj[u];
    adj[u] = pp++;
}
int small;
int n;
bool flag[N];
int dp[N];
int ans1,ans2;
void dfs(int now)
{
    flag[now] = true;
    int s = 0;
    dp[now] = 1;
    foreach
    {
        if(!flag[p->v])
        {
            dfs(p->v);
            dp[now] += dp[p->v];
            s = max(s,dp[p->v]);
        }
    }
    s = max(s,n - dp[now]);
    if(s < small)
    {
        small = s;
        ans1 = now;
        ans2 = -1;
    }
    else if(s == small)
    {
        if(ans1 == -1)
            ans1 = now;
        else
            ans2 = now;
    }
}

int main()
{
    while(scanf("%d",&n) == 1)
    {
        small = inf;
        init();
        rep(i,n-1)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        ans1=  ans2= -1;
        cc(flag,0);
        cc(dp,0);
        dfs(1);
        if(ans2 == -1)
            printf("%d\n",ans1);
        else
            printf("%d %d\n",min(ans1,ans2),max(ans1,ans2));
    }
    return 0;
}