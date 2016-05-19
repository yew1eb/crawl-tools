#include <stdio.h>
#include <memory.h>

#define N 6005

struct node
{
    int v;
    node *next;
};
node *vertices[N],edges[N];
int rating[N];
int dp[N][2];
int ind[N];
int cnt;

void dfs(int u)
{
    if(!vertices[u])
    {
        dp[u][0]=0;
        dp[u][1]=rating[u];
        return;
    }
    int v;
    dp[u][1]+=rating[u];
    for(node *n=vertices[u];n;n=n->next)
    {
        v=n->v;
        dfs(v);
        dp[u][0]+=(dp[v][0]<dp[v][1])?dp[v][1]:dp[v][0];
        dp[u][1]+=dp[v][0];
    }
}
int main()
{
    int n,L,K,root;
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        memset(vertices,0,sizeof(vertices));
        memset(dp,0,sizeof(dp));
        memset(ind,0,sizeof(ind));
        for(int i=1;i<=n;i++)
            scanf("%d",&rating[i]);
        while(scanf("%d%d",&L,&K)&&(L||K))
        {
            edges[cnt].v=L;
            edges[cnt].next=vertices[K];
            vertices[K]=&edges[cnt++];
            ind[L]++;
        }
        for(root=1;root<=n;root++)
        {
            if(!ind[root])
            {
                dfs(root);
                break;
            }
        }
        printf("%d\n",(dp[root][0]>dp[root][1])?dp[root][0]:dp[root][1]);
    }
    return 0;
}