#include <stdio.h>

int f[20];

int main()
{
    int i;
    f[1] = 1;
    f[2] = 2;
    for(i = 3;i<20;i++)
    f[i] = f[i-1]+f[i-2];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&i);
        printf("%d\n",f[i]);
    }
    return 0;
}
