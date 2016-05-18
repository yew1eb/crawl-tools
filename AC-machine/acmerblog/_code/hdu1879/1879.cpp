/* THE PROGRAM IS MADE BY PYY */
/*----------------------------------------------------------------------------//
    Copyright (c) 2012 panyanyany All rights reserved.

    URL   : http://acm.hdu.edu.cn/showproblem.php?pid=1879
    Name  : 1879 继续畅通工程

    Date  : Sunday, February 05, 2012
    Time Stage : half an hour

    Result: 
5317574	2012-02-05 14:27:17	Accepted	1879
187MS	212K	1827 B
C++	pyy

5317518	2012-02-05 14:19:53	Runtime Error
(ACCESS_VIOLATION)	1879
0MS	240K	1884 B
C++	pyy


Test Data :

Review :
直接套模版，结果犯了个小错误……
//----------------------------------------------------------------------------*/

#include <cstdio>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
using namespace std ;

#define MEM(a, v)		memset (a, v, sizeof (a))	// a for address, v for value
#define max(x, y)		((x) > (y) ? (x) : (y))
#define min(x, y)		((x) < (y) ? (x) : (y))

#define INF		(0x3f3f3f3f)
#define MAXN	(103)
#define MAXE	(MAXN*MAXN)

#define DEBUG	/##/

int		n, m ;
int		used[MAXN], dist[MAXN] ;
int		map[MAXN][MAXN] ;

int Prim ()
{
	int i, j, iMinPath, MinPath, sum ;
	MEM (used, 0) ;

	for (i = 1 ; i <= n ; ++i)
		dist[i] = map[1][i] ;

//	dist[0] = INF ;
	used[1] = true ;
	sum = 0 ;

	// 一开始的时候是 i<=n ，结果 sum 一直都大于 INF，因为多运行的那一次
	// 已经没有路可走了，所以 MinPath 就为 INF ，sum 于是就糊里糊涂地加上了……
	for (i = 1 ; i <= n-1 ; ++i)
	{
		MinPath = INF ;
		for (j = 1 ; j <= n ; ++j)
			if (!used[j] && dist[j] < MinPath)
			{
				MinPath = dist[j] ;
				iMinPath = j ;
			}

		used[iMinPath] = true ;
		sum += MinPath ;

		for (j = 1 ; j <= n ; ++j)
			if (!used[j] && dist[j] > map[iMinPath][j])
				dist[j] = map[iMinPath][j] ;
	}
	return sum ;
}

int main ()
{
	int i ;
	int x, y, c, b ;
	while (scanf ("%d", &n), n)
	{
		MEM (map, INF) ;
		m = n*(n-1)/2 ;
		for (i = 1 ; i <= m ; ++i)
		{
			scanf ("%d%d%d%d", &x, &y, &c, &b) ;
			if (b)
				c = 0 ;
			map[x][y] = map[y][x] = min(map[x][y], c) ;
		}
		printf ("%d\n", Prim()) ;
	}
	return 0 ;
}