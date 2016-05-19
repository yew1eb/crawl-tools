#include <stdio.h>
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int n,q1,q2,t1,t2,g,q,x;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d/%d %d/%d",&q1,&t1,&q2,&t2);
		g=gcd(q1,q2);
		q=q1/g*q2;
		t1*=q2/g;
		t2*=q1/g;
		g=gcd(t1,t2);
		x=gcd(q,g);
		q/=x;
		g/=x;
		if(g-1)printf("%d/%d\n",q,g);
		else printf("%d\n",q);
	}
    return 0;
}