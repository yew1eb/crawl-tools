#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
#include<string>
#define N 20000000
using namespace std;
int n,m,ss;//ss用于存最小时间
int a[105][105][30];//状态数组，第3维是带的炸药个数，前2个是坐标。
string map[105];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//用于变换坐标
struct node
{
	int x,y;
	int k,time;//k是携带的炸药包，time是到这里所花的时间
	//重载<运算符，用于优先队列的实现
	friend bool operator < (const node a,const node b)
	{
		return a.time>b.time;
	}
}w,v;
priority_queue<node> q;
bool check(int x,int y)//边境检查
{
	if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]!='*')
		return 1;
	return 0;
}
void bfs()
{
	memset(a,-1,sizeof(a));
	for(int i=0;i<n;i++)//找出所有的门并加入队列
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]=='#')
			{
				w.x=i;w.y=j;
				w.time=0;w.k=0;
				map[i][j]='*';
				q.push(w);
			}
			else if(map[i][j]>='A'&&map[i][j]<='Z')
			{
				w.x=i;w.y=j;
				w.time=0;
				w.k=map[i][j]-'A'+1;
				map[i][j]='*';
				q.push(w);
			}
		}
	}
	while(!q.empty())
	{
		v=q.top();
		q.pop();
		for(int i=0;i<4;i++)
		{
			w.x=v.x+dir[i][0];
			w.y=v.y+dir[i][1];
			if(!check(w.x,w.y))
				continue;
			if(map[w.x][w.y]=='.')//如果是路，直接走过去
			{
				w.k=v.k;
				//如果携带w.k个炸药在x,y点的状态没有检查过
				//或者以前的走法没有现在的走法优
				if(a[w.x][w.y][w.k]==-1||a[w.x][w.y][w.k]>v.time)
				{
					w.time=v.time;
					a[w.x][w.y][w.k]=w.time;
					q.push(w);
				}
			}
			else if(map[w.x][w.y]>='1'&&map[w.x][w.y]<='9')
			{
				//炸这个石头
				if(v.k>0&&(a[w.x][w.y][v.k-1]==-1||a[w.x][w.y][v.k-1]>v.time))
				{
					w.k=v.k-1;
					w.time=v.time;
					a[w.x][w.y][w.k]=w.time;
					q.push(w);
				}
				//不炸这个石头
				if(a[w.x][w.y][v.k]==-1||a[w.x][w.y][v.k]>v.time+map[w.x][w.y]-'0')
				{
					w.k=v.k;
					w.time=v.time+map[w.x][w.y]-'0';
					a[w.x][w.y][w.k]=w.time;
					q.push(w);
				}
			}
			else if(map[w.x][w.y]=='$'&&v.time<ss)
			{
				ss=v.time;
			}
		}
	}
}
int main()
{
	while(getline(cin,map[0])&&map[0][0]!='-')
	{
		int i=1;
		while(getline(cin,map[i])&&map[i].size()!=0)
			i++;
		n=i;
		m=map[0].size();
        ss=N;
		bfs();
		if(ss==N)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",ss);
	}
	return 0;
}