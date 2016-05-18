#include"stdio.h"
#include"string.h"
#include"algorithm"
using namespace std;
#define N 1005
int main()
{
	int i;
	int n,m;
	int A[N];
	while(scanf("%d%d",&m,&n)!=-1)
	{
		if(m==-1&&n==-1)break;
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		sort(A,A+n);
		int ans=1;
		int p=A[0]+m;
		i=1;
		while(i<n)
		{
			while(i<n&&A[i]<=p)i++;
			if(i>=n)break;
			p=A[i-1]+m;
			while(i<n&&A[i]<=p)i++;
			if(i>=n)break;
			p=A[i]+m;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}