#include <stdio.h>
#include <string.h>
int a[] = {150,200,350};
int f[10005];

int main()
{
    int T, n, i, j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1,f[0]=1;i<=n;i++) f[i] = -1;
        for(i=0;i<3; i++)
            for(j=a[i]; j<=n; j++)
                if(f[j-a[i]]==1)
                 {
                     //printf("i=%d,j=%d\n",i,j);
                     f[j] = 1;
                 }
        for(i=n; i>=0; i--)
            if(f[i]==1) break;
        printf("%d\n",n-i);
    }
    return 0;
}
