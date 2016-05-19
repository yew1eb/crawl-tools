#include <stdio.h>
#include <string.h>
int main()
{
    int n, m, x, price;
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%d",&price);
        while(--n)
        {
            scanf("%d",&x);
            if(price > x) price = x;
        }
        printf("%d\n", m/price);
    }

    return 0;
}
