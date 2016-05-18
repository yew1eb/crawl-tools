#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;
struct seg
{
    double k,b;
    double x1,y1;
    double x2,y2;
    bool flag;
}an[10002];
int same(double a,double b)
{
    if(fabs(a-b)>1e-8) return 0;
    return 1;
}
bool less(double a,double b)
{
    if(a-b>1e-8) return 0;
    return 1;
}
bool cmp(const seg &a,const seg &b)
{
    if(a.flag!=b.flag) return a.flag<b.flag;
    if(a.flag)
    {
        if(!same(a.k,b.k)) return less(a.k,b.k);
        if(same(a.b,b.b)) return less(a.x1,b.x1);
        return less(a.b,b.b);
    }
    else
    {
        if(!same(a.x1,b.x1)) return less(a.x1,b.x1);
        return less(a.y1,b.y1);
    }
}
double MAX(double a,double b)
{
    if(a-b>1e-10) return a;
    return b;
}
int fun(seg &a,seg &b)
{
    if(a.flag!=b.flag) return 0;
    if(a.flag)
    {
        if(!same(a.k,b.k)) return 0;
        if(!same(a.b,b.b)) return 0;
        if(b.x1-a.x2>1e-8) return 0;
        b.x2=MAX(a.x2,b.x2);
        return 1;
    }
    else
    {
        if(same(a.x1,b.x1))
        {
            if(b.y1-a.y2<1e-8)
            {
                b.y2=MAX(b.y2,a.y2);
                return 1;
            }
        }
        return 0;
    }
}
int main()
{
    int b,c,n,m,i,j;
    double x1,x2,y1,y2;
    bool flag;
    while(cin>>n&&n)
    {
        memset(an,0,sizeof(an));
        for(i=0;i<n;i++)
        {
            cin>>an[i].x1>>an[i].y1>>an[i].x2>>an[i].y2;   
            if(an[i].x1==an[i].x2)
            {
                an[i].flag=0;
                if(an[i].y1>an[i].y2) swap(an[i].y1,an[i].y2);
            }
            else
            {
                an[i].flag=1;
                if(an[i].x1>an[i].x2)
                {
                    swap(an[i].x1,an[i].x2);
                    swap(an[i].y1,an[i].y2);
                }
                an[i].k=(an[i].y2-an[i].y1)/(an[i].x2-an[i].x1);
                an[i].b=an[i].y1-an[i].k*an[i].x1;
            }
        }
        sort(an,an+n,cmp);
        m=1;
        for(i=1;i<n;i++)
        {
            if(!fun(an[i-1],an[i]))
                m++;
        }
        cout<<m<<endl;
    }
    return 0;
}