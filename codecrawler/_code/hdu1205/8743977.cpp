#include <stdio.h>

int main()
{
    int t, n, i, x;
    long long sum,max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum = max = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&x);
            sum += x;
            if(max<x) max = x;
        }
        if(max>(sum+1)/2)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
