#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
#define ll long long
#define int64 __int64
#define M 100005
#define N 1005
#define inf 1000010
#define mod 1000000007

struct node
{
	int son_max;
	int son_sum;
	int pos;
}tp[M];
struct Node
{
	int ev , next;
}tree[M];
int n , tot , head[M];

void Add(int s , int e)
{
	tree[tot].ev = e;
	tree[tot].next = head[s];
	head[s] = tot++;
}

void Dfs(int s , int fa)
{
	int i;
	tp[s].son_max = 0;
	tp[s].son_sum = 1;
	tp[s].pos = s;
	for (i = head[s] ; i != -1 ; i = tree[i].next)
	{
		int v = tree[i].ev;
		if (v == fa)continue;
		Dfs(v,s);
		tp[s].son_max = max(tp[s].son_max , tp[v].son_sum);
		tp[s].son_sum += tp[v].son_sum;
	}
	tp[s].son_max = max(tp[s].son_max , n-tp[s].son_sum);
}

bool cmp(node a , node b)
{
	if (a.son_max < b.son_max)return true;
	if (a.son_max > b.son_max)return false;
	if (a.pos < b.pos)return true;
	return false;
}

int main()
{
	int i , t;
	scanf("%d",&t);
	while (t--)
	{
		tot = 0;
		memset(head , -1 , sizeof head);
		scanf("%d",&n);
		for (i = 1 ; i < n ; i++)
		{
			int s , e;
			scanf ("%d%d",&s,&e);
			Add(s,e);
			Add(e,s);
		}
		Dfs(1,0);
		sort(tp+1 , tp+n+1 , cmp);
		printf("%d %d\n",tp[1].pos,tp[1].son_max);
	}
	return 0;
}