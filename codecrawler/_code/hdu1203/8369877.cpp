#include <stdio.h>
#define MAXN 10001
int v[MAXN];
double f[MAXN], p[MAXN];

int main()
{
    int V, n, i, j;
    while(scanf("%d%d",&V, &n),V+n)
    {
        for(i=0; i<n; ++i)
        {
            scanf("%d%lf",&v[i],&p[i]);
            p[i] = 1 - p[i];
        }
        for(i=0; i<=V; ++i) f[i] = 1.0;
        for(i=0; i<n; ++i)
        {
            for(j=V;j>=v[i];--j)
                if(f[j]> f[j-v[i]]*p[i])
                    f[j] = f[j-v[i]]*p[i];
        }
        printf("%.1lf%%\n",(1-f[V])*100);
    }
    return 0;
}
