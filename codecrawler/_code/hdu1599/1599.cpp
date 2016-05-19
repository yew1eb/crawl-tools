#include<iostream>
 const int N=111;
 const int inf=1000000;
 #define min(x,y) ((x<y)?(x):(y));
 using namespace std;
 
 int dist[N][N];
 int edge[N][N];
 int n,m;
 
 void floyd(){
     int ans=inf;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
             dist[i][j]=edge[i][j];
         }
     }
     //根据Floyed的原理，在最外层循环做了k-1次之后，dis[i][j]则代表了i到j的路径中所有结点编号都小于k的最短路径
     for(int k=1;k<=n;k++){
         //环的最小长度为edge[i][k]+edge[k][j]+i->j的路径中所有编号小于k的最短路径长度
         for(int i=1;i<k;i++){
             for(int j=i+1;j<k;j++){
                 if(dist[i][j]+edge[i][k]+edge[k][j]<inf){
                     ans=min(ans,dist[i][j]+edge[i][k]+edge[k][j]);
                 }
             }
         }
         //floyd原来的部分,更新dist[i][j]///
         for(int i=1;i<=n;i++){
             for(int j=1;j<=n;j++){
                 if(dist[i][j]>dist[i][k]+dist[k][j]){
                     dist[i][j]=dist[i][k]+dist[k][j];
                 }
             }
         }
     }
     if(ans==inf){
         printf("It's impossible.\n");
     }else 
         printf("%d\n",ans);
 }
 
 
 int main(){
     while(scanf("%d%d",&n,&m)!=EOF){
         for(int i=1;i<=n;i++){
             for(int j=1;j<=n;j++){
                 if(i==j){
                     edge[i][j]=0;
                 }else 
                     edge[i][j]=inf;
             }
         }
         int x,y,cost;
         for(int i=1;i<=m;i++){
             scanf("%d%d%d",&x,&y,&cost);
             //考虑重边
             if(edge[x][y]>cost){
                 edge[x][y]=edge[y][x]=cost;
             }
         }
         floyd();
     }
     return 0;
 }