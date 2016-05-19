#include <stdio.h>
#include <string.h>

int main()
{
    int k = 0,n;
    int a[105];
    char s[100000];
    printf("PERFECTION OUTPUT\n");
    while(~scanf("%d",&n),n)
    {
        int sum = 1,j;
        for(j = 2; j<=n/2; j++)
        {
            if(n%j == 0)
                sum+=j;
        }
        printf("%5d  ",n);
        if(sum == n)
            printf("PERFECT\n");
        else if(sum < n)
            printf("DEFICIENT\n");
        else
            printf("ABUNDANT\n");
    }
    printf("END OF OUTPUT\n");

    return 0;
}
