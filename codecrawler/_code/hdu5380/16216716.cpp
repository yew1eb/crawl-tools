#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>  
#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <stdlib.h>  
#include <string.h>  
#include <limits.h>  
#include <vector>  
#include <string>  
#include <time.h>  
#include <math.h>  
#include <iomanip>  
#include <queue>  
#include <stack>  
#include <set>  
#include <map>  
const int inf = 1e9;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) pt(x / 10);
    putchar(x % 10 + '0');
}
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
typedef pair<int, int> pii;
ll n, c;
ll in[N], out[N], dis[N];
ll work() {
    ll ans = c*in[0];
    deque<ll> In, o;
    In.push_back(in[0]); o.push_back(c);
    for (int i = 1; i <= n; i++)
    {
        ll tmp = dis[i];
        while (tmp) {
            ll LEF = o.front();
            ll mi = min(tmp, LEF);
            LEF -= mi;
            tmp -= mi;
            o.pop_front();
            if(LEF)
                o.push_front(LEF);
            else
                In.pop_front();
        }
        ll tot = dis[i]; tmp = 0;
        while (!In.empty()) {
            if (In.front() <= out[i])
            {
                tmp += o.front();
                ans -= out[i]*o.front();
                o.pop_front();
                In.pop_front();
            }
            else break;
        }
        if (tmp) {
            ans += out[i] * tmp;
            o.push_front(tmp);
            In.push_front(out[i]);
        }
        while (!In.empty()) {
            if (In.back() >= in[i])
            {
                tot += o.back();
                ans -= In.back()*o.back();
                o.pop_back();
                In.pop_back();
            }
            else break;
        }
        o.push_back(tot);
        In.push_back(in[i]);
        ans += in[i] * tot;
    }
    while (!In.empty()) {
        ans -= o.front() * In.front();
        In.pop_front(); o.pop_front();
    }
    return ans;
}
int main() {
    int T; rd(T);
    while (T--) {
        rd(n); rd(c);
        for (int i = 1; i <= n; i++)rd(dis[i]);
        for (int i = n; i > 1; i--)dis[i] -= dis[i - 1];
        for (int i = 0; i <= n; i++)rd(in[i]), rd(out[i]);        
        pt(work()); puts("");
    }
    return 0;
}
/*
1
3 9
2 4 6
8 2
4 3
6 3
9 6

1
4 9
4 9 12 18
5 1
7 6
3 2
4 2
8 6

1
4 5
2 4 8 10
2 1
2 1
9 3
9 8
7 2

1
9 4
2 4 5 7 8 9 11 14 15
9 8
10 5
8 2
4 3
2 1
7 3
9 6
10 8
5 3
8 5

*/