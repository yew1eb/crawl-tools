#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int MAX = 110;
char  map[MAX][MAX];
int  vis[MAX][MAX];
int m,n,flag;
int k,s_x,s_y,e_x,e_y;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct node{
    int x,y;
    int num;     //当前转弯数
    int dir;
}s_pos;
bool cheak(int x,int y)
{
    if(x>=0&&x<m&&y>=0&&y<n&&map[x][y]!='*')
    return true;
    return false;
}
void bfs(){
    s_pos.x=s_x,s_pos.y=s_y;  s_pos.num=-1; s_pos.dir=-1;
    vis[s_x][s_y]=0;
    queue<node>q;
    q.push(s_pos);
    while(!q.empty()){
        node now = q.front(); q.pop();
        if(now.x==e_x&&now.y==e_y&&now.num<=k){
            flag=1; return;
        }

        for(int i=0;i<4;i++){
            node next = now;
            next.x+=dir[i][0],  next.y+=dir[i][1];

            if(cheak(next.x,next.y)){
                if(next.dir==-1){
                    next.dir=i;
                    next.num=0;
                    if(vis[next.x][next.y]>=next.num){
                      vis[next.x][next.y]=next.num;
                       q.push(next);
                    }
                }
                else{
                    if(i==now.dir){
                       if(vis[next.x][next.y]>=next.num){
                         vis[next.x][next.y]=next.num;
                         q.push(next);
                         }

                    }
                    else{
                        next.num+=1;  next.dir=i;
                        if(next.num<=k&&vis[next.x][next.y]>=next.num){
                             vis[next.x][next.y]=next.num;
                             q.push(next);
                        }


                    }


                }



            }


        }


    }

}

int main(){
    int t;  cin>>t;
    while(t--){
        cin>>m>>n;
        for(int i=0;i<m;i++)  cin>>map[i];
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) vis[i][j]=1000000;

        cin>>k>>s_y>>s_x>>e_y>>e_x;

        s_y-=1;  s_x-=1;  e_y-=1; e_x-=1;
        flag=0;
        if(s_x==e_x&&s_y==e_y){  cout<<"yes"<<endl;  continue; }
        bfs();

        if(flag) cout<<"yes"<<endl;
        else     cout<<"no"<<endl;

    }
    return 0;


}