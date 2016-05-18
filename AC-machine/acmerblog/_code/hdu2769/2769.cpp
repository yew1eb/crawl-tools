#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int x[11000];

int mod;

void exgcd(int &d,int &x,int &y,int a,int b)
{
		if(!b)
					d=a,x=1,y=0;
						else
							exgcd(d,y,x,b,a%b),y-=x*(a/b);
}
int jud(int a,int b,int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		if((((x[i]*a)%mod)*a+(a*b)%mod+b)%mod-x[i+1])
			return 0;
	}
	return 1;
}
int get(int a,int n)
{
	int aa=a+1,bb=(x[2]-(((a*a)%mod)*x[1])%mod+mod)%mod;
	int gcd,y,t;

	exgcd(gcd,t,y,aa,mod);






if(bb%gcd)
		return -1;





	t%=mod;
	t*=bb/gcd;t%=mod;
t=(t+mod)%mod;


	int i;
	for(i=0;i<gcd;i++)
	{
		if(jud(a,t,n))
			return t;
		t+=mod/gcd;
		t%=mod;
	}
	return -1;
}

int main()
{
	mod=10001;
	int n,i,j;


	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(i=0;i<=10000;i++)
	{
		j=get(i,n);
		if(j>=0)
		{
//if((x[1]*i+j)%mod-9727)
//continue;
			for(int ii=1;ii<=n;ii++)
				printf("%d\n",(x[ii]*i+j)%mod);
//printf("%d\n%d\n",i,j);
			return 0;
		}
	}
}