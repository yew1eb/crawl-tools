#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define REP(i,s,t) for(int (i)=(s);(i)<=(t);++(i))
#define UREP(i,s,t) for(int (i)=(s);(i)>=(t);--(i))
#define INF 0x7FFFFFFF

const int maxn = 100000;

int max_harm[1005];
int accum_harm[1005];
int A, T, P, H;
int max_interval, sum;

bool check(int x) {
    int m = 0;
    for (int i=1;i<=max_interval;++i) {
        if (accum_harm[i]) {
            m += x/i*accum_harm[i];
        }
    }
    if (m + P>= H) return true;
    return false;
}

bool check2(int x) {
    int m = 0;
    for (int i=1;i<=max_interval;++i) {
        if (accum_harm[i]) {
            m += x/i*accum_harm[i];
        }
    }
    if (m >= H) return true;
    return false;
}

int go1(int l, int r) {
    int mid;
    while (l<r) {
        mid = l + (r-l)/2;
        if (check(mid))
            r = mid;
        else
            l = mid+1;
    }
    if(check(r))
        return r;
    return -1;
}

int go2(int l, int r) {
    int mid;
    while (l<r) {
        mid = l + (r-l)/2;
        if (check2(mid))
            r = mid;
        else
            l = mid+1;
    }
    if(check2(r))
        return r;
    return -1;
}

int main() {
    //freopen("input.in", "r", stdin);
    int n;
    while (scanf("%d",&n) && n) {
        memset(accum_harm, 0, sizeof(accum_harm));
        memset(max_harm, 0, sizeof(max_harm));
        max_interval = 100;
        double rate = 0;
        REP(i, 1, n-1) {
            scanf("%d%d",&A, &T);
            max_interval = max(max_interval, T);
            max_harm[T] = max(max_harm[T], A);
            accum_harm[T] += A;
            rate += A*1.0/T;
        }
        scanf("%d%d",&P,&H);
        int low = 1, up = H/rate+100;

        int g1 = go1(low, up);
        int g2 = go2(low, up);
        int k1 = -1, k2 = -1;
        //cout << k1 << ' ' << k2 << endl;
        if (g1 && g2) {
            REP(i, g1, g2) {
                int mx = 0;
                for (int j=1;j<=max_interval;++j) {
                    if (i%j == 0 && mx < max_harm[j])
                        mx = max_harm[j];
                }
                if (mx > P) break;
                if (check2(i-1) == false && check(i) == true && mx <= P) {
                    k1 = i;
                    break;
                }
            }
            UREP(i, g2, g1) {
                int mx = 0;
                for (int j=1;j<=max_interval;++j) {
                    if (i%j == 0 && mx < max_harm[j])
                        mx = max_harm[j];
                }
                if (check2(i-1) == false && check(i) == true && mx <= P) {
                    k2 = i;
                    break;
                }
            }
        }
        if (k1 == -1 || k2 == -1) printf("Impossible\n");
        else
            printf("%d %d\n", k1, k2);
    }
    return 0;
}
