#include <string.h>
 #include <stdio.h>
 #include <set>
 typedef long long LL;
 int h,w,full;
 LL d[12][2200],res[12][12];
 int doublei(int state){
     for(int i=0,d=0;i<=w;i++)
         if(i<w&&((state>>i)&1))d++;
         else if(d&1)return 0;
     return 1;
 }
 LL dfs(int state,int step){
     if(d[step][state]!=-1)return d[step][state];
     if(step==h)return state==full-1;
     d[step][state]=0;
     for(int i=0;i<full;i++){
         if((i|state)!=full-1||!doublei(state&i))continue;
         d[step][state]+=dfs(i,step+1);
     }
     return d[step][state];
 }
 int main(){
      while(scanf("%d%d",&h,&w),h||w){
         if(res[w][h])printf("%I64d\n",res[w][h]);
         else{
             full=(1<<w);
             memset(d,-1,sizeof d);
             printf("%I64d\n",res[w][h]=res[h][w]=dfs(full-1,0));
         }
     }
     return 0;
 }