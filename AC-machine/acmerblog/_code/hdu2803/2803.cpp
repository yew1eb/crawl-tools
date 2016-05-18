#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a[101];
    __int64 n,i,sum;
    while(scanf("%I64d",&n)!=EOF&&n)
    {
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		sum=0;
		for(i=0;i<n-1;i++)
			sum+=a[i];
		printf("%I64d/n",sum+a[n-1]*(2010-n));
    }
	return 0;
}