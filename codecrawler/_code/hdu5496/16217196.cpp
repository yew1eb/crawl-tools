#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

typedef  long long LL;
#define MOD 1000000007
const int maxn = 111111;

map<int, int> mp;
int p[maxn];

int main() {
    int T;
    scanf("%d", &T);
    p[0] = 1;
    for(int i = 1; i < maxn; i++)
        p[i] = p[i-1]*2 % MOD;
    while(T--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        mp.clear();
        for(int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            ans = (ans + (LL)x*p[n-i]%MOD*p[i-1]) % MOD;
            ans = ((ans - (LL)x*p[n-i]%MOD*mp[x]%MOD)+MOD) %MOD;
            mp[x] = (mp[x]+p[i-1]) % MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}
