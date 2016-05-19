#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

#define  pb push_back
const int maxn=100;
const double eps=1e-8;
const double pi=acos(-1.0);

inline double sqr(double x)
{
    return x*x;
}

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int sig(double x)
{
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}

struct point
{
    double x,y;
    point(){};
    point(double a,double b):x(a),y(b){}
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    friend point operator + (const point &a,const point &b)
    {
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator - (const point &a,const point &b)
    {
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator == (const point &a,const point &b)
    {
        return sig(a.x-b.x)==0 && sig(a.y-b.y)==0;
    }
    friend point operator * (const point &a,const double &b)
    {
        return point(a.x*b,a.y*b);
    }
    friend point operator * (const double &a,const point &b)
    {
        return point(a*b.x,a*b.y);
    }
    friend point operator / (const point &a,const double &b)
    {
        return point(a.x/b,a.y/b);
    }
    double norm()
    {
        return sqrt(sqr(x)+sqr(y));
    }
};

double det(const point &a,const point &b)
{
    return a.x*b.y-a.y*b.x;
}

double dot(const point &a,const point &b)
{
    return a.x*b.x+a.y*b.y;
}

double dist(const point &a,const point &b)
{
    return (a-b).norm();
}

bool PointOnSegment(point p,point s,point t)
{
    return sig(det(p-s,t-s))==0 && sig(dot(p-s,p-t))<=0;
}

struct polygon
{
    int n;
    point a[maxn];
    polygon(){}
    int judDir()
    {
        int d;
        a[n]=a[0];
        for(int i=0;i<n-1;i++)
        {
            d=sig(det(a[i+1]-a[i],a[i+2]-a[i+1]));
            if(d!=0) break;
        }
        return d;
    }
    void to_counter_clockwise()
    {
        for(int i=0;i<(n)/2;i++)  swap(a[i],a[n-1-i]);
    }
    double area()
    {
        double sum=0;
        a[n]=a[0];
        for(int i=0;i<n;i++) sum+=det(a[i+1],a[i]);
        return sum/2;
    }
    int Point_In(point t)
    {
        int num=0,d1,d2,k;
        a[n]=a[0];
        for(int i=0;i<n;i++)
        {
            if(PointOnSegment(t,a[i],a[i+1])) return 2;
            k=sig(det(a[i+1]-a[i],t-a[i]));
            d1=sig(a[i].y-t.y);
            d2=sig(a[i+1].y-t.y);
            if(k>0 && d1<=0 && d2>0) num++;
            if(k<0 && d2<=0 && d1>0) num--;
        }
        return num!=0;
    }
};

struct polygon_convex
{
    vector<point> p;
    polygon_convex(int Size=0){ p.resize(Size);}
    polygon_convex operator = (polygon_convex x)
    {
        p.clear();
        for(int i=0;i<x.p.size();i++)
            p.push_back(x.p[i]);
        return *this;
    }
};

bool cmp_less(const point &a,const point &b)
{
    return sig(a.x-b.x)<0||sig(a.x-b.x)==0&&sig(a.y-b.y)<0;
}

polygon_convex convex_hull(vector<point> a)
{
    polygon_convex res(2*a.size()+5);
    sort(a.begin(),a.end(),cmp_less);
    a.erase(unique(a.begin(),a.end()),a.end());
    int m=0;
    for(int i=0;i<a.size();i++)
    {
        while(m>1 && sig(det(res.p[m-1]-res.p[m-2],a[i]-res.p[m-2]))<=0)
            m--;
        res.p[m++]=a[i];
    }
    int k=m;
    for(int i=int(a.size())-2;i>=0;i--)
    {
        while(m>k&&sig(det(res.p[m-1]-res.p[m-2],a[i]-res.p[m-2]))<=0)
            m--;
        res.p[m++]=a[i];
    }
    res.p.resize(m);
    if(a.size()>1) res.p.resize(m-1);
    return res;
}

polygon plg[22];
polygon_convex c[22];
double a[22];
bool vis[22];
int n;

int main()
{
    int tp=0;
    point p;
    vector<point> pl;
    while(cin>>n && n!=-1)
    {
        pl.clear();
        for(int i=0;i<n;i++)
        {
            p.input();
            pl.pb(p);
        }
        c[tp]=convex_hull(pl);
        plg[tp].n=c[tp].p.size();
        for(int i=0;i<plg[tp].n;i++) plg[tp].a[i]=c[tp].p[i];
        if(plg[tp].judDir()==1) plg[tp].to_counter_clockwise();
        a[tp]=plg[tp].area();
        vis[tp++]=0;
    }
    double busted=0;
    double x,y;
    while(cin>>x>>y)
    {
        p.x=x;
        p.y=y;
        for(int i=0;i<tp;i++)
        {
            if(plg[i].Point_In(p)>0 && !vis[i])
            {
                vis[i]=1;
                busted+=a[i];
            }
        }
    }
    printf("%.2f\n",busted);
    return 0;
}