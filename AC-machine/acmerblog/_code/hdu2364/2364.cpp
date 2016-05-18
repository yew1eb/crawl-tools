#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=80+10;
char Map[MAX][MAX];
int mark[MAX][MAX][5];//到达i,j是以方向k到达的是否标记
int t,n,m;
int dir[4][2]={0,1,1,0,0,-1,-1,0};

struct Node{
    int x,y,time,dir;
    Node(){}
    Node(int X,int Y,int Time,int Dir):x(X),y(Y),time(Time),dir(Dir){}
}start;

int BFS(int flag){
    if(start.x == 0 || start.y == 0 ||start.x == n-1 || start.y == m-1)return 0;
    queue<Node>q;
    Node oq,next;
    q.push(start);
    mark[start.x][start.y][0]=mark[start.x][start.y][1]=flag;
    mark[start.x][start.y][2]=mark[start.x][start.y][3]=flag;
    while(!q.empty()){
        oq=q.front();
        q.pop();
        bool f=true;//标记是否只能直走
        for(int i=0;i<4;++i){
            if(i%2 == oq.dir%2)continue;
            next=Node(oq.x+dir[i][0],oq.y+dir[i][1],oq.time+1,i);
            if(next.x<0 || next.y<0 || next.x>=n || next.y>=m)continue;
            if(Map[next.x][next.y] == '#')continue;
            f=false;//左右可以走(无论以前是否走过) 
            if(mark[next.x][next.y][i] == flag)continue;
            mark[next.x][next.y][i]=flag;
            if(next.x == 0 || next.y == 0 || next.x == n-1 || next.y == m-1)return next.time;
            q.push(next);
        }
        if(f){//只能直走 
            int i=oq.dir;
            next=Node(oq.x+dir[i][0],oq.y+dir[i][1],oq.time+1,i);
            if(next.x<0 || next.y<0 || next.x>=n || next.y>=m)continue;
            if(Map[next.x][next.y] == '#' || mark[next.x][next.y][i] == flag)continue;
            mark[next.x][next.y][i]=flag;
            if(next.x == 0 || next.y == 0 || next.x == n-1 || next.y == m-1)return next.time;
            q.push(next);
        }
    }
    return -1;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;++i)cin>>Map[i];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(Map[i][j] == '@')start.x=i,start.y=j;
            }
        }
        start.time=0,start.dir=-1;
        cout<<BFS(t+1)<<endl;
    }
    return 0;
}