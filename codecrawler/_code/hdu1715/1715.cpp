//大数运算！！
#include"stdio.h"
#include"string.h"
int a[1001][1001];
int main()
{
	int i,j,k;
	int n,t;
	int carry;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		a[1][1]=1;a[2][1]=1;
		for(i=3,k=1;i<=n;i++)
		{
			for(j=1,carry=0;j<=k;j++)
			{
				a[i][j]=a[i-1][j]+a[i-2][j]+carry;;
				carry=a[i][j]/10;
				a[i][j]%=10;
			}
			while(carry)//这里容易忽略！！
			{
				a[i][++k]=carry;
				carry/=10;
			}
		}
		for(i=k;i>0;i--)
			printf("%d",a[n][i]);
		printf("\n");
	}
	return 0;
}