#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
int n1,n2,k;
char map[105][105];
int visit[105][105];
struct node
{
	int x;
	int y;
	int turn;
};
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int go(int x,int y)
{
	if(1<=x&&x<=n1&&1<=y&&y<=n2&&map[x][y]=='.')
	return 1;
	return 0;
}
void bfs(node s1,node s2)
{
	queue<node>q;
	node st,ed;
	int i,nextx,nexty;
	memset(visit,0,sizeof(visit));
	st.x=s1.x;
	st.y=s1.y;
	st.turn=-1;
	q.push(st);
	while(!q.empty())
	{
		st=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			nextx=st.x+dir[i][0];
			nexty=st.y+dir[i][1];
			while(go(nextx,nexty))
			{
				if(!visit[nextx][nexty])
				{
					visit[nextx][nexty]=1;
					ed.x=nextx;
					ed.y=nexty;
					ed.turn=st.turn+1;
					if(ed.x==s2.x&&ed.y==s2.y&&ed.turn<=k)
					{
						printf("yes\n");
						return;
					}
					q.push(ed);
				}
				nextx+=dir[i][0];
				nexty+=dir[i][1];
			}
		}
	}
	printf("no\n");
	return;
}
int main()
{
	int t,i,j;
	node s1,s2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n1,&n2);
        for(i=1;i<=n1;i++)
		{
			getchar();
			for(j=1;j<=n2;j++)
		    scanf("%c",&map[i][j]);
		}
		scanf("%d%d%d%d%d",&k,&s1.y,&s1.x,&s2.y,&s2.x);
	    if(s1.y==s2.y&&s1.x==s2.x)
		printf("yes\n");
		else
		bfs(s1,s2);
	}
	return 0;
}