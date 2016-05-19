#include <stdio.h>

int main()
{
    __int64 n, m, tmp;
    while (scanf("%I64X %I64X", &n, &m) != EOF)
    {
        tmp = m + n;
        if (tmp >= 0)
            printf("%I64X\n", tmp);
        else
            printf("-%I64X\n", -tmp);
    }
    return 0;
}