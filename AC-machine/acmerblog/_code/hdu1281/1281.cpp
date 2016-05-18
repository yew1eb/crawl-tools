#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int N,M,K;
int map[105][105];
int visit[105];
int link[105];
int a[11000],b[11000];

int getnum(int x)
{
	for(int i=1;i<=M;i++)
	{
		if(!visit[i]&&map[x][i])
		{
			visit[i]=1;
			if(!link[i]||getnum(link[i]))
			{
				link[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int maxmatch()
{
	int t=0;
	for(int i=1;i<=N;i++)
	{
		memset(visit,0,sizeof(visit));
		if(getnum(i))
			t++;
	}
	return t;
}


int main()
{
	int k=1;
	while(scanf("%d%d%d",&N,&M,&K)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(link,0,sizeof(link));
		for(int i=1;i<=K;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			map[a[i]][b[i]]=1;
		}
		int num=maxmatch();
		int t=0;
		int d;
		for(i=1;i<=K;i++)
		{
			memset(link,0,sizeof(link));
			map[a[i]][b[i]]=0;	
			d=maxmatch();
			map[a[i]][b[i]]=1;
			if(d!=num)
				t++;
		}
		printf("Board %d have %d important blanks for %d chessmen.\n",k++,t,num);
	}
	return 0;
}