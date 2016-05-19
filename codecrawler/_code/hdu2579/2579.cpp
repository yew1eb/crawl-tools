#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<algorithm>
#define N 105
using namespace std;
char map[N][N];
int step[N][N][10];//多加一维，记录(time%k)
int r,c,k,x_s,y_s,x_e,y_e;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
struct node
{
	int x,y,mod;
};
int BFS()
{
	int i;
	queue<node>q;
	node now,next;
	now.x=x_s;
	now.y=y_s;
	now.mod=0;
	memset(step,-1,sizeof(step));
	step[now.x][now.y][now.mod]=0;
	q.push(now);
	while(!q.empty()){
		now=q.front();
		q.pop();
		if(now.x==x_e && now.y==y_e) return step[now.x][now.y][now.mod];
		for(i=0;i<4;i++){
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];
			next.mod=(now.mod+1)%k;
			if(next.x<0 || next.x>=r || next.y<0 ||next.y>=c) continue;
			if(step[next.x][next.y][next.mod]!=-1)            continue;
			if(map[next.x][next.y]=='#' && next.mod!=0)       continue;
			step[next.x][next.y][next.mod]=step[now.x][now.y][now.mod]+1;
			q.push(next);
		}
	}
	return -1;
}
int main()
{
	int T,i,j,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&r,&c,&k);
		for(i=0;i<r;i++){
			scanf("%s",map[i]);
			for(j=0;map[i][j];j++){
				if(map[i][j]=='Y'){
					x_s=i;y_s=j;map[i][j]='.';
				}
				if(map[i][j]=='G'){
					x_e=i;y_e=j;map[i][j]='.';
				}
			}
		}
		ans=BFS();
		if(ans==-1) printf("Please give me another chance!\n");
		else printf("%d\n",ans);
	}
	return 0;
}