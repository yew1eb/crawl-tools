#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<cctype>
#include<stack>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 100000 + 5;
const int INF = 0x3f3f3f3f;

int A[MX];
int MIN[MX][30], MAX[MX][30];

void RMQ_init(int n) {
    for(int i = 0; i < n + 1; i++) {
        MAX[i][0] = MIN[i][0] = A[i];
    }
    for(int j = 1; (1 << j) <= n + 1; j++) {
        for(int i = 0; i + (1 << j) - 1 < n + 1; i++) {
            MAX[i][j] = max(MAX[i][j - 1], MAX[i + (1 << (j - 1))][j - 1]);
            MIN[i][j] = min(MIN[i][j - 1], MIN[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int RMQ_min(int L, int R) {
    int k = 0;
    while((1 << (k + 1)) <= R - L + 1) k++;
    return min(MIN[L][k], MIN[R - (1 << k) + 1][k]);
}

int RMQ_max(int L, int R) {
    int k = 0;
    while((1 << (k + 1)) <= R - L + 1) k++;
    return max(MAX[L][k], MAX[R - (1 << k) + 1][k]);
}

int getR(int L, int k, int n) {
    int l = L, r = n, m, ans;
    while(l <= r) {
        m = (l + r) >> 1;
        int poor = RMQ_max(L, m) - RMQ_min(L, m);
        if(poor < k) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        RMQ_init(n);

        LL ans = 0;
        for(int L = 1; L <= n; L++) {
            int R = getR(L, k, n);
            ans += R - L + 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
