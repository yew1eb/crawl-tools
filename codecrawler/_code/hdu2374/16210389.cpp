#include <cstdio>
int main()
{
    int n, i, j;
    __int64 a[56];
    while(scanf("%d",&n) && n)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%I64d",&a[i]);
        }
        __int64 ans = 0;
        for(i = n; i > 0; i--)
        {
            ans+=a[i];
            for(j = i-1; j > 0; j--)
            {
                a[j]+=a[i];
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}