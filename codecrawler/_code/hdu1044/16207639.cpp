#include<iostream>
#include <queue>
#include<string.h>
using namespace std;
int n,m,t,w;
int val[60];
char map[60][60];
int vis[60][60],vis2[60],step[60][60];
queue<int> q;
int d[4][2]={-1,0,1,0,0,-1,0,1};
int abc[60][60],ans,sum;  //abc[i][j]ç¨æ¥å­iå°jçæç­è·ç¦» 
void bfs(int x, int y , int s)  //x,yè¡¨ç¤ºabc[][]ä¸­çiçåæ ï¼sä»£è¡¨içæ§è´¨ï¼æ¯å¥å£ï¼ç¬¬å ä¸ªå®ç©å ï¼è¿æ¯åºå£ï¼ 
{
     while(!q.empty())  q.pop();
     int u=x*m+y;     
     q.push(u);
     vis[x][y]=1;  step[x][y]=0;
     while(!q.empty())
     {  
         u = q.front();  q.pop();
         x = u/m ;  y = u%m;   
         for(int i=0;i<4;i++)
         {
             int xx = x+d[i][0] , yy = y+d[i][1];
             if(xx<0||xx>=n||yy<0||yy>=m) continue; 
             if(vis[xx][yy]==0 && map[xx][yy]!='*') 
             {
                 vis[xx][yy]=1; 
                 step[xx][yy]=step[x][y]+1;  
                 if(map[xx][yy]=='@')   abc[s][0]=step[xx][yy];
                 if(isalpha(map[xx][yy]))   {abc[s][map[xx][yy]-64]=step[xx][yy]; }
                 if(map[xx][yy]=='<')  abc[s][w+1]=step[xx][yy];
                 q.push(xx*m+yy);
             }
         }
     } 
}
void dfs(int p , int s , int time) 
{ //pè¡¨ç¤ºa[][]ä¸­içæ§è´¨ ï¼sè¡¨ç¤ºå½åæç´¢è·¯å¾å¯å¾çå®ç³ä»·å¼ï¼timeè¡¨ç¤ºå½åæç´¢è·¯å¾çæ¶é´ 
     if(time>t || ans==sum) return;
     if(p>w && s > ans)   ans = s ;
    //p>wè¯´æè¿ä¸ä¸ªæ·±æè·¯å¾æå°äºåºï¼åºå£ï¼ 
     for(int i=0;i<=w+1; i++)
     { 
         if(abc[p][i]==0 || vis2[i])  continue;
         vis2[i]=1;
         dfs(i  , s+val[i] , time + abc[p][i]);
         vis2[i]=0;
     }
     
}
int main()
{
    int c , x=0;
    scanf("%d",&c);
    while (c--)
    {
         memset(vis,0,sizeof(vis));
         memset(vis2,0,sizeof(vis2));
         memset(abc,0,sizeof(abc));
         sum=0;    ans=-1;
         scanf("%d%d%d%d",&m,&n,&t,&w);  val[0]=val[w+1]=0;
         for(int i=1;i<=w;i++)  scanf("%d",&val[i]) , sum +=val[i];
         for(int i=0;i<n;i++)  scanf("%s",map[i]);
         for(int i=0;i<n;i++)  for(int j=0;j<m;j++)
         {
              memset(step,0,sizeof(step)); 
              memset(vis,0,sizeof(vis));  
              //è¿ä¸¤ä¸ªèµåå¼0ï¼å ä¸ºabc[][]ä¸­i(å®)ä¸j(å)å°±ä¼å°å ä¹æææ ¼å­éåä¸é 
              if(map[i][j]=='@') bfs(i,j,0);
              if(isalpha(map[i][j]))   bfs(i,j,map[i][j]-64);
              if(map[i][j]=='<')  bfs(i,j,w+1);
         } 
         vis2[0]=1;
         dfs(0,0,0);
         printf("Case %d:\n",++x);
         if(ans>=0) printf("The best score is %d.\n",ans);
         else printf("Impossible\n");
         if(c)  printf("\n");
    }
    return 0;
} 
