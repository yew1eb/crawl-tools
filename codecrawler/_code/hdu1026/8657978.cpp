#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x7f7f7f7f
using namespace std;
int n,m,flag;
char map[110][110];
bool visited[110][110];
int dir[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
struct node {
    int x,y,step;
    int pre_dir;
} s_pos,count_map[110][110];

void print_path(int pre_dir,int x,int y,int step) {
    int pre_x=x-dir[pre_dir][0],pre_y=y-dir[pre_dir][1];
    if(x==0&&y==0)  return ;
    else {
        if(map[x][y]=='.') {
            print_path(count_map[pre_x][pre_y].pre_dir,pre_x,pre_y,step-1);
            printf("%ds:(%d,%d)->(%d,%d)\n",step,pre_x,pre_y,x,y);
        } else {
            print_path(count_map[pre_x][pre_y].pre_dir,pre_x,pre_y,step-(map[x][y]-'0')-1);
            printf("%ds:(%d,%d)->(%d,%d)\n",step-(map[x][y]-'0'),pre_x,pre_y,x,y);
            for(int i=map[x][y]-'0'-1; i>=0; i--) {
                printf("%ds:FIGHT AT (%d,%d)\n",step-i,x,y);
            }
        }
    }
}

bool cheak(int x,int y) {
    if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]!='X')
        return true;
    return false;
}

void bfs() {
    s_pos.x=0,s_pos.y=0,s_pos.step=0;
    s_pos.pre_dir = -1;
    visited[s_pos.x][s_pos.y]=true;
    queue<node > q;
    q.push(s_pos);
    while(!q.empty()) {
        node now=q.front();
        q.pop();
        if(now.x==n-1&&now.y==m-1) {
            flag=1;
        }
        for(int i=0; i<4; i++) {
            node next=now;
            next.x+=dir[i][0],next.y+=dir[i][1];

            if(cheak(next.x,next.y)) {
                if(map[next.x][next.y]=='.') {
                    next.step+=1;

                    if(next.step<count_map[next.x][next.y].step) {
                        count_map[next.x][next.y].step=next.step;
                        count_map[next.x][next.y].pre_dir=i;
                        q.push(next);
                    }
                } else if(map[next.x][next.y]>='1'&&map[next.x][next.y]<='9') {

                    next.step+=map[next.x][next.y]-'0'+1;

                    if(next.step<count_map[next.x][next.y].step) {
                        count_map[next.x][next.y].step=next.step;
                        count_map[next.x][next.y].pre_dir=i;
                        q.push(next);
                    }
                }
            }
        }
    }
}
int main() {

    int i,j;
    while(cin>>n>>m) {
        for(i=0; i<n; i++)   cin>>map[i];
        memset(visited,false,sizeof(visited));
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                count_map[i][j].step=INF;
        flag=0;
        bfs();
        if(!flag) {
            printf("God please help our poor hero.\n");
            printf("FINISH\n");
        } else {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",count_map[n-1][m-1].step);
            print_path(count_map[n-1][m-1].pre_dir,n-1,m-1,count_map[n-1][m-1].step);
            printf("FINISH\n");

        }

    }
    return 0;

}
