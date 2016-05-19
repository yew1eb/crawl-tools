#include<stdio.h>
int main()
{
    int t,n,i,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n/2*3;i++)
            scanf("%d%d",&a,&b);
        printf("%d\n",n/2);
    }
    return 0;
}
