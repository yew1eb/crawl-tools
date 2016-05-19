#include <stdio.h>

unsigned int f[100] ={0,1,1};
int main()
{
    int a, b, n, i;
    while(scanf("%d%d%d",&a,&b,&n))
    {
        if(a==0&&b==0&&n==0) break;
        n %=48; if(n==0) n = 48;
        for(i=3;i<=n;i++)
        {
            f[i] =(a*f[i-1] + b*f[i-2]) % 7;
            //printf("i=%d ;%d\n",i,f[i]);
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
