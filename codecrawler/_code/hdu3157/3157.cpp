#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <queue>
 #define maxn 210
 #define INF 100000000
 using namespace std;
 
 struct Edge{
     int from,to,cap,flow;
 };
 
 struct Dinic{
     int n,m,s,t;
     vector<Edge> edges;
     vector<int> G[maxn];
     bool vis[maxn];
     int d[maxn];
     int cur[maxn];
 
     void ClearAll(int n){
         for(int i = 0;i < n;i++)    G[i].clear();
         edges.clear();
     }
 
     void add_edge(int from,int to,int cap){
         edges.push_back((Edge){from,to,cap,0});
         edges.push_back((Edge){to,from,0,0});
         m = edges.size();
         G[from].push_back(m-2);
         G[to].push_back(m-1);
     }
 
     bool BFS(){
         memset(vis,0,sizeof(vis));
         queue<int> Q;
         Q.push(s);
         vis[s] = 1;
         d[s] = 0;
         while(!Q.empty()){
             int x = Q.front();Q.pop();
             for(int i = 0;i < G[x].size();i++){
                 Edge& e = edges[G[x][i]];
                 if(!vis[e.to] && e.cap > e.flow){
                     vis[e.to] = 1;
                     d[e.to] = d[x] + 1;
                     Q.push(e.to);
                 }
             }
         }
         return vis[t];
     }
 
     int DFS(int x,int a){
         if(x == t || a == 0)    return a;
         int flow = 0,f;
         for(int &i = cur[x];i < G[x].size();i++){
             Edge& e = edges[G[x][i]];
             if(d[x] + 1 == d[e.to] && (f = DFS(e.to,min(a,e.cap-e.flow))) > 0){
                 e.flow += f;
                 edges[G[x][i]^1].flow -= f;
                 flow += f;
                 a -= f;
                 if(a == 0)  break;
             }
         }
         return flow;
     }
 
     int Maxflow(int s,int t){
         this->s = s;this->t = t;
         int flow = 0;
         while(BFS()){
             memset(cur,0,sizeof(cur));
             flow += DFS(s,INF);
         }
         return flow;
     }
 };
 
 Dinic g;
 int in[maxn],flow[50000],low[50000];
 int main()
 {
     int T,n,m,a,b,c;
     scanf("%d",&T);
     while(T--){
         scanf("%d%d",&n,&m);
         memset(in,0,sizeof(in));
         g.ClearAll(n+2);
         for(int i = 0;i < m;i++){
             scanf("%d%d%d%d",&a,&b,&low[i],&c);
             in[a] -= low[i];
             in[b] += low[i];
             g.add_edge(a,b,c-low[i]);
         }
         for(int i = 1;i <= n;i++){
             if(in[i] > 0)   g.add_edge(0,i,in[i]);
             if(in[i] < 0)   g.add_edge(i,n+1,-in[i]);
         }
         g.Maxflow(0,n+1);
         bool flag = true;
         for(int i = 0;i < g.G[0].size();i++){
             //printf("%d %d\n",g.edges[g.G[0][i]].cap,g.edges[g.G[0][i]].flow);
             if(g.edges[g.G[0][i]].flow != g.edges[g.G[0][i]].cap){
                 flag = false;
                 break;
             }
         }
         if(flag){
             printf("YES\n");
             for(int i = 0;i < m;i++){
                 printf("%d\n",low[i] + g.edges[i*2].flow);
             }
         }else{
             printf("NO\n");
         }
         printf("\n");
     }
     return 0;
 }