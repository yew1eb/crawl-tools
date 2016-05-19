#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stack>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;
#define lowbit(a) a&-a
#define Max(a,b) a>b?a:b
#define Min(a,b) a>b?b:a
#define mem(a,b) memset(a,b,sizeof(a))
int dir[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
const double eps = 1e-6;
const double Pi = acos(-1.0);
static const int inf= ~0U>>2;
static const int N=30010;
int scan()
{
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + (ch - '0');
    return flag ? -res : res;
}
void out(int a)
{
    if(a < 0)
    {
        putchar('-');
        a = -a;
    }
    if(a >= 10) out(a / 10);
    putchar(a % 10 + '0');
}
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
struct point
{
    int x,y;
} p[1000],pp[1000];
int acoss(point p1,point p2,point p0)
{
    return abs((p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x));
}
int main()
{
    int  a,area,ans;
    while(cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y>>p[2].x>>p[2].y)
   {
          //while(cin>>p[1].x>>p[1].y>>p[2].x)
          // {
        //p[0].x=0,p[0].y=0,p[2].y=0;
        if(!p[0].x&&!p[0].y&&!p[1].x&&!p[1].y&&!p[2].x&&!p[2].y)break;
        pp[0].x=abs(p[0].x-p[1].x);
        pp[0].y=abs(p[0].y-p[1].y);
        pp[1].x=abs(p[1].x-p[2].x);
        pp[1].y=abs(p[1].y-p[2].y);
        pp[2].x=abs(p[0].x-p[2].x);
        pp[2].y=abs(p[0].y-p[2].y);
        a=gcd(pp[0].x,pp[0].y)+gcd(pp[1].x,pp[1].y)+gcd(pp[2].x,pp[2].y);
        area=acoss(p[1],p[2],p[0]);//æ±S
        ans=(area-a+2)/2;
        printf("%d\n",ans);
    }
    return 0;
}
