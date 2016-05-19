#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 1010
#define INF 0xFFFFFFF

int t , s , d;
int sCity[MAXN];
int dCity[MAXN];
int dis[MAXN];
int vis[MAXN];
int value[MAXN][MAXN];

void init(){
   for(int i = 1 ; i < MAXN ; i++){
      for(int j = 1 ; j < MAXN ; j++)
        value[i][j] = INF;
   }
}

void Dijkstra(int s){
    int pos;
    memset(vis , 0 , sizeof(vis));
    for(int i = 1 ; i < MAXN; i++)
       dis[i] = INF;
    dis[s] = 0;
    for(int i = 1 ; i < MAXN ; i++){
       pos = -1;
       for(int j = 1 ; j < MAXN ; j++){
          if(!vis[j] && (pos == -1 || dis[j] < dis[pos]))
            pos = j;
       } 
       if(pos == -1)
          break;
       vis[pos] = 1;
       for(int j = 1 ; j < MAXN ; j++){
          if(!vis[j] && dis[j] > dis[pos] + value[pos][j])
            dis[j] = dis[pos] + value[pos][j];
       }
    }
}

int main(){
   int a , b , v , ans;
   while(scanf("%d%d%d" , &t , &s , &d) != EOF){
      init();
      for(int i = 0 ; i < t ; i++){
         scanf("%d%d%d" , &a , &b , &v);
         if(value[a][b] > v)
           value[a][b] = value[b][a] = v;
      }
      for(int i = 0 ; i < s ; i++)
         scanf("%d" , &sCity[i]);
      for(int i = 0 ; i < d ; i++)
         scanf("%d" , &dCity[i]);
      ans = INF;
      /*枚举起点*/
      for(int i = 0 ; i < s ; i++){
         Dijkstra(sCity[i]);
         for(int j = 0 ; j < d ; j++)/*枚举终点*/
            ans = ans < dis[dCity[j]] ? ans : dis[dCity[j]];
      }
      printf("%d\n" , ans);
   }
   return 0;
}