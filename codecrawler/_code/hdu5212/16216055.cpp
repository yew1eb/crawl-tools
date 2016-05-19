#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#define Max(a,b) a>b?a:b
#define Min(a,b) a<b?a:b
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int mod = 10007;
const int maxn = 10000+5;
int T,n,m;
ll a[maxn],cnt[maxn],d[maxn];
int main() {
    while(~scanf("%d",&n)) {
        ll maxv = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(d, 0, sizeof(d));
        for(int i=0;i<n;i++) {
            scanf("%I64d",&a[i]);
            cnt[a[i]]++;
            maxv = max(maxv, a[i]);
        }
        ll ans = 0;
        for(int i=2;i<=maxv;i++) {
            for(int j=i;j<=maxv;j+=i) {
                d[i] += cnt[j];
            }
            d[i] *= d[i];
        }
        for(ll i=maxv; i>1; i--) {
            for(int j=i*2;j<=maxv;j+=i) {
                d[i] -= d[j];
            }
            ans = (ans+(i*(i-1))*d[i]%mod)%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
