#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct p1node
{
    double a,b,c,d;
}plane;
plane Pl;

typedef struct p2node
{
    double x,y,z;
}point;
point temp;
point P[ 105 ];
point S[ 105 ];

//è®¡ç®ç¹å¨å¹³é¢ä¸çæå½± 
int shadow( plane p, point s, int n )
{
    //æ±åºè¿så¹³è¡äºplaneçå¹³é¢ ax+by+c=D
    double D = p.a*s.x+p.b*s.y+p.c*s.z;
    if ( D-p.d < 0 ) {//è°æ´æ¹å 
        p.a *= -1;p.b *= -1;p.c *= -1;
        p.d *= -1;
        D *= -1; 
    }
    
    //å¤æ­ç¹ä¸é¢çå³ç³» 
    int count = 0;
    for ( int i = 0 ; i < n ; ++ i ) {
        double det = p.a*P[i].x+p.b*P[i].y+p.c*P[i].z-D;
        if ( det < 0 ) count ++;
    }
    if ( count == 0 ) return 0;
    if ( count != n ) return n+1;
        
    for ( int i = 0 ; i < n ; ++ i ) {
        //ç´çº¿æ¹ç¨: (Sx,Sy,Sz) + t(dx,dy,dz) 
        double dx = P[i].x - s.x;
        double dy = P[i].y - s.y;
        double dz = P[i].z - s.z;
        double t = (p.d-p.a*s.x-p.b*s.y-p.c*s.z)/(p.a*dx+p.b*dy+p.c*dz);
        
        P[i].x = s.x + t*dx;
        P[i].y = s.y + t*dy;
        P[i].z = s.z + t*dz;
    }
    return n;
}

//åæ ç³»æè½¬ï¼å°x-yå¹³é¢ 
void change( plane p, int n )
{
    //å¹³è¡äºx-yå¹³é¢çä¸ç¨è®¡ç®ï¼ä¹ä¸è½è®¡ç®ï¼åæ¯ä¸º0ï¼
    if  ( p.a*p.a + p.b*p.b == 0 ) return;
    for ( int i = 0 ; i < n ; ++ i ) {
        //ç»zè½´æè½¬ 
        double cosC = p.b/sqrt(p.a*p.a+p.b*p.b);
        double sinC = p.a/sqrt(p.a*p.a+p.b*p.b);
        temp.x = P[i].x*cosC-P[i].y*sinC;
        temp.y = P[i].x*sinC+P[i].y*cosC;
        temp.z = P[i].z;
        P[i] = temp;
        //ç»xè½´æè½¬ 
        double cosA = p.c/sqrt(p.a*p.a+p.b*p.b+p.c*p.c);
        double sinA = sqrt(p.a*p.a+p.b*p.b)/sqrt(p.a*p.a+p.b*p.b+p.c*p.c);
        temp.x = P[i].x;
        temp.y = P[i].y*cosA-P[i].z*sinA;
        temp.z = P[i].y*sinA+P[i].z*cosA;
        P[i] = temp; 
    }
}

//è®¡ç®äºç»´å¸åé¢ç§¯ 
double crossproduct( point a, point b, point c )
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
 
bool cmp1( point a, point b )
{
    if ( a.x == b.x )
        return a.y < b.y;
    return a.x < b.x;
}

bool cmp2( point a, point b )
{
    return crossproduct( P[0], a, b )>0;
}

void Graham( int n )
{
    sort( P+0, P+n, cmp1 );
    sort( P+1, P+n, cmp2 );
    
    int top = -1;
    if ( n > 0 ) S[++ top] = P[0];
    if ( n > 1 ) S[++ top] = P[1];
    if ( n > 2 ) {
        for ( int i = 2 ; i < n ; ++ i ) {
            while ( crossproduct( S[top-1], S[top], P[i] ) < 0 ) -- top;
            S[++ top] = P[i];
        }
    }
    
    double area = 0.0;
    for ( int i = 2 ; i <= top ; ++ i )
        area += crossproduct( S[0], S[i-1], S[i] );
    
    printf("%.2lf\n",area*0.5);
}

int main()
{
    int n;
    while ( cin >> Pl.a >> Pl.b >> Pl.c >> Pl.d ) {
        if ( Pl.a == 0 && Pl.b == 0 && Pl.c == 0 ) break;
        cin >> n;
        for ( int i = 0 ; i <= n ; ++ i )
            cin >> P[i].x >> P[i].y >> P[i].z;
        
        int s_count = shadow( Pl, P[n], n );
        if ( !s_count )
            cout << "0.00" << endl;
        else if ( s_count > n ) 
            cout << "Infi" << endl;
        else {
            change( Pl, s_count );
            Graham( s_count );
        }
    }
}