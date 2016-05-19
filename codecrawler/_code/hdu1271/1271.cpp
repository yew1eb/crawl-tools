#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int ans[100];

int main()
{
	int n, a, b, c; //a右，c左
	while(scanf("%d", &n) != EOF && n)
	{
		int count = 0;
		for(int k = 1; k <= n; k *= 10)
		{
			c = (n / k) / 11;
			b = (n / k) % 11;
			if( (b + c) != 0 && b < 10) //不进位
			{
				a = (n - b * k - 11 * c * k) / 2;
				if(n == 2 * a + b * k + 11 * c * k)
					ans[count++] = a + b * k + c * 10 * k;
			}
			b--;
			if( (b + c) != 0 && b >= 0) //仅为后
			{
				a = (n - b * k - 11 * c * k) / 2;
				if(n == 2 * a + b * k + 11 * c * k)
					ans[count++] = a + b * k + c * 10 * k;
			}
		}
		if(count == 0)
			printf("No solution.\n");
		else
		{
			sort(ans, ans + count);
			printf("%d", ans[0]);
			for(int i = 1; i < count; ++i)
				if(ans[i] != ans[i - 1]) //去重操作
					printf(" %d", ans[i]);
			printf("\n");
		}
	}
	return 0;
}