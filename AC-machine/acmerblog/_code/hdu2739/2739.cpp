/*若原图的基图不连通,
 或者存在某个点的入度或出度为 0 则无解。
 统计所有点的入度出度之差 Di, 对于 Di > 0 的点,
 加边(s, i, Di, 0); 对于 Di < 0 的点加边(i, t, -Di,0);
 对原图中的每条边(i, j),
 在网络中加边(i, j, ∞, Dij),Dij 为边(i, j)的权值。
 求一次最小费用流,费用加上原图所有边权和即为结果。
 若进一步要求输出最小权值回路,则对所有流量 fij > 0 的边(i, j),在原图中复制fij 份,这样原图便成为欧拉图,求一次欧拉回路即可。
 */
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <queue>
 #include <algorithm>
 #include <cmath>
 
 using namespace std;
 
 const int maxn = 1e2 + 5;
 const int maxm = 2e4 + 5;
 const int inf = 0x3f3f3f3f;
 
 struct MCMF {
     struct Edge {
         int v, c, w, next;
     }p[maxm << 1];
     int e, head[maxn], dis[maxn], pre[maxn], cnt[maxn], sumFlow, n;
     bool vis[maxn];
     void init(int nt){
         e = 0, n = nt + 1;
         memset(head, -1, sizeof(head[0]) * (n + 2));
     }
     void addEdge(int u, int v, int c, int w){
         p[e].v = v; p[e].c = c; p[e].w = w; p[e].next = head[u]; head[u] = e++;
         swap(u, v);
         p[e].v = v; p[e].c = 0; p[e].w = -w; p[e].next = head[u]; head[u] = e++;
     }
     bool spfa(int S, int T){
         queue <int> q;
         for (int i = 0; i <= n; ++i)
             vis[i] = cnt[i] = 0, pre[i] = -1, dis[i] = inf;
         vis[S] = 1; dis[S] = 0;
         q.push(S);
         while (!q.empty()){
             int u = q.front(); q.pop();
             vis[u] = 0;
             for (int i = head[u]; i + 1; i = p[i].next){
                 int v = p[i].v;
                 if (p[i].c && dis[v] > dis[u] + p[i].w){
                     dis[v] = dis[u] + p[i].w;
                     pre[v] = i;
                     if (!vis[v]){
                         q.push(v);
                         vis[v] = 1;
                         if (++cnt[v] > n) return 0;
                     }
                 }
             }
         }
         return dis[T] != inf;
     }
     int mcmf(int S, int T){
         sumFlow = 0;
         int minFlow = 0, minCost = 0;
         while (spfa(S, T)){
             minFlow = inf + 1;
             for (int i = pre[T]; i + 1; i = pre[ p[i ^ 1].v ])
                 minFlow = min(minFlow, p[i].c);
             sumFlow += minFlow;
             for (int i = pre[T]; i + 1; i = pre[ p[i ^ 1].v ]){
                 p[i].c -= minFlow;
                 p[i ^ 1].c += minFlow;
             }
             minCost += dis[T] * minFlow;
         }
         return minCost;
     }
     int ind[maxn], outd[maxn], ans ;
     bool build(int nt, int mt){
         init(nt);
         memset(ind, 0, sizeof(ind));
         memset(outd, 0, sizeof(outd));
         ans = 0;
         int u, v, c;
         while (mt--){
             scanf("%d%d%d", &u, &v, &c);
             u++, v++;
             addEdge(u, v, inf, c);
             ans += c;
             outd[u]++, ind[v]++;
         }
         for (int i = 1; i <= nt; ++i){
             if (ind[i] == 0 || outd[i] == 0) return false;
         }
         for (int i = 1; i <= nt; ++i){
             if (ind[i] - outd[i] > 0)
                 addEdge(0, i, ind[i] - outd[i], 0);
             else if (ind[i] - outd[i] < 0) 
                 addEdge(i, n, outd[i] - ind[i], 0);
         }
         return true;
     }
     void solve(){
         ans += mcmf(0, n);
         printf("%d\n", ans);
     }
 }my;
 int main(){
     int tcase, n, m;
     scanf("%d", &tcase);
     while (tcase--){
         scanf("%d%d", &n, &m);
         if (!my.build(n, m)){
             printf("-1\n");
             continue;
         }
         my.solve();
     }
     return 0;
 }