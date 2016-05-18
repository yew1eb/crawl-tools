#include<stdio.h>
#include<queue>
using namespace std;
int sx,sy,ex,ey;
int h[4]={1,-1,0,0};
int g[4]={0,0,1,-1};
int dir[8][8][5];
bool visit[7][7];
struct point{
	int x;
	int y;
	int time;
	int pre;
	char dir;
}que[1000];
void limdir(int a,int b,int c,int d){
	int i;
	if(a==c){
		for(i=b+1;i<=d;i++){
			dir[c][i][0]=1;
			dir[c+1][i][1]=1;
		}
	}
	else if(b==d){
		for(i=a+1;i<=c;i++){
			dir[i][b][2]=1;
			dir[i][b+1][3]=1;
		}
	}
}
char cal(int i){
	if(i==0)
		return 'S';
	else if(i==1)
		return 'N';
	else if(i==2)
		return 'E';
	else
		return 'W';
}
void print(int tem){
	if(que[tem].pre!=-1){
		print(que[tem].pre);
		printf("%c",que[tem].dir);
	}
}
int bfs(){
	int front=0,rear=0,xx,yy,i,j,k;
	struct point cur;
	cur.x=sx;
	cur.y=sy;
	cur.time=0;
	cur.pre=-1;
	que[rear++]=cur;

	while(front<rear){
		struct point tem;
		tem=que[front];

		for(i=0;i<4;i++){
			xx=tem.x+h[i];
			yy=tem.y+g[i];

			if(xx<=0 || xx>6 || yy<=0 || yy>6)
				continue;
			if(dir[tem.x][tem.y][i])
				continue;
			if(visit[xx][yy])
				continue;

			struct point pp;
			pp.x=xx;pp.y=yy;pp.time=tem.time+1;
			pp.pre=front;pp.dir=cal(i);
			que[rear]=pp;
			visit[xx][yy]=1;
			if(xx==ex && yy==ey){
				print(rear);
				printf("\n");
				return 1;
			}
			rear++;
		}
		front++;
	}
	return 0;
}

int main(){
	int i,j,k,a,b,c,d;
	while(scanf("%d %d",&sy,&sx) && !(sx==0 && sy==0)){
		scanf("%d %d",&ey,&ex);
		memset(dir,0,sizeof(dir));
		memset(visit,0,sizeof(visit));
		for(i=1;i<=3;i++){
			scanf("%d %d %d %d",&b,&a,&d,&c);
			limdir(a,b,c,d);
		}
		visit[sx][sy]=1;
		bfs();
	}
}