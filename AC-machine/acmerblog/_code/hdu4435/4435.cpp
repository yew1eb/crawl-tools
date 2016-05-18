#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
//#include <conio.h>
using namespace std;
#define INF 100000000
bool mark[200];
int dis[200][200];
int N,D;
double sq(double x1,double y1,double x2,double y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
bool visit[150];
int ct;
void dfs(int u){
  visit[u]=true;
  ct++;
  for(int i=1;i<=N;i++)
   if(!visit[i]&&dis[u][i]<=D){
      dfs(i);
  }
}
void OK(int u,int lt){
 // printf("%d %d ?",u,lt);getch();
    if(mark[u]){
            lt=D,visit[u]=true;
            ct++;
    }
    else{
        if(lt>=(D+1)/2) visit[u]=true,ct++;
        else return;
    }
    for(int i=1;i<=N;i++)
        if(u!=i&&!visit[i]&&dis[u][i]<=lt)
          OK(i,lt-dis[u][i]);

}

int main(){

   int rc[200][2];
   int i,j;
   while(scanf("%d %d",&N,&D)!=EOF){
        //memset(mark,0,sizeof(mark));
        for(i=1;i<=N;i++) mark[i]=true;
        for(i=1;i<=N;i++)
         scanf("%d %d",&rc[i][0],&rc[i][1]);
         if(N==1){printf("0\n");continue;}
        for(i=1;i<N;i++)
          for(j=i+1;j<=N;j++){
            double t=sq(rc[i][0],rc[i][1],rc[j][0],rc[j][1]);
             int ti=ceil(sqrt(t));
             dis[i][j]=dis[j][i]=ti;
        }
        memset(visit,0,sizeof(visit));
        ct=0;
        dfs(1);
        if(ct<N) {printf("-1\n");continue;}
        for(i=N;i>1;i--){
            mark[i]=false;
           ct=0;
           memset(visit,0,sizeof(visit));
           OK(1,0);
           if(ct<N)
              mark[i]=true;
          //  printf("\n");
        }
      for(i=N;i>0;i--)if(mark[i]) break;
      for(;i>0;i--) if(mark[i])printf("1");else printf("0");
      printf("\n");
   }
  return 0;
}