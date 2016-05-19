#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int map[10][10];
int vis[10][10];
int deep,n;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
bool cheack(int x,int y){
     return x>=0&&x<n&&y>=0&&y<n;
}
void change_color(int x,int y,int color){
    for(int i=0;i<4;i++){
        int nx=x+dx[i];  int ny=y+dy[i];
        if(cheack(nx,ny)){
            if(vis[nx][ny]==1)  continue;

            if(map[nx][ny]==color){
               vis[nx][ny]=1;
               change_color(nx,ny,color);
            }
            else{
               vis[nx][ny]=2;
            }
        }
    }
}
int h(){
    int cnt=0;
    bool mark[10];
    memset(mark,false,sizeof(mark));
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++){
        if(vis[i][j]==1)  continue;
        mark[map[i][j]]=true;
    }

    for(int i=0;i<=5;i++)  if(mark[i])  cnt++;
   // printf("%d\n",cnt);
    return cnt;
}
bool  dfs(int d){
      int t=h();
      if(d==deep)     return (t==0?true:false);
      if(d+t>deep)    return false;

      for(int i=0;i<=5;i++){
         int cnt=0; int tvis[10][10];
         memcpy(tvis,vis,sizeof(vis));
         for(int j=0;j<n;j++) for(int k=0;k<n;k++){
             if(map[j][k]!=i) continue;
             if(vis[j][k]==2){
                  vis[j][k]=1;
                  change_color(j,k,i);
                  cnt++;
             }
         }
//         for(int i=0;i<n;i++){ for(int j=0;j<n;j++)
//              printf("%d ",vis[i][j]);
//              printf("\n");
//         }
      //   system("pause");
         if(cnt>0&&dfs(d+1))  return true;
         memcpy(vis,tvis,sizeof(tvis));
      }
      return false;
}
int main(){

    while(scanf("%d",&n)!=EOF,n){
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
         scanf("%d",&map[i][j]);
        }
        memset(vis,0,sizeof(vis));
        deep=0;  vis[0][0]=1;
        change_color(0,0,map[0][0]);
//         for(int i=0;i<n;i++){ for(int j=0;j<n;j++)
//              printf("%d ",vis[i][j]);
//              printf("\n");
//         }
        while(true){
           if(dfs(0)) break;
            deep++;
         }
        printf("%d\n",deep);
    }
    return 0;
}
