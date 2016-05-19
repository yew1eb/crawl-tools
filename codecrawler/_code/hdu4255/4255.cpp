#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define Maxn 200

int graph[Maxn+5][Maxn+5];
int primeVis[Maxn*Maxn + 10];
int vis[Maxn*Maxn + 10];
int dis[Maxn*Maxn + 10];
int disx[4] = {0,1,0,-1};
int disy[4] = {-1,0,1,0};

struct Coord
{
   //鏅�氭ā寮忎笅
   int x,y;
}coord[Maxn*Maxn+10];

void init()
{
   memset(primeVis,0,sizeof(primeVis));
}
void getPrimeVis()
{
   //鍒繕浜�1涔熸槸鍚堟暟
   primeVis[1] = 1;
   for(int i=2;i<Maxn+5;i++)
   {
      if(!primeVis[i])
      {
         for(int j=i*i;j<=Maxn*Maxn;j+=i) primeVis[j] = 1;
      }
   }
}
//浠ユ櫘閫氭柟寮忓缓绔嬪浘锛岃�屼笉鏄绠楁満鏂瑰紡锛坹鍜寈鏄鍊掔殑锛�
void getMap()
{
   int t = Maxn*Maxn;
   int left = 1;
   int right = Maxn;
   int top = Maxn;
   int bottom = 1;
   while(t)
   {
      for(int i=left;i<=right;i++) {graph[i][top] = t--;coord[t+1].x = i;coord[t+1].y = top;}
      top--;
      for(int i=top;i>=bottom;i--) {graph[right][i] = t--;coord[t+1].x = right;coord[t+1].y = i;}
      right--;
      for(int i=right;i>=left;i--) {graph[i][bottom] = t--;coord[t+1].x = i;coord[t+1].y = bottom;}
      bottom++;
      for(int i=bottom;i<=top;i++) {graph[left][i] = t--;coord[t+1].x = left;coord[t+1].y = i;}
      left++;
   }
   
}

int bfs(int s,int t)
{
   memset(vis,0,sizeof(vis));
   memset(dis,0,sizeof(dis));
   queue<int> q;
   q.push(s);
   vis[s] = 1;
   while(!q.empty())
   {
      int temp = q.front();
      q.pop();
      for(int i=0;i<4;i++)
      {
         int curx = coord[temp].x + disx[i];
         int cury = coord[temp].y + disy[i];
         if(curx>=1 && curx<=Maxn && cury>=1 && cury<=Maxn)
         {
            //鏈璁块棶杩囦笖鏄悎鏁�
            int cur = graph[curx][cury];
            if(vis[cur]==0 && primeVis[cur])
            {
               vis[cur] = 1;
               dis[cur] = dis[temp] + 1;
               if(cur == t) return dis[cur];
               q.push(cur);
            }
         }
      }
   }
   return -1;
}
int main()
{
   #ifndef ONLINE_JUDGE
      freopen("in.txt","r",stdin);
   #endif
   int n,m;
   int a,b;
   init();
   getPrimeVis();
   getMap();
   int cas = 0;
   while(scanf(" %d %d",&a,&b)!=EOF)
   {
      cas++;
      printf("Case %d: ",cas);
      int ans = bfs(a,b);
      if(ans == -1) puts("impossible");
      else printf("%d\n",ans);
   }
   return 0;
}