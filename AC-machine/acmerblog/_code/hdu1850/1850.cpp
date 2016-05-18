#include<stdio.h>
int s[110];
int main ()
{
	int n, a;
	int i, j;
	while(scanf("%d", &n) && n != 0)
	{
		int temp = 0;
		for(i = 1; i <= n; i++)
		{
			scanf("%d", &a);
			temp ^= a;
			s[i] = a;
		}

		int ans = 0;
		if(temp != 0)
		{
		
			for(i = 1; i <= n; i++)
			{
					int k = 0;
					for(j = 1; j <= n; j++)
					{
						if(i != j)
					       k ^= s[j];
					}
					if(k <= s[i])
						ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}