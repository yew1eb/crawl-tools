#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>

const int N=1005;

int pre[N];       //ä¿å­å¢å¹¿è·¯å¾ä¸çç¹çåé©±é¡¶ç¹
bool vis[N];
int map[N][N];    //æ®çç½ç»å®¹é

int s,t;          //sä¸ºæºç¹ï¼tä¸ºæ±ç¹
int n,m;

bool BFS()        //æ¾å¢å¹¿è·¯
{
    int i,cur;
    std::queue<int>Q;
    memset(pre,0,sizeof(pre));
    memset(vis,0,sizeof(vis));
    vis[s]=true;    Q.push(s);
    while(!Q.empty())
    {
        cur=Q.front();
        Q.pop();

        if(cur==t) return true;       //å¦æå·²è¾¾å°æ±ç¹tï¼è¡¨æå·²ç»æ¾å°ä¸æ¡å¢å¹¿è·¯å¾ï¼è¿åtrue.
        for(i=1;i<=n;i++)
        {
            if(!vis[i]&&map[cur][i])  //åªææ®çå®¹éå¤§äº0æ¶æå­å¨è¾¹
            {
                Q.push(i);
                pre[i]=cur;
                vis[i]=true;
            }
        }
    }
    return false;
}

int Max_Flow()
{
    int i,ans=0;
    while(true)
    {
        if(!BFS()) return ans;     //å¦ææ¾ä¸å°å¢å¹¿è·¯å¾å°±è¿åã
        int Min=999999999;
        for(i=t;i!=s;i=pre[i])     //éè¿pre[]æ°ç»æ¥æ¾å¢å¹¿è·¯å¾ä¸çè¾¹ï¼æ±åºæ®çå®¹éçæå°å¼ã
            Min=std::min(Min,map[pre[i]][i]);
        for(i=t;i!=s;i=pre[i])
        {
            map[pre[i]][i]-=Min;
            map[i][pre[i]]+=Min;
        }
        ans+=Min;
    }
}

int main()
{
    int T,k=1;
    int u,v,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        s=1; t=n;
        memset(map,0,sizeof(map));
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&c);
            map[u][v]+=c;
        }
        printf("Case %d: %d\n",k++,Max_Flow());
    }
    return 0;
}
