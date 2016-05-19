#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define EPS 1e-10
#define MAX(a,b) ((a)>(b)?(a):(b))
const double pi = acos( -1.0 );
using namespace std;

int tc, ren[105], tr;
double SqS2( double x, double y )
{
    return sqrt( x*x + y*y );
}
struct CO
{
    char c[12];
    double x[5];
    int en, r;
} co[105];
struct MA
{
    double m[4][4];
} sa;
void Mul( MA &x, double p[4] )
{
    int i, j;
    double t[4];
    for( i = 0; i < 4; i ++ )
        t[i] = p[i];
    for( i = 0; i < 4; i ++ )
    {
        p[i] = 0;
        for( j = 0; j < 4; j ++ )
            p[i] += x.m[i][j] * t[j];
    }
}
MA Mul( MA &x, MA &y )
{
    MA a;
    int i, j, k;
    for( i = 0; i < 4; i ++ )
        for( j = 0; j < 4; j ++ )
        {
            a.m[i][j] = 0;
            for( k = 0; k < 4; k ++ )
                a.m[i][j] += x.m[i][k] * y.m[k][j];
        }
    return a;
}
MA Mi( MA &x, int m )
{
    int i, j;
    MA a;
    if( m == 0 )
    {
        for( i = 0; i < 4; i ++ )
            for( j = 0; j < 4; j ++ )
                a.m[i][j] = sa.m[i][j];
        return a;
    }
    if( m == 1 )
    {
        for( i = 0; i < 4; i ++ )
            for( j = 0; j < 4; j ++ )
                a.m[i][j] = x.m[i][j];
        return a;
    }
    a = Mi( x, m>>1 );
    a = Mul( a, a );
    if( m & 1 )
        a = Mul( a, x );
    return a;
}
MA GetM( int l, int r )
{
    int i, j, k;
    double t, t1;
    MA a, b, mz, mx, mz0;
    for( i = 0; i < 4; i ++ )
        for( j = 0; j < 4; j ++ )
            a.m[i][j] = sa.m[i][j];
    for( i = l; i <= r; i ++ )
    {
        if( co[i].c[0] == 'r' && co[i].c[1] == 'e' )  //re
        {
            if( co[i].en > i+1 && co[i].r > 0 )
            {
                b = GetM( i+1, co[i].en-1 );
                b = Mi( b, co[i].r );
                a = Mul( b, a );
            }
            i = co[i].en;
        }
        else if( co[i].c[0] == 'r' )   //ro
        {
			if( co[i].x[3] == 0 )
				continue;
            for( k = 0; k < 4; k ++ )
                for( j = 0; j < 4; j ++ )
                    mz0.m[k][j] = mz.m[k][j] = mx.m[k][j] = sa.m[k][j];
            t = SqS2( co[i].x[0], co[i].x[1] );
            mz.m[0][0] = mz.m[1][1] = co[i].x[0] / t;
            mz.m[0][1] = co[i].x[1] / t;
            mz.m[1][0] = -mz.m[0][1];
            t1 = SqS2( t, co[i].x[2] );
            mx.m[0][0] = mx.m[2][2] = co[i].x[2] / t1;
            mx.m[2][0] = t / t1;
            mx.m[0][2] = -mx.m[2][0];
            mz0.m[0][0] = mz0.m[1][1] = cos( co[i].x[3]/180 * pi );
            mz0.m[1][0] = sin( co[i].x[3]/180 * pi );
            mz0.m[0][1] = -mz0.m[1][0];
            b = Mul( mx, mz );
            b = Mul( mz0, b );
            mz.m[1][0] = -mz.m[1][0];
            mz.m[0][1] = -mz.m[0][1];
            mx.m[0][2] = -mx.m[0][2];
            mx.m[2][0] = -mx.m[2][0];
            b = Mul( mx, b );
            b = Mul( mz, b );
            a = Mul( b, a );
        }
        else if( co[i].c[0] == 's' )   //scale
            for( j = 0; j < 3; j ++ )
                for( k = 0; k < 4; k ++ )
                    a.m[j][k] *= co[i].x[j];
        else if( co[i].c[0] == 't' )   //trans
            for( j = 0; j < 3; j ++ )
                a.m[j][3] += co[i].x[j];
    }
    return a;
}

int main()
{
    int n, i, j;
    double p[4];
    for( i = 0; i < 4; i ++ )
        for( j = 0; j < 4; j ++ )
            sa.m[i][j] = 0;
    for( i = 0; i < 4; i ++ )
        sa.m[i][i] = 1;
    MA mm;
    while( ~scanf( "%d", &n ) && n )
    {
        tc = tr = 0;
        while( tr >= 0 )
        {
            scanf( "%s", co[tc].c );
            if( co[tc].c[0] == 'e' )    //end
            {
                if( tr > 0 )
                    co[ ren[tr-1] ].en = tc;
                tr --;
            }
            else if( co[tc].c[0] == 'r' && co[tc].c[1] == 'e' )  //re
            {
                ren[tr++] = tc;
                scanf( "%d", &( co[tc].r ) );
            }
            else if( co[tc].c[0] == 'r' )   //ro
                for( i = 0; i < 4; i ++ )
                    scanf( "%lf", (co[tc].x)+i );
            else
                for( i = 0; i < 3; i ++ )
                    scanf( "%lf", (co[tc].x)+i );
            tc ++;
        }
		if( tc > 1 )
	        mm = GetM( 0, tc-2 );
		for( i = 0; i < n; i ++ )
        {
            for( j = 0; j < 3; j ++ )
                scanf( "%lf", p+j );
			if( tc > 1 )
			{
				p[3] = 1;
				Mul( mm, p );
			}
			for( j = 0; j < 3; j ++ )
				if( p[j] <= 0 && p[j] > -0.005 )
					p[j] = 0;
            printf( "%.2lf %.2lf %.2lf\n", p[0], p[1], p[2] );
        }
        printf( "\n" );
    }
    return 0;
}