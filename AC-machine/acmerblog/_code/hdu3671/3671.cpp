#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
const int MAX=1005;
struct Bridge{int x,y;}br[1000002];
struct node
{
 int v,next;
}g[MAX*MAX];
int adj[MAX],vis[MAX],low[MAX],dfn[MAX],flag[MAX],e,n,m,index,cnt;
int set[MAX],num[MAX],bn,D[MAX];
bool cut[MAX];
void add(int u,int v)
{
 g[e].v=v; g[e].next=adj[u]; adj[u]=e++;
 g[e].v=u; g[e].next=adj[v]; adj[v]=e++;
}
void dfs(int u,int fa,int deep)
{
	int i,v;
	vis[u]=1;
	low[u]=D[u]=++index;
	int tot=0;
	for(i=adj[u];i!=-1;i=g[i].next)
	{
	 v=g[i].v;
	 if(v==fa||flag[v])
 continue;
 if(vis[v]!=0)
 low[u]=min(low[u],D[v]);
 if(vis[v]==0)
 {
 dfs(v,u,deep+1);
 tot++;
 low[u]=min(low[u],low[v]);
 if((fa==-1&&tot>1)||(fa!=-1&&low[v]>=D[u]))
 cut[u]=true;
 }
	}
 vis[u]=2;
}
int find(int x)
{
 if(set[x]!=x)
 set[x]=find(set[x]);
 return set[x];
}
bool check(int x)
{
 for(int i=1;i<=n;i++)
 {
 set[i]=i;
 num[i]=1;
 }
 for(int j=0;j<e;j+=2)
 {
 if(g[j].v==x||g[j^1].v==x)
 continue;
 int f1=find(g[j].v);
 int f2=find(g[j^1].v);
 if(f1==f2)
 continue;
 else
 {
 set[f1]=f2;
 num[f2]+=num[f1];
 }
 }
 cnt=n-1;
 int j=0;
 bool ok=false;
 for(int i=1;i<=n;i++)
 {
 int t=find(i);
 if(t==i)
 j++;
 if(num[t]==1&&i!=x)
 ok=true;
 }
 if(j==3)
 {
 if(ok)
 cnt--;
 return true;
 }
 return j>2;
}
void solve()
{
 int i,j,k;
 int ans=0;
 bn=0;
 memset(flag,0,sizeof(flag));
 for(i=1;i<=n;i++)
 {
 if(check(i))
 {
 ans+=cnt;
 continue;
 }
 memset(cut,0,sizeof(cut));
 memset(dfn,0,sizeof(dfn));
 memset(vis,0,sizeof(vis));
 memset(low,0,sizeof(low));
 memset(D,0,sizeof(D));
 index=0;
 flag[i]=1;
 if(i==1)
 dfs(2,-1,0);
 else
 dfs(1,-1,0);
 for(j=1;j<=n;j++)
 if(cut[j])
 ans++;
 flag[i]=0;
 }
 printf("%d\n",ans/2);
}
int main()
{
 int i,j,k;
 int ca=0;
 while(scanf("%d%d",&n,&m)!=EOF)
 {
 if(n==0&&m==0)
 break;
 memset(adj,-1,sizeof(adj));
 e=0;
 while(m--)
 {
 scanf("%d%d",&i,&j);
 add(i,j);
 }
 printf("Case %d: ",++ca);
 if(n<=3)
 {
 puts("0");
 continue;
 }
 solve();
 }
 return 0;
}