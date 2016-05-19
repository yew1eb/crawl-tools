#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define g 9.8
#define pi acos(-1)
#define eps 10e-8

using namespace std;

double calc ( int h0 , double v , double angle )
{
    double vx = v * cos ( angle );
    double vy = v * sin ( angle );
    double t = vy/g;
    double s = vx*t;
    double h = h0 *1.0 + 0.5*g*t*t;
    t = sqrt ( 2.0*h/g );
    s += t*vx;
    return s;
}

double search ( int h0 , double v  )
{
    double left = 0.0 , right = (pi*1.0)/2;
    double mid , midmid;
    while ( left + eps <= right )
    {
        mid = ( left + right )/2.0;
        midmid = ( mid + right ) /2.0;
        if ( calc ( h0 , v ,mid ) >= calc( h0, v , midmid ) )
            right = midmid;
        else left = mid;
    }
    return  calc ( h0 , v , left );
} 

int main ( )
{
    int t;
    scanf ( "%d" , &t );
    int h,v;
    while ( t-- )
    {
        scanf ( "%d%d" , &h , &v );
        printf ( "%.2f\n" , search (h , v ) );
    }
}