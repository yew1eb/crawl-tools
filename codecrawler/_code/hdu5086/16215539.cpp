#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long
const ll mod=1000000007;
ll n;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        ll x;
        ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            scanf("%I64d",&x);
            ans=(ans+i*(n-i+1)%mod*x%mod)%mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
