#include<cstdio>
#include<queue>
using namespace std;
#define MAX 22

struct node
{
	int x,y,time;//坐标，以及起点到此点的用时
	bool operator <(const node &N)const//用优先队列，按用时从小到大排序
	{
		return N.time<time;
	}
}st;//开始点

int R,C;//行列
int endx,endy;//目标的坐标
char map[MAX][MAX];
int T[3];//对于三种不同地带的用时

void Input()
{
	int i;
	scanf("%d%d%d",&T[0],&T[1],&T[2]);
	for(i=0;i<R;i++,getchar())
		scanf("%s",map[i]);
	scanf("%d%d%d%d",&st.x,&st.y,&endx,&endy);
	st.time=0;
}

int vis[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

int bfs()
{
	priority_queue<node>q;
	map[st.x][st.y]='@';//走过了的地方我们就标记为石头，不再走
	q.push(st);

	while(!q.empty())
	{
		node pre=q.top();q.pop();
		if(pre.x==endx && pre.y==endy)
		{
			return pre.time;
		}
		for(int i=0;i<4;i++)
		{
			node p;
			p.x=pre.x+vis[i][0];
			p.y=pre.y+vis[i][1];
			p.time=pre.time;
			if(p.x>=0 && p.y >= 0 && p.x < R && p.y < C && map[p.x][p.y]!='@')//对于地图中不是石头的地方访问
			{
				if(map[p.x][p.y]=='T')p.time+=T[2];//这里看看是哪一种地带，
				else if(map[p.x][p.y]=='.')p.time+=T[1];
				else if(map[p.x][p.y]=='#')p.time+=T[0];
				map[p.x][p.y]='@';
				q.push(p);
			}
		}
	}
	return -1;//走不到返回-1
}

int main()
{
	int cas=1;
	while(~scanf("%d%d",&R,&C))
	{
		Input();
		printf("Case %d: %d\n",cas++,bfs());
	}
	return 0;
}