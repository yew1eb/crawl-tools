#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
#define CLR(x,k) memset(x,k,sizeof(x))
#define min3(x,y,z) min(min(x,y),z)
#define min4(a,b,c,d) min(min(a,b),min(c,d))
const int MAXN = 10005;
struct Edge{int v;Edge*next;}edges[MAXN<<1],*cur,*head[MAXN];
inline void add(int u,int v){cur->v=v;cur->next=head[u];head[u]=cur++;}

int DP[MAXN][2][2],val[MAXN],vis[MAXN];
void tree_dp(int u)
{
    vis[u]=1;
    int col=val[u],rec=1-col,dp[3]={},sum=0;
    dp[1]=dp[2]=INF;
    for(Edge*p=head[u];p;p=p->next){
        int v=p->v;
        if(vis[v])continue;
        tree_dp(v);
        sum+=DP[v][col][0];
        dp[2]=min(dp[1]+DP[v][rec][1],dp[2]+DP[v][rec][0]);
        dp[1]=min(dp[0]+DP[v][rec][1],dp[1]+DP[v][rec][0]);
        dp[0]+=DP[v][rec][0];
    }
    DP[u][col][0]=min4(sum,dp[0]+2,dp[1]+2,dp[2]+2);
    DP[u][col][1]=min (dp[0]+1,dp[1]+1);
    DP[u][rec][0]=min4(sum+1,dp[0]+1,dp[1]+1,dp[2]+1);
    DP[u][rec][1]=min (dp[0],dp[1]);
//    printf("----%d------\n",u);
//    printf("%d\n",DP[u][0][0]);
//    printf("%d\n",DP[u][0][1]);
//    printf("%d\n",DP[u][1][0]);
//    printf("%d\n",DP[u][1][1]);
//    printf("%d %d %d\n",dp[0],dp[1],dp[2]);
}

void init()
{
    CLR(head,0);
    cur=edges;
    CLR(vis,0);
}
int main()
{
    ///freopen("test.txt","r",stdin);
    int N,cas=0;
    while(~scanf("%d",&N))
    {
        init();
        for(int i=1,a,b;i<N;++i){
            scanf("%d%d",&a,&b);
            add(a,b);add(b,a);
        }
        for(int i=1;i<=N;++i)
            scanf("%d",val+i);
        tree_dp(1);
        printf("Case %d: %d\n",++cas,min(DP[1][0][0],DP[1][1][0]));
    }
    return 0;
}