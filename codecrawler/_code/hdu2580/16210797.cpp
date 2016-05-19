#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<math.h>
#include<set>
#include<vector>
#define MAXN 15
#define INF 1000
using namespace std;
int no[2000000],maxok[2000000];//noå¨å­çæ¯loseçæ°ã  maxokãiãå­çæ¯å¨iä¹åè½ç»æçæå¤§çæ°ï¼ 
int main()
{
    int i,j,n,m,k,t,c,ca=0;
    for(scanf("%d",&t);t--;)
    {
        ca++;
        scanf("%d%d",&n,&k);
        if(n<=k+1)//n<=k+1æ¶ä¸å®æ¯è¾ï¼ 
        {
            printf("Case %d: lose\n",ca);
            continue;
        }
        int x=0,y=0;
        no[0]=maxok[0]=1;
        while(no[x]<n)
        {
            x++;
            no[x]=maxok[x-1]+1;//å¨xä¹åï¼æå¤§çè½ç¬¦åçæ°æ¯maxokãx-1ããå 1åå°±ä¸ç¬¦åã 
            while(no[y+1]*k<no[x])//æ¾å°äºno[x]çæå¤§æ°:ä¾å­k=3æ¶æ15å¾å°4 
                y++;
            if(no[y]*k<no[x])//åé¢å¾å°çæ°å¯è½ä¸ç¬¦åæ¡ä»¶ 
                maxok[x]=no[x]+maxok[y];//å¦æç¬¦åç´æ¥å¾no[x]+maxok[y]ï¼ä¾å­ä¸­æ¨å¾15+maxok[3] 
            else
                maxok[x]=no[x];//å¦åè½ç»ææå¤§çæ°ä¸ºæ¬èº«ã 
        }
        if(no[x]==n)//åå¥½ç»æn  è¯´æè¿ä¸ªæ°å±äºnoæ°ç»ãå³ä¸è½ç±ç¬¦åæ¡ä»¶çæ°ç»æï¼loseï¼ 
        {
            printf("Case %d: lose\n",ca);
            continue;
        }
        int ans;
        while(n)
        {
            if(n>=no[x])//ä¸æ­çåå»æå¤§çæ°ï¼å©ä¸çæå°çæ°å°±æ¯äºã 
            {
                ans=no[x];
                n-=no[x];
            }
            x--;
        }
        printf("Case %d: %d\n",ca,ans);
    } 
    return 0;
}
/*
k=3æ¶ï¼
  no={1,2,3,4,6,8,11,15,21,29
maxok=1,2,3,5,7,10,14,20
*/ 