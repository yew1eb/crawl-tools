#include<iostream>
 #include<cstdio>
 #include<cstring>
 #include<cmath>
 #include<queue>
 using namespace std;
 #define MAXN 1000007
 typedef long long ll;
 ll Hash[MAXN];
 
 struct Node{
     int map[4][8],step;
     bool operator == (const Node &p) const {
         for(int i=0;i<4;i++)
             for(int j=0;j<8;j++)
                 if(map[i][j]!=p.map[i][j])
                     return false;
         return true;
     }
     //手写hash
     ll HashValue(){
         ll value=0;
         for(int i=0;i<4;i++)
             for(int j=0;j<8;j++)
                 value+=(value<<ll(1))+(ll)map[i][j];
         return value;
     }
 };
 
 Node Start,End;
 
 void Initaite(){
     memset(Hash,-1,sizeof(Hash));
     for(int i=0;i<4;i++){
         Start.map[i][0]=0;
         for(int j=1;j<8;j++){
             scanf("%d",&Start.map[i][j]);
         }
     }
     Start.step=0;
 }
 
 //最后的结果
 void GetEnd(){
     for(int i=0;i<4;i++){
         End.map[i][7]=0;
         for(int j=0;j<7;j++){
             End.map[i][j]=(i+1)*10+(j+1);
         }
     }
 }
 
 //取得value的hash值+hash判重
 bool HashInsert(ll value){
     int v=value%MAXN;
     while(Hash[v]!=-1&&Hash[v]!=value){
         v+=10;
         v%=MAXN;
     }
     if(Hash[v]==-1){
         Hash[v]=value;
         return true;
     }
     return false;
 }
 
 void bfs(){
     queue<Node>Q;
     Node p,q;
     Q.push(Start);
     HashInsert(Start.HashValue());
     while(!Q.empty()){
         p=Q.front();
         Q.pop();
         for(int i=0;i<4;i++){
             for(int j=0;j<8;j++){
                 if(!p.map[i][j]){
                     q=p;
                     q.step++;
                     int value=p.map[i][j-1]+1;//找比map[i][j-1]大1的数
                     if(value==1||value%10==8)continue;//0或者value为7的不能移动
                     int x,y,flag=true;
                     for(int k=0;k<4&&flag;k++){
                         for(int l=1;l<8&&flag;l++){
                             if(p.map[k][l]==value){
                                 x=k,y=l;
                                 flag=false;
                             }
                         }
                     }
                     if(!flag){
                         swap(q.map[i][j],q.map[x][y]);
                         ll value=q.HashValue();
                         //hash判重
                         if(HashInsert(value)){
                             if(q==End){
                                 printf("%d\n",q.step);
                                 return ;
                             }
                             Q.push(q);
                         }
                     }
                 }
             }
         }
     }
     puts("-1");
 }
 
 void Solve(){
     int k=0;
     //将11，21,31,41这四个数移到第0列
     for(int i=0;i<4;i++){
         for(int j=1;j<8;j++){
             if(Start.map[i][j]==(k+1)*10+1){
                 swap(Start.map[i][j],Start.map[k][0]);
                 k++,i=0,j=0;
             }
         }
     }
     if(Start==End){
         puts("0");//前四步不记录总步数
         return ;
     }
     bfs();
 }
 
 int main(){
     int _case;
     scanf("%d",&_case);
     GetEnd();
     while(_case--){
         Initaite();
         Solve();
     }
     return 0;
 }