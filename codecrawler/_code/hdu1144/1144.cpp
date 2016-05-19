#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

const int N = 10005;

bool select[N]={false};
int k,m,r,c;
bool result;
int main()
{
	while(cin>>k && k!=0)
	{
		cin>>m;
		memset(select,false,sizeof(select));
		result = true;
		int snum;
		while(k--)
		{
			cin>>snum;
			if(!result)
			{
				continue;
			}
			if(select[snum])
			{
				result = false;
			}
			else
			{
				select[snum] = true;
			}
		}
		//test every category of courses
		while(m--)
		{
			cin>>c>>r;
			while(c--)
			{
				cin>>snum;
				if(!result)
				{
					continue;
				}
				if(select[snum])
				{
					--r;
				}
			}
			if(r>0)
			{
				result = false;
			}
		}
		cout<<(result?"yes":"no")<<endl;
	}
	return 0;
}