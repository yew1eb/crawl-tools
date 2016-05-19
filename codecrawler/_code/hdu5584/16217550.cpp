#include <bits/stdc++.h>
using namespace std;

long long ans;

void dfs (long long a, long long b) {
    if (a > b)
        swap (a, b);
    ans++;
    long long g = __gcd (a, b);
    long long aa = a/g, bb = b/g;
    if (bb%(aa+1) == 0) {
        long long ans = bb/(aa+1);
        long long x = ans*g, y = a;
        dfs (x, y);
    }
}

int main () {
    int t, kase = 0;
    long long a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        ans = 0;
        dfs (a, b);
        printf ("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}
