#include <stdio.h>
#include <string.h>
#define max(a,b) a>b ?  a:b
int a[110][110];
int f[110];

int main()
{
    int n,m, i, k, j;
    while(scanf("%d%d",&n,&m),n+m) {
        memset(f,0,sizeof(f));
        for(i=0; i<n; i++)
            for(j=1; j<=m; j++)
                scanf("%d",&a[i][j]);
        for(i=0; i<n; i++)
            for(j=m; j>=0; j--)
                for(k=1; k<=j; k++)
                    f[j] = max(f[j], f[j-k]+a[i][k]);
        printf("%d\n",f[m]);
    }
    return 0;
}
