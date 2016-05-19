#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Node
{
    int now,next,val;
}tree[20005];

int dp[10005][15];
int head[10005];
int n,s,k,len;

void add(int x,int y,int w)//å»ºæ 
{
    tree[len].now = y;
    tree[len].val = w;
    tree[len].next = head[x];
    head[x] = len++;
}

void dfs(int root,int p)
{
    int i,j,l,son;
    for(i = head[root];i!=-1;i = tree[i].next)
    {
        son = tree[i].now;
        if(son == p)
        continue;
        dfs(son,root);
        for(j = k;j>=0;j--)
        {
            dp[root][j]+=dp[son][0]+2*tree[i].val;//åå°dp[son][0]æ¾è¿èåï¼ç±äºdp[son][0]æ¯è¡¨ç¤ºç¨ä¸ä¸ªæºå¨äººå»èµ°å®ææå­æ ï¼æåååå°posè¿ä¸ªèç¹ï¼æä»¥è±è´¹è¦ä¹ä»¥2
            for(l = 1;l<=j;l++)//å¨è¿éæ¾å°æ¯dp[son][0]æ´ä¼çæ¹æ¡ï¼åç»èå
            dp[root][j] = min(dp[root][j],dp[root][j-l]+dp[son][l]+l*tree[i].val);
        }
    }
}

int main()
{
    int i,x,y,w;
    while(~scanf("%d%d%d",&n,&s,&k))
    {
        len = 0;
        memset(head,-1,sizeof(head));
        memset(dp,0,sizeof(dp));
        for(i = 1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            add(x,y,w);
            add(y,x,w);
        }
        dfs(s,-1);
        printf("%d\n",dp[s][k]);
    }

    return 0;
}
