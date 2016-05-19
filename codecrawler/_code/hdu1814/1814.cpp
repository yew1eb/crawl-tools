#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>

#define ll double
#define eps 1e-5

using namespace std;

inline ll Max(ll a,ll b){return a>b?a:b;}
inline ll Min(ll a,ll b){return a<b?a:b;}


#define N 8010*2
#define M 40000+5

struct Edge{
	int to, nex;
}edge[M];

int head[N], edgenum;
void addedge(int u, int v){
	Edge E = {v, head[u]};
	edge[edgenum] = E;
	head[u] = edgenum ++;
}

bool mark[N];
int Stack[N], top;
void init(){
	memset(head, -1, sizeof(head)); edgenum = 0;
	memset(mark, 0, sizeof(mark));
}

bool dfs(int x){
	if(mark[x^1])return false;//一定是拆点的点先判断
	if(mark[x])return true;

	mark[x] = true;
	Stack[top++] = x;

	for(int i = head[x]; i != -1; i = edge[i].nex)
		if(!dfs(edge[i].to)) return false;

	return true;
}

bool solve(int n){
	for(int i = 0; i < n; i+=2)
		if(!mark[i] && !mark[i^1])
		{
			top = 0;
			if(!dfs(i))//dfs(i) 假设i成立 
			{//当i不成立时，把所有因i成立的点都取消标记
				while( top ) mark[ Stack[--top] ] = false;
				if(!dfs(i^1))
					return false;//若i的对立面也不成立则i点无解
			}
		}
		return true;
}

int main(){
	int n, i, j, m;
	while(~scanf("%d%d",&n,&m)){
		n <<= 1;
		init();

		while(m--)
		{
			int u,v;
			scanf("%d %d",&u,&v); u--, v--;
			addedge(u,v^1);
			addedge(v,u^1);
		}

		if(solve(n))
		{
			for(i=0;i<n;i++)
				if(mark[i])printf("%d\n",i+1);
		}
		else
			printf("NIE\n");

	}
	return 0;
}