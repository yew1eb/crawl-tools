一.
经典完全背包
#include<iostream>
using namespace std;
int f[32768];
int volume[4]={0,1,2,3};
int main()
{
	f[0] = 1;
    for(int i = 1; i<=3; i++)
	{
		for(int j = volume[i]; j<32768; j++)
		{
			f[j] += f[j - volume[i]];
		}
	}
	int n;
	while(cin>>n)
		cout<<f[n]<<endl;
	return 0;
}

二.
找由几个3和几个2组成
这个方法这道题来说明显比背包优化了空间复杂度和时间复杂度
#include<iostream>
using namespace std;
int n;
int main()
{
	while(cin>>n)
	{
	int s = n/3 +1;    //由3组成的情况
    for(int i=0; i<=n/3; i++)
	     s+=(n - 3*i)/2;   //加上由2组成的
		cout<<s<<endl;
	}
	return 0;
}

三.网上还有用母函数的解决的，我没写过就不帖代码了