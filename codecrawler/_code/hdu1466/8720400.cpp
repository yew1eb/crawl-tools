#include <stdio.h>
#include <string.h>
const int maxn = 21;
int f[maxn][191];
void init()
{
    int i, j, k;
    memset(f,0,sizeof(f));
    for(i=1; i<maxn; i++)
        f[i][0] = 1;
    for(i=1; i<maxn; i++)
        for(j=0; j<i; j++)
            for(k=0; k<=(i-j)*(i-j-1)/2; k++)
                if(f[i-j][k])
                    f[i][(i-j)*j+k] = 1;
}
int main()
{
    int n, i;
    init();
    while(~scanf("%d",&n))
    {
        printf("0");
        for(i=1; i<=n*(n-1)/2; i++)
            if(f[n][i])
                printf(" %d",i);
        printf("\n");
    }
    return 0;
}
