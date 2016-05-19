#include<iostream>
#include<string>
using namespace std;

struct node
{
	int x,y;
};
int map[10][10];
node *Q;
int n;
bool isok;
void output()
{
	int i,j;
	for(i=1;i<10;i++)
	{
		for(j=1;j<10;j++)
		{
			if(j>1)printf(" ");
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
}
bool unfind(int x,int y,int k)
{
	int i,j;
	for(i=1;i<10;i++)
	{
		if(map[x][i]==k||map[i][y]==k)return false;
	}
	int tx=(x-1)/3*3+1;
	int ty=(y-1)/3*3+1;
	for(i=tx;i<tx+3;i++)
		for(j=ty;j<ty+3;j++)
			if(map[i][j]==k)return false;
			
			return true;
}
void dfs(int cnt)
{
	if(isok)return;
	int i;
	if(cnt==n)
	{
		isok=true;
		output();
	}
	else
	{
		int tx=Q[cnt].x;
		int ty=Q[cnt].y;
		for(i=1;i<10;i++)
		{
			if(unfind(tx,ty,i))
			{
				map[tx][ty]=i;
				dfs(cnt+1);
				map[tx][ty]=0;
			}
		}
	}
}


int main()
{
	char ch[2];
	int a=0;
	while(scanf("%s",ch)!=EOF)//cin>>ch
	{
		
		Q=new node[81];
		n=0;
		if(ch[0]!='?')
			map[1][1]=ch[0]-'0';
		else
		{
			map[1][1]=0;
			Q[n].x=1;
			Q[n++].y=1;
		}
		int i,j;
		for(i=1;i<10;i++)
		{
			for(j=1;j<10;j++)
			{
				if(i!=1||j!=1)
				{scanf("%s",ch);
				//cin>>ch;
				if(ch[0]!='?')
				{
					int t=ch[0]-'0';
					map[i][j]=t;
				}
				else
				{
					map[i][j]=0;
					Q[n].x=i;
					Q[n++].y=j;
				}
				} 
			}
		}
		if(a)printf("\n");a++;
		isok=false;
		dfs(0);
	}
	return 0;
}