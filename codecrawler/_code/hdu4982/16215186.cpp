#include <cstdio>
#include <cstring>
#include <cmath>

int n, k;

bool judge(int num) {
    int yu = num * num;
    int kk = n - yu;
    if (kk == 0) return false;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < k - 2; i++) {
    cnt++;
    if (cnt == kk) cnt++;
    sum += cnt;
    }
    if (sum + kk >= n) return false;
    int need = n - sum - kk;
    if (need <= cnt) return false;
    cnt++;
    if (kk == cnt || kk == cnt + 1) {
    if (need == kk) return false;
    }
    return true;
}

bool solve() {
    int m = sqrt(n * 1.0);
    for (int i = m; i >= 1; i--) {
    if (judge(i)) {
        return true;
    }
    }
    return false;
}

int main() {
    while (~scanf("%d%d", &n, &k)) {
    if (solve()) printf("YES\n");
    else printf("NO\n");
    }
    return 0;
}