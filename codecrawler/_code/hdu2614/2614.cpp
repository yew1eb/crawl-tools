/* THE PROGRAM IS MADE BY PYY */
/*----------------------------------------------------------------------------//
Copyright (c) 2011 panyanyany All rights reserved.

URL   : http://acm.hdu.edu.cn/showproblem.php?pid=2614
Name  : 2614 Beat

Date  : Saturday, August 13, 2011
Time Stage : 1 hours around

Result:
4404951	2011-08-13 14:52:37 Accepted 2614 31MS 192K 1185 B C++ pyy


Test Data:

Review:
一开始没用used标记已做完的工作，结果超时了……
//----------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define infinity	0x7f7f7f7f
#define minus_inf	0x80808080

#define MAXSIZE 16

int n, most ;
int time[MAXSIZE][MAXSIZE], used[MAXSIZE] ;

void dfs (int cur, int t, int cnt)
{
	most = max (most, cnt) ; // 这里的比较要随时进行
	if (cnt == n)
		return ;

	int i ;
	for (i = 1 ; i < n ; ++i)
	{
		if (!used[i] && time[cur][i] >= t)
		{
			used[i] = 1 ;
			dfs (i, time[cur][i], cnt + 1) ;
			used[i] = 0 ;
		}
	}
}

int main ()
{
	int i, j ;
	while (scanf ("%d", &n) != EOF)
	{
		most = 0 ;
		memset (used, 0, sizeof (used)) ;
		for (i = 0 ; i < n ; ++i)
		{
			for (j = 0 ; j < n ; ++j)
				scanf ("%d", &time[i][j]) ;
		}
		used[0] = 1 ;
		dfs (0, 0, 1) ;
		printf ("%d\n", most) ;
	}
	return 0 ;
}