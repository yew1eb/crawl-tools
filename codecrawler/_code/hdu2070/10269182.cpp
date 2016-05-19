#include <stdio.h>
#include <string.h>

int main()
{
    __int64 f[60];
    int n;
    f[0] = 0; f[1] = 1;
    for(int i=2; i<=50; ++i)
        f[i] = f[i-1] + f[i-2];
    while(~scanf("%d",&n) )
    {
        if(n==-1) break;
        printf("%I64d\n",f[n]);
    }
    return 0;
}