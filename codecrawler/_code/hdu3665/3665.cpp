#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")
#define STOP system("pause")

using namespace std;

const int MAX = 15;
int mm[MAX][MAX];
bool sea[MAX];

void init()
{
	memset(sea, false, sizeof(sea));
	for(int i=0; i<MAX; i++)
	{
		for(int k=0; k<MAX; k++)
			mm[i][k] = INT_MAX;
		mm[i][i] = 0;
	}
}

int Dijkstra(int from, int n)
{
	int dis[MAX];
	bool used[MAX];
	for(int i=0; i<n; i++) dis[i] = INT_MAX;
	memset(used, false, sizeof(used));
	used[from] = true; dis[from] = 0;
	int now = from;
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++)
			if( mm[now][k] != INT_MAX && dis[now] != INT_MAX 
				&& mm[now][k] + dis[now] < dis[k] )
				dis[k] = dis[now] + mm[now][k];
		
		int mmin = INT_MAX;
		
		for(int k=0; k<n; k++)
			if( mmin > dis[k] && !used[k] )
				mmin = dis[now = k];
		used[now] = true;
	}
	
	int ans = INT_MAX;
	for(int i=0; i<n; i++)
		if( sea[i] && ans > dis[i] )
			ans = dis[i];
	return ans;
}

int main()
{
	int n, p, m, to, len;
	
	while( ~scanf("%d", &n) )
	{
		init();		
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&m, &p);
			if( p ) sea[i] = true;
			while( m-- )
			{
				scanf("%d%d", &to, &len);
				if( len < mm[i][to] )
					mm[i][to] = mm[to][i] = len;
			}
		}
		
		int ans = Dijkstra(0, n);
		
		printf("%d\n", ans);
	}

return 0;
}
