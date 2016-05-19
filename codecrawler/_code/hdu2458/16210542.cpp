/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-28 08:47
 # Filename: POJ3692 HDU2458 Kindergarten.cpp
 # Description : 
    æ¬é¢æ¯è¦æ±å¾ä¸­çæå¤§å®å¨å­å¾ï¼æå¤§å¢ï¼ä¸­é¡¶ç¹çä¸ªæ°ãç±äºåå¾çè¡¥å¾æ¯ä¸ä¸ªäºåå¾ï¼å¶æå¤§å®å¨æ°ç­ä»·äºå¶è¡¥å¾çæå¤§ç¬ç«éä¸­åç´ çä¸ªæ°ï¼äºæ¯å¯ä»¥æ ¹æ®äºåå¾çæ§è´¨æ±åºè¿ä¸ªæå¤§ç¬ç«éãèæ®éå¾çæå¤§å¢åæ¯ä¸ä¸ªNPé®é¢ã

    å®çï¼äºåå¾æå¤§ç¬ç«éä¸­åç´ ä¸ªæ°=é¡¶ç¹æ°-äºåå¾æå¤§å¹éæ°

    æå¤§å®å¨æ°ï¼å¾ä¸­æå¤§å®å¨å­å¾çé¡¶ç¹ä¸ªæ°ã

    ç¬ç«éï¼å¾ä¸­ä»»æä¸¤ä¸ªé¡¶ç¹é½ä¸ç¸è¿çé¡¶ç¹éåã
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 450
using namespace std;

int map[MAX][MAX];
int used[MAX],mat[MAX],g,b,n,m;

bool find(const int &x)
{
    for(int i=1;i<=b;++i)
        if(used[i]==0 && !map[x][i])        //ç±äºæ¯æ±è¡¥å¾ï¼æä»¥è¿éçmap[x][i]è¦ç­äº0
        {
            used[i]=1;
            if(mat[i]==0 || find(mat[i]))
            {
                mat[i]=x;
                return true;
            }
        }
    return false;
}

int hungary()
{
    int ans=0;
    memset(mat,0,sizeof(mat));
    for(int i=1;i<=g;++i)
    {
        memset(used,0,sizeof(used));
        if(find(i))
            ++ans;
    }
    return ans;
}

int main(void)
{
#ifdef DEBUG  
    freopen("data.txt","r",stdin);  
#endif  

    int u,v;
    int ncases=1;
    while(scanf("%d%d%d",&g,&b,&m) && (g||b||m))
    {
        memset(map,0,sizeof(map));
        n=g+b;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            map[u][v]=1;
        }
        int ans=hungary();
        printf("Case %d: %d\n",ncases++,n-ans);

    }

    return 0;
}
