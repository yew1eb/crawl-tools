/*======================================================
# Author: whai
# Last modified: 2015-12-07 21:13
# Filename: d.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 5 * 1e5 + 5;

vector<int> G[N];
int dp[N][15];

void dfs1(int u, int k) {
    dp[u][0] = 1;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        dfs1(v, k);
        for(int j = 0; j < k; ++j) {
            dp[u][j + 1] += dp[v][j];
        }
    }
}

void dfs2(int u, int k) {
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        for(int j = k; j >= 2; --j) {
            dp[v][j] += dp[u][j - 1] - dp[v][j - 2];
        }
        dp[v][1] += dp[u][0];
        dfs2(v, k);
    }
}

void init(int n) {
    for(int i = 0; i <= n; ++i) {
        G[i].clear();
    }
    memset(dp, 0, sizeof(dp));
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n, k, A, B;
        cin>>n>>k>>A>>B;
        init(n);
        for(int i = 2; i <= n; ++i) {
            int fa = ((LL)A * i + B) % (i - 1) + 1;
            G[fa].PB(i);
        }

        dfs1(1, k);
        dfs2(1, k);

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            int tmp = 0;
            for(int j = 0; j <= k; ++j) {
                tmp += dp[i][j];
            }
            ans ^= tmp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
