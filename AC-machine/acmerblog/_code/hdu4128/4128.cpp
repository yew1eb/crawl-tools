#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define sqr(x) ((x)*(x))
const double oo=1e50,eps=1e-8,pi=acos(-1.0);
using namespace std;
struct point{
    double x,y,z,_,d;
}p[200000];
int s[200000],t[200000];
int n,d,L,W,T,u[200000],st[200000];
double WW,LL,tot,Min;
inline double cr(point e,point r) {return e.x*r.y-e.y*r.x;}
inline double dot(point e,point r) {return e.x*r.x+e.y*r.y+e.z*r.z;}
inline void cross(point p,point q,point &e)
{
    e.x=p.y*q.z-p.z*q.y;
    e.y=p.z*q.x-p.x*q.z;
    e.z=p.x*q.y-p.y*q.x;
}
inline void ori(point &a)
{
    a._=atan2(a.y,a.x);
    a.d=a.z/sqrt(sqr(a.x)+sqr(a.y));
}
inline bool cmp(int i,int j)
{
    double tmp=p[i]._-p[j]._;
    if (fabs(tmp)>pi/2) return tmp<-eps;
    tmp=cr(p[i],p[j]);
    if (fabs(tmp)>eps) return tmp>eps;
    return p[i].d<p[j].d;
}
inline bool check(point L,point T,point I)
{
    point p;
    cross(L,T,p);
    if (dot(p,I)>-eps) return 1;
    return 0;
}
double doit()
{
    int tot=0;
    ++tot,p[tot].x=1,p[tot].y=0,p[tot].z=0;
    ++tot,p[tot].x=0,p[tot].y=1,p[tot].z=0;
    ++tot,p[tot].x=-1,p[tot].y=0,p[tot].z=oo;
    ++tot,p[tot].x=0,p[tot].y=-1,p[tot].z=oo;
    for (int i=1;i<=n-1;i++) {
        ++tot;
        p[tot].x=s[i]-s[n];
        p[tot].y=1;
        p[tot].z=t[i]-t[n];
    }
    for (int i=1;i<=tot;i++) ori(p[i]),u[i]=i;
    sort(u+1,u+tot+1,cmp);
    int h,r;
    st[h=r=1]=u[1]; 
    for (int i=2;i<=tot;i++) {
        if (fabs(cr(p[u[i]],p[u[i-1]]))<eps) continue;
        for (;(h<r) && (!check(p[st[r-1]],p[st[r]],p[u[i]]));r--) ;
        for (;(h<r) && (!check(p[st[h]],p[st[h+1]],p[u[i]]));h++) ;
        st[++r]=u[i];
    }
    for (;(h<r) && (!check(p[st[r-1]],p[st[r]],p[st[h]]));r--) ;
//    for (;(h<r) && (!check(p[st[h]],p[st[h+1]],p[st[r]]));h++) ;
    st[r+1]=st[h];
    double ans=oo;
    for (int i=h;i<=r;i++) {
        point e;
        if ((st[i]==3) || (st[i]==4) || (st[i+1]==3) || (st[i+1]==4)) continue;
        cross(p[st[i]],p[st[i+1]],e);
        e.x/=e.z,e.y/=e.z,e.z=1;
        double sum=(WW-s[n]*LL)*e.x+e.y*LL;
        ans=min(ans,sum);
    }
    return -ans;
}
int main()
{
    scanf("%d",&T);
    for (;T;T--) {
        scanf("%d%d%d%d",&n,&d,&L,&W);
        LL=L-d*n,WW=W;
        tot=0,Min=oo;
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&s[i],&t[i]);
            WW-=s[i]*d;
            tot+=d*t[i];
            Min=min(Min,(double)s[i]);
        }
        if (WW<0 || LL<0) {
            printf("No solution\n");
            continue;
        }
        if (1==n) {
            if (L*s[1]>W) printf("No solution\n");
            else printf("%.2lf\n",(double)L*t[1]);
            continue;
        }
        if (Min*LL>WW) {
            printf("No solution\n");
            continue;
        }
        double ans=doit()+t[n]*LL+tot;
        if (ans<-eps) {
            printf("No solution\n");
            continue;
        }
//        cout<<low<<' '<<lim<<' '<<WW-s[n]*LL<<endl;
        printf("%.2lf\n",fabs(ans));
    }
    return 0;
}