#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX 107

using namespace std;

int n,m;
int p[MAX],s[MAX];

int main ( )
{
    while ( ~scanf ( "%d%d" , &n , &m ) )
    {
        for ( int i = 1 ; i <= m ; i++ )
            scanf ( "%d%d" , &s[i] , &p[i] );
        int ans = -1;
        for ( int i = 1 ; i <= m ; i++ )
        {
            int temp = (n%s[i]?n/s[i]+1:n/s[i])*p[i];
            if ( ans == -1 ) ans = temp;
            else ans = min ( ans , temp );
        }
        printf ( "%d\n" , ans );
    }
}