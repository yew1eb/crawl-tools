#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<list>
#include<cctype>
#include<ctime>
#include<algorithm>
using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define inf -1u>>1
#define MP(x,y) make_pair(x,y)
#define two(x) (1<<x)
#define eps 1e-8
const double pi=acos(-1.0);

/***************By Asakura*****************/
#define N 100005
#define M 500005
struct edge{
 int v;
 int next;
 int vis;
}ee[M*2];
int n,m,root,low[N],dfn[N],p[N],leave[N],deep[N],tot,cnt;
int dp[25][N];
void init()
{
 tot=0;
 cnt=0;
 memset(p,-1,sizeof(p));
 memset(dfn,0,sizeof(dfn));
 memset(low,0,sizeof(low));
 memset(dp,-1,sizeof(dp));
 memset(deep,-1,sizeof(deep));
 memset(leave,-1,sizeof(leave));
}
void add(int u,int v)
{
 ee[cnt].v=v;ee[cnt].next=p[u];ee[cnt].vis=0;
 p[u]=cnt++;
 ee[cnt].v=u;ee[cnt].next=p[v];ee[cnt].vis=0;
 p[v]=cnt++;
}
void dfs(int u,int dep)
{
 dfn[u]=low[u]=++tot;
 deep[u]=dep;
 int i;
 for(i=p[u];~i;i=ee[i].next)
 {
 if(ee[i].vis)continue;
 ee[i].vis=ee[i^1].vis=1;
 int v=ee[i].v;
 if(!dfn[v])
 {
 dfs(v,dep+1);
 low[u]=min(low[u],low[v]);
 dp[1][v]=u;
 }
 else
 low[u]=min(low[u],dfn[v]);
 }
 leave[u]=tot;
}
void tarjan()
{
 int i,j;
 for(i=1;i<=n;i++)
 if(!dfn[i])
 dfs(i,0);
 for(i=2;i<20;i++)
 for(j=1;j<=n;j++)
 if(dp[i-1][j]!=-1)
 dp[i][j]=dp[i-1][dp[i-1][j]];
}
bool s_tree(int x,int root)
{
 if(dfn[x]>=dfn[root]&&leave[x]<=leave[root])
 return true;
 return false;
}
int find(int x,int sp)
{
 int i,cnt=1,t=x;
 if(sp<0)
 return -1;
 while(sp)
 {
 if(sp&1)
 t=dp[cnt][t];
 cnt++;
 sp>>=1;
 }
 return t;
}
bool judgeE(int s,int t,int u,int v)
{
 if(deep[u]<deep[v])
 swap(u,v);
 bool flag=0;
 bool f1=s_tree(s,u);
 bool f2=s_tree(t,u);
 if(!f1&&!f2)
 flag=1;
 else if(f1&&f2)
 flag=1;
 else if(f1^f2&&low[u]<=dfn[v])
 flag=1;
 return flag;
}
bool judgeV(int s,int t,int u)
{
 bool f1=s_tree(s,u);
 bool f2=s_tree(t,u);
 bool flag=0;
 int tmd1,tmd2;
 if(!f1&&!f2)
 flag=1;
 else if(f1&&!f2)
 {
 tmd1=find(s,deep[s]-deep[u]-1);
 if(low[tmd1]<dfn[u]&&tmd1!=-1)
 flag=1;
 }
 else if(!f1&&f2)
 {
 tmd2=find(t,deep[t]-deep[u]-1);
 if(low[tmd2]<dfn[u]&&tmd2!=-1)
 flag=1;
 }
 else
 {
 tmd1=find(s,deep[s]-deep[u]-1);
 tmd2=find(t,deep[t]-deep[u]-1);
 if(tmd1==tmd2)
 flag=1;
 else if(low[tmd1]<dfn[u]&&low[tmd2]<dfn[u])
 flag=1;
 }
 return flag;
}
int main()
{
 int u,v,q,type,s,t,a,b,i;
 while(scanf("%d%d",&n,&m)!=EOF)
 {
 init();
 for(i=1;i<=m;i++)
 {
 scanf("%d%d",&u,&v);
 add(u,v);
 }
 tarjan();
 scanf("%d",&q);
 while(q--)
 {
 scanf("%d",&type);
 if(type==1)
 {
 scanf("%d%d%d%d",&s,&t,&u,&v);
 if(judgeE(s,t,u,v))
 puts("yes");
 else
 puts("no");
 }
 else
 {
 scanf("%d%d%d",&s,&t,&u);
 if(judgeV(s,t,u))
 puts("yes");
 else
 puts("no");
 }
 }
 }
 return 0;
}