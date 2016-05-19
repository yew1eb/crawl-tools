#include <iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int n,m,st,ed,front,rear;
double mat[1005][1005],dis[1005];
int v[1005],q[1000001];
void Spfa()
{
	int p;
	while(front<rear)//模拟栈，直到栈为空
	{
		p=q[front++];
		v[p]=0;
		for(int i=0;i<n;i++)
		{
			if(mat[p][i]==0||p==i)
				continue;
			if(dis[p]*mat[p][i]>dis[i])
			{
				dis[i]=dis[p]*mat[p][i];
				if(!v[i])
				{
					q[rear++]=i;
					v[i]=1;
				}
			}
		}
	}
}
int main()
{
	
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%lf",&mat[i][j]);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&st,&ed);
			memset(v,0,sizeof(v));
			memset(dis,0,sizeof(dis));
			v[st-1]=dis[st-1]=1;
			front=0;
			rear=1;
			q[front]=st-1;
			Spfa();
			if(dis[ed-1]!=0)
				printf("%.3lf\n",dis[ed-1]);
			else
				puts("What a pity!");
		}
	}
}