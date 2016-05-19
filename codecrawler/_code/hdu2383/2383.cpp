#include<stdio.h>
#include<string.h>
int map[23][23];
int visit[23][23];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int row,line;
int vp, vs, vt;
int starti,startj,endi,endj;
struct queue
{
	int x,y;
	int va;
};
void Priqueue(int h,int t,struct queue q[])
{
	struct queue b;
	int s = t;
	b = q[t];
	while(b.va<q[--s].va)
		q[s+1] = q[s];
	q[s+1] = b;
}
int BFS()
{
	struct queue queue[19999];
	int tail,head,i;
	memset(visit,0,sizeof(visit));
	tail = head = 0;
	queue[tail].x = starti;
	queue[tail].y = startj;
	queue[tail++].va = 0;
	while(head<tail)
	{
		int X = queue[head].x;
		int Y = queue[head].y;
		int V = queue[head++].va;
		
		if(X==endi && Y==endj)
			return V;
		for(i=0;i<4;i++)
			if(map[X+dir[i][0]][Y+dir[i][1]] && !visit[X+dir[i][0]][Y+dir[i][1]])
			{
				visit[X][Y] = 1;
				queue[tail].x = X+dir[i][0];
				queue[tail].y = Y+dir[i][1];
				queue[tail++].va = V+map[X+dir[i][0]][Y+dir[i][1]];
				Priqueue(head,tail-1,queue);
			}
	}
	return -1;
}
int main()
{
	int i,j,ca=1;
	char ch[30];
	while(scanf("%d%d",&row,&line)!=EOF)
	{
		scanf("%d%d%d",&vp,&vs,&vt);
		memset(map,0,sizeof(map));
		for(i=1;i<=row;i++)
		{
			scanf("%s",ch+1);
			for(j=1;j<=line;j++)
			{
				if(ch[j]=='#')
					map[i][j] = vp;
				else if(ch[j]=='.')
					map[i][j] = vs;
				else if(ch[j]=='T')
					map[i][j] = vt;
			}
		}
		scanf("%d%d%d%d",&starti,&startj,&endi,&endj);
		starti++,startj++,endi++,endj++;
		printf("Case %d: %d\n",ca++,BFS());
		
	}
	return 0;

}