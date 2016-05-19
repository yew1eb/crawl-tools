#include <stdio.h>
#include <string.h>
#define INF 1000000000
int max(int a,int b)
{
    return a>b?a:b;
}
int f[40000];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k;
        for(i=0;i<=n;i++)
            f[i]=0;
        f[0]=1;
        for(i=1;i<=3;i++)
        {
            for(j=i;j<=n;j++)
            f[j]=f[j-i]+f[j];
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
