#include<iostream>
using namespace std;
int n;
int x[100];
int ans[11];
bool Place(int k)
{
	int i = 1;
	while (i<k)
	{
		if (x[i]==x[k] || abs(x[i]-x[k])==abs(i-k))	return false;
		i++;
	}
	return true;
}
int main()
{
	int k, cnt;
	memset(ans, 0, sizeof(ans));
	while (scanf("%d", &n)!=EOF && n!=0)
	{
		if (ans[n]>0) 
		{
			printf("%d\n", ans[n]);
			continue;
		}
		x[1] = 0;
		k = 1, cnt = 0;
		while (k>0)
		{
			x[k]++;
			while (x[k]<=n && !Place(k))
			{
				x[k]++;
			}
			if (x[k]<=n)
			{
				if (k==n)
				{
					cnt++;
				}
				else 
				{
					k++;
					x[k] = 0;
				}
			}
			else k--;
		}
		ans[n] = cnt;
		printf("%d\n", cnt);
	}
	return 0;
}