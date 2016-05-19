#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10005;
int n, m;
vector<int> G[maxn*2];
bool mark[maxn*2];
int S[maxn*2], top;

bool dfs(int x)
{
    if(mark[x^1]) return false;
    if(mark[x]) return true;
    mark[x] = true;
    S[top++] = x;
    for(int i=0; i<G[x].size(); ++i)
        if(!dfs(G[x][i])) return false;
    return true;
}

bool TwoSat()
{
    memset(mark, 0, sizeof mark );
    for(int i=0; i<n; i += 2) {
        if(!mark[i] && !mark[i^1]) {
            top = 0;
            if(!dfs(i)) {
                while(top) mark[S[--top]] = false;
                if(!dfs(i^1)) return false;
            }
        }
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.cpp","r",stdin);
    freopen("out.cpp", "w", stdout);
#endif // ONLINE_JUDGE
    int u, v;
    while(~scanf("%d%d", &n, &m)) {
        n *= 2;
        for(int i=0; i<n; ++i) G[i].clear();
        while(m--) {
            scanf("%d%d", &u, &v);
            u--;
            v--;
            G[u].push_back(v^1);
            G[v].push_back(u^1);
        }
        if(TwoSat()) {
            for(int i=0; i<n; i+=2)
                if(mark[i])
                    printf("%d\n", i+1);
                else
                    printf("%d\n", (i^1)+1);
        } else printf("NIE\n");
    }
    return 0;
}
