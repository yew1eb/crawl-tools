#include <iostream>
#include <string.h>
#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
const int maxn = 505;
const int maxm = maxn * maxn * 2;
const int inf = 0x3f3f3f3f;

int pt[maxm], next[maxm], head[maxn], flow[maxm];
int level[maxn], queue[maxn], pos;
int n, m;

void AddEdge(int a, int b, int c)
{
	pt[++pos] = b;
	next[pos] = head[a];
	head[a] = pos;
	flow[pos] = c;
}

void Connect(int a, int b, int c)
{
	AddEdge(a, b, c);
	AddEdge(b, a, 0);
}

bool bfs(int s, int t)
{
	int qs, qe, v, e;
	memset (level, 0, sizeof level);
	qs = qe = 0;
	queue[qe++] = s;
	level[s] = 1;
	while (qs < qe)
	{
		v = queue[qs++];
		for (e = head[v]; e != -1; e = next[e])
			if (flow[e] > 0 && level[pt[e]] == 0)
			{
				queue[qe++] = pt[e];
				level[pt[e]] = level[v] + 1;
			}
	}
	return level[t] > 0;
}

int Update(int v, int t, int tmpflow)
{
	int e, tmp, res = 0;
	if (v == t) return tmpflow;
	for (e = head[v]; e != -1; e = next[e])
		if (flow[e] > 0 && level[pt[e]] == level[v] + 1)
		{
			tmp = Update(pt[e], t, min(flow[e], tmpflow));
			flow[e] -= tmp; flow[e^1] += tmp;
			res += tmp; tmpflow -= tmp;
			if (tmpflow == 0) break;
		}
	level[v] = -1;
	return res;
}

int dinic(int s, int t)
{
	int res = 0;
	while (bfs(s, t))
		res += Update(s, t, inf);
	return res;
}

void init()
{
	int i, a, b, c;
	pos = -1;
	memset (head, -1, sizeof head);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		Connect(0, i, a);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		Connect(i, n + 1, a);
	}
	for (i = 0; i < m; i++)
	{
		scanf ("%d%d%d", &a, &b, &c);
		AddEdge(a, b, c);
		AddEdge(b, a, c);
	}
}

void Solve()
{
	int res = dinic(0, n + 1);
	printf("%d\n", res);
}

int main()
{
	while (scanf ("%d%d", &n, &m) != EOF)
	{
		init();
		Solve();
	}
	return 0;
}