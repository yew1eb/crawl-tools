#include<iostream>
#include<queue>
using namespace std;
int map[1010][1010];
int cnt_map[1010][1010];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int s_x,s_y;
int e_x,e_y;
int flag,n,m;
struct node{
    int cnt;
    int x,y;
    int pre_dir;
}s_pos;
bool cheak(int x,int y){

    if(x>=1&&x<=n&&y>=1&&y<=m&&(map[x][y]==0||x==e_x&&y==e_y))
        return true;
    return false;
}

void dfs(int x,int y,int cnt,int pre_dir){
    if(flag||cnt>3) return ;
    if(x==e_x&&y==e_y){
        flag=1;
        return ;
    }

    for(int i=0;i<4;i++){

        int n_x,n_y;
         n_x=x+dir[i][0];
         n_y=y+dir[i][1];

    
        if(cheak(n_x,n_y)&&cnt+1<=cnt_map[n_x][n_y]){

        

            if(pre_dir==i&&cnt<=3&&cnt<cnt_map[n_x][n_y]) {
                cnt_map[n_x][n_y]=cnt;
                dfs(n_x,n_y,cnt,pre_dir);
            }

            if((pre_dir!=i||pre_dir==-1)&&cnt<=3) {
            
                cnt_map[n_x][n_y]=cnt+1;

                dfs(n_x,n_y,cnt+1,i);
            }
        
        


        }
    }


}
int main(){

    int i,j,q;

    while(cin>>n>>m,n+m){
        for(i=1;i<=n;i++) for(j=1;j<=m;j++)
            scanf("%d",&map[i][j]);

        scanf("%d",&q);

        while(q--){

        //    memset(visited,0,sizeof(visited));

            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    cnt_map[i][j]=100000;

            scanf("%d%d%d%d",&s_x,&s_y,&e_x,&e_y);

        //    cout<<cnt_map[1][1]<<endl;
            if(map[s_x][s_y]!=map[e_x][e_y]||map[s_x][s_y]==0||map[e_x][e_y]==0){
                puts("NO");
            }
            else{
                
                flag=0;
            //    visited[s_x][s_y]=1;
                dfs(s_x,s_y,0,-1);
                if(flag) puts("YES");
                else     puts("NO");

            }
        }


    }

    return 0;
}