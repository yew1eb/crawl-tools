/*
Running Rabbits
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
using namespace std;
typedef struct Rabbit
{
	char Direc[2+5];
	int Speed;
	int hour;
	int row;
	int col;
	Rabbit()
	{
		memset(Direc,'\0',sizeof(Direc));
		Speed=0;
		hour=0;
		row=0;
		col=0;
	}
}Rabbit,*RabbitLink;
Rabbit Tom,Jerry;
int N=0;//N*N Maze
int K=0;//time process
/*move the cell by its speed and direction*/
int MoveAhead(Rabbit &Cell)
{
	switch(Cell.Direc[0])
	{
		case 'N':
		Cell.row-=Cell.Speed;
		break;
		case 'E':
		Cell.col+=Cell.Speed;
		break;
		case 'S':
		Cell.row+=Cell.Speed;
		break;
		case 'W':
		Cell.col-=Cell.Speed;
		break;
	}
	return(0);
}
/*judge the row and col whether overflow*/
bool IsWall(Rabbit &Cell)
{
	if(Cell.row<1||Cell.row>N||Cell.col<1||Cell.col>N)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}
/*turnaround the cell to the contrary direction*/
int TurnAround(Rabbit &Cell)
{
	if(Cell.row<1)//North overflow
	{
		Cell.Direc[0]='S';
		Cell.row=fabs(Cell.row-1)+1;
	}
	else if(Cell.row>N)//South overflow
	{
		Cell.Direc[0]='N';
		Cell.row=N-fabs(Cell.row-N);
	}
	if(Cell.col<1)//West overflow
	{
		Cell.Direc[0]='E';
		Cell.col=fabs(Cell.col-1)+1;
	}
	else if(Cell.col>N)//East overflow
	{
		Cell.Direc[0]='W';
		Cell.col=N-fabs(Cell.col-N);
	}
	return(0);
}
/*judge the two cell whether have collition*/
bool IsCollision(Rabbit &Cell1,Rabbit &Cell2)
{
	if(Cell1.row==Cell2.row&&Cell1.col==Cell2.col)
	{
		return(true);
	}	
	else
	{
		return(false);
	}
}
/*change the direction each other*/
int Collision(Rabbit &Cell1,Rabbit &Cell2)
{
	char temp=Cell1.Direc[0];
	Cell1.Direc[0]=Cell2.Direc[0];
	Cell2.Direc[0]=temp;
	return(0);
}
/*cell trun the left*/
int TurnLeft(Rabbit &Cell)
{
	switch(Cell.Direc[0])
	{
		case 'N':
		Cell.Direc[0]='W';
		break;
		case 'E':
		Cell.Direc[0]='N';
		break;
		case 'S':
		Cell.Direc[0]='E';
		break;
		case 'W':
		Cell.Direc[0]='S';
		break;
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
	while(scanf("%d",&N)!=EOF&&N)//from 1 to N
	{
		scanf("%s%d%d",Tom.Direc,&Tom.Speed,&Tom.hour);
		scanf("%s%d%d",Jerry.Direc,&Jerry.Speed,&Jerry.hour);
		scanf("%d",&K);
		Tom.row=1;
		Tom.col=1;
		Jerry.row=N;
		Jerry.col=N;
		int i=0;
		for(i=1;i<=K;i++)
		{
			MoveAhead(Tom);
			MoveAhead(Jerry);
			//collision with wall
			if(IsWall(Tom))
			{
				TurnAround(Tom);
			}
			if(IsWall(Jerry))
			{
				TurnAround(Jerry);
			}
			//collision each other
			if(IsCollision(Tom,Jerry))
			{
				Collision(Tom,Jerry);
			}
			else
			{
				//turn left
				if(i%Tom.hour==0)
				TurnLeft(Tom);
				if(i%Jerry.hour==0)
				TurnLeft(Jerry);
			}
		}
		printf("%d %d\n%d %d\n",Tom.row,Tom.col,Jerry.row,Jerry.col);
	}
	return(0);
}
int main()
{
	MainProc();
	return(0);
}
