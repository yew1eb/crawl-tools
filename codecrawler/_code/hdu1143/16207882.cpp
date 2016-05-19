#include <stdio.h>

int f[50] = {0};
int i,n;

int main()
{
    f[0] = 1;
    f[2] = 3;
    for(i = 4;i<=30;i+=2)
    {
        f[i] = f[i-2]*4-f[i-4];
    }
    while(~scanf("%d",&n),n>=0)
    {
        printf("%d\n",f[n]);
    }


    return 0;
}
