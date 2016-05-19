#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <deque>
#include <set>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <map>
typedef long long LL;
const int INF = 1<<29;
const LL mod = 530600414;
const int MAXN = 81000;//ç¹æ°çæå¤§å¼
const int MAXM = 604000;//è¾¹æ°çæå¤§å¼
int rmq[2*MAXN];//rmqæ°ç»ï¼å°±æ¯æ¬§æåºåå¯¹åºçæ·±åº¦åºå
struct ST
{
    int mm[2*MAXN];
    int dp[2*MAXN][20];//æå°å¼å¯¹åºçä¸æ 
    void init(int n)
    {
        mm[0] = -1;
        for(int i = 1;i <= n;i++)
        {
            mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
            dp[i][0] = i;
        }
        for(int j = 1; j <= mm[n];j++)
            for(int i = 1; i + (1<<j) - 1 <= n; i++)
                dp[i][j] = rmq[dp[i][j-1]] < rmq[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
    }
    int query(int a,int b)//æ¥è¯¢[a,b]ä¹é´æå°å¼çä¸æ 
    {
        if(a > b)swap(a,b);
        int k = mm[b-a+1];
        return rmq[dp[a][k]] <= rmq[dp[b-(1<<k)+1][k]]?dp[a][k]:dp[b-(1<<k)+1][k];
    }
};
//è¾¹çç»æä½å®ä¹
struct Edge{
    int from,to,next;
}edge[MAXM];

int edgenum,head[MAXN];
int F[MAXN*2];//æ¬§æåºåï¼å°±æ¯dfséåçé¡ºåºï¼é¿åº¦ä¸º2*n-1,ä¸æ ä»1å¼å§
int P[MAXN];//P[i]è¡¨ç¤ºç¹iå¨Fä¸­ç¬¬ä¸æ¬¡åºç°çä½ç½®
int cnt;
ST st;

void addedge(int u,int v)//å è¾¹ï¼æ åè¾¹éè¦å ä¸¤æ¬¡
{
    Edge E={u,v,head[u]};
    edge[edgenum] = E;
    head[u] = edgenum++;
}
int len[MAXN],fa[MAXN];
void dfs(int u,int pre,int dep)
{
    fa[u]=pre;
    F[++cnt] = u;
    rmq[cnt] = dep;
    P[u] = cnt;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        if(v == pre)continue;
        dfs(v,u,dep+1);
        F[++cnt] = u;
        rmq[cnt] = dep;
    }
}
void LCA_init(int root,int node_num)//æ¥è¯¢LCAåçåå§å
{
    cnt = 0;
    dfs(root,root,0);
    st.init(2*node_num-1);
}
int query_lca(int u,int v)//æ¥è¯¢u,vçlcaç¼å·
{
    return F[st.query(P[u],P[v])];
}
int dp[MAXN];
void init(){
    memset(head,-1,sizeof(head)), edgenum = 0;
    memset(dp,0,sizeof(dp));
}
int gao(int u,int fa)
{
    for(int i=head[u];~i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa) continue;
        gao(v,u);
        dp[u]+=dp[v];
    }
    return 0;
}
int main()
{
    int t,cas=1,n,m,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b);
            addedge(b,a);
        }
        LCA_init(1,n);
        for(int i=0;i<=m-n;i++)
        {
            scanf("%d%d",&a,&b);
            int x=query_lca(a,b);
            dp[a]++;
            dp[b]++;
            dp[x]-=2;
//            dp[fa[x]]--;
        }
        gao(1,1);
        int ans=INF;
        for(int i=2;i<=n;i++)
            ans=min(ans,dp[i]+1);
        printf("Case #%d: ",cas++);
        printf("%d\n",ans);
    }
    return 0;
}