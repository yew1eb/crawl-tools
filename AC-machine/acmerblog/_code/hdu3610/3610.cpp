#include<stdio.h>
#define N 25 
#define md 1000000007
struct Matrix
{
	__int64 m[N][N];
}init;
int n,x,y,z;
Matrix Mult(Matrix m1,Matrix m2)
{
	Matrix ans;
	for(int i=1;i<=z;i++)
		for(int j=1;j<=z;j++)
		{
			ans.m[i][j]=0;
			for(int k=1;k<=z;k++)
				ans.m[i][j]=(ans.m[i][j]+m1.m[i][k]*m2.m[k][j])%md;
		}
	return ans;
}
Matrix Pow(Matrix m1,int b)
{
	Matrix ans;
	for(int i=1;i<=z;i++)
		for(int j=1;j<=z;j++)
			ans.m[i][j]=(i==j);
	while(b)
	{
		if(b&1)
		ans=Mult(ans,m1);
		m1=Mult(m1,m1);
		b>>=1;
	}
	return ans;
}
int main()
{
	int i,j;
	__int64 ans;
	while(scanf("%d%d%d%d",&x,&y,&z,&n)!=-1)
	{
		for(i=1;i<=z;i++)
		{
			for(j=1;j<=z;j++)
			init.m[i][j]=0;
		}
		for(i=x;i<=y;i++)
		{
			init.m[1][i]=1;
		}
		for(i=1;i<z;i++)
		{
			init.m[i+1][i]=1;
		}
		init=Pow(init,n-1);
		ans=0;
		for(i=1;i<z;i++)
			ans=(ans+init.m[i][1])%md;
		printf("%I64d\n",ans);
	}
	return 0;
}