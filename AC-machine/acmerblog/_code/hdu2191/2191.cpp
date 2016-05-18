/*
 * HDU-2191 纪念512
 * mike-w
 * 2011-10-15
 * ---------------------
 * 简单的多重背包
 * 为死者默哀...
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 111

long p[SIZE],w[SIZE],c[SIZE];
long opt[SIZE];
long N,M,C;

int read(void)
{
	long i;
	scanf("%ld%ld",&N,&M);
	for(i=0;i<M;i++)
		scanf("%ld%ld%ld",p+i,w+i,c+i);
	return 0;
}

long calc(void)
{
	long i,j,k,t,u;
	memset(opt,0,sizeof(opt));
	for(i=0;i<M;i++)
	{
		for(j=1,t=p[i],u=w[i];j<=c[i];c[i]-=j,t<<=1,j<<=1,u<<=1)
			for(k=N;k>=t;k--)
				if(opt[k]<opt[k-t]+u)
					opt[k]=opt[k-t]+u;
		if(c[i]>0)
			for(k=N,t=c[i]*p[i],u=w[i]*c[i]; k>=t;k--)
				if(opt[k]<opt[k-t]+u)
					opt[k]=opt[k-t]+u;
	}
	return opt[N];
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("2919.in","r",stdin);
#endif
	scanf("%ld",&C);
	while(C-->0)
	{
		read();
		printf("%ld\n",calc());
	}
	return 0;
}