#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define N 1010
using namespace std;

queue<int> q;

int val[N],n,k,sum[N];
vector <int> g[N];
bool vis[N];
int ans;

void init (){
    for (int i = 0;i <= n;i ++){
        g[i].clear();
        vis[i] = true;
        sum[i] = 0;
        ans = 0;
    }
    while (!q.empty()) q.pop();
}

void process (){
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int sz = g[u].size();
        for (int i = 0;i < sz;i ++){
            int v = g[u][i];
            if (!vis[v]) continue;
            sum[v] -= val[u];
            if (sum[v] < k){
                vis[v] = false;
                q.push(v);
                ans -= val[v];
            }
        }
    }
    int t = 0;
    for (int i = 0;i < n;i ++)
        if (vis[i]) t ++;
    printf ("%d %d\n",t,ans);
}
int main (){
    int t,x;
    while (~scanf ("%d%d",&n,&k)) {
        if (n + k == 0) break;
        init();
        for (int i = 0;i < n;i ++){
            scanf ("%d",&val[i]);
            ans += val[i];
            scanf ("%d",&t);
            while (t --){
                scanf ("%d",&x);
                g[i].push_back(x);
            }
        }
        for (int i = 0;i < n;i ++){
            sum[i] = val[i];
            int sz = g[i].size();
            for (int j = 0;j < sz;j ++){
                int v = g[i][j];
                sum[i] += val[v];
            }
        }
        for (int i = 0;i < n;i ++) {
            if (sum[i] < k){
                q.push(i);
                ans -= val[i];
                vis[i] = false;
            }
        }
        process();
    }
    return 0;
}