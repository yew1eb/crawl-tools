#include<stdio.h>
int main()
{
    int f[100];
    int n, i, x;
    f[1]=4;
    for(i=2;i<=30;i++)
       f[i]=(f[i-1]-1)*2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
     {
        scanf("%d",&x);
        printf("%d\n",f[x]);
     }
    return 0;
}
