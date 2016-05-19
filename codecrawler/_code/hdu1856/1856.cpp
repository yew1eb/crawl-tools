/* THE PROGRAM IS MADE BY PYY */
/*----------------------------------------------------------------------------//
	Copyright (c) 2011 panyanyany All rights reserved.

	URL   : http://acm.hdu.edu.cn/showproblem.php?pid=1856
	Name  : 1856 More is better

	Date  : Monday, August 29, 2011
	Time Stage : half hour

	Result:
4512304	2011-08-29 19:39:07	Accepted	1856
265MS	78584K	1213 B
C++	pyy

4512286	2011-08-29 19:37:01	Wrong Answer	1856
265MS	78584K	1213 B
C++	pyy


Test Data:

Review:
其实也挺简单的，只不过数据有点大，以及res要初始化
为1，因为最少都有一个boy，所以当n=0的时候，res就输出1
//----------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

#define MAXSIZE 10000009

int n, res ;
typedef struct tagNODE {
	int cnt, prn ;
} NODE ;

NODE ufSet[MAXSIZE] ;

int find (int x)
{
	int tmp ;
	if (ufSet[x].prn != x)
		ufSet[x].prn = find (ufSet[x].prn) ;
	return ufSet[x].prn ;
}

void merge (int px, int py)
{
	ufSet[py].prn = px ;
	ufSet[px].cnt += ufSet[py].cnt ;
	ufSet[py].cnt = 1 ;

	res = max (res, ufSet[px].cnt) ;
}

int main ()
{
	int i, j ;
	int x, y, px, py ;
	while (scanf ("%d", &n) != EOF)
	{
		res = 1 ;
		for (i = 1 ; i < MAXSIZE ; ++i)
		{
			ufSet[i].prn = i ;
			ufSet[i].cnt = 1 ;
		}
		for (i = 0 ; i < n ; ++i)
		{
			scanf ("%d%d", &x, &y) ;
			px = find (x) ; py = find (y) ;
			if (px != py)
				merge (px, py) ;
		}
		printf ("%d\n", res) ;
	}
	return 0 ;
}