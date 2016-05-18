#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#define maxn 105
#define mod 10000
#define INF 0x3f3f3f3f
using namespace std;

int n,m,ans;
int sx,sy,sp;
bool vis[maxn][maxn];
int mp[maxn][maxn];
int dp[maxn][maxn];
int dx[]={1,0};
int dy[]={0,1};
struct Node
{
    int x,y,p;
    bool operator <(const Node&xx) const
    {
        if(x!=xx.x) return x>xx.x;
        return y>xx.y;
    }
}cur,now;
priority_queue<Node>q;

void solve()
{
    int i,j,cnt,r,d;
    while(!q.empty()) q.pop();
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    cur.x=cur.y=1;
    cur.p=mp[1][1];
    vis[1][1]=1;
    q.push(cur);
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        sx=now.x;
        sy=now.y;
        sp=now.p;
        cnt=sp;
        r=sx+sp;
        r=min(n,r);
        for(i=sx;i<=r;i++)
        {
            d=sy+cnt;
            d=min(d,m);
            for(j=sy;j<=d;j++)
            {
                if(i==sx&&j==sy) continue ;
                dp[i][j]+=dp[sx][sy];
                if(dp[i][j]>=mod) dp[i][j]%=mod;
                if(!vis[i][j])
                {
                    cur.x=i;
                    cur.y=j;
                    cur.p=mp[i][j];
                    vis[i][j]=1;
                    q.push(cur);
                }
            }
            cnt--;
        }
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&mp[i][j]);
            }
        }
        solve();
        printf("%d\n",dp[n][m]);
    }
    return 0;
}