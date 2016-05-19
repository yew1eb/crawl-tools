#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cstring>
#include <cstdio>
#include <time.h>
#include <cmath>
#include <queue>

#define P 0.6
#define INF 0x7fffffff

using namespace std;

const int N=1001;
const int maxn=10;
const int maxd=25;

struct node
{
    double x;
    double y;
    double dis;
}p[N],tr[maxn];

int x,y,n;

inline int max(int x,int y)
{
    return x<y?y:x;
}

double get_dis(node t)
{
    double mi=INT_MAX;
    for(int i=0;i<n;i++)
    {
        double dis=(t.x-p[i].x)*(t.x-p[i].x)+(t.y-p[i].y)*(t.y-p[i].y);
        if(dis<mi)
            mi=dis;
    }
    return mi;
}

node get_ans()
{
    node tmp;
    double t,t_min=(1e-2)*5,k1,k2;
    t=max(x,y)*1.0/sqrt(n*1.0);
    for(int i=0;i<maxn;i++)
    {
        tr[i].x=((rand()%1000+1)*1.0/1000.00)*x;
        tr[i].y=((rand()%1000+1)*1.0/1000.00)*y;
        tr[i].dis=get_dis(tr[i]);
    }
    while(t>t_min)
    {
        for(int i=0;i<maxn;i++)
        {
            for(int j=1;j<=maxd;j++)
            {
                k1=(double)(rand()%1000+1)*1.0/1000.00*t;
                k2=sqrt(t*t-k1*k1);
                if(rand()%2) k1*=-1;
                if(rand()%2) k2*=-1;
                tmp.x=tr[i].x+k1;
                tmp.y=tr[i].y+k2;
                if(tmp.x>=0&&tmp.x<=x&&tmp.y>=0&&tmp.y<=y)
                {
                    tmp.dis=get_dis(tmp);
                    if(tmp.dis>tr[i].dis)
                        tr[i]=tmp;
                }
            }
        }
        t=t*P;
    }
    int max=0;
    for(int i=1;i<maxn;i++)
    {
        if(tr[i].dis>tr[max].dis)
            max=i;
    }
    return tr[max];
}

int main()
{
    int t;
    node ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&x,&y,&n);
        for(int i=0;i<n;i++)
            scanf("%lf %lf",&p[i].x,&p[i].y);
        ans=get_ans();
        printf("The safest point is (%.1lf, %.1lf).\n",ans.x,ans.y);
    }
    return 0;
}