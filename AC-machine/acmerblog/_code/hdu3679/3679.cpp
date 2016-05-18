#include<stdio.h>
#include<string.h>

int n;

int a[4][2000];
int b[4][2000];

int main()
{
	int T = 0;
	while(1){
		++T;
		scanf("%d",&n);
		if(n == 0)
			break;
		for(int i = 1;i <= 3;++i)
			for(int j = 1;j <= n;++j)
				scanf("%d",&a[i][j]);
		for(int i = 1;i <= 2;++i)
			for(int j = 1;j <= n;++j)
				b[i][a[i][j]] = j;
		int sum = 0;
		for(int j = 1;j <= n;++j){
			if(a[3][j] >= b[1][j])
				sum += 3;
			else if(b[1][j] <= b[2][j])
				sum += 2;
			else
				sum += 1;
		}
		printf("Case %d: %d\n",T,sum);
	}
	return 0;
}