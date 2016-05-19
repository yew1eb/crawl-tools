#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"queue"
#define N 5001
using namespace std;

int n,m,cost;
char map[N][N];
char flag[N][N];

int s_x,s_y,e_x,e_y;
int dir[4][2]={1,0, -1,0, 0,1, 0,-1};
struct A
{
	int x,y;
}hehe[555];
int tot;

struct node
{
	int x,y;
	int cost;
	friend bool operator<(node n1,node n2)
	{
		return n2.cost<n1.cost;
	}
};

int BFS()
{
	priority_queue<node>q;
	node now,next;
	int i,j;

	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
		flag[i][j]=0;
	now.x=s_x;
	now.y=s_y;
	now.cost=0;
	q.push(now);
	flag[now.x][now.y]=1;
	while(!q.empty())
	{
		now=q.top();
		q.pop();
		if(now.x==e_x && now.y==e_y)	return now.cost-cost;
		for(i=0;i<4;i++)
		{
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];

			if(next.x<0 || next.x>=n || next.y<0 || next.y>=m)	continue;
			if(map[next.x][next.y]=='#')continue;
			if(flag[next.x][next.y])	continue;

			if(map[next.x][next.y]=='*')
			{
				next.cost=now.cost+cost;
				q.push(next);
				flag[next.x][next.y]=1;
			}
			else if(map[next.x][next.y]=='P')
			{
				if(flag[next.x][next.y])	continue;
				int l;
				for(l=0;l<tot;l++)
				{
					next.x=hehe[l].x;
					next.y=hehe[l].y;
					next.cost=now.cost;
					q.push(next);
					flag[next.x][next.y]=1;
				}
			}
		}
	}
	return -1;
}
int main()
{
	int i,l;
	int ans;
	while(scanf("%d%d%d",&n,&m,&cost)!=-1)
	{
		tot=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",&map[i]);
			for(l=0;map[i][l];l++)
			{
				if(map[i][l]=='Y')		{s_x=i;s_y=l;}
				else if(map[i][l]=='C')	{e_x=i;e_y=l;map[i][l]='*';}
				else if(map[i][l]=='P')	{hehe[tot].x=i;hehe[tot].y=l;tot++;}
			}
		}

		ans=BFS();
		if(ans==-1)	printf("Damn teoy!\n");
		else		printf("%d\n",ans);
	}
	return 0;
}