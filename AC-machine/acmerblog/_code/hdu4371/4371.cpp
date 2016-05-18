#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;

int main()
{
	int T,Case;
	int i;
	int n,m;
	int temp,min;
	cin>>T;
	for(Case=1;Case<=T;Case++)
	{
		cin>>n>>m;
		min=1<<30;
		for(i=0;i<m;i++)
		{
			scanf("%d",&temp);
			if(temp<min)	min=temp;
		}
		temp=n%(min<<1);
		printf("Case #%d: %s\n",Case,temp<min ? "Alice" : "Bob");
	}
	return 0;
}