#include<cstdio>

const int k=110;
int dir[8][2]={-1,-1,-1,0,0,-1,-1,1,1,-1,0,1,1,0,1,1};
char map[k][k];
int cnt;
int n,m;
bool isval(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m)return false;
	return true;
}
void dfs(int x,int y)
{
	int i;
	for(i=0;i<8;i++)
	{
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if(isval(tx,ty)
			&&(map[tx][ty]=='@'))
		{
			map[tx][ty]='*';
			dfs(tx,ty);
		}
	}
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0||m==0)break;
		int i,j;
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]); 
			}
		}
		cnt=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(map[i][j]=='@')
				{
					++cnt;
					dfs(i,j);
				}
				printf("%d\n",cnt);
	}
	return 0;
}