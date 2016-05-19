#include <iostream>
using namespace std;
const int M = 110;
int map[M][M];
int xy[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
bool reported;
int A,B,n,m;
struct Robot
{
	int x, y;
	int d;
}r[M];

int dir(char d)
{
	if(d=='S') return 0;
	if(d=='E') return 1;
	if(d=='N') return 2;
	if(d=='W') return 3;
}
void move(int id, int times)
{
	int d = r[id].d;
	map[r[id].x][r[id].y]=0;
	for(int i=0; i<times; i++)
	{
		r[id].x += xy[d][0];
		r[id].y += xy[d][1];
		if((!r[id].x||r[id].x>A) || (!r[id].y||r[id].y>B))
		{
			reported = true;
			printf("Robot %d crashes into the wall\n", id);
			return ;
		}
		if(map[r[id].x][r[id].y]!=0)
		{
			reported = true;
			printf("Robot %d crashes into robot %d\n", id, map[r[id].x][r[id].y]);
			return ;
		}
	}
	map[r[id].x][r[id].y] = id;
}
int main()
{
	int i,t,id,times;
	char d;
	scanf("%d", &t);
	while(t--)
	{
		memset(map, 0, sizeof(map));
		reported = false;
		scanf("%d %d", &A, &B);
		scanf("%d %d", &n, &m);
		for(i=1; i<=n; i++)
		{
			scanf("%d %d %c", &r[i].x, &r[i].y, &d);
			r[i].d = dir(d);
			map[r[i].x][r[i].y] = i;
		}
		for(i=0; i<m; i++)
		{
			scanf("%d %c %d",&id, &d, ×);
			if(d=='F' && !reported) move(id, times);
			else if(d=='L' && !reported)
			{
				times %=4;
				r[id].d = (r[id].d+times)%4;
			}
			else if(d=='R' && !reported)
			{
				times %= 4;
				r[id].d = (r[id].d-times)%4;
				if(r[id].d<0) r[id].d +=4;
			}
		}
		if(!reported) printf("OK\n");
	}
	return 0;
}