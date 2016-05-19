#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;
const int maxn = 100007;
const double eps = 1e-8;

int num[maxn];

struct Seg {
    int l, r, zero, one;
};

int tot_s;
struct Seg s[maxn];
stack<struct Seg> sta;

int sgn(double x) {
    return x < -eps ? -1 : x > eps;
}

double cal(struct Seg a) {
    double ans = a.one + a.zero;
    ans = a.one / ans;
    return ans;
}
int main() {
//    freopen("in.txt" , "r", stdin);
    int n;
    int test_case;
    scanf("%d", &test_case);
    while (test_case--) {
        scanf("%d", &n);
        double ans = 0;
        int loc_first = 0;
        int loc_last = n + 1;
        tot_s = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &num[i]);
        }
        for (int i = 1; i <= n && num[i] == 0; i++) {
            loc_first = i;
        }
        for (int j = n; j >= 1 && num[j] == 1; j--) {
            loc_last = j;
        }
        loc_last--;
        loc_first++;
        num[n + 1] = 1;
        if (loc_first > loc_last) {
            printf("%.6f\n", ans);
            continue;
        }
        while (loc_first <= loc_last) {
            s[tot_s].l = loc_first;
            while (num[loc_first] == 1) {
                loc_first++;
            }
            s[tot_s].one = loc_first - s[tot_s].l;
            while (num[loc_first] == 0) {
                loc_first++;
            }
            s[tot_s].r = loc_first - 1;
            s[tot_s].zero = s[tot_s].r - s[tot_s].l + 1 - s[tot_s].one;
            tot_s++;
        }
//        for (int i = 0; i < tot_s; i++) {
//            printf("%d %d\n", s[i].l, s[i].r);
//        }
        sta.push(s[0]);
        for (int i = 1; i < tot_s; i++) {
            struct Seg cnt = s[i];
            while (!sta.empty()) {
                double pre_ave = cal(sta.top());
                double cnt_ave = cal(cnt);
                if (sgn(cnt_ave - pre_ave) >= 0) {
                    sta.push(cnt);
                    break;
                }
                struct Seg pre_seg = sta.top();
                sta.pop();
                cnt.l = pre_seg.l;
                cnt.one += pre_seg.one;
                cnt.zero += pre_seg.zero;
            }
            if (sta.empty()) {
                sta.push(cnt);
            }
        }
        while (!sta.empty()) {
            struct Seg cnt = sta.top();
            double ave = cal(cnt);
            ans += (1 - ave) * (1 - ave) * cnt.one + ave * ave * cnt.zero;
            sta.pop();
        }
        printf("%.6f\n", ans);
    }
    return 0;
}
