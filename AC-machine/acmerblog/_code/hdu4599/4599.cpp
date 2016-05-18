#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define mod 2011
typedef long long ll;

inline ll Pow(ll a,ll n)
{
	ll ans=1,t=a;
	while(n)
	{
		if(n%2) ans=ans*t%mod;
		n/=2;
		t=t*t%mod;
	}
	return ans;
}
ll n;
int main()
{
	while(~scanf("%I64d",&n))
	{
		ll m1,m2;
		ll ny=Pow(5,mod-2);
		m2=(Pow(6,n)-1+mod)%mod*ny%mod;

		ny=Pow(30,mod-2);
		m1=(Pow(6,n)+24)%mod*ny%mod;
		printf("%I64d %I64d\n",m1%mod,m2%mod);
	}
	//system("pause");
	return 0;
}
