#include"stdio.h"
#include"math.h"
#include"string.h"
int queue[5555];


struct A
{
	int x,y;
	int r;
	int total;
	int mem[222];
}E[222];
int n;


int dis[222];
int dis_1[222];
int dis_2[222];
int dis_3[222];


int MIN(int a,int b)
{
	return a>b?b:a;
}


void SPFA(int s)
{
	int key,k;
	int i;
	int hash[222];
	int temp;
	
	for(i=1;i<=n;i++)	dis[i]=1111111;
	dis[s]=0;
	
	memset(hash,0,sizeof(hash));
	k=0;
	key=1;
	queue[0]=s;
	hash[s]=1;
	while(k<key)
	{
		for(i=0;i<E[queue[k]].total;i++)
		{
			temp=dis[queue[k]]+1;
			if(temp<dis[E[queue[k]].mem[i]])
			{
				dis[E[queue[k]].mem[i]]=temp;
				if(!hash[E[queue[k]].mem[i]])
				{
					hash[E[queue[k]].mem[i]]=1;
					queue[key++]=E[queue[k]].mem[i];
				}
			}
		}
		hash[queue[k]]=0;
		k++;
	}
}
int main()
{
	int T;
	int i,l;
	int t1,t2;
	int min;


	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);


		for(i=1;i<=n;i++)	scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].r);
		for(i=1;i<=n;i++)
		{
			E[i].total=0;
			for(l=1;l<=n;l++)
			{
				if(i==l)	continue;
				t1=abs(E[i].x-E[l].x)*abs(E[i].x-E[l].x)+abs(E[i].y-E[l].y)*abs(E[i].y-E[l].y);
				t2=(E[i].r+E[l].r)*(E[i].r+E[l].r);
				if(t2>=t1)	E[i].mem[E[i].total++]=l;
			}
		}


		SPFA(1);
		for(i=1;i<=n;i++)	dis_1[i]=dis[i];
		SPFA(2);
		for(i=1;i<=n;i++)	dis_2[i]=dis[i];
		SPFA(3);
		for(i=1;i<=n;i++)	dis_3[i]=dis[i];


		min=111111;
		for(i=1;i<=n;i++)	min=MIN(min,dis_1[i]+dis_2[i]+dis_3[i]);


		if(min==111111)	printf("-1\n");
		else			printf("%d\n",n-min-1);
	}
	return 0;
}