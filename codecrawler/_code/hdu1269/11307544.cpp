#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;

const int maxn = 100000 + 10;

vector<int> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;

void dfs(int u){
    pre[u] = lowlink[u] = ++ dfs_clock;
    S.push(u);
    for(int i=0; i<G[u].size(); ++i){
        int v = G[u][i];
        if(!pre[v]){
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }else if(!sccno[v]){
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }
    if(lowlink[u] == pre[u]){
        scc_cnt++;
        for(;;){
            int x = S.top(); S.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}

void find_scc(int n){
    dfs_clock = scc_cnt = 0;
    memset(sccno, 0, sizeof sccno);
    memset(pre, 0, sizeof pre );
    for(int i=0; i<n; ++i)
        if(!pre[i]) dfs(i);
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        if(n==0 && m==0) break;
        for(int i=0; i<n; ++i) G[i].clear();
        for(int i=0; i<m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v); u--; v--;
            G[u].push_back(v);
        }

        find_scc(n);

        if(scc_cnt == 1) puts("Yes");
        else puts("No");
    }
}
