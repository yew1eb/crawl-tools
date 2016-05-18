#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <queue>
 #include <iostream>
 
 using namespace std;
 
 const int N = 55555;
 const int INF = 0x55555555;
 struct Edge {
     int id, nx, val;
     Edge() {}
     Edge(int id, int nx, int val) : id(id), nx(nx), val(val) {}
 } edge[N << 2];
 int eh[N], ec;
 
 void init() {
     ec = 0;
     memset(eh, -1, sizeof(eh));
 }
 
 void addedge(int u, int v, int w) {
     edge[ec] = Edge(v, eh[u], w);
     eh[u] = ec++;
 }
 
 int rx[N << 1], dis[N];
 bool vis[N];
 queue<int> Q;
 
 void spfa(int s) {
     while (!Q.empty()) Q.pop();
     memset(vis, 0, sizeof(vis));
     for (int i = 0; i < N; i++) dis[i] = -INF;
     Q.push(s);
     vis[s] = true;
     dis[s] = 0;
     while (!Q.empty()) {
         int cur = Q.front();
         Q.pop();
         vis[cur] = false;
         for (int t = eh[cur]; ~t; t = edge[t].nx) {
             if (dis[edge[t].id] < dis[cur] + edge[t].val) {
                 dis[edge[t].id] = dis[cur] + edge[t].val;
                 if (vis[edge[t].id]) continue;
                 Q.push(edge[t].id);
                 vis[edge[t].id] = true;
             }
         }
     }
 }
 
 int main() {
 //    freopen("in", "r", stdin);
     int n, x, y, z;
     while (~scanf("%d", &n)) {
         init();
         int cnt = 0;
         for (int i = 0; i < n; i++) {
             scanf("%d%d%d", &x, &y, &z);
             addedge(x, y + 1, z);
             rx[cnt++] = x;
             rx[cnt++] = y + 1;
         }
         sort(rx, rx + cnt);
         cnt = unique(rx, rx + cnt) - rx;
         for (int i = 1; i < cnt; i++) addedge(rx[i], rx[i - 1], rx[i - 1] - rx[i]), addedge(rx[i - 1], rx[i], 0);
         spfa(rx[0]);
         printf("%d\n", dis[rx[cnt - 1]]);
     }
     return 0;
 }