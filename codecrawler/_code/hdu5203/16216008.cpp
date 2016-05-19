#include <iostream>
using namespace std;

int main() {
    int n, m, temp;
    while (scanf("%d%d", &n, &m) != EOF) {
        int left = 0x3f3f3f3f, right = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d", &temp);
            left = min(left, temp);
            right = max(right, temp);
        }
        int len_L = left - 1;
        int len_R = n - right;

        if (len_L == 0 && len_R == 0) {
            printf("0\n");

        } else if (len_L != 0 && len_R != 0) {
            long long cnt = 0, ans = 0;
            int len_max = max(len_L, len_R);
            int len_min = min(len_L, len_R);
            for (int i = 1; i <= len_max / 2; i++)
                if (len_L + len_R > 2 * max(len_min, max(i, len_max - i))) {
                    if (i == len_max - i)
                        ans--;
                    cnt++;
                }
            cout << ans + cnt * 2 << endl;

        } else if ((len_L == 0 && len_R != 0) || (len_L != 0 && len_R == 0)) {
            long long cnt = 0;
            int len = len_L + len_R;
            for (int i = 1; i <= (len-1) / 2; i++) {
                len_L = len - i - (len-1) / 2;
                cnt += (len - 1) / 2 - len_L + 1;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
