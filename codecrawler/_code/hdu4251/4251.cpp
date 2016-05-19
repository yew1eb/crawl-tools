#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<cmath>
using namespace std;
#define M 100007

int a[20][M], toleft[20][M], sorted[M], n;
void build( int p, int l, int r )
{
	if( l == r ) return;
	int m = (l+r)>>1, lp = l, rp = m+1, num = 0;

	for( int i = l; i <= r; i++ ){
		if( a[p][i] < sorted[m] ) num++;
	}
	num = m - l + 1 - num;       //用于处理多个中位数，表示放在左边的中位数的个数
	for( int i = l; i <= r; i++ ){
		if( i == l ) toleft[p][i] = 0;
		else toleft[p][i] = toleft[p][i-1];
		if( a[p][i] < sorted[m] ){
			toleft[p][i]++;
			a[p+1][lp++] = a[p][i];
		}
		else if( a[p][i] > sorted[m] ){
			a[p+1][rp++] = a[p][i];
		}
		else if( num > 0 ){   //中位数放在左边
			toleft[p][i]++;
			a[p+1][lp++] = a[p][i];
			num--;
		}
		else a[p+1][rp++] = a[p][i]; //中位数放在右边
	}
	build( p+1, l, m );
	build( p+1, m+1, r );
}

int query( int p, int l, int r, int x, int y, int k )
{
	if( l==r ) return a[p][l];
	int s, ss, newl, newr, newk, m = (l+r)>>1;
	if( l == x ){
		s = 0;
		ss = toleft[p][y];
	}
	else{
		s = toleft[p][x-1];
		ss = toleft[p][y];
	}
	if( k <= ss - s ){
		return query( p+1, l, m, l+s, l+ss-1, k );
	}
	else{
		newl = m + 1 + x - l - s;//相对位置
		newr = m + 1 + y - l - ss;
		newk = k - ( ss - s );
		return query( p+1, m+1, r, newl, newr, newk );
	}
}
int main()
{
	int m, t = 0, x, y, k;
	while( scanf( "%d", &n ) == 1 ){
		printf( "Case %d:\n", ++t );
		for( int i = 1; i <= n; i++ ){
			scanf( "%d", &a[0][i] );
			sorted[i] = a[0][i];
		}
		sort( sorted + 1, sorted + n + 1); //排序用于求中位数
		build( 0, 1, n );
		scanf( "%d", &m );
		while( m-- ){
			scanf( "%d%d", &x, &y );
			k = (y-x)/2 + 1;
			int ans = query( 0, 1, n, x, y, k );
			printf( "%d\n", ans );
		}
	}
}
