#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
struct as
{
    double x;
    double y;
}p[210];
int is_cm(as a,as b,as c,as d)//判断是否相交
{
    double Sabc=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    double Sabd=(b.x-a.x)*(d.y-a.y)-(b.y-a.y)*(d.x-a.x);
    if(Sabc*Sabd>0)
        return 0;
    double Scda=(d.x-c.x)*(a.y-c.y)-(d.y-c.y)*(a.x-c.x);
    double Scdb=(d.x-c.x)*(b.y-c.y)-(d.y-c.y)*(b.x-c.x);
    if(Scda*Scdb<=0)
        return 1;
    else
        return 0;
}
int main()
{
    int n,i,j,sum;
    while(cin>>n,n)
    {
        sum=0;
        for(i=0;i<2*n;i++)
           scanf("%lf%lf",&p[i].x,&p[i].y);
        for(i=0;i<2*n;i+=2)
            for(j=i+2;j<2*n;j+=2)
            if(is_cm(p[i],p[i+1],p[j],p[j+1]))
                sum++;
        cout<<sum<<endl;
    }
}