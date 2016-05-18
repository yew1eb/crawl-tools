#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int k, i, j, d;
    int bin[32] = {0};
    char str[4];
    
    while (scanf("%d",&k) != EOF)
    {
        getchar();
        for (i = 0; i < k; i++)
        {
            gets(str);
            if( strcmp(str, "- -") == 0 )
                bin[i] = 1;
            else
                bin[i] = 0;
        }
        d = 0;
        for (j = k-1; j >= 0; j--)
            d += bin[j] * pow(2, k-1-j);
        printf("%d\n", d);
    }

    return 0;
}