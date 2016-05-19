#include <iostream>
#include <math.h>

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)

using namespace std;

struct point
{
    double x,y;
};

struct line
{
    point a,b;
};

double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

bool dots_inline(point p1,point p2,point p3)
{
    return zero(xmult(p1,p2,p3));
}

bool same_side(point p1,point p2,line l)
{
    return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}

bool dot_online_in(point p,line l)
{
    return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}

bool intersect_in(line u,line v)
{
    if (!dots_inline(u.a,u.b,v.a)||!dots_inline(u.a,u.b,v.b))
        return !same_side(u.a,u.b,v)&&!same_side(v.a,v.b,u);
    return dot_online_in(u.a,v)||dot_online_in(u.b,v)||dot_online_in(v.a,u)||dot_online_in(v.b,u);
}

int main()
{
    int n;
    while(cin>>n && n)
    {
        line l[105];
        for(int i = 1; i <= n; i++)
        {
            cin >> l[i].a.x >> l[i].a.y >> l[i].b.x >> l[i].b.y;
        }
        int cnt = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(intersect_in(l[i], l[j]))
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}
