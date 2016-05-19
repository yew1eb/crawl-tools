#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define INF 1<<30
 #define maxn 110
 #define maxm 20000
 using namespace std;
 
 int v[maxm],next[maxm],w[maxm];
 int first[maxn],d[maxn],work[maxn],q[maxn];
 int _v[maxm],_next[maxm],_w[maxm];
 int src_set[maxn],sink_set[maxn];
 int e,S,T,n,m;
 
 void init(){
     e = 0;
     memset(first,-1,sizeof(first));
 }
 
 void add_edge(int a,int b,int c){
     v[e] = b;next[e] = first[a];w[e] = c;first[a] = e++;
     v[e] = a;next[e] = first[b];w[e] = 0;first[b] = e++;
 }
 
 int bfs(){
     int rear = 0;
     memset(d,-1,sizeof(d));
     d[S] = 0;q[rear++] = S;
     for(int i = 0;i < rear;i++){
         for(int j = first[q[i]];j != -1;j = next[j])
             if(w[j] && d[v[j]] == -1){
                 d[v[j]] = d[q[i]] + 1;
                 q[rear++] = v[j];
                 if(v[j] == T)   return 1;
             }
     }
     return 0;
 }
 
 int dfs(int cur,int a){
     if(cur == T)    return a;
     for(int &i = work[cur];i != -1;i = next[i]){
         if(w[i] && d[v[i]] == d[cur] + 1)
             if(int t = dfs(v[i],min(a,w[i]))){
                 w[i] -= t;w[i^1] += t;
                 return t;
             }
     }
     return 0;
 }
 
 int dinic(){
     int ans = 0;
     while(bfs()){
         memcpy(work,first,sizeof(first));
         while(int t = dfs(S,INF))   ans += t;
     }
     return ans;
 }
 
 int main()
 {
     int kase;
     scanf("%d",&kase);
     while(kase--){
         init();
         scanf("%d%d",&n,&m);
         S = 1,T = n;
         for(int i = 0;i < m;i++){
             int a,b,c;
             scanf("%d%d%d",&a,&b,&c);
             add_edge(a,b,c);
         }
         int maxflow = dinic();
         for(int i = 0;i < e;i++){
             _v[i] = v[i],_next[i] = next[i],_w[i] = w[i];
         }
         int src_cnt = 0,sink_cnt = 0;
         for(int i = 2;i < n;i++){
             if(d[i] != -1)  src_set[src_cnt++] = i;
             else    sink_set[sink_cnt++] = i;
         }
         int ans = 0;
         for(int i = 0;i < src_cnt;i++){
             for(int j = 0;j < sink_cnt;j++){
                 for(int k = 0;k < e;k++)
                     v[k] = _v[k],next[k] = _next[k],w[k] = _w[k];
                 add_edge(src_set[i],sink_set[j],INF);
                 int tmp = dinic();
                 if(tmp > ans)   ans = tmp;
                 first[src_set[i]] = next[e-2];
                 first[sink_set[j]] = next[e-1];
                 e -= 2;
             }
         }
         printf("%d\n",maxflow+ans);
     }
     return 0;
 }