/**********************************************\
* æå¤§ç¬ç«éæçæ¯ä¸¤ä¸¤ä¹é´æ²¡æè¾¹çé¡¶ç¹çéåï¼*
* é¡¶ç¹æå¤çç¬ç«éæä¸ºæå¤§ç¬ç«éã          *
* äºåå¾çæå¤§ç¬ç«é=èç¹æ°-ï¼åå·ï¼æå¤§å¹éæ°*
\**********************************************/ 
 
#include<stdio.h>
#include<string.h>

#define MAX1 1005
#define MAX2 1005          //äºé¨å¾ä¸ä¾§é¡¶ç¹çæå¤§ä¸ªæ°
//n,m,MAX1,MAX2éæ ¹æ®å®éæåµè¿è¡ä¿®æ¹

//æ¨¡æ¿å¼å§
int  n,m,match[MAX2];     //äºåå¾çä¸¤ä¸ªéååå«å«ænåmä¸ªåç´ ã
bool visit[MAX2],G[MAX1][MAX2]; //Gå­å¨é»æ¥ç©éµã
bool DFS(int k)
{   int t;
    for(int i = 0; i < m; i++)
    {     if(G[k][i] && !visit[i])
          {    visit[i] = true;    t = match[i];    match[i] = k;   //è·¯å¾ååæä½ã
               if(t == -1 || DFS(t))  return true;   //æ´ä¸ªç®æ³çæ ¸å¿é¨å
               match[i] = t;
          }
     }
     return false;
}
int Max_match ()
{     int ans = 0,i;
      memset(match, -1, sizeof(match));
      for(i = 0; i <n ;i++)
      {    memset(visit,0,sizeof(visit));
           if(DFS(i))   ans++;
      }
      return ans;
}
// æ¨¡æ¿ç»æ
//æ¨¡æ¿è¿åçæ¯æå¤§çå¹é
int main()
{  
   int t;
   int i,a,b,c;
   while(scanf("%d",&t)!=-1)
   {   
       n=t;m=t;
       memset(G,0,sizeof(G)); 
       while(t--)
       {  
           scanf("%d: (%d)",&a,&b);       
           for(i=0;i<b;i++)           
           {   
               scanf("%d",&c);
               G[a][c]=1;
           }
       }
       printf("%d\n",n-Max_match()/2);
   }
    return 0;   
}
