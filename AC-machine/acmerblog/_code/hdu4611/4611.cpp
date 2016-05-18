#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long gcd(long long a,long long b){
	return b ? gcd(b,a % b) : a;
}
long long lcm(long long a,long long b){
	return a / gcd(a,b) * b;
}
long long get(long long n,long long a,long long b){
	long long ans = 0,tem = 0,x = 0,y = 0,now = 0;
	while(now < n){
		tem = min(a - x,b - y);
		if(tem + now > n)tem = n - now;
		ans += tem * abs(x - y);
		x = (x + tem) % a;
		y = (y + tem) % b;
		now += tem;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t --){
		long long n,a,b;
		//scanf("%I64d%I64d%I64d",&n,&a,&b);
		cin>>n>>a>>b;
		long long ans = 0;
		long long l = lcm(a,b);
		if(n > l)ans = get(l,a,b) * (n / l) + get(n % l,a,b);
		else ans = get(n,a,b);
		//long long ans = get(lcm(a,b),a,b) * n / lcm(a,b) + get(n % lcm(a,b),a,b);
		//printf("%I64d\n",ans);
		cout<<ans<<endl;
	}
	return 0;
}