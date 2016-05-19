#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct Point
{
     int x,y;
     bool operator<(const Point &cmp) const
     {
         return x<cmp.x;
     }
};

Point p[210];
Point mine[510];

int cross(Point A,Point B,Point C)
{
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}

int n,m;
int num[210][510];

void Init(Point a,Point b,int &cnt)
{
    int x1=a.x;
    int x2=b.x;
    for(int i=0;i<m;i++)
        if(x1<=mine[i].x&&mine[i].x<x2)
            if(cross(a,b,mine[i])>0)
               cnt++;
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        sort(p,p+n);
        for(int i=0;i<m;i++)
            scanf("%d%d",&mine[i].x,&mine[i].y);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                 Init(p[i],p[j],num[i][j]=0);
        double ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                      int cnt=num[i][k]-num[i][j]-num[j][k];
                      if(cnt==0) continue;
                      double area=cross(p[i],p[j],p[k])/2.0;
                      double tmp=fabs(area/cnt);
                      if(ans==-1||tmp<ans) ans=tmp;
                }
            }
        }
        printf("Case #%d: ",cas++);
        if(ans==-1) puts("-1");
        else        printf("%.6lf\n",ans);
    }
    return 0;
}