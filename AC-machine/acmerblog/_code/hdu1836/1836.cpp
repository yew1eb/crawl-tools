/*
 * hdu-1863
 * mike-w
 * 2012-4-13
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 128
#define INF (2<<25)
#define min(x,y) ((x)>(y)?(y):(x))

int dst[MAX_SIZE];
int tag[MAX_SIZE];
int f[MAX_SIZE][MAX_SIZE];
int N,M;

int ex_min(void)
{
	int i,x;
	for(x=-1,i=1;i<=M;i++)
		if(!tag[i] && dst[i]<INF)
			break;
	for(x=i++;i<=M;i++)
		if(!tag[i] && dst[i]<dst[x])
			x=i;
	return x<=M?x:-1;
}

int random_start(void)
{
	int i,j;
	for(i=1;i<=M;i++)
		for(j=1;j<=M;j++)
			if(f[i][j]>0)
				return i;
	return -1;
}

int prim(void)
{
	int i,x,cost;
	int start=random_start();
	if(start==-1)
		return -1;
	for(i=1;i<=M;i++)
		dst[i]=f[start][i],tag[i]=0;
	cost=0;
	while((x=ex_min())!=-1)
	{
		tag[x]=1;
		cost+=dst[x];
		for(i=1;i<=M;i++)
			if(!tag[i] && f[x][i]<INF && dst[i]>f[x][i])
				dst[i]=f[x][i];
	}
	for(i=1;i<=M;i++)
		if(!tag[i])
			cost=-1;
	return cost;
}

int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif
	int i,j,cost,e1,e2,e3;
	while(scanf("%d",&N),N)
	{
		scanf("%d",&M);
		for(i=1;i<=M;i++)
			for(j=1;j<=M;j++)
				f[i][j]=(i==j?0:INF);
		for(i=1;i<=N;i++)
		{
			scanf("%d%d%d",&e1,&e2,&e3);
			f[e1][e2]=f[e2][e1]=min(f[e1][e2],e3);
		}
		if(N>0)
			cost=prim();
		else
			cost=0;
		if(cost==-1)
			puts("?");
		else
			printf("%d\n",cost);
	}
	return 0;
}