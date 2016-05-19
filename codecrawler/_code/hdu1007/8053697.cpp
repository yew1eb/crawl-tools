#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 100002
#define INF 0x3f3f3f3f
using namespace std;
struct NODE{ double x, y;};
NODE edge[N], b[N];
int cmp_x(const void *a, const void *b)
{
    NODE *aa = (NODE*) a;
    NODE *bb = (NODE*) b;
    return aa->x > bb->x ? 1: -1;
}
int cmp_y(const void *a, const void *b)
{
    NODE *aa = (NODE*) a;
    NODE *bb = (NODE*) b;
    return aa->y > bb->y ? 1: -1;
}

inline double dis( NODE a, NODE b)
{
    double xx =a.x - b.x, yy = a.y - b.y;
    return sqrt(xx*xx+yy*yy);
}
double find(int l, int r)//&#199;¡ã¡À&#213;o¨®&#191;a&#199;&#248;&#188;&#228; 
{
    if(r-l == 1) return INF;
    if(r-l == 2) return dis(edge[l], edge[r-1]);
    //------------
    int i, j, k;
    double dm, tmp;
    int m = (l+r)/2;
    double  d1 = find(l, m);
    double  d2 = find(m, r);
    dm = d1 < d2 ? d1:d2;
    for(i=l,k=0;i<r;i++)
        if(fabs(edge[m].x-edge[i].x)<=dm )
            b[k++] = edge[i];
    qsort(b,k,sizeof(b[0]),cmp_y);
    for(i=0;i<k;i++)
        for(j=i+1;j<k;j++)
        {
            tmp = dis(b[i],b[j]);
            if(tmp<dm)dm=tmp;
        }
    return dm;

}
int main()
{
    int n, i;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf",&edge[i].y, &edge[i].x);
        qsort(edge,n,sizeof(edge[0]),cmp_x);
        double d = find(0,n);
        printf("%.2lf\n",d/2);
    }
    return 0;
}
