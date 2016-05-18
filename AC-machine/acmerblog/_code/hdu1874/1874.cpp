#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define N 210
#define MAX 9999999
#define CLR(arr, what) memset(arr, what, sizeof(arr))

int num, road;
int dis[N], maze[N][N];
bool visit[N];

void Dijkstra(int start)
{
	int temp, k;
	CLR(visit, false);
	for(int i = 0; i < num; ++i)
		dis[i] = (i == start ? 0 : maze[start][i]);
	visit[start] = true;
	for(int i = 0; i < num; ++i)
	{
		temp = MAX;
		for(int j = 0; j < num; ++j)
			if(!visit[j] && temp > dis[j])
				temp = dis[k = j];
		if(temp == MAX)
			break;
		visit[k] = true;
		for(int j = 0; j < num; ++j)
			if(!visit[j] && dis[j] > dis[k] + maze[k][j])
				dis[j] = dis[k] + maze[k][j];
	}
}

int main()
{
    int a, b, cost, start, end;
    while(scanf("%d%d", &num, &road) != EOF)
    {
        for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				maze[i][j] = MAX;
        for(int i = 0; i < road; ++i)
        {
            scanf("%d%d%d", &a, &b, &cost);
            if(cost < maze[a][b]) //一条路可以有多个cost，记录最小的。注意~~~
            maze[a][b] = maze[b][a] = cost;
        }
        scanf("%d%d", &start, &end);
        Dijkstra(start);
        if(dis[end] == MAX)
			printf("-1\n");
        else 
			printf("%d\n", dis[end]);
    }
    return 0;
}