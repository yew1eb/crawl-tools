#include<algorithm>
#include<iostream>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<complex>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<bitset>
#include<cctype>
#include<math.h>
#include<string>
#include<time.h>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<set>

#define LL long long
#define ULL unsigned long long

using namespace std;
const int mod = 1000000007;
const double PI = acos(-1.0);
const double E = exp(1.0);
const int M = 200005;

LL Pow(LL x, LL n, int Mod)
{
    LL ans = 1;
    while( n ){
        if(n & 1)
            ans = (ans * x) % Mod;
        x = (x * x) % Mod;
        n /= 2;
    }
    return ans;
}

int main()
{
    int t;
    int c;
    LL k1, k2, b1;
    LL b;
    int cas = 1;
    while( cin >> c >> k1 >> b1 >> k2 ){
        LL ans, n;
        cout << "Case #" << cas++ << ":" << endl;
        bool OK = 1;
        for(LL i = 1; i < c; ++i){
            LL temp = Pow(i, k1 + b1, c);
            b = c - temp;
            bool ok = 1;
            for(LL j = 2; j < 50; ++j){
                LL ans1 = Pow(i, k1 * j + b1, c);
                LL ans2 = Pow(b, k2 * j - k2 + 1, c);
                ans = (ans1 + ans2) % c;
                //cout << ans1 << " fdafas" << ans2 << endl;
                if(ans){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                OK = 0;
                cout << i << " " << b << endl;
            }
        }
        if(OK)
            puts("-1");

    }
    return 0;
}