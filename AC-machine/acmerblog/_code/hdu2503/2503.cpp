#include<iostream>
using namespace std;
int gcd(int a,int b)
{return (b==0? a:gcd(b,a%b));}
int main()
{

	int t,a,b,c,d,e;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			e=gcd((a*d+c*b),b*d);
			printf("%d %d\n",(a*d+c*b)/e,b*d/e);
		}
	}
	return 0;
}