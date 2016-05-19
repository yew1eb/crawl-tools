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
#define BUG puts("here!!!")

using namespace std;

const double eps = 1e-6;
const int MAX = 1010;
struct point{double x,y;};
point p[MAX];
bool dy(double x,double y)    {    return x > y + eps;}    // x > y 
bool xy(double x,double y)    {    return x < y - eps;}    // x < y 
bool dyd(double x,double y)    {     return x > y - eps;}    // x >= y 
bool xyd(double x,double y)    {    return x < y + eps;}     // x <= y 
bool dd(double x,double y)     {    return fabs( x - y ) < eps;}  // x == y
double disp2p(point a,point b) //  a b ä¸¤ç¹ä¹é´çè·ç¦» 
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
point circumcenter(point a,point b,point c)
{
     point ret;
     double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1*a1 + b1*b1)/2; 
      double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2*a2 + b2*b2)/2; 
      double d = a1 * b2 - a2 * b1; 
      ret.x = a.x + (c1*b2 - c2*b1)/d; 
      ret.y = a.y + (a1*c2 - a2*c1)/d; 
 return ret;
}
void min_cover_circle(point p[],int n,point &c,double &r)
{
    random_shuffle(p,p+n);// #include <algorithm>
    c = p[0]; r = 0;
    for(int i=1; i<n; i++)
        if( dy(disp2p(p[i],c),r) )
        {
            c = p[i]; r = 0;
            for(int k=0; k<i; k++)
                if( dy(disp2p(p[k],c),r) )
                {
                    c.x = (p[i].x + p[k].x)/2;
                    c.y = (p[i].y + p[k].y)/2;
                    r = disp2p(p[k],c);
                    for(int j=0; j<k; j++)
                        if( dy(disp2p(p[j],c),r) )
                        {                            // æ±å¤æ¥ååå¿ï¼ä¸ç¹å¿ä¸å±çº¿ 
                            c = circumcenter(p[i],p[k],p[j]);
                            r = disp2p(p[i],c);
                        }
                }
        }
}

int main()
{
    int ncases,n;
    
    double x,y;
    while( ~scanf("%lf%lf%d",&x,&y,&n) )
    {
        for(int i=0; i<n; i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        double r;
        point c;
        min_cover_circle(p,n,c,r);
        printf("(%.1lf,%.1lf).\n",c.x,c.y);
        printf("%.1lf\n",r);
    }

return 0;
}
