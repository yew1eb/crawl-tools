#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 1e4 + 10;
const int Mod = 10007;

int cnt[MaxN], F[MaxN];

int main() {
    int n, a;
    while(~scanf("%d", &n)) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++) {
            scanf("%d", &a);
            for(int j = 1; j * j <= a; j++) {
                if(a % j == 0) {
                    cnt[j]++;
                    if(j * j != a)
                        cnt[a / j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 10000; i >= 1; i--) {
            F[i] = cnt[i] * cnt[i] % Mod;
            for(int j = i * 2; j <= 10000; j += i)
                F[i] = (F[i] - F[j] + Mod) % Mod;
            int p = i * (i - 1) % Mod;
            ans = (ans + p * F[i] % Mod) % Mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}