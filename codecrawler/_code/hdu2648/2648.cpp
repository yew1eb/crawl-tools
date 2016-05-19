#include <iostream>
#include <map>
#include <string>
using namespace std;
#define N 10005

map<string,int> elem;
int node[N];

int main()
{
	int n,m,i,val,j,rank;
	string str;
	while(cin>>n)
	{
		int n1=n;
		for(i=1;i<=n1;i++)
		{
			cin>>str;
			if(str=="memory")
			{
				str[0]='0';
				elem[str]=0;
				i--;
				n1--;
			}
			else
				elem[str]=i;
		}
		memset(node,0,sizeof(node));
		scanf("%d",&m);
		while(m--)
		{
			for(i=1;i<=n;i++)
			{
				cin>>val>>str;
				if(str=="memory")
					str[0]='0';
				node[elem[str]]+=val;
			}
			int cnt=0;
			for(i=1;i<n;i++)
			{
				if(node[i]>node[0])
					cnt++;
			}
			printf("%d/n",cnt+1);
		}
	}
	return 0;
}