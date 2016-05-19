#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll __int64
ll n;

ll solve(ll n)
{
    ll p,ans = 0,tem,mod = 1e9,t;
    if(!n) return 0;
    while(n)
    {
        p = n/mod;
        if(p>=4)
        {
            t = 1;
            while(n)
            {
                t*=4;
                n/=10;
            }
            ans += t/4*3;
        }
        else
        {
            tem = n/10;
            t = p;
            if(!tem)
                ans+=t;
            else
            {
                while(tem)
                {
                    t*=4;
                    tem/=10;
                }
                ans+=t/4*3;
            }
        }
        n%=mod;
        mod/=10;
    }
    return ans;
}

int main()
{
    while(~scanf("%I64d",&n))
        printf("%I64d\n",solve(n));

    return 0;
}
