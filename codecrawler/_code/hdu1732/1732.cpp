#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 8;
int n,m,pos;
char map[maxn][maxn];
int dis[maxn][maxn];
bool vis[maxn][maxn][maxn][maxn][maxn][maxn][maxn][maxn];  //三个箱子位置 + 人位置 
int xs[] = {0,1,0,-1};
int ys[] = {1,0,-1,0};
struct node
{
	int x[3],y[3],step;
	int man_x,man_y;
	bool check( int k )
	{
		if( x[k] >= 0 && x[k] < n && y[k] >= 0 && y[k] < m && map[x[k]][y[k]] != '#' )
			return true;
		else
			return false;
	}
	bool operator < ( const node &k ) const
	{
		return step > k.step;
	}
};
struct Node
{
	int x,y,g;
	bool check()
	{
		if( x >= 0 && x < n && y >= 0 && y < m &&  map[x][y] != '#' )  //小BFS检查边界
			return true;
		else
			return false;
	}
};

void BFS( node v )	//小BFS 算人到每个点的距离
{
	Node cur,cnt;	
	cur.x = v.man_x;
	cur.y = v.man_y;
	cur.g = 0;
	bool mark[maxn][maxn] = {0};
	memset(dis,-1,sizeof(dis));
	mark[cur.x][cur.y] = true;
	dis[cur.x][cur.y] = 0;
	queue<Node>que;
	que.push(cur);
	while ( !que.empty() )
	{
		cur = que.front(); que.pop();
		for( int i = 0; i < 4; i ++ )
		{
			cnt.x = cur.x + xs[i];
			cnt.y = cur.y + ys[i];
			if( cnt.check() && !mark[cnt.x][cnt.y] && !( ( cnt.x == v.x[0] && cnt.y == v.y[0] )||( cnt.x == v.x[1] && cnt.y == v.y[1] )||( cnt.x == v.x[2] && cnt.y == v.y[2] ) ) )
			{
				mark[cnt.x][cnt.y] = true;
				cnt.g = cur.g + 1;
				dis[cnt.x][cnt.y] = cnt.g;
				que.push( cnt );
			}
		}
	}
}

int BFS_Box( node start )
{
	node cur,cnt;
	int mx,my;
	priority_queue<node>que;
	memset( vis,0,sizeof(vis) );
	que.push( start );
	while ( !que.empty() )
	{
		cur = que.top(); que.pop();
		if( map[cur.x[0]][cur.y[0]] == '@' &&  map[cur.x[1]][cur.y[1]] == '@' && map[cur.x[2]][cur.y[2]] == '@' )
			return cur.step;
		if( vis[cur.x[0]][cur.y[0]][cur.x[1]][cur.y[1]][cur.x[2]][cur.y[2]][cur.man_x][cur.man_y] )
			continue;
		vis[cur.x[0]][cur.y[0]][cur.x[1]][cur.y[1]][cur.x[2]][cur.y[2]][cur.man_x][cur.man_y] = true;
		BFS( cur );
		for ( int k = 0; k < 3; k ++ )		//三个箱子各推次
		{
			for( int i = 0; i < 4; i ++ )
			{
				cnt = cur;
				cnt.x[k] += xs[i];    mx = cur.x[k] - xs[i];
				cnt.y[k] += ys[i];    my = cur.y[k] - ys[i];
				if(  cnt.check(k) && mx >= 0 && mx < n && my >= 0 && my < m && dis[mx][my] != -1 )		//判断边界
				{    
					if( !(( cnt.x[k] == cur.x[0] && cnt.y[k] == cur.y[0] )||( cnt.x[k] == cur.x[1] && cnt.y[k] == cur.y[1] )||( cnt.x[k] == cur.x[2] && cnt.y[k] == cur.y[2] ) ) )  //判断所推向位置是否为箱子
					{                     
						cnt.step = cur.step + dis[mx][my] + 1;
						cnt.man_x = cur.x[k]; cnt.man_y = cur.y[k];
						que.push(cnt);
					}
				}
			}
		}

	}
	return -1;
}

int main()
{
	//freopen("data.txt","r",stdin);
	int sx,sy;    
	while( scanf("%d%d",&n,&m) != EOF )
	{
		node start;
		int k = 0;
		for( int i = 0; i < n; i ++ )
		{
			getchar();
			for ( int j = 0; j < m; j ++ )
			{
				scanf("%c",&map[i][j]);
				if( map[i][j] == '*' )
				{
					start.x[k] = i; start.y[k] = j;
					map[i][j] = '.';
					k++;
				}
				if( map[i][j] == 'X' )
				{
					map[i][j] = '.';
					start.man_x = i,start.man_y = j;
				}
			}
		}
		start.step = 0;
		printf("%d\n",BFS_Box(start) );
	}
	return 0;
}