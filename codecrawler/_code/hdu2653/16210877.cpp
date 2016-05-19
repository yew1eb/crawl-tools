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
int mark[MAX][MAX][MAX];//å¨ä½ç½®i,jå©ä½é­åkæ¯å¦æ è®°
int n,m,t,p;
int dir[4][2]={0,1,0,-1,1,0,-1,0};

struct Node{
    int x,y,time,m;
    Node(){}
    Node(int X,int Y,int Time,int M):x(X),y(Y),time(Time),m(M){}
    bool operator<(const Node &a)const{
        return time>a.time;
    }
}start;

priority_queue<Node>q;
int BFS(int &flag){
    while(!q.empty())q.pop();
    Node next,oq;
    q.push(start);
    mark[start.x][start.y][start.m]=flag;
    while(!q.empty()){
        oq=q.top();
        q.pop();
        if(Map[oq.x][oq.y] == 'L')return oq.time;
        if(oq.time>t)return INF; 
        for(int i=0;i<4;++i){
            next=Node(oq.x+dir[i][0],oq.y+dir[i][1],oq.time+1,oq.m);
            if(next.x<0 || next.y<0 || next.x>=n || next.y>=m)continue;
            if(Map[next.x][next.y] == '#')continue;
            if(Map[next.x][next.y] != '@' && Map[oq.x][oq.y] != '@' && mark[next.x][next.y][next.m] != flag){
                ++next.time;
                q.push(next);
                mark[next.x][next.y][next.m]=flag;
            }
            if(next.m>0 && mark[next.x][next.y][next.m-1] != flag){
                --next.m;
                next.time=oq.time+1;
                q.push(next);
                mark[next.x][next.y][next.m]=flag;
            }
        }
    }
    return INF;
}

int main(){
    int num=0;
    while(cin>>n>>m>>t>>p){
        for(int i=0;i<n;++i)cin>>Map[i];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(Map[i][j] == 'Y')start.x=i,start.y=j;
            }
        }
        start.time=0,start.m=p;
        int temp=BFS(++num);
        cout<<"Case "<<num<<":\n";
        if(temp>t)cout<<"Poor Yifenfei, he has to wait another ten thousand years."<<endl;
        else cout<<"Yes, Yifenfei will kill Lemon at "<<temp<<" sec."<<endl;
    }
    return 0;
}