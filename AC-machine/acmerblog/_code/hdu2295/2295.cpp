/*最小支配集*/
 #include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<stdlib.h>
  #define INF 0x3fffffff
  #define EPS 1e-8
  #define EP 1e-10
  #define NN 55
 struct POINT{
        double x, y;
 }f[NN], g[NN];
 double dis[NN][NN];
 
 int adj[NN][NN];
 int N, M, K, head;
 
 int R[NN * NN], L[NN * NN], U[NN * NN], D[NN * NN];
 int C[NN * NN];//记录每个节点所在列 
 int cntc[NN]; //记录每列包含的节点数 
 
 /*删除第c列*/ 
 void remove(int c){
     int i;
     for (i = D[c]; i != c; i = D[i]){
         R[L[i]] = R[i];
         L[R[i]] = L[i];        
     }
 }
 /*恢复第c列*/ 
 void resume(int c){
     int i;
     for (i = D[c]; i != c; i = D[i]){
         R[L[i]] = i;
         L[R[i]] = i;        
     }
 }
 
 int h(){
     bool hash[NN];
     memset(hash, 0, sizeof(hash));
     
     int i, j, c;
     int ans = 0;
     for (c = R[head]; c != head; c = R[c]){
         if (!hash[c]){
            ans ++;
            for (i = D[c]; i != c; i = D[i]){
                for (j = R[i]; j != i; j = R[j]){
                    hash[C[j]] = true;
                }
            }
         }
     }
     return ans;    
 }
 
 /*DLX主要部分*/ 
 int dfs(int k){
     if (R[head] == head) return 1;
     if (k + h() > K) return 0;// A*剪枝 
     
     
     int i, j, c;
     int Min = INF;
     for (i = R[head]; i != head; i = R[i]){
         if (cntc[i] < Min){
            Min = cntc[i];
            c = i;
         }
     }
     for (i = D[c]; i != c; i = D[i]){
         remove(i);
         for (j = R[i]; j != i; j = R[j]){
             remove(j);
             cntc[C[j]]--;
         }
         if (dfs(k + 1)) return 1;
         for (j = L[i]; j != i; j = L[j]){
             resume(j);
             cntc[j]++;
         }
         resume(i);
     }
     return 0;
 }
 /*建图*/ 
 int Build(){
      int i, j, now, pre, first;
      head = 0;
      for (j = head; j < N; j++){
          R[j] = j + 1;
          L[j + 1] = j;    
      }
      L[head] = j;
      R[j] = head;
      
      /*列双向链表*/
      for (j = 1; j <= N; j++){
          pre = j;
          cntc[j] = 0;
          for (i = 1; i <= M; i++){
              if (adj[i][j]){
                 now = i * N + j;
                 C[now] = j;
                 cntc[j]++;
                 D[pre] = now;
                 U[now] = pre;
                 pre = now;
              }
          }
          now = j;
          D[pre] = now;
          U[now] = pre;
          if (cntc[j] == 0) return 0;
      }
      /*行双向链表*/
      for (i = 1; i <= M; i++){
          pre = first = -1;
          for (j = 1; j <= N; j++){
              if (adj[i][j]){
                 now = i * N + j;
                 if (pre != -1){
                         R[pre] = now;
                         L[now] = pre;
                 }else{
                       first = now;
                 }
                 pre = now;
              }
          }
          if (first != -1){
             now = first;
             R[pre] = now;
             L[now] = pre;
          }
      }
      return 1;
 }
 
 /*判断*/ 
 int OK(double mid){
     int i, j;
     for (i = 1; i <= M; i++){
         for (j = 1; j <= N; j++){
             if (dis[i][j] - mid < EP){
                adj[i][j] = 1;
             }else adj[i][j] = 0;
         }
     }
     if (Build())
     return dfs(0);
     else return 0;
 }
 
 /*二分距离*/
 double Binary(){
        double low = 0;
        double hig = 1500;
        double mid, ans = -1;
        while(hig - low > EPS){
            mid = (low + hig) / 2;
            if (OK(mid)){
               ans = mid;
               hig = mid;
            }else low = mid;
        }
        return ans;
 }
 /*计算雷达i到城市j的距离*/
 double Distance(int i, int j){
        return sqrt((g[i].x - f[j].x) * (g[i].x - f[j].x) 
        + (g[i].y - f[j].y) * (g[i].y - f[j].y));
 }
 /*初始化距离矩阵dis[M][N]*/ 
 void Init(){
      int i, j;
      for (i = 1; i <= M; i++){
          for (j = 1; j <= N; j++){
              dis[i][j] = Distance(i, j);
          }
      }
 }
 int main()
 {
     int T, i;
     scanf("%d", &T);
     while(T--){
        scanf("%d%d%d", &N, &M, &K);
        for (i = 1; i <= N; i++){
            scanf("%lf%lf", &f[i].x, &f[i].y);
        }
        for (i = 1; i <= M; i++){
            scanf("%lf%lf", &g[i].x, &g[i].y);
        }
        Init();
        printf("%.6lf\n", Binary());
     }
     return 0;
 }