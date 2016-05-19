#include <stdio.h>
#include <string.h>

int main()
{
    int t,n,a[110];
    int i,j,sum;
    scanf("%d", &t);
    while(t-- && scanf("%d", &n))
    {
        memset(a, 0, sizeof(a));
        for(i = 2; i <= n; i++)
            for(j = 1; j*i <= n; j++)
                a[j*i]++;
        for(sum = 0, i = 1; i <= n; i++)
            if(!(a[i]%2)) sum++;
        printf("%d\n", sum);
    }
    return 0;
}