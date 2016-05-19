#include<stdio.h>

int main(void)
{
    __int64 a, b;

    while(scanf("%I64X%I64X", &a, &b) != EOF)
        printf(a+b<0?"-%I64X\n":"%I64X\n", a+b<0?-a-b:a+b);
    return 0;
}
            
