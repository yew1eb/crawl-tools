#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 3300;
const int maxm = maxn*maxn;
const int INF = 0x7f7f7f7f;

int n, m, mst, mark;

int cost[maxn];
//node's father;
int father[maxn];
int *fa = father;
//The son of each node
int son[maxn];
//Every node's ID
int dfn[maxn]; 
//the order;
int ndfs[maxn];
int dp[maxn][maxn];

int edge_sum;
int head[maxn];
int tree_head[maxn];
typedef struct Edge{
	int v;
	int w;
	int next;
}Edge;

Edge edge[maxm];
Edge tree[maxn];

void init(){
	mark = 0;
	edge_sum = 0;
	memset(head,-1,sizeof(head));
	memset(father,-1,sizeof(father));
	memset(tree_head,-1,sizeof(tree_head));
}

void getData(){
	int a, b, c;
	for(int i = 0; i < m; i++){	
		scanf("%d%d%d",&a,&b,&c);
		edge[edge_sum].v = b;
		edge[edge_sum].w = c;
		edge[edge_sum].next = head[a];
		head[a] = edge_sum++; 

		edge[edge_sum].v = a;
		edge[edge_sum].w = c;
		edge[edge_sum].next = head[b];
		head[b] = edge_sum++;
	}
}

int dis[maxn];
bool vist[maxn];
int closed[maxn];

void prim(){
	int i, j;			
	memset(dis,0x7f,sizeof(dis));
	memset(vist,false,sizeof(vist));

	for(i = head[0]; i != -1; i = edge[i].next){
		closed[edge[i].v] = 0;
		dis[edge[i].v] = edge[i].w;
	}

	mst = 0;
	dis[0] = INF;
	vist[0] = true;

	for(i = 0; i < n-1; i++){
		int k = 0;
		for(j = 1; j < n; j++)
			if(!vist[j] && dis[j] < dis[k])
				k = j;

		mst += dis[k];
		cost[k] = dis[k];
		vist[k] = true;

		father[k] = closed[k];
		tree[i].v = k;
		tree[i].next = tree_head[closed[k]];
		tree_head[closed[k]] = i;

		for(j = head[k]; j != -1; j = edge[j].next){
			if(vist[edge[j].v]) continue;
			if(edge[j].w > dis[edge[j].v]) continue;
			closed[edge[j].v] = k;
			dis[edge[j].v] = edge[j].w;
		}
	}
}

void dfs(int root){
	son[root] = 1;
	dfn[root] = mark;
	ndfs[mark++] = root;
	for(int i = tree_head[root];i != -1; i = tree[i].next){
		dfs(tree[i].v);
		son[root] += son[tree[i].v];
	}
}

int min(int a, int b){
	if(a < b) return a;
	else return b;
}

inline void swap(int &a, int &b){
	int c;
	c = a;
	a = b;
	b = c;
}

void work(){
	int i, j;
	memset(dp,0x7f,sizeof(dp));
	for(i = 0; i < n; i++)
		for(j = head[i]; j != -1; j = edge[j].next)
			if(fa[edge[j].v] != i && fa[i] != edge[j].v){
				dp[i][edge[j].v] = edge[j].w;
			}
	for(i = 0; i < n; i++)
		for(j = n-1; j > 0; j--)
			dp[i][fa[ndfs[j]]] = min(dp[i][fa[ndfs[j]]],dp[i][ndfs[j]]);
}

int ans[maxn];
void qurry(){
	memset(ans,-1,sizeof(ans));
	int i, j, Q, x, y, c;
	double sum = 0;
	scanf("%d",&Q);

	for(int ii = 0; ii < Q; ii++){
		scanf("%d%d%d",&x,&y,&c);
		if(father[x] == y) swap(x,y);
		if(fa[x] != y && fa[y] != x){
			sum += mst;
		}else if(father[y] == x && ans[y] != -1){
			sum += mst - cost[y] + min(ans[y],c);
		}else{
			ans[y] = INF;
			for(i = 0; i < n; i++){
				if(dfn[i] < dfn[y] || dfn[i] > dfn[y] + son[y] -1)
					ans[y] = min(ans[y],dp[i][y]);
				else
					ans[y] = min(ans[y],dp[x][i]);
			}

			sum += mst - cost[y] + min(ans[y],c);
		}
	}

	printf("%0.4lf\n",sum/Q);
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		if(n == 0 && m == 0) break;
		init();
		getData();
		prim();
		dfs(0);
		work();
		qurry();
	}
	return 0;
}