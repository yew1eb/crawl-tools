#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<math.h>
#define N 1010
#define inf 10000000
using namespace std;
inline int Min(int a,int b){return a>b?b:a;}

struct node{
	int from, to, nex;
}edge[N*5];
int head[N], edgenum;
void addedge(int u, int v){
	node E={u,v,head[u]};
	edge[ edgenum ] = E;
	head[u] = edgenum++;
}
int DFN[N], Low[N], Time, vis[N], sign, belong[N];
int Stack[N], top;
void tarjan(int u, int fa){
	DFN[ u ] = Low[ u ] = Time++;
	vis[ u ] = 1;
	Stack[top++] = u;
	int child = 0;
	for(int i = head[u]; i!=-1; i = edge[i].nex){
		int v = edge[i].to;
		if(DFN[ v ] == -1){
			tarjan(v, u);
			Low[u] = Min(Low[u], Low[v]);
		}
		/*else if(fa == v){
			if(child) Low[u] = Min(Low[u], DFN[v]);
			child++;
		}*/
		else if(vis[v])//v是走过的点 -> 这是反向弧
			Low[u] = Min(Low[u], DFN[v]);
	}
	if(DFN[u] == Low[u])//反向弧在u及u以下
	{
		sign++;
		while(1){
			int now = Stack[--top];
			vis[now] = 0;
			belong[now] = sign;
			if(now == u)break;
		}
	}
}

void tarjan_init(){
		memset(head, -1, sizeof(head)); edgenum = 0;
		memset(DFN, -1, sizeof(DFN));
		memset(Low, -1, sizeof(Low));
//		memset(belong, 0, sizeof(belong));
		memset(vis, 0, sizeof(vis));
		sign = top = 0;
		Time = 0;
}
int a[N], n, m;
int lala[N], inde[N];

int main(){
	int i,j,u,v;
	while(~scanf("%d %d",&n,&m)){
		tarjan_init();

		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		while(m--){
			scanf("%d %d",&u,&v);
			addedge(u, v);
		}
		for(i=1;i<=n;i++)if(DFN[i]==-1)tarjan(i, -1);

		int ans1 = 0, ans2 = 0;
		memset(inde, 0, sizeof(inde));
		for(i = 0;i<edgenum; i++)
		{
			u = edge[i].from; v = edge[i].to;
			if(belong[u] != belong[v])
				inde[ belong[v] ] ++;
		}
		for(i = 1; i <= sign;i++)
		{
			if(inde[i] == 0)
				ans1++;
			lala[i] = inf;
		}
		for(i = 1; i <= n;i++)
		{
			int tmp = belong[i];
			if(inde[ tmp ] == 0)
				lala[tmp] = Min(lala[tmp], a[i]);
		}
		for(i = 1; i <= sign; i++)
			if(lala[i] != inf)
				ans2 += lala[i];

		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}