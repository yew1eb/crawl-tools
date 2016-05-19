#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;
const LL mod = 1000000007;

int n,t;

LL pow1 ( LL num , LL n )
{
    LL ret = 1;
    while ( n )
    {
        if ( n&1 )
        {
            ret *= num;
            ret %= mod;
        }
        num = num*num;
        num %= mod;
        n >>= 1;
    }
    return ret;
}

int main ( )
{
    scanf ( "%d" , &t );
    while ( t-- )
    {
        scanf ( "%d" , &n );
        LL ans = pow1 ( 2 , n-1 );
        cout << (ans-1+mod)%mod << endl;
    }
}