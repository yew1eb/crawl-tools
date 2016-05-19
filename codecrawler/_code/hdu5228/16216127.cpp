#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <deque>
#include <stack>
#include <cctype>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 20;
const int INF = 0xfffffff;
const double EPS = 1e-8;
const ll MOD = 1e9 + 7;
const ld PI = acos (-1.0);

#define INFL 0x7fffffffffffffffLL
#define met(a, b) memset(a, b, sizeof(a))
#define put(a) cout << setiosflags(ios::fixed) << setprecision(a)

int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        char x;
        int y, ans[N][N];
        met (ans, 0);
        for (int i=0; i<5; i++)
        {
            cin >> x >> y;
            ans[x-'A'][y] = 1;
            if (y == 1) ans[x-'A'][14] = 1;
        }
        int res = 5;
        for (int i=0; i<4; i++)
        {
            for (int j=5; j<=14; j++)
            {
                int tmp = 0;
                for (int k=0; k<5; k++)
                    tmp += ans[i][j-k];
                res = min (res, 5-tmp);

            }
        }
        cout << res << endl;
    }
    return 0;
}
