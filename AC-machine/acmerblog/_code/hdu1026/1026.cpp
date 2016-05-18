#include <iostream>
#include <queue>
using namespace std;
const int MAX = 99999999;
int n,m;
struct st
{
	char cc;
	int num,x,y,prex,prey;
}map[105][105];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
void outPut()
{
	int x=0,y=0,a,b,num=1,i;
	if(map[0][0].num!= MAX)
	{
		printf("It takes %d seconds to reach the target position, let me show you the way.\n",map[0][0].num);
		while(x!= n-1| y!=m-1)
		{
			a=map[x][y].prex; 
			b=map[x][y].prey;
			if(map[x][y].cc!='.')
				for(i=0;i<map[x][y].cc - '0';i++)
					printf("%ds:FIGHT AT (%d,%d)\n",num++,x,y);
			printf("%ds:(%d,%d)->(%d,%d)\n",num++,x,y,a,b);
			x=a; y=b;
		}
		if(map[x][y].cc!='.')
		{
			for(i=0;i<map[x][y].cc - '0';i++)
				printf("%ds:FIGHT AT (%d,%d)\n",num++,x,y);
		}
		printf("FINISH\n");
	}
	else
	{
		printf("God please help our poor hero.\nFINISH\n");
	}
}

void bfs()
{
	int temp;
	struct st fir;
	queue<st> qu;
	map[n-1][m-1].num=0;
	if(map[n-1][m-1].cc>='1'&&map[n-1][m-1].cc<='9')
		map[n-1][m-1].num=map[n-1][m-1].cc - '0';
	qu.push(map[n-1][m-1]);
	while(!qu.empty())
	{
		fir=qu.front();
		for(int i=0;i<4;i++)
		{
			int tx=fir.x+dir[i][0],ty=fir.y+dir[i][1];
			if(tx<0||ty<0||tx>=n||ty>=m||map[tx][ty].cc=='X') continue;
			if(map[tx][ty].cc!='.')       
				temp=fir.num + map[tx][ty].cc-'0';
			else  
				temp=fir.num;  
			if(temp+1<map[tx][ty].num)
			{
				map[tx][ty].num=temp+1;
				map[tx][ty].prex=fir.x;
				map[tx][ty].prey=fir.y;
				qu.push(map[tx][ty]);                    
			}
		}
		qu.pop();
	}
	outPut();
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		getchar();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&map[i][j].cc);
				map[i][j].num = MAX;
				map[i][j].x=i;
				map[i][j].y=j;
				map[i][j].prey=map[i][j].prex=-1;
			}
			getchar();
		}
		bfs();
	}
}