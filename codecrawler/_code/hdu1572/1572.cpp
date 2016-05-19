#include <cstdio>
#include <cstring>
#include <cstdio>
using namespace std;

int map[35][35], N, K, obj[35], RK;

void DFS( int pos, int step, int dis, int &ans )
{
	if( step== RK )
	{
		ans= ans< dis? ans: dis;
	}
	for( int i= 1; i< N; ++i )
	{
		if( obj[i] ) // 如果有人要求到该栈而又没有开去过
		{
			obj[i]= 0;
			DFS( i, step+ 1, dis+ map[pos][i], ans );
			obj[i]= 1;
		}
	}
}

int main()
{
	while( scanf( "%d", &N ), N )
	{
		int ans= 0x7fffffff;
		RK= 0;
		memset( map, 0, sizeof( map ) );
		memset( obj, 0, sizeof( obj ) );
		for( int i= 0; i< N; ++i )
		{
			for( int j= 0; j< N; ++j )
			{
				scanf( "%d", &map[i][j] );
			}
		}
		scanf( "%d", &K );
		for( int i= 1; i<= K; ++i )
		{
			int c;
			scanf( "%d", &c );
			if( obj[c]== 0 )
			{
				obj[c]= 1;
				RK++;// 用来记录总共有多少不重复的站
			}
		}
		DFS( 0, 0, 0, ans );
		printf( "%d\n", ans );
	}
	return 0;
}