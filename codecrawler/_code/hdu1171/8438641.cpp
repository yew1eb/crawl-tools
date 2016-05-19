#include <stdio.h>
#include <string.h>
#define N 60
int f[100000];
int v[N], m[N];

int main()
{
    int i, j, k, sum, n;
    while(scanf("%d",&n))
    {
        if(n<0) break;
        for(i=0,sum=0;i<n; i++)
        {
            scanf("%d%d",&v[i],&m[i]);
            sum += v[i]*m[i];
        }
        memset(f,0,sizeof(f));
        f[0] = 1;
        for(i=0; i<n; i++)
            for(j=m[i];j>0; j--)
            for(k=sum/2; k>=j*v[i]; k--)
                if(f[k-j*v[i]])
                    f[k] = 1;
        for(i=sum/2; i>0; i--)
        {
            if(f[i]) break;
        }
        if(i<sum-i) i = sum-i;
        printf("%d %d\n",i,sum-i);
    }
    return 0;
}




