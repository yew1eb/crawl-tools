#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
#define MAXN 131071
struct HashNode { ll data, id, next; };
HashNode hash[MAXN<<1];
bool flag[MAXN<<1];
ll top;

void Insert ( ll a, ll b )
{
    ll k = b & MAXN;
    if ( flag[k] == false )
    {
        flag[k] = true;
        hash[k].next = -1;
        hash[k].id = a;
        hash[k].data = b;
        return;
    }
    while( hash[k].next != -1 )
    {
        if( hash[k].data == b ) return;
        k = hash[k].next;
    }
    if ( hash[k].data == b ) return;
    hash[k].next = ++top;
    hash[top].next = -1;
    hash[top].id = a;
    hash[top].data = b;
}

ll Find ( ll b )
{
    ll k = b & MAXN;
    if( flag[k] == false ) return -1;
    while ( k != -1 )
    {
        if( hash[k].data == b ) return hash[k].id;
        k = hash[k].next;
    }
    return -1;
}

ll gcd ( ll a, ll b )
{
    return b ? gcd ( b, a % b ) : a;
}

ll ext_gcd (ll a, ll b, ll& x, ll& y )
{
    ll t, ret;
    if ( b == 0 )
    {
        x = 1, y = 0;
        return a;
    }
    ret = ext_gcd ( b, a % b, x, y );
    t = x, x = y, y = t - a / b * y;
    return ret;
}

ll mod_exp ( ll a, ll b, ll n )
{
    ll ret = 1;
    a = a % n;
    while ( b >= 1 )
    {
        if( b & 1 )
            ret = ret * a % n;
        a = a * a % n;
        b >>= 1;
    }
    return ret;
}

ll BabyStep_GiantStep ( ll A, ll B, ll C )
{
    top = MAXN;  B %= C;
    ll tmp = 1, i;
    for ( i = 0; i <= 100; tmp = tmp * A % C, i++ )
        if ( tmp == B % C ) return i;

    ll D = 1, cnt = 0;
    while( (tmp = gcd(A,C)) !=1 )
    {
        if( B % tmp ) return -1;
        C /= tmp;
        B /= tmp;
        D = D * A / tmp % C;
        cnt++;
    }

    ll M = (ll)ceil(sqrt(C+0.0));
    for ( tmp = 1, i = 0; i <= M; tmp = tmp * A % C, i++ )
        Insert ( i, tmp );

    ll x, y, K = mod_exp( A, M, C );
    for ( i = 0; i <= M; i++ )
    {
        ext_gcd ( D, C, x, y ); // D * X = 1 ( mod C )
        tmp = ((B * x) % C + C) % C;
        if( (y = Find(tmp)) != -1 )
            return i * M + y + cnt;
        D = D * K % C;
    }
    return -1;
}

int main()
{
    ll A, B, C;
    while( scanf("%I64d%I64d%I64d",&A,&C,&B ) !=EOF )
    {
    	if(B>C) {
		printf("Orz,I can’t find D!\n");
		continue;
    	}
        memset(flag,0,sizeof(flag));
        ll tmp = BabyStep_GiantStep ( A, B, C );
        if ( tmp == -1 )puts("Orz,I can’t find D!");
        else printf("%I64d\n",tmp);
    }
    return 0;
}