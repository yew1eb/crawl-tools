/***********************************************
 * Author: fisty
 * Created Time: 2015/2/28 19:15:19
 * File Name   : 31#1001.cpp
 *********************************************** */
#include <iostream>
#include <cstring>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
#define Debug(x) cout << #x << " " << x <<endl
#define Memset(x, a) memset(x, a, sizeof(x))
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> P;
#define FOR(i, a, b) for(int i = a;i < b; i++)
#define MAX_N 100100
#define Abs(x) x < 0 ? (-(x)) : x
int a[MAX_N];

int main() {
    //freopen("in.cpp", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;   
    cin >> t;
    while(t--){
        Memset(a, 0);
        int n, k;
        cin >> n >> k;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        LL ans = 0;
        for(int i = 1;i <= n; i++){
            int m = (upper_bound(a + 1, a + n + 1, a[i]+k) - (a + 1)) - i;
            //if(m != n)
            ans += m;
        }
        cout << ans << endl;
    }
    return 0;
}
