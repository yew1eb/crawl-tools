#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

#define Maxn (1005 * 2)
#define Maxm (2005 * 4)
struct Edge
{
	int a,b;
}edge[Maxm];

int first[Maxn],next[Maxm];
int total;

//scc相关
int sccno[Maxn];
bool instack[Maxn];
int dfn[Maxn];
int low[Maxn];
int dfs_clock;
int scc_cnt;
stack <int> st;

//2sat相关

void addEdge(int a,int b)
{
	edge[total].a = a,edge[total].b = b;
	next[total] = first[a];
	first[a] = total++;
}

void init()
{
	total = 0;
	memset(first,-1,sizeof(first));
}
void tarjan(int u)
{
  	dfn[u] = low[u] = ++dfs_clock;
  	st.push(u);
  	instack[u] = true;
  	for(int i=first[u];i!=-1;i=next[i])
  	{
    	int v = edge[i].b;
    	if(!dfn[v])
    	{
      		tarjan(v);
      		low[u] = min(low[u],low[v]);
    	}
    	else if(instack[v])
    	{
      		low[u] = min(low[u],dfn[v]);
    	}
  	}
  	if(dfn[u] == low[u])
  	{
    	scc_cnt++;
    	while(1)
    	{
      		int v = st.top();
      		st.pop();
      		instack[v] = false;
      		sccno[v] = scc_cnt;
      		if(u == v) break;
    	}
  	}
}
void find_scc(int start,int n)
{
	scc_cnt = dfs_clock = 0;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
  	memset(instack,false,sizeof(instack));
  	while(!st.empty())
  	{
    	st.pop();
  	}
  	for(int i=start;i<=n;i++)
  	{
    	if(!dfn[i]) tarjan(i);
  	}
}

bool twoSet(int start,int n,int add)
{
	find_scc(start,n);
	for(int i=start;i<=n;i++)
	{
		int temp;
		if(i>add) temp = i-add;
		else temp = i+add;
		if(sccno[i] == sccno[temp]) return false;
	}
	
	return true;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m,p;
	int a,b;
	while(scanf(" %d %d %d",&m,&n,&p)!=EOF)
	{
		init();
		//不可同时为空
		for(int i=0;i<n;i++)
		{
			scanf(" %d %d",&a,&b);
			addEdge(a,b+m);
			addEdge(b,a+m);
		}
		//至少有一个为空
		for(int i=0;i<p;i++)
		{
			scanf(" %d %d",&a,&b);
			addEdge(b+m,a);
			addEdge(a+m,b);
		}
		if(!twoSet(1,2*m,m))
		{
			puts("No");
			continue;
		}
		puts("Yes");
	}
	return 0;
}