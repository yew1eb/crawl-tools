#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
#define MAXN 1010
#define INF 0xFFFFFFF

int n;
char str[MAXN][MAXN];
int value[MAXN][MAXN];
int t[MAXN];
int dis[MAXN];
int vis[MAXN];
queue<int>q;

/*初始化*/
void init(){
   int i , j , k , len;    
   char ch1[10], ch2[10];
   for(i = 1 ; i <= n ; i++){
      len = strlen(str[i])-4;
      for(k = 0 ; k < 4 ; k++)
          ch1[k] = str[i][len+k];  
      ch1[4] = '\0';/*末尾加上'\0'，表示字符串结束*/
      for(j = 1 ; j <= n ; j++){
         value[i][j] = INF;
         for(k = 0 ; k < 4 ; k++)
            ch2[k]  = str[j][k];
         ch2[4] = '\0';/*末尾加上'\0'，表示字符串结束*/
         if(!strcmp(ch1 , ch2))
           value[i][j] = t[i];
      }   
      value[i][i] = 0;
   }
}

/*SPFA*/
void SPFA(){
    memset(vis , 0 , sizeof(vis));
    for(int i = 2 ; i <= n ; i++)
       dis[i] = INF;
    dis[1] = 0;
    vis[1] = 1;
    q.push(1);
    while(!q.empty()){
       int x = q.front();
       q.pop();
       vis[x] = 0;
       for(int i = 1 ; i <= n ; i++){
          if(value[x][i] && dis[i] > dis[x] + value[x][i]){
            dis[i] = dis[x] + value[x][i];
            if(!vis[i]){
               vis[i] = 1;
               q.push(i);
            }
          }
       }
    }
}

int main(){
   while(scanf("%d" , &n) && n){
      for(int i = 1; i <= n ; i++)
         scanf("%d %s" , &t[i] , str[i]);
      init();
      SPFA();
      if(dis[n] != INF)
        printf("%d\n" , dis[n]);
      else
        printf("-1\n");
   }
   return 0;
}