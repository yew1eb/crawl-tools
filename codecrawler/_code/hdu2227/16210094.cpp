#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 1e5 + 5;
const int HS = 1000007;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n;
LL S[MX], A[MX], B[MX];

LL sum(int x) {
    LL ret = 0;
    for(; x; x -= x & -x) {
        ret += S[x];
        ret %= mod;
    }
    return ret;
}

LL query(int L, int R) {
    return (sum(R) - sum(L - 1) + mod) % mod;
}

void update(int x, LL d) {
    for(; x <= n; x += x & -x) {
        S[x] += d;
        S[x] %= mod;
    }
}

int BS(LL A[], int L, int R, int x) {
    int l = L, r = R, m;
    while(l <= r) {
        m = (l + r) >> 1;
        if(A[m] == x) return m;
        if(A[m] < x)  l = m + 1;
        else        r = m - 1;
    }
    return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    while(~scanf("%d", &n)) {
        memset(S, 0, sizeof(S));

        for(int i = 1; i <= n; i++) {
            scanf("%I64d", &A[i]);
            B[i] = A[i];
        }
        sort(A + 1, A + 1 + n);

        LL ans = 0, ret;
        for(int i = 1; i <= n; i++) {
            int pos = BS(A, 1, n, B[i]);
            ret = query(1, pos) + 1;
            update(pos, ret);
            ans = (ans + ret) % mod;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}