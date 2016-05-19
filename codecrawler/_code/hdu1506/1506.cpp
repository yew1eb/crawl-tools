#include <iostream>
using namespace std;

__int64 a[100005];
int r[100005];
int l[100005];

int main()
{
	int n,i,k;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		scanf("%d",&a[1]);
		l[0] = 0;
		l[1] = 1;
		for(i=2;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i] > a[i-1])
				l[i] = i;
			else
			{
				k = i;
				while(k--)
				{
					if(a[k] < a[i])
					{
						l[i] = k+1;
						break;
					}
					else
					{
						k = l[k];
					}
				}
			}
		}
		r[n] = n;
		for(i=n-1;i>=1;i--)
		{
			if(a[i] > a[i+1])
				r[i] = i;
			else
			{
				k = i;
				while((++k) != n+1)
				{
					if(a[k] < a[i])
					{
						r[i] = k-1;
						break;
					}
					else
					{
						k = r[k];
					}
				}
				if(k == n+1)
					r[i] = n;
			}
		}

		__int64 max = 0;
		for(i=1;i<=n;i++)
		{
			__int64 ave = (r[i] - l[i] + 1) * a[i];
			if(ave > max)
				max = ave;
		}
		printf("%I64d/n",max);
	}
	return 0;
}