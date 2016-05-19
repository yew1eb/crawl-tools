#include <iostream>
#include <string>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MAX = 1010;

bool visited[MAX];
int map[MAX][MAX];
int value[MAX][MAX];
int cost[MAX];
int dist[MAX];
//int prec[MAX];
int n,m,s,t,dis,cos;

void Dijkstra()
{
	int i,min,v;
	memset(dist,0x7f,sizeof(dist));
	memset(visited,false,sizeof(visited));
	dist[s] = 0;

	while(true)
	{
		min = INF, v = s;
		for (i=0; i<n; ++i)
		{
			if (!visited[i] && dist[i] < min)
				min = dist[i], v = i;
		}

		if (min == INF)
			break;
		visited[v] = true;
		for (i=0; i < n; ++i)
		{
			if (!visited[i] && map[v][i] < INF)
			{
				if (dist[v] + map[v][i] < dist[i])
				{
					dist[i] = dist[v] + map[v][i];
					cost[i] = cost[v] + value[v][i];
				}
				else if (dist[v] + map[v][i] == dist[i] && cost[v] + value[v][i] < cost[i])
					cost[i] = cost[v] + value[v][i];
			}
		}
	}
}
/*
void print(int v)
{
	if ( v != s )
		print(prec[v]);
	cout << v << ' ';
}*/
int main()
{
	int i,x,y;
	while(cin >> n >> m && !(n==0&&m==0))
	{
		memset(map,0x7f,sizeof(map));
		memset(value,0x7f,sizeof(value));	//debug
		memset(cost,0,sizeof(cost));

		for ( i = 0; i < m; ++i )
		{
			cin >> x >> y >> dis >> cos;
			--x,--y;
			if ( dis < map[x][y] )
			{
				map[x][y] = map[y][x] = dis;
				value[x][y] = value[y][x] = cos;
			}
			else if ( dis == map[x][y] && cos < value[x][y] )
				value[x][y] = value[y][x] = cos;
		}
		cin >> s >> t;
		--s,--t;
		Dijkstra();
		cout << dist[t] << " " << cost[t] << endl;
	}
	return 0;
}