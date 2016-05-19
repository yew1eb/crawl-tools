/*
é¢æï¼
     ä¸æ£µæ ï¼ç¼å·1-nï¼ï¼1æ¯æäººåºå£ï¼åªæä¸ä¸ªæäººï¼ã
å¶å­èç¹æ¯æåãå¨èç¹å¤è£å¤§ç®ãæ¯ä¸ªèç¹æ k ç§å¤§ç®éæ©ï¼
å¯æ¯æ¯ä¸ªèç¹æå¤è£ä¸ä¸ªå¤§ç®ãæ¯ä¸ªå¤§ç®æä¸ä¸ªè±è´¹åä¸ä¸ªå¨åå¼ã
ä½ ä¸å±æmé±ï¼æä¹è½ä½¿å¨åå¼æå¤§ãæäººå»æ»å»åªä¸ªæåæ¯ä»»æçï¼
æä»¥æå¤§å¨åæ¯æ¯æ¡è·¯å¼åçæå°å¼ãå¤§ç®æ¾å¨å¶å­èç¹ä¹æ¯ç®¡ç¨çã
æè·¯ï¼
     æ¯ä¸ªèç¹æè½å¾å°çpoweråºè¯¥å»å¿å­èç¹çæå°å¼ï¼
ç¶åå ä¸æ¬èç¹å»ºå¡æå¾çpowerãå ä¸ºä½ è¦ä¿è¯ä¸å®è½å®å¾ä½ã
æä»¥å¾èèæåæåµï¼ç¶åå°½éæä¼å®æï¼ä½¿è¿ä¸ªæåæåµå°½éçå¥½ã
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1002;
const int maxm=202;
const int inf=1<<29;
int n,m,t,num,dp[maxn][maxm],hp[maxn][maxm];
vector<int>p[maxn];
void init()
{
    int i,j;
    for(i=0; i<=n; i++)
    {
        p[i].clear();
         for(j=0; j<=m; j++)
         {
          hp[i][j]=0;
          dp[i][j]=inf;
         }
    }
}
void dfs(int u,int fa)
{
    int i,j,k,v,cnt=p[u].size();
    if(u!=1&&cnt==1)///å¶å­èç¹
    {
        for(i=m; i>=0; i--)
        {
            dp[u][i]=hp[u][i];
        }
        return;
    }
    for(i=0; i<cnt; i++)
    {
        v=p[u][i];
        if(v==fa)continue;
        dfs(v,u);
        for(j=m; j>=0; j--)
        {
            int mmin=0;
            for(k=0; k<=j; k++)///æ¾å°å­©å­èç¹çæå°å¼ä¸­çæå¤§å¼
            {
                mmin=max(mmin,min(dp[u][j-k],dp[v][k]));
            }
            dp[u][j]=mmin;///æ²¡æéæ©æ ¹èç¹
        }
    }
    for(j=m; j>=0; j--)///æ ¹èç¹éæ©äºä¸ç»æ°æ®
    {
        for(k=0; k<=j; k++)
        {
            dp[u][j]=max(dp[u][j],dp[u][j-k]+hp[u][k]);
        }
    }
}
int main()
{
    scanf("%d",&t);
    int i,j,u,v,cost,power;
    while(t--)
    {
        scanf("%d",&n);
        init();
        for(i=1; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            p[u].push_back(v);
            p[v].push_back(u);
        }
        scanf("%d",&m);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&num);
            for(j=1; j<=num; j++)
            {
                scanf("%d%d",&cost,&power);
                hp[i][cost]=max(hp[i][cost],power);
            }
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                hp[i][j]=max(hp[i][j],hp[i][j-1]);
            }
        }
        dfs(1,0);
        printf("%d\n",dp[1][m]);
    }
    return 0;
}
/*
4
2
1 2
30
3 10 20 20 40 30 50
3 10 30 20 40 30 45
4
2 1
3 1
1 4
60
3 10 20 20 40 30 50
3 10 30 20 40 30 45
3 10 30 20 40 30 35
3 10 30 20 40 30 35

*/
