#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr))
const int MAX = 250100;
bool dp[MAX];
int V;

void zeroOnePack(int cost ,int value)
{
	for(int i = V; i >= cost ;i--)
		if(dp[i - cost] == true)
			dp[i] = true;
}
void completePack(int cost,int value)
{
	for(int i = cost ;i <= V ;i++)
		if(dp[i - cost] == true)
			dp[i] = true;
}
void multipPack(int cost ,int value ,int amount)
{
	if(cost * amount >= V)
		completePack(cost,value);
	else
	{
		int k = 1;
		while(k < amount )
		{
			zeroOnePack(cost * k ,value * k);
			amount -= k;
			k *= 2;
		}
		zeroOnePack(cost * amount ,value * amount );
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	int group_num;
	while(cin>>group_num,group_num > 0)
	{
		CLR(dp,false);
		dp[0] = true;
		int v[510],num[510];
		V = 0;
		for(int i = 1;i <= group_num ;i++)
		{
			scanf("%d%d",&v[i],&num[i]);
			V += (v[i] * num[i]);
		}
		int tmp = V;
		V /= 2; 
		for(int i = 1;i <= group_num ;i++)
		{
			multipPack(v[i],1,num[i]);
		}
		int cur=0;
		for(int i = V;i >= 1 ;i--)
			if(dp[i] == true)
			{
				cur = i;
				break;
			}
		printf("%d %d\n",tmp-cur,cur);
	}
	return 0;
}