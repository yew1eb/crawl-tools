#include <stdio.h>
 #include <cstring>
 #include <stdio.h>
 #include <queue>
 #include <algorithm>
 using namespace std;
 
 const int MAXN = 1010;
 const int MAXM = 1000000;
 const int INF = 0x1f1f1f1f;
 
 struct Edge
 {
     int from;
     int to;
     int w;
 }edge[MAXM];
 int tot;
 
 void add(int s, int u, int w)
 {
     edge[tot].from = s;
     edge[tot].to = u;
     edge[tot].w = w;
     tot++;
 }
 
 int arr[MAXN], a, b, dis[MAXN], in[MAXN];
 int main()
 {
    // freopen("in.txt", "r", stdin);
     int n, iCase = 0;
     char ord[10];
     bool flag;
     while (~scanf("%d", &n)) {
         if (n == 0) break;
 
         iCase++;
         printf("Case %d:\n", iCase);
         memset(dis, INF, sizeof(dis));
         memset(in, 0, sizeof(in));
         tot = 0;
         flag = true;
 
         for (int i = 0; i < n; ++i)
             scanf("%d", &arr[i]);
         scanf("%s", ord);
         while (ord[0] != '#') {
             scanf("%d %d", &a, &b);
             a--, b--;
             in[b]++;
             if (strcmp(ord, "SAS") == 0) {  //如果是SAS..就G[a][b] = 0;
                 add(a, b, 0);
             } else if (strcmp(ord, "SAF") == 0) {  //如果是SAF..就是G[a][b] = -arr[b];
                 add(a, b, -arr[b]);
             } else if (strcmp(ord, "FAF") == 0) {  //如果是SAF..就是G[a][b] = arr[a]-arr[b];
                 add(a, b, arr[a]-arr[b]);//!
             } else {
                 add(a, b, arr[a]);  //如果是SAF..就是G[a][b] = arr[a];
             }
             scanf("%s", ord);
         }
 
         queue<int> Q;
         for (int i = 0; i < n; ++i) {
             if (in[i] == 0) {
                 dis[i] = 0;
             }
             Q.push(i);
             in[i] = 1;
         }
 
         for (int i = 0; i < n-1; ++i)
             for (int j = 0; j < tot; ++j) {
                 int from = edge[j].from, to = edge[j].to, w = edge[j].w;
                     if (dis[to] > dis[from]+w)
                         dis[to] = dis[from]+w;
             }
         for (int i = 0; i < tot; ++i) {
             int from = edge[i].from, to = edge[i].to, w = edge[i].w;
                 if (dis[to] > dis[from]+w) {
                     flag = false;
                     break;
                 }
         }
 
 /*
         while (!Q.empty()) {
             int id = Q.front();
             Q.pop();
             for (int i = 0; i < n; ++i)
                 if (i != id && dis[id]+G[id][i] < dis[i]) {
                     dis[i] = dis[id]+G[id][i];
                     in[i]++;
                     if (in[i] > n) {
                         flag = false;
                         goto loop;
                     }
                     Q.push(i);
                 }
         }
 */
       //  loop:
         if (flag) {
             int minDis = INF;
             for (int i = 0; i < n; ++i)
                 minDis = min(minDis, dis[i]);
             for (int i = 0; i < n; ++i)
                 printf("%d %d\n", i+1, dis[i]-minDis);
         } else puts("impossible");
         puts("");
     }
     return 0;
 }