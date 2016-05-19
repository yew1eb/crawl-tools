#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct pnode
{
    double x,y;
    pnode( double a, double b ) {x = a;y = b;}
    pnode(){};
}point;
point P[5];

typedef struct lnode
{
    double x,y,dx,dy;
    lnode( point a, point b ) {x = a.x;y = a.y;dx = b.x-a.x;dy = b.y-a.y;}
    lnode(){};
}line;

double dist( point a, point b )
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double dist( point p, int N )
{
    double sum = 0.0;
    for ( int i = 0 ; i < N ; ++ i )
        sum += dist( p, P[i] );
    return sum;
}

double p_to_l( point a, line l )
{
    return l.dx*(a.y-l.y)-l.dy*(a.x-l.x);
}

point l_cross_s( line l, point a, point b )
{
    line m = line( a, b );
    if ( m.dx*l.dy == m.dy*l.dx ) return a;
    else {
        double a1 = -l.dy,b1 = l.dx,c1 = l.dx*l.y-l.dy*l.x;
        double a2 = -m.dy,b2 = m.dx,c2 = m.dx*m.y-m.dy*m.x;
        double x = (c1*b2-c2*b1)/(a1*b2-a2*b1);
        double y = (c1*a2-c2*a1)/(b1*a2-b2*a1);
        return point( x, y );
    }
}

int main()
{
    while ( scanf("%lf%lf",&P[0].x,&P[0].y) != EOF ) {
        if  ( P[0].x == -1 ) break;
        for ( int i = 1 ; i < 4 ; ++ i )
            scanf("%lf%lf",&P[i].x,&P[i].y);
        
        //é¡¶ç¹å¤æ­ 
        double temp,min = dist( P[0], 4 );
        for ( int i = 1 ; i < 4 ; ++ i ) {
            temp = dist( P[i], 4 );
            if ( min > temp )
                min = temp;
        }
        
        //äº¤ç¹å¤æ­ 
        point p4,p3,p2,p1 = P[0];
        int   U[4];
        for ( int i = 1 ; i < 4 ; ++ i ) {
            for ( int j = 1 ; j < 4 ; ++ j )
                U[j] = 0;
            U[i] = 1; p2 = P[i];
            for ( int j = 1 ; j < 4 ; ++ j ) 
                if ( !U[j] ) { 
                    U[j] = 1; p3 = P[j];break; 
                }
            for ( int j = 1 ; j < 4 ; ++ j )
                if ( !U[j] ) { 
                    U[j] = 1; p4 = P[j];break; 
                }
            
            line l1 = line( p1, p2 );
            line l2 = line( p3, p4 );
            if ( p_to_l( p1, l2 )*p_to_l( p2, l2 ) <= 0 )
            if ( p_to_l( p3, l1 )*p_to_l( p4, l1 ) <= 0 ) {
                point q = l_cross_s( line( p1, p2 ), p3, p4 );
                temp = dist( q, 4 );
                if ( min > temp )
                    min = temp;
            }
        }
        
        printf("%.4lf\n",min);
    }
    return 0;
}