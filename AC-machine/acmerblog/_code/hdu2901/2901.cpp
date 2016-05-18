#include <cstdio>

using namespace std;

typedef long long ll;
int mod;
ll mypow(ll a, ll n)
{
    ll ret = 1;
    while(n)
    {
        if(n%2) ret = (ret*a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return ret;
}
int cal(int a, int b)
{
    if(a&1) return 0;
    return mypow(a/2,b);
}
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)==2)
    {
        mod = a;
        printf("%d\n",cal(a,b));
    }
}