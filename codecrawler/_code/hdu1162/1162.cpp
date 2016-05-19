#include<cstdio>
#include<cmath>
#include<cstring>
#include<climits> //INT_MAX的头文件
#include<algorithm>
using namespace std;

#define MAXN 110
double map[MAXN][MAXN], lowcost[MAXN];
bool visit[MAXN];
double sum;

struct point
{
	double x, y;
};
point dian[MAXN];

double fun(const point x, const point y)
{
	return sqrt((y.y - x.y) * (y.y - x.y) + (y.x - x.x) * (y.x - x.x));
}

void prim(int end)
{
	double temp;
	int i, j, k;
	sum = 0;
	memset(visit, false, sizeof(visit));
	for(i = 1; i <= end; ++i)
		lowcost[i] = map[1][i];
	visit[1] = true;
	for(i = 1; i <= end; ++i)
	{
		temp =INT_MAX; //这里错了N久。。以后就这么用了。。。
		for(j = 1; j <= end; ++j)
			if(!visit[j] && temp > lowcost[j])
			temp = lowcost[k = j];
		if(temp == INT_MAX)
			break;
		visit[k] = true;
		sum += temp;
		for(j = 1; j <= end; ++j)
			if(!visit[j] && lowcost[j] > map[k][j])
				lowcost[j] = map[k][j];
	}
}

int main()
{
	int i, j, num, count;
	double x, y;
	while(scanf("%d", &num) != EOF)
	{
		count = 0;
		for(i = 1; i < MAXN; ++i)
			for(j = 1; j < MAXN; ++j)
				map[i][j] = INT_MAX;
		for(i = 1; i <= num; ++i)
		{
			count++;
			scanf("%lf%lf", &dian[count].x, &dian[count].y);
		}
		for(i = 1; i <= count; ++i)
			for(j = 1; j <= count; ++j)
			{
				if(j == i) continue;
				map[i][j] = min(map[i][j], fun(dian[i], dian[j]));
			}
		prim(count);
		printf("%.2lf\n", sum);
	}
	return 0;
}