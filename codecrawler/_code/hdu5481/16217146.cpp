#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 110010;
const ll mod = 1000000007;
map<ll, ll> myMap;
ll l[maxn], r[maxn];
vector<ll> vec;
ll cnt[2*maxn];

ll power_mod(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int main() {

    //freopen("aa.in", "r", stdin);
    int T, n;
    ll ans;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        vec.clear();
        myMap.clear();
        ans = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d %I64d", &l[i], &r[i]);
            vec.push_back(l[i]);
            vec.push_back(r[i]);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; ++i) {
            int s = lower_bound(vec.begin(), vec.end(), l[i]) - vec.begin();
            int e = lower_bound(vec.begin(), vec.end(), r[i]) - vec.begin();
            cnt[s]++;
            cnt[e]--;
        }
        int t_n = vec.size();
        for(int i = 1; i < t_n; ++i) {
            cnt[i] += cnt[i-1];
        }
        for(int i = 0; i < t_n; ++i) {
            myMap[vec[i]] = cnt[i];
        }
        map<ll, ll>::iterator it = myMap.begin();
        map<ll, ll>::iterator pit = it; it++;
        for( ; it != myMap.end(); ++it, ++pit) {
            ll x = pit->second;
            ans = (ans + (((it->first - pit->first) * (power_mod(2, x) - 1)) % mod * power_mod(2, n - x)) % mod) % mod;
        }
        if(ans < 0) ans += mod;
        printf("%I64d\n", ans);
    }
    return 0;
}
