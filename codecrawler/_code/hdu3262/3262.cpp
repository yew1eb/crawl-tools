#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

#define si1(a) scanf("%d",&a)
#define si2(a,b) scanf("%d%d",&a,&b)
#define sd1(a) scanf("%lf",&a)
#define sd2(a,b) scanf("%lf%lf",&a,&b)
#define ss1(s)  scanf("%s",s)
#define pi1(a)    printf("%d\n",a)
#define pi2(a,b)  printf("%d %d\n",a,b)
#define mset(a,b)   memset(a,b,sizeof(a))
#define forb(i,a,b)   for(int i=a;i<b;i++)
#define ford(i,a,b)   for(int i=a;i<=b;i++)

typedef long long LL;
const int N=33;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;

int n,m,k;
int xh[N][N];

struct xkn
{
    int time,ren;
    int i;
}p[55];

struct jilu
{
    int x,y;
}o[55];

bool cmp(xkn a,xkn b)
{
    return a.time<b.time;
}

bool yes(int i,int j,int ren)
{
    for(int k=0;k<ren;k++)
        if(xh[i][j+k]==-1)
            return false;
    return true;
}

void xiaohao(int ren,int t)
{
    int flag1=-1,flag2=-1;
    int Max1,Max2;
    int x,y;
    for(int i=0;i<n;i++)
        for(int j=0;j<=m-ren;j++)
        {
            if(yes(i,j,ren))
            {
                if(flag1==-1)
                {
                    flag1=1;
                    Max1=xh[i][j];
                    x=i;    y=j;
                }
                else if(Max1<xh[i][j])
                {
                    Max1=xh[i][j];
                    x=i;    y=j;
                }
            }
        }
    if(flag1!=-1)
    {
        //pi2(x+1,y+1);
        o[t].x=x+1; o[t].y=y+1;
        for(int k=0;k<ren;k++)
            xh[x][y+k]=-1;
        return ;
    }

    forb(i,0,n)
        forb(j,0,m)
        {
            if(xh[i][j]!=-1)
            {
                if(flag2==-1)
                {
                    flag2=1;
                    Max2=xh[i][j];
                    x=i;    y=j;
                }
                else if(Max2<xh[i][j])
                {
                    Max2=xh[i][j];
                    x=i;    y=j;
                }
            }
        }
    if(flag2!=-1)
    {
        //pi2(x+1,y+1);
        o[t].x=x+1; o[t].y=y+1;
        xh[x][y]=-1;
        return ;
    }
    o[t].x=-1; o[t].y=-1;
}

int main()
{
//    freopen("input.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&k)&&(n+m+k))
    {
        forb(i,0,n) forb(j,0,m) si1(xh[i][j]);
        forb(i,0,k)
        {
            int a,b;
            scanf("%d:%d %d",&a,&b,&p[i].ren);
            p[i].time=a*60+b;
            p[i].i=i;
        }
        sort(p,p+k,cmp);
        forb(i,0,k)
        {
            xiaohao(p[i].ren,p[i].i);
        }
        forb(i,0,k)//必须按照开始的顺序输出
        {
            if(o[i].x==-1)
                puts("-1");
            else
                pi2(o[i].x,o[i].y);
        }
    }
    return 0;
}