#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,sum = 0,a,i;
        scanf("%d",&n);
        for(i = 0;i<n;i++)
        {
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n",sum-n+1);
    }

    return 0;
}
