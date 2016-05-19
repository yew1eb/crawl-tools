#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	int T;
	__int64 n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d",&n);
		__int64 m=(2*n+1+sqrt(4*n+1.0))/2;
		if(  (__int64(sqrt(m*1.0)))*(__int64(sqrt(m*1.0)))  ==m)
			m--;
		__int64 ans=0;
		__int64 temp=(__int64)sqrt(m*1.0);
		for(__int64 i=1;i<temp;i++)  //i也要用__int64,不然一直WA
		{
           ans+=i*((i+1)*(i+1)-i*i);
		}
		for(__int64 i=temp*temp;i<=m;i++)
			ans+=temp;
		printf("%I64d %I64d\n",m,ans);
	}
	//system("pause");
	return 0;
}