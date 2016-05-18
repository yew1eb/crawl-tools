//Time:265ms
//Memory:1080KB
//Length:953B
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define MAXN 100010
#define EPS 1e-8
int x[2][MAXN];
double cal(int l,int r,int len)
{
    len=abs(len);
    return sqrt(len*1.0*len+(x[1][r]-x[0][l])*1.0*(x[1][r]-x[0][l]));
}
int main()
{
    //freopen("/home/moor/Code/input","r",stdin);
    int ncase,n,m,a,b;
    scanf("%d",&ncase);
    for(int hh=1;hh<=ncase;++hh)
    {
        printf("Case #%d: ",hh);
        scanf("%d%d%d%d",&a,&b,&n,&m);
        double ans=0;
        for(int i=0;i<n;++i)    scanf("%d",&x[0][i]);
        for(int i=0;i<m;++i)    scanf("%d",&x[1][i]);
        ans=cal(0,0,b-a);
        for(int l=1,r=1;l<n||r<m;)
        {
            double t1=1e50,t2=1e50;
            if(r!=m)    t2=cal(l-1,r,b-a);
            if(l!=n)    t1=cal(l,r-1,b-a);
            if(t1<t2-EPS)   ans+=t1,++l;
            else    ans+=t2,++r;
        }

        printf("%.2f\n",ans);
    }
    return 0;
}