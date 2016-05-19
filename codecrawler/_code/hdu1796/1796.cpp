#include <stdio.h>
#include <string.h>


int ans,n,m;
int arr[200],cnt;
int select[200],Lcm;


int gcd(int n,int m) {

	int r = n % m;
	while (r) {

		n = m,m = r;
		r = n % m;
	}
	return m;
}
int lcm(int n,int m) {

	return n / gcd(n,m) * m;
}
int Solve(int n) {

	int i,j,k;


	for (ans = 0, i = 1; i < (1<<m); ++i) {

		cnt = 0;
		for (j = 0; j < m; ++j)
			if (i & (1<<j)) select[++cnt] = j;
		

		for (Lcm = j = 1; j <= cnt; ++j) 
			Lcm = lcm(Lcm,arr[select[j]]);


		if (cnt % 2 == 1)  ans += n / Lcm;
		else ans -= n / Lcm;
	}
	return ans;
}



int main()
{
	int i,j,k;


	while (scanf("%d%d",&n,&m) != EOF) {

		for (i = 0; i < m; ++i) {
		
			scanf("%d",&arr[i]);
			if (arr[i] == 0) i--,m--;
		}
		printf("%d\n",Solve(n-1));
	}
}