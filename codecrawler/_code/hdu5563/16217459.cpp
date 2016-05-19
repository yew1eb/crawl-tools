#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#define eps 0.00001
using namespace std;
double min(double a,double b)
{
    return a<b?a:b;
}
pair<double,double>p[10];
double juli(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    int T,i,j,k,cnt;
    double d[10005];
    scanf("%d",&T);
    while(T--)
    {
        cnt=1;
        double x,y;
        for(i=1;i<=5;i++)
        {scanf("%lf%lf",&x,&y);
        p[i]=make_pair(x,y);

    }
    for(i=1;i<=5;i++)
        for(j=i+1;j<=5;j++)
    {
     d[cnt++]=juli(p[i].first,p[i].second,p[j].first,p[j].second);
    }
        int t=1;
        sort(d+1,d+cnt);
        for(i=2;i<cnt;i++)
        {
            if(fabs(d[i]-d[i-1])>eps)t++;
        }
        if(t<=2)printf("Yes\n");
        else printf("No\n");
    }
}