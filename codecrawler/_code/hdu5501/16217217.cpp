#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define fuck printf("fuck")
#define FIN freopen("input.txt","r",stdin)
#define FOUT freopen("output.txt","w+",stdout)
using namespace std;
typedef long long LL;

const int MX = 3000 + 5;

int T, n, m;
int dp[MX];

struct Data {
    int a, b, c;
    Data() {}
    Data(int _a, int _b, int _c) {
        a = _a; b = _b; c = _c;
    }
    bool operator<(const Data &P) const {
        return (LL)b * P.c > (LL)P.b * c;
    }
} D[MX];

int main() {
    //FIN;
    scanf("%d", &T);
    while(T--) {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &n, &m);

        for(int i = 1; i <= n; i++) {
            scanf("%d%d%d", &D[i].a, &D[i].b, &D[i].c);
        }
        sort(D + 1, D + 1 + n);

        for(int i = 1; i <= n; i++) {
            for(int j = m; j >= D[i].c; j--) {
                dp[j] = max(dp[j], dp[j - D[i].c] + D[i].a - D[i].b * j);
            }
        }
        int ans = 0;
        for(int i = 0; i <= m; i++) {
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
