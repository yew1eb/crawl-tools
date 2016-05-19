#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

const long long mod=100000000ll;
int p[10005];
bool flag[10005];
int pcnt;
void pre()
{
	pcnt=0;
	memset(flag,false,sizeof(flag));
	int i=2;
	while (i<=10000)
	{
		if (flag[i])
		{
			i++;continue;
		}
		int j=i+i;
		p[pcnt++]=i;
		while (j<=10000)
		{
			flag[j]=true;
			j+=i;
		}
		i++;
	}
}
long long phi(long long x)
{
	long long res=x;
	int t=x;
	for (int i=0;p[i]*p[i]<=x && i<pcnt;i++)
	{
		if (x%p[i]==0)
		{
			res/=p[i];
			res*=p[i]-1;
			while (x%p[i]==0) x/=p[i];
			if (x==1) break;
		}
	}
	if (x!=1)
	{
		res/=x;
		res*=x-1;
	}
	return res;
}
long long power(long long a,long long b,long long mod)
{
	a%=mod;
	long long res=1;
	while (b)
	{
		if (b&1) res=(res*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return res;
}
bool larger(long long a,int b,long long p)
{
	long long now=1;
	for (int i=1;i<=b;i++)
	{
		for (int j=1;j<=a;j++)
		{
			now=now*a;
			if (now>=p) return true;
		}
		a=now;
	}
	return false;
}
long long solve(long long a,int k,long long mod)
{
	if (k==1) return a%mod;
	long long t=phi(mod);
	long long last=solve(a,k-1,t);
	if (larger(a,k-1,t)) return power(a,last%t+t,mod);
	else return power(a,last,mod);
}
int main()
{
	pre();
	long long a;
	int k;
	while (scanf("%I64d%d",&a,&k)>0)
	{
		printf("%I64d\n",solve(a,k,mod)%mod);
	}
}