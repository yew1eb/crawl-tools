#include <stdio.h>
__int64 pow(int n)
{
    __int64 s = 1;
    for(int i = 1;i<=n;i++)
    s*=3;
    return s;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a;
        __int64 ans;
        scanf("%d",&a);
        ans = pow(a);
        printf("%I64d\n",ans);

    }

    return 0;
}
