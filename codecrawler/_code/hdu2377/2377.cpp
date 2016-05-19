/* THE PROGRAM IS MADE BY PYY */
/*----------------------------------------------------------------------------//
    Copyright (c) 2011 panyanyany All rights reserved.

    URL   : http://acm.hdu.edu.cn/showproblem.php?pid=2377
    Name  : 2377 Bus Pass

    Date  : Tuesday, January 24, 2012
    Time Stage : 2 hours

    Result: 
5290124	2012-01-24 15:02:29	Accepted	2377
375MS	2692K	2336 B
C++	pyy

5289711	2012-01-24 12:12:48	Wrong Answer	2377
375MS	2692K	2292 B
C++	pyy

5289706	2012-01-24 12:07:45	Wrong Answer	2377
390MS	2692K	2282 B
C++	pyy


Test Data :

Review :
话说这题确实是没有思路，只好参考了大牛的代码，原来可以这样做～
大牛题解：http://blog.csdn.net/popopopolo/article/details/6432852
//----------------------------------------------------------------------------*/

#include <cstdio>
#include <CSTRING>

#include <queue>

using namespace std ;

#define MEM(a, v)		memset (a, v, sizeof (a))	// a for address, v for value

#define INF		(-1)
#define MAXN	10000

struct EDGE {
	int v, w, next ;
} ;

bool	used[MAXN] ;

int		nz, nr, edgeCnt ;
int		first[MAXN], max_d[MAXN], dist[MAXN] ;
EDGE	edge[20*MAXN] ;

void add (const int u, const int v, const int w)
{
	edge[edgeCnt].v = v ;
	edge[edgeCnt].w = w ;
	edge[edgeCnt].next = first[u] ;
	first[u] = edgeCnt++ ;
}

void spfa (const int beg)
{
	int i, d, u, v ;
	queue<int>	q ;

	MEM (dist, INF) ;
	MEM (used, 0) ;

	// 这里不加就WA，考验思维缜密度，搞程序的一定要细心啊！
// 真心不明白为什么要加这里，求解释！
	if (max_d[beg] == INF)
		max_d[beg] = 1 ;

	dist[beg] = 1 ;
	used[beg] = 1 ;
	q.push (beg) ;

	while (!q.empty ())
	{
		u = q.front () ;
		q.pop () ;
		used[u] = 0 ;

		for (i = first[u] ; i != -1 ; i = edge[i].next)
		{
			d = dist[u] + edge[i].w ;
			v = edge[i].v ;
			if (dist[v] == INF || dist[v] > d)
			{
				dist[v] = d ;
				if (max_d[v] == INF || max_d[v] < dist[v])
					max_d[v] = dist[v] ;
				if (!used[v])
				{
					q.push (v) ;
					used[v] = 1 ;
				}
			}
		}
	}
}

int main ()
{
	int i, j ;
	int u, v, w ;
	int tcase, mz, minV, id ;
	while (scanf ("%d", &tcase) != EOF)
	{
		while (tcase--)
		{
			MEM (first, -1) ;
			MEM (max_d, INF) ;
			edgeCnt = 0 ;
			
			scanf ("%d%d", &nz, &nr) ;
			for (i = 0 ; i < nz ; ++i)
			{
				scanf ("%d%d", &u, &mz) ;
				while (mz--)
				{
					scanf ("%d", &v) ;
					add (v, u, 1) ;
					add (u, v, 1) ;
				}
			}
			
			while (nr--)
			{
				scanf ("%d", &v) ;
				for (i = 0 ; i < v ; ++i)
				{
					scanf ("%d", &u) ;
					spfa (u) ;
				}
			}
			minV = INF ;
			id = -1 ;
			for (i = 0 ; i < MAXN ; ++i)
				if (max_d[i] != INF)
				{
					if (minV == INF || minV > max_d[i])
					{
						minV = max_d[i] ;
						id = i ;
					}
				}
			printf ("%d %d\n", minV, id) ;
		}
	}
	return 0 ;
}