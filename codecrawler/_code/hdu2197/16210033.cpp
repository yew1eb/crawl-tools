#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;
const int mod = 2008;

map<int, int > mp;

int pow_mod(int a, int n) {
    int ans = 1;
    int tmp = a;
    while (n) {
        if (n & 1) 
            ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;
        n >>= 1;
    }
    return ans;
}

int cal(int x) {
    if (mp[x] != 0) return mp[x];
    if (x == 1) return mp[x] = 2;
    int ans = pow_mod(2, x);
    ans = (ans - 2 + mod) % mod;
    for (int i = 2; i*i <= x; i++) {
        if (x % i != 0) continue;
        if (i * i == x) {
            ans -= cal(i);
            continue;
        }
        else {
            ans = (ans - cal(i) + mod) % mod;
            ans = (ans - cal(x/i) + mod) % mod;
        }
    }
    return mp[x] = (ans + mod) % mod;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", cal(n));
    }
    return 0;
}