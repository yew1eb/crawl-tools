#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int pieset[16][4][4]={0};//all pieces set,note piece#1 place 1111 piece#2 place 2222 no the problem says place 1111,piece#i place iii
int n=0;//per cases pieces number
int piesize[16][2]={0};//all pieces size m*n
int piecnt[16]={0};//piecnt[i] is piece#(i+1) 's sum !0 count
int puzzle[4][4]={0};//place the all piece to this matirx
int flag=0;//is solution possible flag
/*judge the block !0 and !0 is invalid*/
bool IsFit(int dest[][4])
{
	int i=0,j=0;
	for(i=0;i<=4-1;i++)
	{
		for(j=0;j<=4-1;j++)
		{
			if(dest[i][j]!=0&&puzzle[i][j]!=0)
			{
				return(false);
			}
		}
	}
	return(true);
}
/*fit the piece to the puzzle*/
int FitPie(int dest[][4])
{
	int i=0,j=0;
	for(i=0;i<=4-1;i++)
	{
		for(j=0;j<=4-1;j++)
		{
			if(dest[i][j]!=0)
			{
				puzzle[i][j]=dest[i][j];
			}
		}
	}
	return(0);
}
/*unfit the piece from the puzzle*/
int UnFitPie(int dest[][4])
{
	int i=0,j=0;
	for(i=0;i<=4-1;i++)
	{
		for(j=0;j<=4-1;j++)
		{
			if(dest[i][j]!=0)
			{
				puzzle[i][j]=0;
			}
		}
	}
	return(0);
}
/*judge the matrix is filled with the piece*/
bool IsFilled()
{
	int i=0,j=0;
	for(i=0;i<=4-1;i++)
	{
		for(j=0;j<=4-1;j++)
		{
			if(puzzle[i][j]==0)
			{
				return(false);
			}
		}
	}
	return(true);
}
/*DFS the piece,the cur is piece number, or index of now will place the piece*/
int DFS(int cur)
{
	if(flag)
	{
		return(0);
	}
	if(cur>=n)
	{
		if(IsFilled())//judge the matrix is filled with the piece
		{
			flag=1;
			return(0);
		}
	}
	else
	{
		//translate the piece
		int i=0,j=0;//i,j is increase of the coordinate
		int t=0,r=0;//destination two dimension coordinate
		int x=0,y=0;//source two dimension coordinate
		for(i=-3;i<=3;i++)//can translate to - direction
		{
			for(j=-3;j<=3;j++)
			{
				int dest[4][4]={0};//we can not destroyed the original data from the pieset,this is translate destination piece
				int destflag=0;//break is true flag = 1, then the dest is invalid
				for(x=0;x<=piesize[cur][0]-1;x++)
				{
					for(y=0;y<=piesize[cur][1]-1;y++)
					{
						if(pieset[cur][x][y]>0)//find the valid point
						{
							//translate
							t=x+i;
							r=y+j;
							if(t>=4||r>=4||t<0||r<0)//invalid translation
							{
								destflag=1;
								break;
							}
							dest[t][r]=pieset[cur][x][y];//translation
						}
					}
					if(destflag)
					{
						break;//invalid translation
					}
				}
				if(!destflag)//the translation is valid
				{
					if(IsFit(dest))//the piece[cur] is fit for now puzzle matrix
					{
						FitPie(dest);
						DFS(cur+1);
						if(flag)//prevent the answer puzzle matrix recover
						{
							return(0);
						}
						UnFitPie(dest);
					}
				}
			}
		}
	}
	return(0);
}
/*output the puzzle*/
int OutPuzzle()
{
	int i=0,j=0;
	for(i=0;i<=4-1;i++)
	{
		for(j=0;j<=4-1;j++)
		{
			printf("%d",puzzle[i][j] );
		}
		printf("\n");
	}
	return(0);
}
/*for test*/
int test()
{
	return(0);
}
/*main process*/
int MainProc()
{
	int t=0;
	while(scanf("%d",&n)!=EOF&&n>0)
	{
		//fromat control
		t++;
		if(t>1)
		{
			printf("\n");
		}
		//init
		memset(pieset,0,sizeof(pieset));
		memset(piesize,0,sizeof(piesize));
		memset(puzzle,0,sizeof(puzzle));
		memset(piecnt,0,sizeof(piecnt));
		flag=0;
		int i=0,j=0,k=0;
		int piececnt=0;
		for(k=0;k<=n-1;k++)
		{
			scanf("%d%d",&piesize[k][0],&piesize[k][1]);
			for(i=0;i<=piesize[k][0]-1;i++)
			{
				for(j=0;j<=piesize[k][1]-1;j++)
				{
					int num=0;
					scanf("%1d",&num);//scanf format control
					if(num>0)
					{
						piececnt++;
						piecnt[k]++;
						pieset[k][i][j]=k+1;//piece#i place i
					}
				}
			}
		}
		if(piececnt==16)//prune,the puzzle 0' count != left pieces !0's count then prune it
		DFS(0);
		if(flag)
		{
			OutPuzzle();
		}
		else
		{
			printf("No solution possible\n");
		}
	}
	return(0);
}
int main(int argc, char const *argv[])
{
	/* code */
	MainProc();
	return 0;
}