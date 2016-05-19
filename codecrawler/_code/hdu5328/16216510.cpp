#include <bits/stdc++.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <time.h>
#include <vector>
#include <cstdio>
#include <string>
#include <iomanip>
///cout << fixed << setprecision(13) << (double) x << endl;
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define pi acos(-1.0)
#define eps 1e-8
#define Mp(a, b) make_pair(a, b)
#define asd puts("asdasdasdasdasdf");
typedef long long ll;
//typedef __int64 LL;
const int inf = 0x3f3f3f3f;

ll a[1000010];

int main()
{
    int tot, n;
    scanf("%d", &tot);
    while( tot-- ) {
        scanf("%d", &n);
        for( int i = 1; i <= n; ++i ) 
            scanf("%lld", &a[i]);
        if( n <= 2 ) {
            printf("%d\n", n);
            continue;
        }
        int ans = 2, tmp = 1;
        for( int i = 2; i < n; ++i ) {
            if( a[i] * 2 == a[i-1] + a[i+1] ) {
                ans = max( ans, i+2 - tmp );
            }
            else {
                tmp = i;
            }
        }
        tmp = 1;
        for( int i = 2; i < n; ++i ) {
            if( a[i] * a[i] == a[i-1] * a[i+1] ) {
                ans = max( ans, i+2 - tmp );
            }
            else {
                tmp = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}