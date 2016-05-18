//英语又没学好，题意是将n分成n/2份，判断n/2份都相等吗

#include<iostream>
using namespace std;
int a[1002];

int main()
{
	int n, i, sum=0;
	while(scanf("%d", &n) != EOF && n)
	{
		for( i=0; i < n; i++ )
			scanf("%d", a+i);
		int temp;
		if(n % 2)
		{
			printf("No\n");
			continue;
		}
		temp = a[0] + a[n-1];
		for( i=1; i < n/2; i++ )
		{
			if(a[i] +a[n-i-1] != temp)	break;
		}
		if(i == n/2)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}