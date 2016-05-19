#include <cstdio>
 #include <cstring>
 #include <iostream>
 #include <stack>
 #define N 50006
 using namespace std;
 
 struct Edge
 {
     int u, val, next;
     Edge() {}
     Edge(int a, int b, int c)
     {
         u=a, val=b, next=c;
     }
 } edge[100006];
 
 int head[N],tot,n,m,dfn[N],low[N],T,ind,id[N],in[N];
 bool vs[N];
 stack<int> S;
 
 void add_edge(int st, int en, int val)
 {
     edge[tot]=Edge(en,val,head[st]);
     head[st]=tot++;
 }
 
 void tarjan(int u)
 {
     S.push(u), vs[u]=true;
     dfn[u]=low[u]=T++;
     for(int e=head[u]; e!=-1; e=edge[e].next)
     {
         int v=edge[e].u;
         if(!dfn[v])
         {
             tarjan(v);
             low[u]=min(low[u], low[v]);
         }
         else if(vs[v] && low[u]>dfn[v]) low[u]=dfn[v];
     }
     if(low[u]==dfn[u])
     {
         ind++;
         int v;
         do
         {
             v=S.top();
             S.pop();
             id[v]=ind;
             vs[v]=false;
         }while(v!=u);
     }
 }
 
 int main()
 {
     while(scanf("%d%d", &n, &m)!=EOF)
     {
         memset(head, -1, sizeof head);
         tot=0;
         for(int i=0, a, b, c; i<m; i++)
         {
             scanf("%d%d%d", &a, &b, &c);
             add_edge(a,b,c);
         }
         while(!S.empty()) S.pop();
         memset(vs, 0, sizeof vs);
         memset(dfn,0, sizeof dfn);
         memset(low,0,sizeof low);
         T=ind=0;
         for(int i=0; i<n; i++) if(!dfn[i]) tarjan(i);
         for(int i=0; i<ind; i++) in[i]=999999;
         for(int i=0; i<n; i++)
         {
             int u=id[i];
             for(int e=head[i]; e!=-1; e=edge[e].next)
             {
                 int v=id[edge[e].u];
                 if(u!=v) in[v]=min(in[v], edge[e].val);
             }
         }
         int ans=0;
         for(int i=0; i<ind; i++)
         {
             if(i==id[0]||in[i]==999999) continue;
             ans+=in[i];
         }
         printf("%d\n", ans);
     }
     return 0;
 }