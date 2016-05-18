#include<iostream>
 const int N=1010;
 using namespace std;
 
 int n,m;
 int parent[N];
 
 //初始化
 void UFset(){
     for(int i=1;i<=n;i++){
         parent[i]=-1;
     }
 }
 //找根结点
 int Find(int x){
     int s;
     for(s=x;parent[s]>=0;s=parent[s]);
     //优化
     while(s!=x){
         int temp=parent[x];
         parent[x]=s;
         x=temp;
     }
     return s;
 }
 //合并
 void Union(int R1,int R2){
     int r1=Find(R1);
     int r2=Find(R2);
     int temp=parent[r1]+parent[r2];
     if(parent[r1]>parent[r2]){
         parent[r1]=r2;
         parent[r2]=temp;
     }else {
         parent[r2]=r1;
         parent[r1]=temp;
     }
 }
 
 int main(){
     while(scanf("%d%d",&n,&m)!=EOF){
         if(n==0)break;
         int x,y,ans=n-1;
         UFset();
         for(int i=1;i<=m;i++){
             scanf("%d%d",&x,&y);
             if(Find(x)!=Find(y)){
                 Union(x,y);
                 ans--;
             }
         }
         printf("%d\n",ans);
     }
     return 0;
 }