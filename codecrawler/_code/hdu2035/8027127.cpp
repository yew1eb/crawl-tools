#include <stdio.h>
int pow_mod(int a, int b, int m)
{
    int ans = 1;
    while(b)
    {
        if(b&1)
        {
            ans = ans*a % m;
            b--;
        }
        b /=2;
        a = a*a % m;
    }
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