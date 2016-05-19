#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned __int64
#define ll __int64
//#define ll long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define middle l+r>>1
#define INF 0x3F3F3F3F
#define esp (1e-10)
#define MOD 100000007
#define type int
//const double pi=acos(-1.0);
const int M=10000 +5;
#define clr(x,c) memset(x,c,sizeof(x))
type min(type x,type y){return x<y? x:y;}
type max(type x,type y){return x>y? x:y;}
void swap(type& x,type& y){type t=x;x=y;y=t;}
int T,cas=0;

int n,m,c;
struct node{int v,len;};
vector<node>son[M];
int fa[M],dis[M],dp[M<<1][22];
int tot,idx[M<<1],dep[M<<1],r[M];
bool vis[M];

node New(int _v,int _l){
	node r;
	r.v=_v,r.len=_l;
	return r;
}

int find(int x){
	for(;x!=fa[x];x=fa[x]);
	return x;
}

void dfs(int u,int cur,int len){
	vis[u]=true;
	idx[tot]=u,dep[tot]=cur;
	r[u]=tot,dis[u]=len;
	tot++;
	for(int i=0;i<son[u].size();i++){
		int v=son[u][i].v;
		if(!vis[v]){
			dfs(v,cur+1,len+son[u][i].len);
			idx[tot]=u,dep[tot]=cur,tot++;
		}
	}
}

inline int getMin(int i,int j){
	return dep[i]<=dep[j]? i:j;
}

void ST(int n){
	int i,j;
	for(i=1;i<=n;i++) dp[i][0]=i;
	int m=log(double(n))/log(2.0);
	for(j=1;j<=m;j++)
		for(i=1;i+(1<<j)-1<=n;i++)
			dp[i][j]=getMin(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
}

int rmq(int l,int r){
	int k=log(double(r-l+1))/log(2.0);
	return getMin(dp[l][k],dp[r-(1<<k)+1][k]);
}

int lca(int u,int v){
	int i=r[u],j=r[v];
	return i<j? idx[rmq(i,j)]:idx[rmq(j,i)];
}

void run(){
	int i,j,k;
	int u,v,d,id;
	for(i=1,++n;i<=n;i++){
		vis[i]=false;
		fa[i]=i,son[i].clear();
	}
	while(m--){
		scanf("%d%d%d",&u,&v,&d);
		fa[find(u)]=find(v);
		son[u].push_back(New(v,d));
		son[v].push_back(New(u,d));
	}
	for(i=1;i<n;i++) if(fa[i]==i) son[n].push_back(New(i,1));
	tot=1,dfs(n,0,0),ST((n<<1)-1);
	while(c--){
		scanf("%d%d",&u,&v);
		k=lca(u,v);
		if(k==n) puts("Not connected");
		else printf("%d\n",dis[u]+dis[v]-(dis[k]<<1));
	}
}

int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	//run();
	while(~scanf("%d%d%d",&n,&m,&c)) run();
	//for(scanf("%d",&T),cas=1;cas<=T;cas++) run();
	//system("pause");
	return 0;
}