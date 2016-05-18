#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct Point
{
    int x;
    int y;
    Point() {}
    Point(int _x,int _y):x(_x),y(_y) {}
    friend Point operator + (Point a,Point b)
    {
        return Point(a.x+b.x , a.y+b.y);
    }
    friend Point operator - (Point a,Point b)
    {
        return Point(a.x-b.x , a.y-b.y);
    }
};
Point p[1002];
Point stack[10002];

double det(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}
double det(Point a,Point b,Point o)
{
    return det(a-o,b-o);
}
double det(Point a,Point b,Point c,Point d)
{
    return det(b-a,d-c);
}

bool cmp(Point a,Point b)
{
    return a.y<b.y || (a.y == b.y && a.x<b.x);
}
double dis(Point a,Point b)
{
    return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) );
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int n,l;

    while(scanf(" %d %d",&n,&l)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf(" %d %d",&p[i].x,&p[i].y);
        }
        sort(p,p+n,cmp);
        int top = -1;
        stack[++top] = p[0];
        stack[++top] = p[1];
        for(int i=2; i<n; i++)
        {
            while(top && det(stack[top],p[i],stack[top-1]) < 0)
            {
                top--;
            }
            stack[++top] = p[i];
        }
        //int midtop = top;
        for(int i=n-2; i>=0; i--)
        {
            //左链有可能会回溯到右链么？top>midtop是否不加也可以？
            //while(top>midtop && det(stack[top],p[i],stack[top-1]) < 0)
            while(det(stack[top],p[i],stack[top-1]) < 0)
            {
                top--;
            }
            stack[++top] = p[i];
        }
        double ans = 2 * l * acos(-1.0);
        for(int i=0; i<top; i++)
        {
            ans += dis(stack[i],stack[i+1]);
        }
        ans += 0.5;
        printf("%d\n",(int)ans);
    }
    return 0;
}