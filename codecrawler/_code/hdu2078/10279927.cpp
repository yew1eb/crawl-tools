#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, t, Min, x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        Min = 1000;
        while(n--)
        {
            scanf("%d",&x);
            if(Min > x) Min  =x;
        }
        int ans = (100 - Min) * (100 - Min);
        printf("%d\n",ans);
    }
    return 0;
}
