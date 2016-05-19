#include <stdio.h>

int main()
{
    int t, n, sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum = 0;
        while(n)
        {
            n = n/5;
            sum+=n;
        }
        printf("%d\n",sum);
    }
    return 0;
}
