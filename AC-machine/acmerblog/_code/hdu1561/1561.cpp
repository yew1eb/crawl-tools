#include <stdio.h>
#include <string.h>
#define MAX 210
#define max(a,b) (a)>(b)?(a):(b)


struct node {

	int v;
	node *next;
}*head[MAX],tree[MAX];
int n,m,money[MAX];	//root表示输入时是否与根相连
int ptr,dp[MAX][MAX];


void Initial() {
	
	ptr = 1;
	memset(dp,0,sizeof(dp));
	memset(head,NULL,sizeof(head));
}
void AddEdge(int fa,int son) {

	tree[ptr].v = son;
	tree[ptr].next = head[fa];
	head[fa] = &tree[ptr++];
}
int Tree_DP(int v) {

	int i,j,k,tot = 1;
	node *p = head[v];

	
	while (p != NULL) {

		tot += Tree_DP(p->v);
		int tp = tot < m ? tot : m;		//加个剪枝，这个到目前为止能到达最大容量
		for (j = tp; j >= 1; --j)   //分组背包
			for (i = 1; i <= j; ++i)
				dp[v][j] = max(dp[v][j],dp[p->v][i]+dp[v][j-i]);
		p = p->next;
	}


	if (v != 0) {

		for (j = m; j >= 1; --j)
			dp[v][j] = dp[v][j-1] + money[v];	//必选当前节点自己
	}
	return tot;
}


int main()
{
	int i,j,k,a,b;


	while (scanf("%d%d",&n,&m),n+m) {

		Initial();
		for (i = 1; i <= n; ++i) {

			scanf("%d%d",&a,&b);
			money[i] = b;
			AddEdge(a,i);
		}


		Tree_DP(0);
		printf("%d\n",dp[0][m]);
	}
}