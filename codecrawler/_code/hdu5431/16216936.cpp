#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_set>
using namespace std;
using namespace std::tr1;

#define LL __int64

const int N = 7 * 1e6;
const int LEN = 20000 + 5;

LL a[N];
int tot;

char str[N];

unordered_set<LL> myset;

void init(int n) {
    myset.clear();
    tot = 0;
}

void deal(char str[]) {
    int len = strlen(str);
    init(len);
    for(int i = 1; i <= min(31, len); ++i) {
        LL num = 0;
        for(int j = 0; j < i; ++j) {
            LL add = 0;
            if(str[j] == 'B') add = 1;
            num = num * 2 + add;
        }
        LL h = (1LL << i) + num;
        if(myset.find(h) == myset.end()) {
            myset.insert(h);
            a[tot++] = h;
        }
        LL sub = (1LL << i);
        for(int j = i; j < len; ++j) {
            LL add = 0;
            if(str[j] == 'B') add = 1;
            num = num * 2 + add;
            if(str[j - i] == 'B') num -= sub;
            h = (1LL << i) + num;
            if(myset.find(h) == myset.end()) {
                myset.insert(h);
                a[tot++] = h;
            }
        }
    }
}

int ok(LL x, LL r) {
    LL p = lower_bound(a, a + tot, x) - a;

    LL tmp_r = x - 1 - p;
    if(a[p] == x) -- tmp_r;

    if(tmp_r < r) return -1;
    else {
        if(p < tot && a[p] == x) return 0;
        return 1;
    }

}

LL gao(int rank) {
    sort(a, a + tot);

    LL L = 1, R = (1LL << 33) - 1;
    
    LL ret = R;

    while(L < R) {
        LL mid = (L + R) >> 1;
        int flag = ok(mid, rank);

        if(flag == 0) {
            R = mid - 1;
        } else if(flag == 1) {
            R = mid;
            ret = min(ret, R);
        } else {
            L = mid + 1;
        }
    }

    if(ok(R, 1) == 1) ret = min(ret, R);
    
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", str);
        deal(str);
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            int r;
            scanf("%d", &r);
            LL ans = gao(r);

            int len = 0;
            LL tmp_ans = ans;
            while(tmp_ans) {
                ++len;
                tmp_ans /= 2;
            }
            
            ans -= (1LL << len);

            if(ans == 0) puts("A");
            else {
                for(int i = len - 2; i >= 0; --i) {
                    if(ans & (1LL << i)) {
                        printf("B");
                    } else {
                        printf("A");
                    }
                }
                puts("");
            }
        }
    }
    return 0;
}
