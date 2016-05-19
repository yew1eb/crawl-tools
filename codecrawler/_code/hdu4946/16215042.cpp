#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

const int maxn=505;
struct Point{
    int x,y,v,id,flag,vis;
    Point(int x=0,int y=0):x(x),y(y){}
}e[maxn],p[maxn],ch[maxn];
typedef Point Vector;
Vector operator - (Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);}
int Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}//åç§¯
int cmp1(Point a,Point b)
{
    if(a.v==b.v)return a.x<b.x||(a.x==b.x&&a.y<b.y);
    return a.v>b.v;
}
int cmp2(Point a,Point b)
{
    return a.id<b.id;
}
int ConvexHull(Point *p,Point *ch,int n)//æ±å¸å
{
    //sort(p,p+n,cmp3);
    int i,m=0,k;
    for(i=0;i<n;i++)
    {
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    k=m;
    for(i=n-2;i>=0;i--)
    {
        //cout<<"*"<<m<<endl;
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    if(n>1)m--;
    return m;
}

int main()
{
    //freopen("D:\\in.txt","r",stdin);
    int n,tt=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        int i,j,k,t,m;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
            e[i].id=i;
            e[i].flag=0;
            e[i].vis=0;
        }
        sort(e,e+n,cmp1);
        for(i=1;i<n;i++)
        {
            if(e[i].v!=e[i-1].v)break;
            if(e[i].x==e[i-1].x&&e[i].y==e[i-1].y)e[i].vis=e[i-1].vis=1;
        }
        t=i;
        for(i=0;i<t;i++)
        {
            p[i]=e[i];
        }
        if(e[0].v==0)t=0;
        m=ConvexHull(p,ch,t);
        for(i=0;i<t;i++)
        {
            for(j=0;j<m;j++)
            {
                if(Cross(ch[j]-ch[(j+1)%m],ch[j]-e[i])==0)
                {
                    if(!e[i].vis)//è¯¥ç¹æ²¡æä¸ä¹éåä¸éåº¦ç¸åçç¹
                    e[i].flag=1;
                    break;
                }
            }
        }
        sort(e,e+n,cmp2);
        printf("Case #%d: ",++tt);
        for(i=0;i<n;i++)printf("%d",e[i].flag);
        printf("\n");
    }
    return 0;
}
/*
5
0 0 1
1 0 1
0 1 1
1 1 1
2 0 1
3
0 0 0
1 1 0
2 2 0
9
0 0 1
1 0 1
2 0 1
0 1 1
1 1 2
2 1 1
0 2 1
1 2 1
2 2 1
ans:
11111
000
000010000
*/
