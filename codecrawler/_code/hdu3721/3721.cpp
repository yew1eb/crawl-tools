 #pragma comment(linker, "/STACK:1024000000,1024000000")
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <queue>
 #include <algorithm>
 using namespace std;
 
 const int maxn=2555;
 const int oo=0x3fffffff;
 int visit[maxn], pre[10*maxn];
 int reach[10*maxn], flow[10*maxn], head[maxn], next[10*maxn];
 int stack[10*maxn], sa[10*maxn], sb[10*maxn];
 int color[10*maxn];
 int st, sd, ans, edge;
 
 struct Node
 {
     int u, e;
     int dis;
 };
 queue<Node>q;
 
 inline void addedge(int u, int v, int c)
 {
     reach[edge]=v, flow[edge]=c, next[edge]=head[u], head[u]=edge++;
     reach[edge]=u, flow[edge]=c, next[edge]=head[v], head[v]=edge++;
 }
 
 void bfs(int ss,int op)
 {
     memset(visit,0,sizeof(visit));
     while(!q.empty()) q.pop();
     Node s, p;
     s.u=ss, s.dis=0, s.e=-1, sd=-1, st=ss;
     q.push(s);
     visit[ss]=1;
     int maxx=0, pos;
     while(!q.empty())
     {
         p=q.front();
         q.pop();
         for(int i=head[p.u]; i>=0; i=next[i])
         {
             if(color[i]||color[i^1]) continue;
             int v=reach[i], val=flow[i];
             s.u=v, s.dis=p.dis+val, s.e=i;
             if(!visit[s.u])
             {
                 visit[s.u]=1;
                 pre[s.e]=p.e;
                 if(s.dis>maxx)
                 {
                     st=s.u;
                     maxx=s.dis;
                     sd=s.e;
                 }
                 q.push(s);
             }
         }
     }
     ++op;
     if(op==1) bfs(st,op);
     else  ans=maxx;
 }
 
 int cal(int s[], int n, double len)  ///找最靠近中点的点
 {
     int sum=0;
     for(int i=0; i<n; i++)
     {
         sum+=flow[s[i]];
         if(sum>=len)
         {
             if(sum-len<=len-(sum-flow[ s[i] ])) return reach[ s[i]^1 ];
             else return reach[ s[i] ];
         }
     }
 }
 
 int Solve(int n)
 {
     int MIN=oo;
     memset(color,0,sizeof(color));
     memset(pre,-1,sizeof(pre));
     bfs(1,0);
     int top=0;
     while(sd!=-1) stack[top++]=sd,sd=pre[sd];
     for(int i=0; i<top; i++)  ///枚举最长路上的所有边
     {
         int x=stack[i], na=0, nb=0;
         color[x]=1;
         for(int j=0; j<edge; j++) pre[j]=-1;
         bfs(reach[x],0);
         while(sd!=-1) sa[na++]=sd, sd=pre[sd];
         int u=cal(sa,na,1.0*ans/2);
         if(!na) u=reach[x];
         for(int j=0; j<edge; j++) pre[j]=-1;
         bfs(reach[x^1],0);
         while(sd!=-1) sb[nb++]=sd,  sd=pre[sd];
         int v=cal(sb,nb,1.0*ans/2);
         if(!nb) v=reach[x^1];
         addedge(u,v,flow[x]);
         bfs(1,0);
         MIN=min(MIN,ans);
         color[edge-1]=1;    ///注意把新加的边移除，
         color[x]=0;
     }
     return MIN;
 }
 
 int main()
 {
     int n, T, tcase=0;
     cin >> T;
     while(T--)
     {
         cin >> n;
         edge=0;
         memset(head,-1,sizeof(head));
         for(int i=1; i<n; i++)
         {
             int a, b, c;
             scanf("%d%d%d",&a,&b,&c);
             addedge(a,b,c);
         }
         int tmp=Solve(n);
         printf("Case %d: %d\n",++tcase,tmp);
     }
 }
 /*
 10
 9
 0 1 1
 1 2 1
 2 3 1
 2 4 1
 0 5 1
 5 6 1
 5 7 1
 7 8 1
 4
 0 1 2
 1 2 2
 2 3 2
 5
 0 1 1
 1 2 2
 2 3 3
 3 4 4
 */
