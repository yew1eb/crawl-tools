/*
题意：n*n的矩形中放入颜色值为[1,50]的气球，要求每一个人扎k次，每扎一次，可以将同行或者同列相同颜色的气球全部扎破。求是否存在不可能全部扎破的气球，按照升序规律输出气球的颜色。

题解：多次进行最小点覆盖运算即可
矩形行列分别为集合A和集合B，如果判断k气球，则如果map[i][j] = k，则表示存在一条边，这样便可以转换成最小点覆盖问题，只需要找出最小的点，清除掉两集合之间所有的边即可。
*/

#include <iostream>
#define re(i, n) for(int i = 0; i < n; ++ i)
using namespace std;

const int nMax = 105;
int map[nMax][nMax];
int link[nMax];
int useif[nMax];
int ans[nMax];
int len;
int n, k;

int dfs(int t, int col)
{
	re(i, n)
	{
		if(!useif[i] && map[t][i] == col)
		{
			useif[i] = 1;
			if(link[i] == -1 || dfs(link[i], col))
			{
				link[i] = t;
				return 1;
			}
		}
	}
	return 0;
}

int maxMatch(int col)
{
	memset(link, -1, sizeof(link));
	int num = 0;
	re(i, n)
	{
		memset(useif, 0, sizeof(useif));
		if(dfs(i, col)) num ++;
	}
	return num;
}

int main()
{
	//freopen("f://data.in", "r", stdin);
	while(scanf("%d %d", &n, &k) != EOF)
	{
		memset(map, 0, sizeof(map));
		len = 0;
		if(!n && !k) break;
		re(i, n) re(j, n) scanf("%d", &map[i][j]);
		for(int i = 1; i <= 50; ++ i)
		{
			if(maxMatch(i) > k)
				ans[len ++] = i;
		}
		if(!len) 
			printf("-1\n");
		else
		{
			re(i, len - 1) printf("%d ", ans[i]);
			printf("%d\n",ans[len - 1]);
		}
	}
	return 0;
}