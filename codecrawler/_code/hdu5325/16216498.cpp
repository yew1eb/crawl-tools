#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <limits.h>
using namespace std;
typedef long long LL;
#define y1 y234
#define MAXN 500010 // 1e6
int n;
int a[MAXN];
vector<int> edge[MAXN];
int ans[MAXN];
void DFS(int u) {
    ans[u] = 1;
    int len = edge[u].size();
    for(int i = 0; i < len; i++) {
        int v = edge[u][i];
        if(!ans[v]) DFS(v);
        ans[u] += ans[v];
    }
}
int main() {
    while(~scanf("%d", &n)) {
        memset(ans, 0, sizeof ans);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            edge[i].clear();
        }
        int u, v;
        for(int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            if(a[u] < a[v]) edge[u].push_back(v);
            else if(a[v] < a[u]) edge[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            if(ans[i]) continue;
            DFS(i);
        }
        int maxn = -1;
        for(int i = 1; i <= n; i++) {
            maxn = max(ans[i], maxn);
        }
        printf("%d\n", maxn);
    }
    return 0;
}