#include <stdio.h>
int pow_mod(int a, int n, int m)
{
    if(n==1) return a % m;
    int x = pow_mod(a,n/2, m);
    int ans = x*x % m;
    if(n&1) ans = ans*a % m;
    return ans;
}

int main()
{
    int a, b;
    while(scanf("%d%d",&a,&b))
    {
        if(a==0&&b==0) break;
        printf("%d\n",pow_mod(a,b,1000));
    }
}