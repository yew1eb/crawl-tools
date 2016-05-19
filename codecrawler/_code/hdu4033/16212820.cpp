#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=s; i<t; i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen("x", "r", stdin)
#define file_w(x) freopen("x", "w", stdout)

using namespace std;

const int MAX = 110;
const double pi = acos(-1.0);
const double inf = 20000;
double len[MAX];
const double eps = 1e-6;
bool dy(double x,double y)    {    return x > y + eps;}    // x > y 
bool xy(double x,double y)    {    return x < y - eps;}    // x < y 
bool dyd(double x,double y)    {     return x > y - eps;}    // x >= y 
bool xyd(double x,double y)    {    return x < y + eps;}     // x <= y 
bool dd(double x,double y)     {    return fabs( x - y ) < eps;}  // x == y
double ang_cal(double a, double b, double c)
{
    return acos((a*a + b*b - c*c)/(2*a*b));
}
int solve(int n, double x)
{
    double ang = 0;
    FOR(i, 0, n)
    {
        if( dyd(x, len[i] + len[i+1]) ) return 1;    // è¾¹é¿è¿å¤§æä¸æä¸è§å½¢ 
        if( xyd(x, fabs(len[i] - len[i+1])) ) return -1;//è¾¹é¿è¿å°æä¸æä¸è§å½¢ 
        double a = ang_cal(len[i], len[i+1], x);
        ang += a;
    }
    if( dy(ang, 2*pi) ) return 1;    // è§åº¦å¤§ï¼ä¹å°±æ¯xè¿å¤§ 
    if( xy(ang, 2*pi) ) return -1;    // è§åº¦å°ï¼ä¹å°±æ¯xè¿å° 
    if( dd(ang, 2*pi) ) return 0;
}

bool check(int n, double ang, double x)
{
    double a1 = ang_cal(len[1], x, len[0]);
    double a2 = ang_cal(len[1], x, len[2]);
    return dd(a1+a2, ang);
}
int main()
{
    int ncases, n, ind = 1;
    
    scanf("%d", &ncases);
    
    while( ncases-- )
    {
        scanf("%d", &n);
        FOR(i, 0, n)
            scanf("%lf", &len[i]);
        
        len[n] = len[0];
        
        double begin = 0, end = inf, mid;
        bool f = false;
        int cnt = 0;
        
        while( xyd(begin, end) )
        {
            if( dd(begin, end) )
                cnt++;
            if( cnt == 2 ) break;    // é¿åæ¾ä¸å°æ­»å¾ªç¯ 
            mid = (begin + end)/2;
            int ans = solve(n, mid);
            if( ans == 0 )
            {
                f = true;
                break;
            }
            if( ans > 0 )
                end = mid;
            else
                begin = mid;
        }
        
        printf("Case %d: ",ind++);
        
        if( f )
        {
            double ang = (n-2)*pi/n;
            if( !check(n, ang, mid) )    // æ£æµè§åº¦æ¯å¦ä¸ºæ­£å¤è¾¹å½¢çè§åº¦ 
            {
                printf("impossible\n");
                continue;
            }
            printf("%.3lf\n", mid);
        }
        else
            printf("impossible\n");
    }

return 0;
}
