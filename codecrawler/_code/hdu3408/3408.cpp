#include <cstdio>
#include <cmath>
#include <algorithm>
#define eps 1e-8
using namespace std;

int n;
double vx,vy;

typedef struct pointtype
{
 double x,y;
}point;

typedef struct linetype
{
 point a,b;
 int num;
}line;

typedef struct polygontype
{
 int m;
 point p[11];
}poly;

poly po[6];
line li[53];
point s,t;

int dblcmp(double d)
{
 if(fabs(d)<eps) return 0;
 return d>0?1:-1;
}

int xyCmp(double p,double mini,double maxi)
{
 return dblcmp(p-mini)*dblcmp(p-maxi);
}

int betweenCmp(point a,point b,point c)
{
 if(fabs(b.x-c.x)>fabs(b.y-c.y))
 return xyCmp(a.x,min(b.x,c.x),max(b.x,c.x));
 else
 return xyCmp(a.y,min(b.y,c.y),max(b.y,c.y));
}

double dis(point a,point b)
{
 return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double mul(point p1,point p2,point p0)
{
 return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int segcross(point a,point b,point c,point d,point &p)
{
 double s1,s2,s3,s4;
 int d1,d2,d3,d4;
 d1=dblcmp(s1=mul(a,b,c));
 d2=dblcmp(s2=mul(a,b,d));
 d3=dblcmp(s3=mul(c,d,a));
 d4=dblcmp(s4=mul(c,d,b));
 if((d1^d2)==-2&&(d3^d4)==-2)
 {
 p.x=(c.x*s2-d.x*s1)/(s2-s1);
 p.y=(c.y*s2-d.y*s1)/(s2-s1);
 return 1;
 }
 if(d1==0&&betweenCmp(c,a,b)<=0)
 {p.x=c.x,p.y=c.y;return 2;}
 if(d2==0&&betweenCmp(d,a,b)<=0)
 {p.x=d.x,p.y=d.y;return 2;}
 if(d3==0&&betweenCmp(a,c,d)<=0)
 {p.x=a.x,p.y=a.y;return 2;}
 if(d4==0&&betweenCmp(b,c,d)<=0)
 {p.x=b.x,p.y=b.y;return 2;}
 return 0;
}

int main()
{
 int i,j;
 int nli,ansi;
 point ptmp,ansp;
 while(1)
 {
 nli=0,ansp.x=99999999,ansp.y=999999999,ansi=999;
 scanf("%d",&n);
 if(!n) break;
 scanf("%lf%lf%lf%lf",&s.x,&s.y,&vx,&vy);
 for(i=1;i<=n;i++)
 {
 scanf("%d",&po[i].m);
 for(j=1;j<=po[i].m;j++)
 scanf("%lf%lf",&po[i].p[j].x,&po[i].p[j].y);
 }
 t.x=s.x,t.y=s.y;
 for(i=1;i<=160;i++)
 t.x+=vx,t.y+=vy;
 for(i=1;i<=n;i++)
 {
 for(j=1;j<po[i].m;j++)
 li[++nli].a=po[i].p[j],li[nli].b=po[i].p[j+1],li[nli].num=i;
 li[++nli].a=po[i].p[1],li[nli].b=po[i].p[po[i].m],li[nli].num=i;
 }
 for(i=1;i<=nli;i++)
 if(segcross(s,t,li[i].a,li[i].b,ptmp))
 if(dis(ptmp,s)<dis(ansp,s))
 {
 ansp=ptmp;
 ansi=li[i].num;
 }
 if(ansi==1)
 printf("HIT\n");
 else
 printf("MISS\n");
 }
 return 0;
}