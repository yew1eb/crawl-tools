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

typedef __int64 LL;
const int N=110;
const int mod=1000007;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-7;

int n,m;
int xh[N][N];   //xh[i][j]表示线段ij下面有多少个点

struct point
{
    LL x,y;
    void input()
    {
        scanf("%I64d%I64d",&x,&y);
    }
}house[110],gold[1010];

bool cmp(point a,point b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}

bool chacheng(point a,point b,point c)
{
    point u,v;
    u.x=b.x-a.x;    u.y=b.y-a.y;
    v.x=c.x-b.x;    v.y=c.y-b.y;
    LL t=u.x*v.y-u.y*v.x;
    if(t>=0)
        return true;
    return false;
}

bool under(int i,int j,int k)
{
    if(gold[k].x<house[i].x||gold[k].x>=house[j].x)
        return false;

    return chacheng(house[j],house[i],gold[k]);
}

int main()
{
//    freopen("input.txt","r",stdin);
    int ca=0;
    while(si2(n,m)!=EOF)
    {
        forb(i,0,n)
            house[i].input();
        forb(i,0,m)
            gold[i].input();

        sort(house,house+n,cmp);

        mset(xh,0);
        forb(i,0,n)
            forb(j,i+1,n)
                forb(k,0,m)
                    if(under(i,j,k))
                        xh[i][j]++,xh[j][i]++;
        int num=0;
        forb(i,0,n)
            forb(j,i+1,n)
                forb(k,j+1,n)
                    if(abs(xh[i][k]-xh[i][j]-xh[j][k])&1)
                        num++;
        printf("Case %d: %d\n",++ca,num);
    }

    return 0;
}

