#include <iostream>
#include <cstring>
using namespace std;

const int INF=0x7FFFFFF;
int dp[100005];
int value[1000],weight[1000];

int min(int a,int b)
{
	if(a<=b)
		return a;
	else
		return b;
}

int main()
{
	int testcase;
	int needweight,totalmoney,pignum;
	cin>>testcase;
	while(testcase--)
	{
		memset(value,0,sizeof(value));
		memset(weight,0,sizeof(weight));
		for(int i=1;i<100005;i++)
		{
			dp[i]=INF;
		}
		dp[0]=0;


		cin>>needweight>>totalmoney;
		cin>>pignum;
		for(int i=0;i<pignum;i++)
		{
			cin>>weight[i]>>value[i];
		}
		
		totalmoney-=needweight;//减去初始的重量 
		
		for(int i=0;i<pignum;i++)
		{
			for(int j=value[i];j<=totalmoney;j++)
			{
				dp[j]=min(dp[j],dp[j-value[i]]+weight[i]);
			}
		}
			if(dp[totalmoney]!=INF)
			{
				cout<<"The minimum amount of money in the piggy-bank is "<<dp[totalmoney]<<"."<<endl;
			}
			else
				cout<<"This is impossible."<<endl;
		
		
	}
		
	return 0;
}