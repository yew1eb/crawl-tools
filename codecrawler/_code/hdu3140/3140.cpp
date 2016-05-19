#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include<queue>
#include<set>
using namespace std;

int step[5] , n , m , maxsz;
int A[351] , p[5];
unsigned short f[5][923531];
unsigned short sz[5];
int st[5][8000];
bool vis[5][923531];

void init()
{
	memset(step,0,sizeof(step));
	memset(vis,0,sizeof(vis));
	memset(sz,0,sizeof(sz));
	memset(f,0,sizeof(f));
}

void getCard(int ss)
{
	memset(step,0,sizeof(step));
	int i = 4;
	int tmp = ss;
	while (ss)
	{
		if (p[i] && ss >= p[i])
		{
			step[i] = ss / p[i];
			ss -= p[i]*step[i];
		}
		--i;
	}
}

int getState()
{
	int ret = 0;
	for (int i = 4 ; i >= 1 ; --i) if (step[i])
		ret += step[i]*p[i];
	return ret;
}

void input()
{
	for (int i = 1 ; i <= n ; ++i) scanf("%d",A+i);
	for (int i = 0 ; i < m ; ++i)
	{
		int a;
		scanf("%d",&a);
		++step[a];
	}
	maxsz = 1;
	p[1] = 1;
	for (int i = 2 ; i <= 4 ; ++i)
	{
		p[i] = p[i-1];
		if (step[i-1]) p[i] *= (1+step[i-1]);
	}
	for (int i = 1 ; i <= 4 ; ++i)
		if (step[i]==0) p[i] = 0;
	for (int i = 1 ; i <= 4 ; ++i) if (step[i])
		maxsz *= step[i];
	int h = getState();
	f[1][h] = A[1];
	st[1][sz[1]++] = h;
}

void Dp(int to,int w)
{
	int j = getState();
	if (f[to][j] < w) f[to][j] = w;
	if (!vis[to][j]) 
	{
		vis[to][j] = true;
		st[to][sz[to]++] = j;
	}
}

void solve()
{
	for (int i = 1 ; i < n ; ++i)
	{
		for (int j = 0 ; j < sz[i%5] ; ++j)
		{
			int s = st[i%5][j];
			getCard(s);
			for (int k = 1 ; k <= 4 ; ++k) if (step[k])
			{
				--step[k];
				Dp((i+k)%5, f[i%5][s]+A[i+k]);
				++step[k];
			}
		}
		sz[i%5] = 0;
		memset(f[i%5],0,sizeof(f[i%5]));
		memset(vis[i%5],false,sizeof(vis[i%5]));
	}
	printf("%d\n",f[n%5][0]);
}

int main()
{
	while (scanf("%d%d",&n,&m)==2)
	{
		init();
		input();
		solve();
	}
}