#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
char map[50][50];
int cnt[50][50];
int r,c;
int flag;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int sum;
char op[]="DRUL";
char ans[10000];
int cur_step;
bool cheack(int x,int y){
      if(x>=0&&x<c&&y>=0&&y<r)
      return true;
      return false;
}
void dfs(int x,int y,int cur_sum,int step){
     if(cur_sum==sum){  flag=1;  cur_step=step;return ;}

     for(int i=0;i<4;i++){
         int next_x=x+dir[i][0],next_y=y+dir[i][1];
         if(cnt[next_x][next_y]>0)  continue ;

         while(cnt[next_x][next_y]==0&&cheack(next_x,next_y)){
             next_x+=dir[i][0],next_y+=dir[i][1];
         }
         if(cheack(next_x,next_y)&&cnt[next_x][next_y]>0){
             int x1=next_x+dir[i][0],  y1=next_y+dir[i][1];
             ans[step]=op[i];

             if(cnt[next_x][next_y]==1){
                    cnt[next_x][next_y]=0;
                    dfs(next_x,next_y,cur_sum+1,step+1);
                    if(flag)  return ;                     //要RETURN
                    
                    cnt[next_x][next_y]=1;
             }
             else{
                if(cheack(x1,y1)){
                   cnt[x1][y1]+=cnt[next_x][next_y]-1;
                   int temp=cnt[next_x][next_y];
                   cnt[next_x][next_y]=0;

                   dfs(next_x,next_y,cur_sum+1,step+1);

                    if(flag)  return ;
                   cnt[x1][y1]=cnt[x1][y1]-(temp-1);
                   cnt[next_x][next_y]=temp;
                }
                else{
                   int temp=cnt[next_x][next_y];
                   cnt[next_x][next_y]=0;
                   dfs(next_x,next_y,cur_sum+temp,step+1);

                    if(flag)  return ;
                   cnt[next_x][next_y]=temp;
                }
             }


         }

     }

}
int main(){
    while(cin>>r>>c){

        memset(cnt,0,sizeof(cnt));
        sum=0;

        for(int i=0;i<c;i++)  cin>>map[i];

        for(int i=0;i<c;i++)        for(int j=0;j<r;j++)
        if(map[i][j]=='.')   cnt[i][j]=0;
        else           {     cnt[i][j]=map[i][j]-'a'+1;  sum+=cnt[i][j]; }
        int i,j;  flag=0;  cur_step=0;
        ans[0]='\0';

        for( i=0;i<c;i++){

             for( j=0;j<r;j++)
             if(map[i][j]=='.'){

                dfs(i,j,0,0);
                if(flag) break;
          }
          if(flag)  break;
        }

        ans[cur_step]='\0';
        if(flag){
            printf("%d\n%d\n",i,j);
            printf("%s\n",ans);
        }
    }
    return 0;
}