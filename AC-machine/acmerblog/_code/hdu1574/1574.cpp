#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 99999999
#define NN 20010
int RP[NN];
int l,r,max, rp;
int main()
{
	int T,n,a,b,c,i,x;
	scanf("%d",&T);
	while(T--){
	
		scanf("%d",&n);	
		for(i=0;i<NN;i++)RP[i] = -INF;
		l=r= 10000;
		max = 0;
		RP[l]=0;
		while(n--){
			scanf("%d%d%d",&a,&b,&c);
			b 