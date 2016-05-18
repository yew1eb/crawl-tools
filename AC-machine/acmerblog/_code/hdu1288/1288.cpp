#include <iostream>
using namespace std;
int main()
{
	int n,x1,x5,x10;
	int a,b,c;
	while(cin>>n>>x1>>x5>>x10&&(n+x1+x5+x10))
	{
		a=b=c=0;
		if(n%5>x1)  如果n%5大于x1，那么即使满足后面的，也有零头剩余
		{
			cout<<"Hat cannot buy tea."<<endl;
			continue;
		}
		a=n%5;        
		n-=a;
		x1-=a;
		if(n<=x1)
		{
			a=n+a;
			printf("%d YiJiao, %d WuJiao, and %d ShiJiao\n",a,b,c);
			continue;
		}
		x1/=5;
		n-=5*x1;
		a+=5*x1;
		if(n<=5*x5)
		{
			b+=n/5;
			printf("%d YiJiao, %d WuJiao, and %d ShiJiao\n",a,b,c);
			continue;
		}
		n-=5*x5;
		b=x5;
		if(n%10==0)
		{
			if(n<=10*x10){
				c+=n/10;
				printf("%d YiJiao, %d WuJiao, and %d ShiJiao\n",a,b,c);
				continue;
			}
			else
			{
				cout<<"Hat cannot buy tea."<<endl;
				continue;
			}
		}
		else
		{
			if(b>0)
				b--;
			else
			{
				if(a>=5)
					a-=5;
				else
				{
					cout<<"Hat cannot buy tea."<<endl;
					continue;
				}
			}
			n+=5;
			if(n<=10*x10)
			{
				c=n/10;
				printf("%d YiJiao, %d WuJiao, and %d ShiJiao\n",a,b,c);
				continue;
			}
			else
			{
				cout<<"Hat cannot buy tea."<<endl;
				continue;
			}
		}
	}
	return 0;
}