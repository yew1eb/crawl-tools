#include <stack>
#include <cstdio>
#include <list>
#include <cassert>
#include <set>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <string>
#include <map>
#include <cmath>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define X first
#define Y second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
#define FOR(i, a, b) for (int i=(a); (i) < (b); (i)++)
#define FOOR(i, a, b) for (int i = (a); (i)<=(b); (i)++)
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-4;
const int MAXN = 10;
const int MOD = 10000007;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
const int seed = 131;
int cases = 0;
typedef pair<int, int> pii;

map<string, int> mp;
int len[2];

int main()
{
    //ROP;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        MS(len, 0);
        mp.clear();
        int n;
        scanf("%d", &n);
        LL ans = 0;
        string str;
        FOR(i, 0, n)
        {
            cin >> str;
            ans += mp[str] + len[(SZ(str)&1)^1];    //len[0]è¡¨ç¤ºå¶æ°ä¸²çä¸ªæ°ï¼1æ¯å¥æ°ä¸²çä¸ªæ°
            mp[str]++;
            len[SZ(str)&1]++;
        }
        LL y = n*(n-1)/2;
        LL gcd = __gcd(ans, y);
        ans /= gcd, y /= gcd;
        printf("%I64d/%I64d\n", ans, y);
    }
    return 0;
}