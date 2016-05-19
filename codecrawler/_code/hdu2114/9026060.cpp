#include <stdio.h>
typedef long long LL;
int main()
{
    LL n, ans;
    while(~scanf("%I64d",&n)) {
        ans = (n*(n+1)/2 )% 10000;
        ans = (ans*ans) %10000;
        printf("%04I64d\n",ans);
    }
    return 0;
}
