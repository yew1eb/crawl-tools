#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

ll a,b,c,d,p,m;

ll gcd(ll a, ll b){
	if (b == 0)	
		return a;
	return gcd(b,a%b);
}

ll f(ll a, ll b){
	if (a < 0 || b < 0)
		return 0;
	ll ma = a%p, mb = b%p;
	ll ans = (a/p)*(b/p)*p;
	ans += (ma+1)*(b/p) + (mb+1)*(a/p);
	if (ma > m){
		ans += min(m, mb) + 1;
		ll t = (p+m-ma) % p;
		if (t <= mb)
			ans +=  mb-t+1;
	}
	else {
		ll t = (p+m-ma)%p;
		if (t <= mb)
			ans += min(m-t+1, mb-t+1);
	}
	return ans;
}

int main(){
	int cas = 1,t;
	scanf("%d", &t);
	while (t--){
		scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &p, &m);
		ll ans = f(b, d)-f(b, c-1)-f(a-1, d)+f(a-1, c-1);
		ll tot = (b-a+1)*(d-c+1);
		ll g = gcd(ans, tot);
		printf("Case #%d: ", cas++);
		cout << ans/g << "/" << tot/g << endl;
	}
	return 0;
}