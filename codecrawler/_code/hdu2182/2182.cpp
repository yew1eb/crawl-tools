#include <iostream>
#include <cstdio>
using namespace std;

int ansnum;
int neigh[22][3];
bool vis[22];
int state[22];
int m;

void dfs(int x, int num)
{
	int i, j;

	if (num == 20)
	{
		bool flag = false;
		for (i=0; i<3; i++) if (neigh[x][i] == m) flag = true;
		if (flag)
		{
			ansnum ++;
			printf("%d: ", ansnum);
			for (j=0; j<20; j++) printf(" %d", state[j]);
			printf(" %d\n", m);
		}
		return ;
	}

	for (i=0; i<3; i++)
	{
		if (!vis[neigh[x][i]])
		{
			state[num] = neigh[x][i];
			vis[neigh[x][i]] = true;

			dfs(neigh[x][i], num+1);
			
			vis[neigh[x][i]] = false;
		}
	}
}

int main()
{
	int i;
	for (i=1; i<=20; i++)
	{
		scanf("%d %d %d", &neigh[i][0], &neigh[i][1], &neigh[i][2]);
	}
	while (scanf("%d", &m), m)
	{
		ansnum = 0;
		memset(vis, false, sizeof(vis));
		vis[m] = true;
		state[0] = m;
		dfs(m, 1);
	}
	return 0;
}