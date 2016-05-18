#include<stdio.h>
int num[30005],e[9000000],n,m,c;
inline void swap( int i,int j )
{
	e[i] ^= e[j] ^= e[i] ^= e[j];
}
void up( int c )
{
	if( c > 1 )
		if( e[c] > e[c/2] )
			swap( c,c/2 ),up( c / 2 );
}
void insert( int x )
{
	e[++c] = x;
	up( c );
}
inline void down( int q )
{
	int p = q * 2;
	if( p <= c )
	{
		if( p + 1 <= c )
			p = e[p] > e[p+1] ? p : ( p + 1 );
		if( e[p] > e[q] )
			swap( p,q ),down( p );
	}
}
int pop(  )
{
	int x = e[1];
	swap( 1,c-- );
	down( 1 );
	return x;
}
int main(  )
{
	while( scanf( "%d%d",&n,&m ) != EOF )
	{
		c = 0;
		for( int i = 0; i < n; ++i )
			scanf( "%d",&num[i] );
		for( int i = 0; i < n - 1; ++i )
			for( int j = i + 1; j < n; ++j )
				insert( num[i] + num[j] );
		for( int i = 0; i < m; ++i )
			printf( i == 0 ? "%d" : " %d",pop(  ) );
		puts( "" );
	}
	return 0;
}