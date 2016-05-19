#include <stdio.h>
#include <string.h>

int main()
{
    int n,  m;
    int x, Min;
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%d",&Min);
        while(--n)
        {
            scanf("%d",&x);
            if(Min > x) Min = x;
        }
        printf("%d\n", m / Min);

    }
    return 0;
}
