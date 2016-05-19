#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <cstdlib>
 #include <iostream>
 
 typedef __int64  ll;
 const int maxv = 1100;
 const int maxe = 12000;
 const ll inf = 0x7f7f7f7f;
 
 int in[maxv], vis[maxv], pre[maxv], fold[maxv], pos;
 //   in-arc's cost              pre-vex      new vex-num
 ll min_cost;
 struct edge{
     int b, e;
     ll c;
 }E[maxe];
 // save arcs
 
 bool make_tree(int root, int v, int e){
     int cnt;
 
     min_cost = 0;
     while (true){
         for (int i = 0; i < v; i++){
             in[i] = inf;
             pre[i] = -1;
         } // suppose every vex does not have pre-vex
         for (int i = 0; i < e; i++){
             int s = E[i].b;
             int t = E[i].e;
 
             if (in[t] > E[i].c && s != t){
                 in[t] = E[i].c;
                 pre[t] = s;
                 if (s == root){
                     pos = i;
                 } // record the vex whose pre-vex is the vertual root by using the edge's number
             }
         } // find the min-in-arc of every vex
 #ifndef ONLINE_JUDGE
         for (int i = 0; i < v; i++){
             printf("pre %d : %d\n", i, pre[i]);
         }
         printf("root  %d\n", root);
 #endif
         for (int i = 0; i < v; i++){
             vis[i] = -1, fold[i] = -1;
             if (in[i] == inf && i != root) return false;
         } // ensure whether the tree can be build, of course, it is no use in this problem
 
         cnt = 0;
         in[root] = 0;
         for (int i = 0, j, k; i < v; i++){
             if (i == root) continue;
             min_cost += in[i];
             vis[i] = i;
             for (j = pre[i]; vis[j] != i && fold[j] == -1 && j != root; j = pre[j]){
                 vis[j] = i;
             }
             if (j == root || fold[j] != -1) continue;
 
             k = j;
             for (fold[k] = cnt, k = pre[k]; k != j; k = pre[k]) fold[k] = cnt;
             cnt++;
         } // find circle and re-number every vex
 #ifndef ONLINE_JUDGE
         printf("cnt %d\n", cnt);
 #endif
         if (!cnt) return true;
         for (int i = 0; i < v; i++){
             if (fold[i] == -1) fold[i] = cnt++;
         } // re-number the rest single vex
         for (int i = 0; i < e; i++){
             int s = E[i].b;
             int t = E[i].e;
 
             E[i].b = fold[s];
             E[i].e = fold[t];
             if (E[i].b != E[i].e)
                 E[i].c -= in[t];
         } // refresh every arcs
         root = fold[root];
         v = cnt;
     }
 }
 
 
 bool deal(){
     int n, m;
     ll e_sum = 0;
 
     if (scanf("%d%d", &n, &m) == EOF) return false;
     for (int i = 0; i < m; i++){
         scanf("%d%d%I64d", &E[i].b, &E[i].e, &E[i].c);
         E[i].b++; E[i].e++;
         e_sum += E[i].c;
     }
     e_sum++;
     for (int i = 0; i < n; i++){
         E[m + i].b = 0;
         E[m + i].e = i + 1;
         E[m + i].c = e_sum;
     } // build virtual root
     make_tree(0, n + 1, m + n);
     if (min_cost < (e_sum << 1)){
         printf("%I64d %d\n", min_cost - e_sum, pos - m);
     }
     else puts("impossible");
     puts("");
 
     return true;
 }
 
 int main(){
 #ifndef ONLINE_JUDGE
     freopen("in","r",stdin);
 #endif
     while (deal());
 
     return 0;
 }