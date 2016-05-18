/*
	本题用深搜，尽可能多的安排rook
*/
#include<stdio.h>
char map[4][4];
int x[20],y[20],c[20],num,n,no;
int xing(int i,int j)
{
	if(c[j]==0)
		return 0;
	if(x[i]!=x[j]&&y[i]!=y[j])
		return 0;
	if(x[i]==x[j])
	{
		int k=y[i],l=y[j],t;
		if(k>l)
		{
			t=k;
			k=l;
			l=t;
		}
		for(;k<=l;k++)
			if(map[x[i]][k]=='X')
				return 0;
		return 1;
	}
	else
	{
		int k=x[i],l=x[j],t;
		if(k>l)
		{
			t=k;
			k=l;
			l=t;
		}
		for(;k<=l;k++)
			if(map[k][y[i]]=='X')
				return 0;
		return 1;
	}
}
int he(int i)
{
	int j;
	for(j=0;j<i;j++)
		if(xing(i,j))
			return 0;
	return 1;
}
void dfs(int ii,int o)
{
	int i;
	if(ii==num)
		return;
	for(i=ii;i<num;i++)//一次试，o可否安排在i
	{
		if(he(i))//判断i处能否安排rook
		{
			c[i]=1;
			if(o>no)//o代表当前rook的数量，若大与no，就更新no
				no=o;
			dfs(i+1,o+1);//o安排在i，接着在从i+1开始往后安排第o+1个rook
			c[i]=0;
		}
	}
}
int main()
{
	int i,j;
	while(scanf("%d",&n),n)
	{
		getchar();
		num=0;
		no=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				map[i][j]=getchar();
				if(map[i][j]=='.')//搜集可安排棋子的位置
				{
					x[num]=i;
					y[num]=j;
					c[num]=0;
					num++;
				}
			}
			getchar();
		}
		dfs(0,1);//在从开始往后的地方，安排第1个rook
		printf("%d\n",no);
	}
	return 0;
}