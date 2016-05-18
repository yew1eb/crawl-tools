#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
// #pragma commet(linker, "/STACK:102400000, 102400000")
using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<PII> VPII;

template <class T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template <class T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

const int N = 105;
const double INF = 1e20;

struct Rec {
    int i, j, k;
    Rec(int a, int b, int c) : i(a), j(b), k(c) {}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int n;
string a, b, x, y;

void getIn(string& x) {
    char s[1005];
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l / 2; i++) swap(s[i], s[l - i - 1]);

    int k = 0; while (s[k] == '0') s[k++] = '9';
    s[k]--;
    x.resize(0);
    for (int i = 0; i < n; i++) {
        if ((s[0] - '0') & 1) x += '1'; else x += '0';
        int jw = 0;
        for (int i = l - 1; i >= 0; i--) {
            int val = s[i] - '0' + jw * 10;
            jw = val & 1;
            s[i] = (val >> 1) + '0';
        }
    }
}

int main() {
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &n);
        getIn(a);
        getIn(x);
        getIn(b);
        getIn(y);

        bool flag = false;
        for (int t = 0; t < n; t++) {
            bool ff = true;
            for (int i = 0; i < n; i++) {
                int k = i + t;
                if (k >= n) k -= n;
                if ((a[k] == b[k]) ^ (x[i] == y[i])) { ff = false; break; }
            }
            if (ff) { flag = true; break; }
        }
        if (flag) printf("Case %d: Yes\n", cas);
        else printf("Case %d: No\n", cas);
    }
    return 0;
}