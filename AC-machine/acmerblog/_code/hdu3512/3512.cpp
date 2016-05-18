#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn= 100005;
long long a[maxn],b[maxn];
const long long INF = 1LL<<62;
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i = 0;i < n;i ++){
			scanf("%I64d",&a[i]);
		}
		for(int i = 0;i < n;i ++){
			scanf("%I64d",&b[i]);
		}
		sort(a,a + n);
		sort(b,b + n);
		int i1 = lower_bound(a,a + n,0) - a;
		int i2 = lower_bound(b,b + n,0) - b;
		long long ans = -INF;
		int d1 = min(n - i1,i2);
		int i = n - 1,j = d1 - 1;
		for(int cnt = 0;cnt < d1;cnt ++){
			 ans = max(ans,a[i --] * b[j --]);
		}
		int d2 = min(i1,n - i2);
		i = d2 - 1,j = n - 1;
		for(int cnt = 0;cnt < d2;cnt ++){
			ans = max(ans,a[i --] * b[j --]);
		}
		i = n - 1 - d1,j = d1;
		for(int cnt = 0;cnt < n - d1 - d2;cnt ++){
			ans = max(ans,a[i --] * b[j ++]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}