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

const int MAX = 35;
struct point {int x,y;};
struct polygon{point p[MAX]; int n;};
polygon g[MAX];
int crossProduct(point a,point b,point c)//向量 ac 在 ab 的方向 顺时针是正 
{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}
bool s2l_inst(point s1,point s2,point l1,point l2)//s是线段，l是直线 
{	// xyd包括端点在直线上。xy是穿过 
	return crossProduct(l1,l2,s1) * crossProduct(l1,l2,s2) <= 0 ;
} 
int solve(point a,point b,int n)
{
	int ans = 0;
	for(int i=0; i<n; i++)
	{
		int len = g[i].n;
		g[i].p[len] = g[i].p[0];
		for(int k=0; k<len; k++)
			if( s2l_inst(g[i].p[k], g[i].p[k+1], a, b) )
			{
				ans++;
				break;
			}
	}
	return ans;
}

int main()
{
	int ncases,n;
	int ind = 1;
	scanf("%d",&ncases);
	
	while(ncases-- )
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&g[i].n);
			for(int k=0; k<g[i].n; k++)
				scanf("%d%d",&g[i].p[k].x, &g[i].p[k].y);
		}
		if( n == 1 )
		{
			printf("Case %d: ",ind++);
			printf("1\n");
			continue;
		}
		int mmax = 0;
		for(int i=0; i<n; i++)
			for(int k=0; k<g[i].n; k++)
				for(int j=i+1; j<n; j++)
					for(int l=0; l<g[j].n; l++)
					{
						int ans = solve(g[i].p[k], g[j].p[l], n);
						if( ans > mmax )
							mmax = ans;
					}
		printf("Case %d: ",ind++);
		printf("%d\n",mmax);
	}

return 0;
}
