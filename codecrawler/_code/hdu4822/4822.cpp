 #pragma comment(linker,"/STACK:16777216")
 #include<stdio.h>
 #include<string.h>
 #include<algorithm>
 using namespace std;
 struct dian{
   int type,u;
 };
 int now,next[200005],head[200005],point[200005];
 int parent[200005][21],size[200005],depth[200005];
 void add(int x,int y)
 {
   next[++now]=head[x];
   head[x]=now;
   point[now]=y;
 }
 void dfs(int u,int pre,int deep)
 {
   int i,v;
   parent[u][0]=pre;
   size[u]=1;
   depth[u]=deep;
   for (i=head[u];i!=-1;i=next[i])
   {
     v=point[i];
     if (v==pre) continue;
     dfs(v,u,deep+1);
     size[u]+=size[v];
   }
 }
 void rmq_build(int n)
 {
   for (int k=0;k<20;k++)
     for (int u=1;u<=n;u++)
       if (parent[u][k]==-1) parent[u][k+1]=-1;
       else parent[u][k+1]=parent[parent[u][k]][k];
 }
 int go_up(int u,int deep)
 {
   for (int k=0;k<=20;k++)
     if ((deep>>k)&1) u=parent[u][k];
   return u;
 }
 int rmq_query(int u,int v)
 {
   if (depth[u]<depth[v]) swap(u,v);
   u=go_up(u,depth[u]-depth[v]);
   if (u==v) return u;
   for (int k=20;k>=0;k--)
     if (parent[u][k]!=parent[v][k])
       u=parent[u][k],v=parent[v][k];
   return parent[u][0];
 }
 dian get_middle(int a,int b,int ab)
 {
   int len=depth[a]+depth[b]-2*depth[ab];
   dian n1;
   if (depth[a]>=depth[b])
     n1.type=1,n1.u=go_up(a,(len-1)/2);
   else n1.type=2,n1.u=go_up(b,len/2);
   return n1;
 }
 int n;
 int cal(int a,int b,int c,int ab,int ac)
 {
   dian ab_m=get_middle(a,b,ab),ac_m=get_middle(a,c,ac);
   if (ab_m.type==1&&ac_m.type==1)
     return depth[ab_m.u]>depth[ac_m.u]?size[ab_m.u]:size[ac_m.u];
   else if (ab_m.type==2&&ac_m.type==2){
       if (depth[ab_m.u]<depth[ac_m.u]) swap(ab_m,ac_m);
       if (rmq_query(ab_m.u,ac_m.u)==ac_m.u) return n-size[ac_m.u];
       return n-size[ab_m.u]-size[ac_m.u];
   }
   else{
     if (ab_m.type==2) swap(ab_m,ac_m);
     int tmp=rmq_query(ab_m.u,ac_m.u);
     if (tmp==ab_m.u) return size[ab_m.u]-size[ac_m.u];
     return size[ab_m.u];
   }
 }
 int main()
 {
   int a,b,c,ab,bc,ac,T,m,i;
   scanf("%d",&T);
   while (T--)
   {
     scanf("%d",&n);
     now=0;
     memset(head,-1,sizeof(head));
     for (i=1;i<n;i++)
     {
       scanf("%d%d",&a,&b);
       add(a,b); add(b,a);
     }
     dfs(1,-1,0);
     rmq_build(n);
     scanf("%d",&m);
     while (m--)
     {
       scanf("%d%d%d",&a,&b,&c);
       ab=rmq_query(a,b),ac=rmq_query(a,c),bc=rmq_query(b,c);
       printf("%d %d %d\n",
           cal(a,b,c,ab,ac),cal(b,a,c,ab,bc),cal(c,a,b,ac,bc));
     }
   }
   return 0;
 }
