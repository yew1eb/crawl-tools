#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#define for0(a,b) for(a=0;a<b;++a)
#define for1(a,b) for(a=1;a<=b;++a)
#define foru(i,a,b) for(i=a;i<=b;++i)
#define ford(i,a,b) for(i=a;i>=b;--i)
using namespace std;

typedef double db;
typedef long long ll;
const db eps = 1e-8;
const int INF = 1e9;
const int maxn = 10000 + 5;
vector<int> g[maxn];
int du[maxn], n, m;
int val[maxn];

int toposort()
{
    int i, j;
    memset(du, 0, sizeof du );
    memset(val, 0, sizeof val );
    for1(i,n) for0(j,g[i].size())
    du[g[i][j]]++;

    int tot = 0;
    queue<int> q;
    for1(i,n) if(!du[i]) {
        q.push(i);
        val[i] = 888;
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        tot++;
        for0(i,g[u].size()) {
            int &v = g[u][i];
            du[v]--;
            if(!du[v]) {
                q.push(v);
                val[v] = val[u] + 1;
            }
        }
    }

    if(tot==n) {
        int ans = 0;
        for1(i,n) ans += val[i];
        return ans;
    } else {
        return -1;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.cpp", "r", stdin);
    freopen("out.cpp","w", stdout);
#endif // ONLINE_JUDGE
    int i, j;
    int u, v;
    while(~scanf("%d%d", &n, &m)) {
        for1(i,n) g[i].clear();
        for1(i,m) {
            scanf("%d%d", &u, &v);
            g[v].push_back(u);
        }

        printf("%d\n", toposort() );
    }
    return 0;
}
