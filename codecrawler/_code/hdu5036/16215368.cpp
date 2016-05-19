#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

const int N = 1005;
int t, n;
bitset<N> bs[N];

int main() {
    int cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            bs[i].reset();
            bs[i][i] = true;
        }
        int num, v;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            while (num--) {
                scanf("%d", &v); v--;
                bs[i][v] = true;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (bs[j][i])
                    bs[j] |= bs[i];
        double ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (bs[j][i]) cnt++;
            ans += 1.0 / cnt;
        }
        printf("Case #%d: %.5lf\n", ++cas, ans);
    }
    return 0;
}