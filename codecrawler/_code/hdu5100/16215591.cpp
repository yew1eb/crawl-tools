#include<stdio.h>
int main()
{
    int t,n,k,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(n<k)
        {
            printf("0\n");
            continue;
        }
        m=n%k;
        if(2*m<=k)
        {
            printf("%d\n",n*n-m*m);
        }
        else
        {
            printf("%d\n",n*n-(k-m)*(k-m));
        }
    }
    return 0;
}
