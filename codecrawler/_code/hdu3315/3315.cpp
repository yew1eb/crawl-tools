#include <cstdio>
 #include <algorithm>
 #include <cstring>
 #include <cstdlib>
 #include <vector>
 #define maxn 105
 using namespace std;
 
 struct KM
 {
     vector<int> G[maxn];
     int W[maxn][maxn],n;
     int Lx[maxn],Ly[maxn];
     int left[maxn];
     bool S[maxn],T[maxn];
 
     void init(int n)
     {
         this->n = n;
         for(int i = 0;i < n;i++)    G[i].clear();
         memset(W,0,sizeof(W));
     }
 
     void add_edge(int u,int v,int w)
     {
         G[u].push_back(v);
         W[u][v] = w;
     }
 
     bool match(int i)
     {
         S[i] = true;
         for(int k = 0;k < G[i].size();k++)
         {
             int j = G[i][k];
             if(Lx[i] + Ly[j] == W[i][j] && !T[j])
             {
                 T[j] = true;
                 if(left[j] == -1 || match(left[j]))
                 {
                     left[j] = i;
                     return true;
                 }
             }
         }
         return false;
     }
 
     void update()
     {
         int a = 1<<30;
         for(int i = 0;i < n;i++)    if(S[i])
             for(int k = 0;k < G[i].size();k++)
             {
                 int j = G[i][k];
                 if(!T[j])   a = min(a,Lx[i] + Ly[j] - W[i][j]);
             }
         for(int i = 0;i < n;i++)
         {
             if(S[i])    Lx[i] -= a;
             if(T[i])    Ly[i] += a;
         }
     }
 
     void solve()
     {
         for(int i = 0;i < n;i++)
         {
             Lx[i] = *max_element(W[i],W[i] + n);
             left[i] = -1;
             Ly[i] = 0;
         }
 
         for(int i = 0;i < n;i++)
         {
             while(1)
             {
                 for(int j = 0;j < n;j++)    S[j] = T[j] = 0;
                 if(match(i))    break;
                 else            update();
             }
         }
     }
 };
 
 KM solver;
 int V[maxn],H[maxn],P[maxn],A[maxn],B[maxn];
 bool check(int i,int j){
     int hh = H[i],aa = A[i];
     int pp = P[j],bb = B[j];
     while(1){
         pp -= aa;
         if(pp <= 0) return 1;
         hh -= bb;
         if(hh <= 0) return 0;
     }
 }
 
 int main()
 {
     int N;
     while(scanf("%d",&N),N){
         solver.init(N);
         for(int i = 0;i < N;i++)    scanf("%d",&V[i]);
         for(int i = 0;i < N;i++)    scanf("%d",&H[i]);
         for(int i = 0;i < N;i++)    scanf("%d",&P[i]);
         for(int i = 0;i < N;i++)    scanf("%d",&A[i]);
         for(int i = 0;i < N;i++)    scanf("%d",&B[i]);
         for(int i = 0;i < N;i++)
         for(int j = 0;j < N;j++){
             if(check(i,j))  solver.add_edge(i,j,V[i]*100);
             else            solver.add_edge(i,j,-V[i]*100);
             if(i == j)      solver.W[i][j] += 1;
         }
         /*for(int i = 0;i < N;i++){
             for(int j = 0;j < N;j++)
                 printf("%d ",solver.W[i][j]);
             printf("\n");
         }*/
         solver.solve();
         int ans = 0;
         for(int i = 0;i < N;i++)
             ans += solver.W[solver.left[i]][i];
         //printf("%d\n",ans);
         if(ans < 0) printf("Oh, I lose my dear seaco!\n");
         else{
             int ans1 = ans / 100;
             double ans2 = 100.0 * (ans % 100) / N;
             printf("%d %.3f%%\n",ans1,ans2);
         }
     }
     return 0;
 }