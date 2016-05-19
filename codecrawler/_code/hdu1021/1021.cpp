#include <stdio.h>

void main()
{
    int n;
    while(scanf("%d", &n) !=EOF)
    {
        if((n - 2) % 4)　// 根据上述规律
           printf("no\n");
        else
           printf("yes\n");
    }
}