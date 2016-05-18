#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int mod=1000000007;

__int64 sp(__int64 a,__int64 b)
{
	__int64 ans=1;
	while(b)
	{
		if(b%2)	ans=(ans*a)%mod;
		b/=2;
		a=(a*a)%mod;
	}
	return ans%mod;
}
__int64 solve(int x)
{
	__int64 ans;
	if(x==1)	return 1;
	if(x==2)	return 2;
	if(x==3)	return 5;
	ans=((2*sp(2,x-2))%mod+((x-2)*sp(2,x-3))%mod)%mod;
	return ans;
}
int main()
{
	int T;
	int n,k;
	int x;
	cin>>T;
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(k>n)	{printf("0\n");continue;}
		x=n;
		x-=(k-1);
		printf("%I64d\n",solve(x));
	}
	return 0;
}