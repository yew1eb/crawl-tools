#include <stdio.h>
int gcd(int a, int b)
{
    return b? gcd(b,a%b):a;
}
int main()
{
    int n, a, b;
    while(~scanf("%d",&n))
    {
        scanf("%d",&a);n--;
        while(n--)
        {
            scanf("%d",&b);
            a = a/gcd(a,b)*b;
        }
        printf("%d\n",a);
    }
    return 0;
}
