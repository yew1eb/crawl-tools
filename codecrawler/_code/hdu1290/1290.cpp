#include"stdio.h"
__int64 a[1001];//线分割平面
__int64 b[1001];//面分割空间
int main()
{
	int i;
	int n;
	a[1]=2;
	b[1]=2;
	for(i=2;i<=1000;i++)
		a[i]=a[i-1]+i;
	for(i=2;i<=1000;i++)
		b[i]=b[i-1]+a[i-1];
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",b[n]);
	return 0;
}