#include<iostream>
#include<string>
#include<map>
#include<stdio.h>
using namespace std;

int main()
{
	int n,k,p;
	map<int,int> L;
//	map<int,int>::iterator it;
	while(scanf("%d",&n)&&n!=0)
	{
		if(n==1)
		{		
			scanf("%d%d",&k,&p);
			L[p]=k;	//按优先级自动排序
		}
		else if(n==2)
		{
			if(L.empty())
				cout<<"0"<<endl;
			else
			{
				cout<<L.rbegin()->second<<endl;
				L.erase(L.rbegin()->first);
			}
		}
		else
		{
			cout<<L.begin()->second<<endl;
			L.erase(L.begin());
		}
	}
	return 0;
}