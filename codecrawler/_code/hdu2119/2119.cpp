#include<iostream>
 #include<cstring>
 const int N=110;
 using namespace std;
 int map[N][N];
 int visited[N];
 int used[N];
 int n,m;
 
 //从定点x出发，用深度优先搜索策略寻找增广路
 int Solve(int x){
     for(int j=0;j<m;j++){
         if(map[x][j]&&!visited[j]){
             visited[j]=1;
             //如果没有匹配，或者已经匹配了，但从used[j]出发可以找到一天增广路；
             //如果前一个条件成立，则不会递归调用
             if(used[j]==-1||Solve(used[j])){
                 used[j]=x;
                 return 1;
             }
         }
     }
     return 0;
 }
 
 
 //求二部图最大匹配的匈牙利算法
 int MaxMatch(){
     int count=0;
     for(int i=0;i<n;i++){
         memset(visited,0,sizeof(visited));
         if(Solve(i))count++;
     }
     return count;
 }
 
 int main(){
     while(~scanf("%d",&n)&&n){
         scanf("%d",&m);
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 scanf("%d",&map[i][j]);
             }
         }
         memset(used,-1,sizeof(used));
         int ans=MaxMatch();
         printf("%d\n",ans);
     }
     return 0;
 }