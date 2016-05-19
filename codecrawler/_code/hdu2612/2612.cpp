#include"stdio.h"
#include"queue"
#include"string.h"
using namespace std;
int dir[4][2]={1,0, -1,0, 0,1, 0,-1};


int ori[211][211];
int map[211][211];
int x_s1,y_s1;
int x_s2,y_s2;
int n,m;


int ans[211][211];


struct node
{
	int x,y;
	int step;
};


int min(int a,int b)
{
	return a>b?b:a;
}
int judge(int x,int y)
{
	if(x<0 || x>=n || y<0 || y>=m)	return 1;
	if(map[x][y]==1)	return 1;
	return 0;
}


void BFS(int x,int y)
{
	queue<node>q;
	node cur,next;
	int i;


	cur.x=x;
	cur.y=y;
	cur.step=0;


	map[cur.x][cur.y]=1;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		if(ori[cur.x][cur.y]==2)	ans[cur.x][cur.y]+=cur.step;
		for(i=0;i<4;i++)
		{
			next.x=cur.x+dir[i][0];
			next.y=cur.y+dir[i][1];


			if(judge(next.x,next.y))	continue;
			next.step=cur.step+1;
			map[next.x][next.y]=1;
			q.push(next);
		}
	}
}


int main()
{
	int i,l;
	char str[211];
	int Ans;


	while(scanf("%d%d",&n,&m)!=-1)
	{
		memset(ori,0,sizeof(ori));
		memset(ans,0,sizeof(ans));
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			for(l=0;str[l];l++)
			{
				if(str[l]=='Y')		{x_s1=i;y_s1=l;}
				else if(str[l]=='M'){x_s2=i;y_s2=l;}
				else if(str[l]=='.')ori[i][l]=0;
				else if(str[l]=='#')ori[i][l]=1;
				else if(str[l]=='@')ori[i][l]=2;
			}
		}


		for(i=0;i<n;i++)
		for(l=0;l<m;l++)
			map[i][l]=ori[i][l];
		BFS(x_s1,y_s1);


		for(i=0;i<n;i++)
		for(l=0;l<m;l++)
			map[i][l]=ori[i][l];
		BFS(x_s2,y_s2);


		Ans=11111111;
		for(i=0;i<n;i++)
		{
			for(l=0;l<m;l++)
			{
				if(ans[i][l])
				{
					Ans=min(Ans,ans[i][l]);
				}
			}
		}
		printf("%d\n",Ans*11);
	}
	return 0;
}