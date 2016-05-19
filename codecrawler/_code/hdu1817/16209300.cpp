#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <string.h>
using namespace std;
typedef __int64 ll;
ll ans, sum;

ll pow(int a, int b)
{
    ll as = 1;
    for(int i = 0; i < b; i++)
        as *= a;
    return as;
}

int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}

ll solve(int n)
{
    sum = 0;
    if(n == 0)
        return 0;
    for(int i = 1; i <= n ;i++)///æè½¬ç½®æ¢
        sum += (ll)pow(3,gcd(i,n));
    if(n % 2 == 0)///ç¿»è½¬ç½®æ¢nä¸ºå¶æ°
    {
        sum += (ll)pow(3,n/2+1)*n/2;
        sum += (ll)pow(3,n/2)*n/2;
    }
    else
        sum += (ll)pow(3,(n+1)/2)*n;
    ans = sum / (2 * n);
    return ans;
}


int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n == -1)
            break;
        printf("%I64d\n",solve(n));
    }
    return 0;
}
