#include <stdio.h>
#include <string.h>

int main()
{
    int n,m;
    __int64 a[25][25];
    int i,j;
    memset(a,0,sizeof(a));
    for(i = 0; i<=20; i++)
    {
        a[i][0] = 1;
    }
    for(i = 1; i<=20; i++)
    {
        for(j = 1; j<=20; j++)
        {
            if(i<j)
            break;
            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }
    while(~scanf("%d%d",&n,&m))
    {
        printf("%I64d\n",a[n][m]);
    }

    return 0;
}
