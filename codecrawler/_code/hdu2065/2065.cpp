#include<stdio.h>
#include<string.h>
int main()
{
    int T,i;
    int a[6]={1,2,6,20,72,72};
    int b[5][4]={{56,60,12,92},{56,0,52,12},{56,40,92,32},{56,80,32,52},{56,20,72,72}};
    __int64 n,m;
    while(scanf("%d",&T)!=EOF&&T)
    {
        for(i=1;i<=T;i++)
        {
            scanf("%I64d",&n);
            printf("Case %d: ",i);
            if(n<=5)
                printf("%d\n",a[n]);
            else
            {
                m=(n-6)%4;
                n=((n-6)/4)%5;
                printf("%d\n",b[n][m]);
            }
        }
        printf("\n");
    }
    return 0;
}