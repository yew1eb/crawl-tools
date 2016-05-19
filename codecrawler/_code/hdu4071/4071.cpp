//Time:468MS	
//Memory:23860K
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;
typedef long long LL;
LL a,b,ans[MAXN],c[MAXN],sum[MAXN],t;
int n;
int main()
{
	//freopen("/home/qitaishui/code/in.txt","r",stdin);
	while(cin>>n>>a>>b)
	{
		LL tmp = 0;
		int pos=1;
		for(int i = 1; i <= n; i++)
			scanf("%d",&c[i]);
		sum[0] = 0;
		t = a+b;
		for(int i = 1; i <= n; i++)
		{
			sum[i]=sum[i-1]+c[i];
			if(sum[i]<=t) pos = i;
			else break;
		}
		//cout<<pos<<endl;
		ans[pos] = c[pos];

		for(int i = pos-1; i>0; i--)
		{
			ans[i] 