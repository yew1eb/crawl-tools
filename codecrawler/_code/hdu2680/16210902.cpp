#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 2002    //è¿ä¸ªå°æ¹å¤ªåç¸ç¸äºï¼æç§é¢ç®ä¸æè®¾æ20002å±ç¶æ²¡æ§è¡å½æ°ä½ï¼ç´æ¥return å¦
#define N 1002    //è¿äºçé¢ç®æ°æ®èå´
#define INF 999999
int n,m,s;
int map[M][M];    //map[i][j]è¡¨ç¤ºiå°jçæå¼
int dis[N];        //dis[i] è¡¨ç¤ºåç¹så°içè·ç¦»
int visit[N];      //é¡¶ç¹æ¯å¦è¢«è®¿é®è¿
void dijkstra(int s)
{
    int i,j,k = 0;
    int min;
    memset(visit,0,sizeof(visit));  //åå§æ¶é½æ²¡è¢«è®¿é®è¿
    for(i = 1; i <=n; i++)
    {
        dis[i] = map[s][i];
    }
    visit[s] = 1;  //ç¬¬ä¸ä¸ªé¡¶ç¹å³åç¹ï¼è¢«è®¿é®
    dis[s] = 0; //så°s å³ä¸º0
    for(i = 1; i < n; i++)
    {
        min = INF;
        //æ¾å°æå°ç
        for (j = 1; j <= n; j++)
        {
            if ( !visit[j] && dis[j] < min)
            {
                min = dis[j];
                k = j;   //æå°çé¡¶ç¹
            }
        }
        if (min == INF)
        {
            break;
        }
        visit[k] = 1; //ké¡¶ç¹è¢«è®¿é®
        //è¿éå°±æ¯æ¯è¾ï¼ç´æ¥å°è¿æ¯è½¬ä¸ä¸åå°
        //æçï¼ä½ ä¸ªç¬¨èè¯å®ä¼é®ï¼ä¸è½è½¬å¤ä¸åï¼
        //ç­æ°ï¼ä»æºç¹ä¸ä¸ªä¸ä¸ªåå¤æ©å±ï¼å·ææä¼å­ç»æãæ¯ä¸ªdis[i]é½ä¿ççä»så°içæç­è·ç¦»ãè½¬å¤ä¸çæåµæå®åè§£å¼ï¼å°±ç¥éäº
        for(j = 1; j <= n; j++)   
        {
            if ( !visit[j] && dis[j] > dis[k] + map[k][j])
            {
                dis[j] = dis[k] + map[k][j];
            }
        }
    }
    return ;
}
int main()
{
    int i,j;
    int p,q,t,w;
    int  minx ,ww;
    while ( scanf("%d %d %d",&n,&m,&s) != EOF)
    {
        memset(dis,0,sizeof(dis));
        for (i = 1; i<= n; i++)
            for(j = 1; j <= n; j ++)
            {
                map[i][j] = INF;
            }
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&p,&q,&t);
            if(t < map[q][p])     //é¢ç®ä¸ææè¯´çt <= 1000çï¼å°¼çä¸å å°±éãä»¥åä¿é©èµ·è§è¦å å
                map[q][p] = t;   //æ³¨æåååååå,å ä¸ºæ¯æS(ç®çå°)çææºç¹ï¼æä»¥æåå¾æ¹åè¦åè¿æ¥å
        }
        dijkstra(s);
        scanf("%d",&w);
        minx = INF;

        for (i = 1; i <=w; i++ )  //æ¾å°æå°çdis
        {
            scanf("%d",&ww);
            if (minx > dis[ww])
            {
                minx = dis[ww];
            }
        }
        if ( minx != INF)
        {
            printf("%d\n",minx);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
