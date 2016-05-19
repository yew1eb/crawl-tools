#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[1505][2];
int vis[1505],head[1505];
int len,root;

struct node
{
    int now,next;
} tree[3005];//å ä¸ºè¦ååå»ºï¼æä»¥è¦å¼2åå¤§å°

void add(int x,int y)//å»ºæ 
{
    tree[len].now = y;
    tree[len].next = head[x];
    head[x] = len++;

    tree[len].now = x;
    tree[len].next = head[y];
    head[y] = len++;
}

void dfs(int root)
{
    int i,k;
    vis[root] = 1;
    dp[root][1] = 1;
    dp[root][0] = 0;
    for(i = head[root]; i!=-1; i = tree[i].next)
    {
        k = tree[i].now;
        if(!vis[k])
        {
            dfs(k);
            dp[root][0] += dp[k][1];
            dp[root][1] += min(dp[k][1],dp[k][0]);
        }
    }
}

int main()
{
    int t,x,y,n,i,j;
    while(~scanf("%d",&t))
    {
        len = 0;
        root = -1;
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        for(j = 1; j<=t; j++)
        {
            scanf("%d:(%d)",&x,&n);
            if(root==-1)
                root = x;
            for(i = 0; i<n; i++)
            {
                scanf("%d",&y);
                add(x,y);
            }
        }
        dfs(root);
        printf("%d\n",min(dp[root][0],dp[root][1]));
    }

    return 0;
}
