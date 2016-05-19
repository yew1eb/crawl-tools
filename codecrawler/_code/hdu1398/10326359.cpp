#include <stdio.h>
#include <string.h>

int a[18]={1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289};
int f[400];

int main()
{
    int n, i, j;
    memset(f, 0 ,sizeof f );
    f[0] = 1;
    for(i=0; i<17; ++i)
    {
        for(j=a[i]; j<=300; ++j)
            f[j] += f[j-a[i]];
    }
    while(scanf("%d",&n),n)
    {
        printf("%d\n",f[n]);
    }
    return 0;
}
