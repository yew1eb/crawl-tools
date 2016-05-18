#include "stdio.h"
#include "string.h"
const int maxn = 105;
int h,w,sx,sy,ans;
int xs[][6] = { {0,-1,-1,0,1,1},{0,-1,-1,0,1,1}};
int ys[][6] = { {1,1,0,-1,0,1},{1,0,-1,-1,-1,0}};
char map[maxn][maxn];
int DFS( int x,int y,char ch )
{
	int sum = 1;
	map[x][y] = 'E';
	for( int i = 0; i < 6; i ++ )
	{
		int xx = x + xs[x%2][i];
		int yy = y + ys[x%2][i];
		if( map[xx][yy] == ch )
		{
			sum += DFS(xx,yy,ch);
		}
	}
	return sum;
}
void dfs( int x,int y )
{
	map[x][y] = 'E';
	for( int i = 0; i < 6; i ++ )
	{
		int xx = x + xs[x%2][i];
		int yy = y + ys[x%2][i];
		if( map[xx][yy] != 'E' )
		{
			dfs(xx,yy);
		}
	}
}
int main()
{
	//freopen("data.txt","r",stdin);
	int k;
	while( scanf("%d%d%d%d",&h,&w,&sx,&sy) == 4 )
	{
		memset( map,'E',sizeof(map) );
		for( int i = 1; i <= h; i ++ )
		{
			getchar();
			if( i%2 )	k = w;
			else k = w-1;
			for( int j = 1; j <= k; j ++ )
			{
				scanf("%c",&map[i][j]);
			}
		}
		ans = DFS(sx,sy,map[sx][sy]);          //从起点标记
		if( ans >= 3 )
		{
			for( int i = 1; i <= w; i ++ )		//从顶行标记
			{
				if( map[1][i] != 'E' )
					dfs(1,i);
			}
			for( int i = 2; i <= h; i ++ )
			{
				for( int j = 1; j <= w; j ++ )
				{
					if( map[i][j] != 'E' )
						ans += DFS(i,j,map[i][j]);
				}
			}
		}
		else
			ans = 0;
		printf("%d\n",ans);
	}
	return 0;
}
/*
4 5 4 4
abbbb
abbb
aabcb
aaab
*/