#include <cstdio>

__int64 fun(__int64 A,__int64 B,__int64 C)
{
	__int64 k = 1;
	 A%=C;
	while(B>=1)
	{
		if((B&1)!=0)
			k = (k*A)%C;
        B>>= 1;
		A = A*A%C;
	}
	return k;
}
int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	__int64 A,B,C;
	while(n--)
	{
		scanf("%I64d%I64d%I64d",&A,&B,&C);
		printf("%I64d\n",fun(A,B,C));
	}
	return 0;
}