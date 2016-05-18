#include<iostream>
#include<set>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
	multiset<int> s;
	int m;
	scanf("%d",&m);
	for(int ca=1;ca<=m;++ca)
	{
		s.clear();
		int n,q,y,po;
		scanf("%d%d%d",&n,&q,&y);
		while(n--)
		{
			scanf("%d",&po);
			s.insert(po);
		}
		int v;
		multiset<int>::iterator msp;
		printf("Case %d:\n",ca);
		while(q--)
		{
			scanf("%d",&v);
			msp=s.lower_bound(v);
			if(msp!=s.end()&&*msp-v<=y)
			{
				printf("%d\n",*msp);
				s.erase(msp);
			}
			else
				printf("-1\n");
		}
	}

}