#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

char map[25][25];
char temp_map[25][25];
bool vis[25][25];
bool mark[25][25];
int n,m,ans,cur_max;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool cheack(int x,int y){
     return x>=0&&x<n&&y>=0&&y<m;
     return false;
}
void dfs(int x,int y,char color){
     for(int i=0;i<4;i++){
        int nx=x+dir[i][0],ny=y+dir[i][1];
        if(cheack(nx,ny)&&!vis[nx][ny]&&temp_map[nx][ny]==color){
           vis[nx][ny]=true;
           temp_map[nx][ny]='0';
           cur_max+=1;
           dfs(nx,ny,color);
        }
     }
}
void move_zero(){
    vector<char > temp[25];
    int len=0,i,j;
    for( i=0;i<m;i++){
       for( j=n-1;j>=0;j--)
           if(map[j][i]>'0') break;

        if(j>=0){
           for(int j=n-1;j>=0;j--){
               if(map[j][i]>'0')
                temp[len].push_back(map[j][i]);
           }
           for(int j=temp[i].size();j<n;j++)
                temp[len].push_back('0');
            len++;
        }
    }
    for(int i=len;i<m;i++){
       for(int j=0;j<n;j++)
        temp[i].push_back('0');
    }

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        map[i][j]=temp[j][n-1-i];
    }
//    for(int i=0;i<m;i++){
//      for(int j=0;j<n;j++)
//       cout<<map[i][j]<<" ";
//       cout<<endl;
//    }
}
int main(){
    int cnt;
    while(scanf("%d%d",&n,&m)!=EOF){

         for(int i=0;i<n;i++)  scanf("%s",map[i]);

         ans=0;
         while(1){
             cnt=0;
             for(int i=0;i<n;i++)  for(int j=0;j<m;j++)  temp_map[i][j]=map[i][j];

             for(int i=0;i<n;i++){
               for(int j=0;j<m;j++)
                 if(temp_map[i][j]>'0'){
                    memset(vis,false,sizeof(vis));
                    cur_max=1;     vis[i][j]=true;

                    dfs(i,j,temp_map[i][j]);

                    if(cnt<cur_max){
                        cnt=cur_max;
                        for(int l=0;l<n;l++) for(int k=0;k<m;k++)
                          mark[l][k]=vis[l][k];
                    }
                 }
             }
             if(cnt<=1) break;
             ans+=cnt*(cnt-1);
            for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
             if(mark[i][j]){
                map[i][j]='0';
             }
             move_zero();
         }
         cout<<ans<<endl;

    }
    return 0;
}
