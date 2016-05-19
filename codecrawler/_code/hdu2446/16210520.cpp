#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")
#define STOP system("pause")

using namespace std;

typedef unsigned __int64 ll;
int main()
{
    int ncases;
    ll n;

    scanf("%d", &ncases);
    
    while( ncases-- )
    {
        scanf("%I64u", &n);
        ll p = (ll)pow(n*6.0, 1.0/3);
        
        p++;
        while( (p*p*p - p) >= n*6.0 ) p--;
        n -= (p*p*p - p)/6;
        
        ll k = (ll)(sqrt(2.0*n));
        
        k++;
        while( k*(k+1)/2 >= n ) k--;
        
        ll ans1 = k + 1;
        ll ans2 = n - k*(k+1)/2;
        printf("%I64u %I64u %I64u\n", p, ans1, ans2);
    }
    
return 0;
}
