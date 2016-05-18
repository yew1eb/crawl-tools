#include<iostream>
 #include<cstdio>
 #include<cstring>
 #include<cmath>
 #include<queue>
 using namespace std;
 #define MAXN 555
 #define MAXM 5555
 struct Node{
     int num[MAXN];
     int len;
 };
 bool digit[22];
 bool mark[MAXM];
 int N,C,M;
 
 //判断C进制的密码转10进制能否被N整除
 int Judge(Node &p){
     int len=p.len,tmp=0;
     for(int i=1;i<=len;i++){
         tmp=(tmp*C+p.num[i])%N;
     }
     return tmp;
 }
 
 
 bool bfs(){
     memset(mark,false,sizeof(mark));
     queue<Node>Q;
     Node p,q;
     p.len=1;
     Q.push(p);
     while(!Q.empty()){
         p=Q.front();
         Q.pop();
         for(int i=(p.len==1?1:0);i<16;i++){
             if(digit[i]){
                 q=p;
                 q.num[q.len]=i;
                 int mod=Judge(q);
                 if(mod){
                     if(!mark[mod]&&q.len+1<=500){
                         mark[mod]=true;
                         q.len+=1;
                         Q.push(q);
                     }
                 }else {
                     for(int i=1;i<=q.len;i++){
                         printf("%X",q.num[i]);
                     }
                     puts("");
                     return true;
                 }
             }
         }
     }
     return false;
 }
 
 
 int main(){
     int _case,x;
     scanf("%d",&_case);
     while(_case--){
         scanf("%d%d%d",&N,&C,&M);
         memset(digit,false,sizeof(digit));
         for(int i=1;i<=M;i++){
             scanf("%x",&x);
             digit[x]=true;
         }
         if(N==0){
             if(digit[0])puts("0");
             else puts("give me the bomb please");
         }else if(!bfs()){
             puts("give me the bomb please");
         }
     }
     return 0;
 }