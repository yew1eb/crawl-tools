#include <stdio.h>

int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a == 0 && b == 0)
        {
            printf("0\n");
            continue;
        }
        if(a!=b && a!=b+2)
        {
            printf("No Number\n");
            continue;
        }
        if(a%2)
        {
            printf("%d\n",a+b-1);
        }
        else
        {
            printf("%d\n",a+b);
        }
    }

    return 0;
}
