#include <stdio.h>

int fun(int a, int b)
{
    int ans;
    if(b==1) return a;
    if(b%2==0)
    {
        ans = fun(a,b/2);
        return (ans%10)*(ans%10) % 10;
    }
    else
    {
        ans = fun(a,b/2);
        return (ans%10)*(ans%10)*(a%10) % 10;
    }
}
int main()
{
    int a, b;
    while(~scanf("%d%d",&a,&b))
    {
        a %= 10;
        printf("%d\n",fun(a,b));
    }
    return 0;
}
