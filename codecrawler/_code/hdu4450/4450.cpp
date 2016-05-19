/*
Draw Something
*/
#include<stdio.h>
#include<stdlib.h>
__int64 Sum=0;
__int64 Num=0;
int N=0;
int main()
{
	while(scanf("%d",&N)!=EOF&&N>0)
	{
		Sum=0;
		while(N--)
		{
			scanf("%I64d",&Num);
			Sum+=Num*Num;
		}
		printf("%I64d\n",Sum);
	}
	return(0);
}

