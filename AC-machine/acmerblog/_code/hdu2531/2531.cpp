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

const int MAX=100+10;
char Map[MAX][MAX];
int mark[MAX][MAX];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int n,m,size;

struct Node{
	int x[21],y[21],time,A,B;
	Node(){}
	Node(int X,int Y,int i){
		x[i]=X;
		y[i]=Y;
	}
}start;

int BFS(int &flag){
	int j;
	queue<Node>q;
	Node oq,next;
	q.push(start);
	mark[start.x[0]][start.y[0]]=flag;
	while(!q.empty()){
		oq=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			for(j=0;j<size;++j){
				next=Node(oq.x[j]+dir[i][0],oq.y[j]+dir[i][1],j);
				if(next.x[j]<0 || next.y[j]<0 || next.x[j]>=n || next.y[j]>=m)break;
				if(Map[next.x[j]][next.y[j]] == 'O')break;
			}
			if(j != size)continue;
			if(mark[next.x[0]][next.y[0]] == flag)continue;
			next.time=oq.time+1;
			mark[next.x[0]][next.y[0]]=flag;
			for(j=0;j<size;++j)
				if(Map[next.x[j]][next.y[j]] == 'Q')return next.time;
			q.push(next);
		}
	}
	return -1;
}

int main(){
	int num=0;
	while(cin>>n>>m,n+m){
		size=0;
		for(int i=0;i<n;++i)cin>>Map[i];
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(Map[i][j] == 'D'){
					start.x[size]=i;
					start.y[size++]=j;
				}
			}
		}
		start.time=0;
		int temp=BFS(++num);
		if(temp == -1)cout<<"Impossible"<<endl;
		else cout<<temp<<endl;
	}
	return 0;
}