#include <stdio.h>
typedef long long LL;

LL gcd(LL a, LL b)
{
    return b?gcd(b, a % b): a;
}
int main()
{
    int t, n, a, b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n, &a);
        while(--n)
        {
            scanf("%d",&b);
            a = a/gcd(a,b)*b;
        }
        printf("%d\n",a);
    }
    return 0;
}
