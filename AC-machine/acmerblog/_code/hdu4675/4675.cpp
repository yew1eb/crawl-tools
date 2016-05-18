#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//

const int V = 300000 + 50;
const int inf = 0x7fffffff;
const int mod = 1000000000 + 7;
int n, m, k;
int sum[V];
__int64 ans[V], d[V], e[V];
__int64 Quick_Pow(__int64 a, __int64 b) {
    __int64 res = 1;
    while(b) {
        if(b & 1)
            res = (res * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return res % mod;
}
__int64 Cal(__int64 n, __int64 k) {
    return (d[n] * e[k] % mod) * e[n - k] % mod;
}
int main() {
    int i, j;
    d[0] = e[0] = 1;
    for(i = 1; i < V; ++i) {
        d[i] = (d[i - 1] * i) % mod;
        e[i] = Quick_Pow(d[i], mod - 2);
    }
    while(~scanf("%d%d%d", &n, &m, &k)) {
        memset(sum, 0, sizeof(sum));
        for(i = 0; i < n; ++i) {
            int temp;
            scanf("%d", &temp);
            sum[temp]++;
        }
        for(i = m; i >= 1; --i) {
            int sum_d = 0;
            for(j = i; j <= m; j += i)
                sum_d += sum[j];
            if(n - sum_d > k) {
                ans[i] = 0;
                continue;
            }
            ans[i] = (Quick_Pow(m / i, n - sum_d) * Quick_Pow(m / i - 1, k - (n - sum_d)) % mod) * Cal(sum_d, k - (n - sum_d)) % mod;
            //减去重复的
            for(j = 2 * i; j <= m; j += i)
                ans[i] = (ans[i] - ans[j] + mod) % mod;
        }
        for(i = 1; i < m; ++i)
            printf("%I64d ", ans[i]);
        printf("%I64d\n", ans[m]);
    }
}
