//dp，但是找规律也可以发现连续的是FIb数列. 
#include <iostream>
#include <cstring>
using namespace std;

long long tar[10100];

void create_fib()
{
	tar[0]=1;
	tar[1]=1;
	for(int i=2;i<=10086;i++)
	{
		tar[i]=tar[i-1]+tar[i-2];
		tar[i]%=10007;
	}
}

int main()
{
	int testcase;
	string str;
	create_fib();
	cin>>testcase;
	for(int t=1;t<=testcase;t++)
	{
		int answer=1,count=0;
		cin>>str;
		for(int i=0;i<str.length();)
		{
			if(str[i]=='h' && str[i+1]=='e')
			{
				count++;
				i+=2;
			}
			else
			{
				answer*=tar[count];
				answer%=10007;
				count=0;
				i++;
			}
		}
		answer*=tar[count]; //最后一段要乘上
		answer%=10007;
		
		cout<<"Case "<<t<<": "<<answer<<endl;
	}
	return 0;
}
