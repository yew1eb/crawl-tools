#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cstdio>
#include <climits>
#define N 1005
#define MOD 1000000007
using namespace std;

int a[N], dp[N][N], num;
int t[N][N];

inline int lowbit(int x) {
    return x & (-x);
}
void add(int i, int j, int c) {
    while(j < num) {
        t[i][j] += c;
        if( t[i][j] >= MOD) t[i][j] %= MOD;
        j += lowbit(j);
    }
    return;
}
int sum(int i, int j) {
    int re = 0;
    while(j) {
        re += t[i][j];
        if(re >= MOD) re %= MOD;
        j -= lowbit(j);
    }
    return re;
}
int main(int argc, char* argv[]) {
    int n, m;
    int tt, ca = 1;
    scanf("%d", &tt);
    while( tt-- ) {
        scanf("%d%d", &n, &m);
        set<int> s;
        map<int, int> mp;
        for(int i=0; i<n; ++i) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }
        num = 1;
        for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
            mp[ *it ] = num++;
        }
        memset(dp, 0, sizeof(dp));
        memset(t, 0, sizeof(t));
        for(int i=0; i<n; ++i)
        for(int j=1; j<=m; ++j) {
            if( j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] += sum(j-1, mp[ a[i] ]-1);
            if(dp[i][j] >= MOD) dp[i][j] %= MOD;

        //    printf("%d %d %d\n", i, j, dp[i][j]);
            add(j, mp[ a[i] ], dp[i][j]);
        }
        int re = 0;
        for(int i=0; i<n; ++i) {
            re += dp[i][m];
            if(re >= MOD) re %= MOD;
        }
        printf("Case #%d: %d\n", ca++, re);
    }
    return 0;
}
