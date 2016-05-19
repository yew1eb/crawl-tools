#include <cstdio>
#include <algorithm>
using namespace std;
#define inf 2147483647
struct node
{
    int l,t;
    bool operator<(const node &c) const
    {
        return l<c.l;
    }
};
node p[55][1005];
int n,m,x,f[55][1005];
void make(int z)
{
    int _min,now,i;
    i=1;
    while (i<=n && p[z][i].l<p[z-1][1].l)
        f[z][i]=inf,++i;
    _min=f[z-1][1]-p[z-1][1].l;
    now=2;
    for (; i<=n; ++i)
    {
        f[z][i]=inf;
        while (now<=n && p[z-1][now].l<=p[z][i].l)
            _min=min(_min,f[z-1][now]-p[z-1][now].l),++now;
        f[z][i]=min(f[z][i],_min+p[z][i].t+p[z][i].l);
    }
    i=n;
    while (i>=1 && p[z][i].l>p[z-1][n].l)
        --i;
    _min=f[z-1][n]+p[z-1][n].l;
    now=n-1;
    for (; i>=1; --i)
    {
        while (now>=1 && p[z-1][now].l>=p[z][i].l)
            _min=min(_min,f[z-1][now]+p[z-1][now].l),--now;
        f[z][i]=min(f[z][i],_min+p[z][i].t-p[z][i].l);
    }
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&m,&n,&x);
        for (i=1; i<=m; ++i)
            for (j=1; j<=n; ++j)
                scanf("%d",&p[i][j].l);
        for (i=1; i<=m; ++i)
            for (j=1; j<=n; ++j)
                scanf("%d",&p[i][j].t);
        for (i=1; i<=m; ++i)
            sort(p[i]+1,p[i]+n+1);
        for (i=1; i<=n; ++i)
            f[1][i]=abs(x-p[1][i].l)+p[1][i].t;
        for (i=2; i<=m; ++i)
            make(i);
        int ans=inf;
        for (i=1; i<=n; ++i)
            ans=min(ans,f[m][i]);
        printf("%d\n",ans);
    }
    return 0;
}