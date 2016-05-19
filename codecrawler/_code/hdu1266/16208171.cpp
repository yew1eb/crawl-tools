#include<stdio.h>
#include<string.h>
#define MAXN 10000

char a[MAXN];
int main()
{
    int t, n, i, len;
    int k;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%s", &a);
        len = strlen(a);
        for(k = len - 1; k >= 0; k--)
        {
            if(a[k] != '0')
                break;
        }
        if(a[0] == '-')
        {
            printf("-");
            for(i = k; i >= 1; i--)
                printf("%c", a[i]);
            for(i = k + 1; i < len; i++)
                printf("0");
        }
        else
        {
            for(i = k; i >= 0; i--)
                printf("%c", a[i]);
            for(i = k + 1; i < len; i++)
                printf("0");
        }
        printf("\n");
    }
    return 0;
}
