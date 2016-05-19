1 # include<stdio.h>
 2 # include<string.h>
 3 # define N 105
 4 struct node{
 5     int from,to,next;
 6 }edge[2*N];
 7 int head[N],tol,visit[N],ans[N],bug[N],n,m,dp[N][N],f[N][N];
 8 void add(int a,int b)
 9 {
10     edge[tol].from=a;edge[tol].to=b;edge[tol].next=head[a];head[a]=tol++;
11 }
12 int max(int a,int b)
13 {
14     return a>b?a:b;
15 }
16 void dfs(int u)
17 {
18     int i,j,r,tt,k;
19     visit[u]=1;
20     for(i=head[u];i!=-1;i=edge[i].next)
21     {
22         r=edge[i].to;
23         if(!visit[r])
24         {
25             dfs(r);
26             for(k=m;k>=1;k--)
27             {
28                 for(j=1;j<=k;j++)
29                 {
30                     f[u][k]=max(f[u][k],f[u][k-j]+dp[r][j]);
31                 }
32             }
33                 /*for(j=0;j<=m;j++)
34                 {
35                 if(j*20>=ans[u]) 
36                     dp[u][j]=max(dp[u][j],dp[r][(j*20-ans[u])/20]+bug[u]);
37                 }*/
38         }
39     }
40     tt=(ans[u]+19)/20;
41     for(j=tt;j<=m;j++)
42         dp[u][j]=f[u][j-tt]+bug[u];
43 }
44 int main()
45 {
46     int i,a,b;
47     while(scanf("%d%d",&n,&m)!=EOF)
48     {
49         if(n==-1 && m==-1) break;
50         for(i=1;i<=n;i++)
51             scanf("%d%d",&ans[i],&bug[i]);
52         tol=0;
53         memset(head,-1,sizeof(head));
54         for(i=1;i<n;i++)
55         {
56             scanf("%d%d",&a,&b);
57             add(a,b);
58             add(b,a);
59         }
60         memset(visit,0,sizeof(visit));
61         memset(dp,0,sizeof(dp));
62             memset(f,0,sizeof(f));
63                     if(m==0)
64         {
65             printf("0\n");
66             continue;
67         }
68 
69         dfs(1);
70         printf("%d\n",dp[1][m]);
71     }
72     return 0;
73 }