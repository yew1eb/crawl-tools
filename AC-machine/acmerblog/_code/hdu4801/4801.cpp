#include<stdio.h>
#include<string.h>
int mian[6][4]={0,1,2,3,16,17,18,19,4,5,10,11,8,9,14,15,6,7,12,13,20,21,22,23};//六个面的编号
int huan[3][12],color[24],ans,n;
int max(int a,int b)
{
	if(a>b)return a;
	return b;
}
void insit()
{
	//转动的三个面的编号（顺时针）
	huan[0][0]=6;huan[0][1]=7;huan[0][2]=13;huan[0][3]=12;
	huan[1][0]=16;huan[1][1]=17;huan[1][2]=19;huan[1][3]=18;
	huan[2][0]=14;huan[2][1]=8;huan[2][2]=9;huan[2][3]=15;
    //转动时面的侧面的编号
	huan[0][4]=2;huan[0][5]=3;huan[0][6]=8;huan[0][7]=14;huan[0][8]=17;huan[0][9]=16;huan[0][10]=11;huan[0][11]=5;
	huan[1][4]=10;huan[1][5]=11;huan[1][6]=12;huan[1][7]=13;huan[1][8]=14;huan[1][9]=15;huan[1][10]=21;huan[1][11]=20;
	huan[2][4]=23;huan[2][5]=21;huan[2][6]=19;huan[2][7]=17;huan[2][8]=13;huan[2][9]=7;huan[2][10]=3;huan[2][11]=1;
}
void move1(int id)//顺时针转动
{
	int i,tt,t=color[huan[id][3]];
	for(i=3;i>0;i--)
		color[huan[id][i]]=color[huan[id][i-1]];
	color[huan[id][0]]=t;
	t=color[huan[id][10]];tt=color[huan[id][11]];
	for(i=11;i>5;i--)
		color[huan[id][i]]=color[huan[id][i-2]];
	color[huan[id][4]]=t;color[huan[id][5]]=tt;
}
void move2(int id)//逆时针转动
{
	int i,tt,t=color[huan[id][0]];
	for(i=0;i<3;i++)
		color[huan[id][i]]=color[huan[id][i+1]];
	color[huan[id][3]]=t;
	t=color[huan[id][4]];tt=color[huan[id][5]];
	for(i=4;i<10;i++)
		color[huan[id][i]]=color[huan[id][i+2]];
	color[huan[id][10]]=t;color[huan[id][11]]=tt;	
}
void move(int id,int i)
{
	if(id==0)move1(i);
	else if(id==1)move2(i);
}
int judge()
{
	int i,j,k=0;
	for(i=0;i<6;i++)
	{
		for(j=1;j<4;j++)
			if(color[mian[i][j]]!=color[mian[i][0]])break;
			if(j==4)k++;
	}
	return k;
}
void dfs(int num,int ii,int id)
{
	if(num>=n||ans==6)return ;
	for(int i=0;i<3;i++)
	{
		if(i==ii)
		{
			move(id,i);
			ans=max(judge(),ans);
			dfs(num+1,i,id);
			move(id^1,i);
			continue;
		}
		for(int j=0;j<2;j++)
		{
			move(j,i);
			ans=max(judge(),ans);
			dfs(num+1,i,j);
			move(j^1,i);
		}
	}
}
int main()
{
	int i;
	insit();
	while(scanf("%d",&n)!=-1)
	{
		for(i=0;i<24;i++)
			scanf("%d",&color[i]);
		ans=judge();
		dfs(0,-1,-1);
		printf("%d\n",ans);
	}
	return 0;
}