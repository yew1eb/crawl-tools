#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#define MAX 1000

using namespace std;

typedef long long LL;

LL f[MAX];
map<long long, bool> mp;

void init  ( )
{
    queue<LL> q;
    f[1] = f[0] = 1;
    mp[1] = true;
    mp[0] = true;
    for ( int i = 2 ; i <= 46 ; i++ )
    {
        f[i] = f[i-1] + f[i-2];
        mp[f[i]] = true;
        q.push ( f[i] );
    }
    while ( !q.empty () )
    {
        LL temp = q.front ( );
        q.pop ( );
        for ( int i = 2 ; i <= 46 ; i++ )
        {
            if ( f[i]*temp > 1000000000L ) break;
            if ( mp[f[i]*temp] ) continue;
            mp[f[i]*temp] = true;
            q.push ( f[i]*temp );
        }
    }
    
}

int main ( )
{
    init ( );
    int t;
    LL n;
    scanf ( "%d" , &t );
    while ( t-- )
    {
        scanf ( "%lld" , &n );
        if ( mp[n] ) puts ( "Yes" );
        else puts ( "No" );
    }
    
}