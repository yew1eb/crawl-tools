#include <stdio.h>
#include <string.h>
#define MAXN 1005
int a[MAXN+1];
int f[MAXN+1];
int LIS(int n)
{
    int i, j, max;
    memset(f,0,sizeof(f));
    f[0] = a[0];
    for(i=1; i<n; ++i)
    {
        max =0;
        for(j=0; j<i; ++j)
            if(a[i] > a[j] && max < f[j]) max = f[j];
        f[i] = max + a[i];
    }
    max = 0;
    for(i=0; i<n; ++i)
        if(max < f[i]) max = f[i];
    return max;
}
int main()
{
    int i, n;
    while(~scanf("%d",&n),n)
    {
        for(i=0; i<n; ++i) scanf("%d",&a[i]);
        printf("%d\n", LIS(n) );
    }
    return 0;
}
