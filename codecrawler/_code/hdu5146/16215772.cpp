#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::sort;
using std::set;
using std::map;
using std::pair;
using std::vector;
using std::multiset;
using std::multimap;
#define pb(e) push_back(e)
#define sz(c) (int)(c).size()
#define mp(a, b) make_pair(a, b)
#define all(c) (c).begin(), (c).end()
#define iter(c) decltype((c).begin())
#define cls(arr,val) memset(arr,val,sizeof(arr))
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
const int Max_N = 1010;
typedef unsigned long long ull;
int arr[Max_N];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w+", stdout);
#endif
    int t, n;
    ull sum1, sum2;
    scanf("%d", &t);
    while (t--) {
        bool f = false;
        sum1 = sum2 = 0;
        scanf("%d", &n);
        rep(i, n) {
            scanf("%d", &arr[i]);
            if (i & 1) sum1 += arr[i];
            else sum2 += arr[i];
        }
        if (sum1 != sum2) { puts("No"); continue; }
        for (int i = 1, j = n; i < j; i++, j--) {
            if (arr[i] != arr[j]) { f = true; break; }
        }
        puts(f ? "Yes" : "No");
    }
    return 0;
}