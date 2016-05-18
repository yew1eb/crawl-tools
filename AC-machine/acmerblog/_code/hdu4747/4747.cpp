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

const int MOD = 1000000007;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

bool cmp(const PII& a, const PII& b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 200010;

PII b[N];
int n, m, a[N], vis[N], next[N];

#define lson step << 1
#define rson step << 1 | 1

struct Node {
    int left , right;
    int mx , lazy;
    LL sum; 
}L[N << 2];
void pushUp (int step) {
    L[step].sum = L[lson].sum + L[rson].sum;
    L[step].mx = max (L[lson].mx , L[rson].mx);
}
void update (int step , int l , int r , int w) ;
void pushDown (int step) {
    int l = L[step].left , r = L[step].right , m = (l + r) >> 1;
    int &z = L[step].lazy;
    if (z != -1) {
        update (lson , l , m , z);
        update (rson , m + 1 ,r , z);
        z = -1;
    }
}
void bulid (int step , int l , int r) {
    L[step].left = l;
    L[step].right = r;
    L[step].mx =  L[step].sum = 0;
    L[step].lazy = -1;
    if (l == r) return ;
    int m = (l + r) >> 1;
    bulid (lson , l , m);
    bulid (rson , m + 1 , r);
}
void update (int step , int p , int w) {
    if (L[step].left == L[step].right) {
        L[step].mx = L[step].sum = w;
        return ;
    }
    pushDown (step);
    int m = (L[step].left + L[step].right) >> 1;
    if (p <= m) update (lson , p , w);
    else update (rson , p , w);
    pushUp (step);
}
void update (int step , int l , int r , int w) {
    if (L[step].left == l && L[step].right == r) {
        L[step].lazy = w;
        L[step].mx = w;
        L[step].sum = (r - l + 1) * 1LL * w;
        return ;
    }
    pushDown (step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) update (lson , l , r , w);
    else if (l > m) update (rson , l , r , w);
    else {
        update (lson , l , m , w);
        update (rson , m + 1 , r , w);
    }
    pushUp (step);
}
int queryp (int step , int w) {
    if (L[step].mx <= w) return n + 1;
    if (L[step].left == L[step].right) return L[step].left;
    pushDown (step);
    int m = (L[step].left + L[step].right) >> 1;
    if (L[lson].mx > w) return queryp (lson , w);
    else return queryp (rson , w);

}
LL querys (int step , int l , int r) {
    if (L[step].left == l && L[step].right == r) 
        return L[step].sum ;
    pushDown (step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) return querys (lson , l , r);
    else if (l > m) return querys (rson , l , r);
    else return querys (lson , l , m) + querys (rson , m + 1 , r);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = make_pair(a[i], i);
            next[i] = n + 1;
            vis[i] = false;
        } 
        vis[0] = false;
        sort(b + 1, b + n + 1, cmp); 
        b[n + 1].first = b[n].first, b[n + 1].second = n + 1;
        for (int i = 1; i <= n; i++) {
            if (b[i + 1].first == b[i].first) next[b[i].second] = b[i + 1].second;
        }
        bulid (1 , 1 , n);
        int mmex = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] <= n) vis[a[i]] = true;
            while (vis[mmex]) mmex++;
            update(1 , i, mmex);
        }
        LL ans = 0;
        a[0] = n + 1; next[0] = n + 1;
        for (int l = 1; l <= n; l++) {
            if (a[l - 1] <= mmex) {
                int p0 = queryp(1 ,a[l - 1]);
                if (p0 != -1) 
                    p0 = max (p0, l);
                int p1 = next[l - 1];
                if (p0 >= l && p0 < p1) 
                    update(1 ,p0 , p1 - 1 , a[l - 1]);
            }
            ans += querys(1 , l, n);
        }
        printf("%I64d\n", ans);
    }
    return 0