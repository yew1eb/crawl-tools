#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>

#define LL long long
#define EPS (1e-8)

using namespace std;

const double PI = acos(-1.0);

struct P
{
    double a;
    int x,y,mark;
} pa[1010],p[1010];

double Cal_Angle(P p1,P p2)
{
    if(p1.x == p2.x && p1.y == p2.y)
        return -100.0;
    P v;
    v.x = p2.x - p1.x;
    v.y = p2.y - p1.y;
    if(p1.y <= p2.y)
        return acos(v.x/sqrt(v.x*v.x + v.y*v.y));
    return 2.0*PI - acos(v.x/sqrt(v.x*v.x + v.y*v.y));
}

void Cal_Angle(P p,P *pa,int n)
{
    for(int i = 0; i < n; ++i)
    {
        pa[i].a = Cal_Angle(p,pa[i]);
    }
}

bool cmp_angle(P p1,P p2)
{
    return p1.a < p2.a;
}

int main()
{
    int n,i,j,k,l,d;
    int Max,tl,tr,b,w,s1,s0,s2,s3;
    double xm,pil,pir;
    P vec;
    while(scanf("%d",&n) && n)
    {
        b = 0;
        w = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].mark);
            pa[i] = p[i];
            if(pa[i].mark)
                b++;
            else
                w++;
        }

        Max = -1;

        for(i = 0; i < n; ++i)
        {
            Cal_Angle(p[i],pa,n);
            sort(pa,pa+n,cmp_angle);

            pir = pa[1].a;
            pil = pir + PI;

            s1 = s0 = s2 = s3 = 0;

            for(j = 1; j < n && pa[j].a < pil; ++j)
            {
                if(pa[j].a == pir)
                {
                    if(pa[j].mark)
                        s3++;
                    else
                        s2++;
                }
                else
                {
                    if(pa[j].mark)
                        s1++;
                    else
                        s0++;
                }
            }

            for(d = j; d < n && pa[d].a == pil; ++d)
            {
                if(pa[d].mark)
                    s3++;
                else
                    s2++;
            }

            if(pa[0].mark)
                s3++;
            else
                s2++;

            tr = s0 + (b-s1)+s2;
            tl = s1 + (w-s0)+s3;
            
            if(tr > Max || tl > Max)
            Max = tr > tl ? tr : tl;

            k = 1;

            while(pir < PI && j < n)
            {
                for(; k < n && pir == pa[k].a; ++k)
                {
                    if(pa[k].mark)
                        --s3;
                    else
                        --s2;
                }
                pir = pa[k].a;
                if(pir > PI)
                    break;
                for(l = k; l < n && pir == pa[l].a; ++l)
                {
                    if(pa[l].mark)
                    {
                        ++s3;
                        --s1;
                    }
                    else
                    {
                        ++s2;
                        --s0;
                    }
                }
                for(; j < n && pa[j].a == pil; ++j)
                {
                    if(pa[j].mark)
                    {
                        --s3;
                        ++s1;
                    }
                    else
                    {
                        --s2;
                        ++s0;
                    }
                }

                pil = pir+PI;

                for(; j < n && pa[j].a < pil; ++j)
                {
                    if(pa[j].mark)
                    {
                        ++s1;
                    }
                    else
                    {
                        ++s0;
                    }
                }

                for(d = j; d < n && pa[d].a == pil ; ++d)
                {
                    if(pa[d].mark)
                        ++s3;
                    else
                        ++s2;
                }
                tr = s0 + (b-s1)+s2;
                tl = s1 + (w-s0)+s3;
                if(tr > Max || tl > Max)
                {
                    Max = tr > tl ? tr : tl;
                }
            }
        }
        printf("%d\n",Max);
    }
    return 0 ;
}