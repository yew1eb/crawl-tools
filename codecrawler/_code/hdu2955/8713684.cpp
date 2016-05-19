#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <string.h>
#define MAXN 105

int main()
{
    int T, n, i, j, sum;
    double P, b[MAXN], f[MAXN*MAXN];
    int a[MAXN];
    scanf("%d",&T);
    while(T--) {
        scanf("%lf%d",&P, &n);
        for(i=0,sum=0; i<n; i++) {
            scanf("%d%lf",&a[i],&b[i]);
            sum += a[i];
        }
//        memset(f,0,sizeof(f));
        for(i=1; i<=sum; i++) f[i] = 0.0;
        f[0] = 1.0;
        for(i=0; i<n; i++)
            for(j=sum; j>=a[i]; j--)
                if(f[j]<f[j-a[i]]*(1-b[i]))
                    f[j] = f[j-a[i]]*(1-b[i]);
        for(j=sum; j>=0; j--) {
            if(f[j]>=(1.0-P)) {
                printf("%d\n",j);
                break;
            }
        }
    }
    return 0;
}
