#include <stdio.h>
#include <string.h>

int main()
{
    int a, b;
    while(~scanf("%x %x",&a,&b))
    {
        printf("%d\n",a+b);
    }
    return 0;
}
