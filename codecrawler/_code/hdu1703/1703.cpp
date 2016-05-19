#include<stdio.h>
int f[5];
int main()
{
	int i,j,n;
	f[1]=0;f[2]=1;f[3]=3;f[4]=4;
	for(i=5;i<100;i++)
		f[i]=f[i-1]+2;
	while(scanf("%d",&n),n)
	{
		if(n<5)
		printf("%d\n",f[n]*5);
		else printf("%d\n",f[4]*5+(n-4)*10);
	}
	return 0;
}