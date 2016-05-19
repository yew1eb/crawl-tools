 #include <iostream>
 #include <cstring>
 #define INF 9999999
 #include <cstdio>
 #include <queue>
 #include <vector>
 #include<algorithm>
 using namespace std;
 #define maxn 6100
 
 struct  edge
 {
     int from,to,cap,flow,cost;
 };
 struct MCMF
 {
     int n,m,s,t;
     vector<edge>edges;
     vector<int>G[maxn];
     int inq[maxn];
     int d[maxn];
     int p[maxn];
     int a[maxn];
     void init(int n)
     {
         this->n=n;
         for(int i=0; i<n; i++)
             G[i].clear();
         edges.clear();
     }
     void addedge(int from,int to,int cap,int cost)
     {
         edges.push_back((edge){from,to,cap,0,cost});
         edges.push_back((edge){to,from,0,0,-cost});
         m=edges.size();
         G[from].push_back(m-2);
         G[to].push_back(m-1);
     }
 
     bool bellman(int s,int t,int &flow,int &cost)
     {
         for(int i=0; i<n; i++)d[i]=INF;
         memset(inq,0,sizeof(inq));
         d[s]=0;
         inq[s]=1;
         p[s]=0;
         a[s]=INF;
 
         queue<int>Q;
         Q.push(s);
         while(!Q.empty())
         {
             int u = Q.front();
             Q.pop();
             inq[u] = 0;
             for(int i = 0; i < G[u].size(); i++)
             {
                 edge& e = edges[G[u][i]];
                 if(e.cap > e.flow && d[e.to] > d[u] + e.cost)
                 {
                     d[e.to] = d[u] + e.cost;
                     p[e.to] = G[u][i];
                     a[e.to] = min(a[u], e.cap - e.flow);
                     if(!inq[e.to])
                     {
                         Q.push(e.to);
                         inq[e.to] = 1;
                     }
                 }
             }
         }
         if(d[t] == INF) return 