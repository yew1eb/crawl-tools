#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1005;
typedef pair<int, int> PR;
int x[maxn], y[maxn], p[maxn];
double dis[maxn];
int pre[maxn];
bool vis[maxn];
vector<PR> vr;
vector<int> edge[maxn];
int n;

inline double dist(int x1, int y1, int x2, int y2){
    return (double)sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

double prim(){
    vr.clear();
    for(int i=0; i<=n; ++i) edge[i].clear();
    for(int i=1; i<n; ++i){
        pre[i] = 0;
        dis[i] = dist(x[0], y[0], x[i], y[i]);
        vis[i] = 0;
    }
    dis[0] = 0; pre[0] = -1; vis[0] = 1;
    double ret = 0;
    for(int i=1; i<n; ++i){
        int k = -1; 
        for(int i=0; i<n; ++i)if(!vis[i]) if(k==-1 || dis[k]>dis[i])
            k = i;
        if(k==-1) break;
        ret += dis[k];
        vis[k] = 1;
        vr.push_back(make_pair<int,int>(pre[k], k) );
        edge[k].push_back(pre[k]);
        edge[pre[k]].push_back(k);
        for(int i=0; i<n; ++i) if(!vis[i])
            if(dis[i]>dist(x[k], y[k], x[i], y[i]) ){
                dis[i] = dist(x[k], y[k], x[i], y[i]);
                pre[i] = k;
            }
    }
    return ret;
}

double dfs(int u, int fa){
    double ret = p[u];
    for(int i=0; i<edge[u].size(); ++i){
        if(edge[u][i]==fa)continue;
        ret = max(ret, dfs(edge[u][i], u) );
    }
    return ret;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i=0; i<n; ++i) scanf("%d%d%d", &x[i], &y[i], &p[i]);
        double mst = prim();
        double ans = -1000;
        for(int i=0; i<vr.size(); ++i){
            int a = vr[i].first;
            int b = vr[i].second;
            double p_a = dfs(a, b);
            double p_b = dfs(b, a);
            double tmp = (p_a + p_b)/(mst - dist(x[a], y[a], x[b], y[b]) );
            if(tmp>ans) ans = tmp;
        }    
        printf("%.2f\n", ans);
    }
    return 0;
}
