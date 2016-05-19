#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std ;
#define INT __int64
INT x , y ;
INT exgcd( INT a , INT b ,INT &x , INT &y ) 
{
	if( b == 0 )
	{
		x = 1 ;
		y = 0 ;
		return a ;
	}
	INT r = exgcd( b , a % b , x , y ) ;
	INT t = x ;
	x = y ;
	y = t - a / b * y ;
	return r ;
}

int main()
{
	int Case ;
	INT m , n ;
	cin >> Case ;
	while( Case-- )
	{
		scanf( "%I64d/%I64d" ,&m , &n );
		INT d = exgcd( m , n , x , y) ;
		if( d != 1 )
		{
			cout << m / d << "/" << n/d << endl ;
			continue ;
		}	
		if( m == 1 )
		{
			cout << "1/" << n - 1 << endl ;
			continue ;
		}
		INT x1 = ( x + n ) % n ;
		INT y1 = ( -y + m ) % m;
		INT x2 = ( -x + n ) % n ;
		INT y2 = ( y + m ) % m ;
		if( x1 > x2 )
			printf( "%I64d/%I64d\n" , y1 , x1 ) ;
		else
				printf( "%I64d/%I64d\n" ,  y2 , x2 ) ;
	}
	return 0 ;
} 	