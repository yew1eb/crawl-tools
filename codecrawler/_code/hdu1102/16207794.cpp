#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define inf 999999999

int N,M;       // N ä»£è¡¨ç¹çæ°éï¼Mä»£è¡¨å·²ä¿®å»ºçè·¯çæ¡æ° 
int map[105][105];
int dis[105];
int visit[105];

int prim()
{
    for(int i=1;i<=N;i++)  //åææ¯ä¸ªç¹å°å·²ç»å»ºå¥½çå¾ä¸­çè·¯å¾ç½®ä¸ºæ ç©·å¤§ 
        dis[i]=inf;
    dis[1]=0;              //èµ·ç¹ä¸ºé¡¶ç¹1 
    for(int j=1;j<=N;j++)
    {
        int t=inf,pos;  //ä¸´æ¶åé:æç­è·¯å¾è·ç¦»t,åè¯¥é¡¶ç¹pos 
        for(int i=1;i<=N;i++)     //æ¥æ¾æç­è·¯å¾'ç¹' 
        {
            if(!visit[i]&&t>dis[i])
            {
                t=dis[i];
                pos=i;
            }
        }
        visit[pos]=1;         //æç­è·¯å¾ç¹æ è®°ä¸ºå·²ç»è®¿é® 
        for(int i=1;i<=N;i++)  //æ´æ°æç­è·¯å¾ç¹ 
        {
            //å¦æ,é¡¶ç¹iæªè¢«è®¿é®è¿
            //ä¸å¾ä¸­æ°å å¥çposç¹å°iç¹çè·ç¦»ç­äºåæ¥å¾å°iç¹çè·ç¦»
            //ä¸poså°içç¹æè¿é(å³ä¸ä¸ºæ ç©·å¤§),åå°iç¹å°å¾çè·ç¦»æ´æ°. 
            if(!visit[i]&&dis[i]>map[pos][i]&&map[pos][i]!=inf)
            {
                dis[i]=map[pos][i];
            }
        }
    }    
    int temp=0;
    for(int k=1;k<=N;k++)
    {
        temp+=dis[k];
    }
    return temp;
}


int main()
{
    int a,b;
    while(scanf("%d",&N)!=EOF)
    {
        memset(map,0x3f,sizeof(map));
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=N;i++)        //æå»ºå¾çç©éµ 
        {
            for(int j=1;j<=N;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        scanf("%d",&M);
        for(int i=1;i<=M;i++)       //è¾å¥å·²ç»ä¿®å»ºå¥½çè·¯ 
        {
            scanf("%d%d",&a,&b);
            map[a][b]=0;
            map[b][a]=0;
        }
        int ans=prim();
        printf("%d\n",ans);
    }
    return 0;
}
