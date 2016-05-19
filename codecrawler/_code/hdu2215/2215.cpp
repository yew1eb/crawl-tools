// hdu 2215.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "math.h"
#include <iostream>
using namespace std;
#define ABS_N(x) ((x)<0?-(x):(x))
int N,stack_top;
struct Node
{
	int x,y;
}m_stack[1005],position[1005];
inline int CrossMutiply(Node p1,Node p2,Node p3)
{
	return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
inline int Distance(Node p1,Node p2)
{
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int CMP(const void* a,const void* b)
{
	Node *p1=(Node*)a,*p2=(Node*)b;
	int m=CrossMutiply(position[0],*p1,*p2);
	if(m==0) return Distance(position[0],*p1)-Distance(position[0],*p2);
	else return -m;
}
void Convex()
{
	int swap=0;
	for(int i=1;i<N;i++)
	{
		if((position[i].y<position[swap].y)||(position[i].y==position[swap].y&&position[i].x<position[swap].x))
			swap=i;
	}
	Node temp=position[swap];
	position[swap]=position[0];
	position[0]=temp;
	qsort(position+1,N-1,sizeof(position[0]),CMP);
	m_stack[0]=position[0];
	m_stack[1]=position[1];
	stack_top=1;
	for(int i=2;i<N;i++)
	{
		while(stack_top>=1&&CrossMutiply(m_stack[stack_top-1],m_stack[stack_top],position[i])<=0)
			stack_top--;
		m_stack[++stack_top]=position[i];
	}
}
inline double Diameter(Node p1,Node p2,Node p3)
{
	double temp=sqrt((double)Distance(p2,p3));
	double temp2=CrossMutiply(p1,p2,p3);
	temp2=temp2/(sqrt((double)(Distance(p1,p2)*Distance(p1,p3))));
	temp=temp/temp2;
	return ABS_N(temp);
}
int main()
{
	freopen("d://1.txt","r",stdin);
	double ans,temp;
	while(scanf("%d",&N)&&N)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%d%d",&position[i].x,&position[i].y);
		}
		if(N==1)
		{
			printf("%.2f/n",0.5);
			continue;
		}
		else if(N==2)
		{
			printf("%.2f/n",sqrt((double)Distance(position[0],position[1]))/2+0.5);
			continue;
		}
		Convex();
		if(stack_top==1)
		{
			printf("%.2f/n",sqrt((double)Distance(m_stack[0],m_stack[1]))/2+0.5);
			continue;
		}
		ans=0;
		for(int i=0;i<stack_top-1;i++)
		{
			for(int j=i+1;j<stack_top;j++)
			{
				for(int k=j+1;k<=stack_top;k++)
				{
					temp=Diameter(m_stack[i],m_stack[j],m_stack[k]);
					if(temp>ans) ans=temp;
				}
			}
		}
		printf("%.2f/n",ans/2+0.5);
	}
	return 0;
}