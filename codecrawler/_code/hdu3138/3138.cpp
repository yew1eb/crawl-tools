#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int X = 1005;

ll a[X],b[X];
ll ans;
int n;

int main(){
	freopen("ain.txt","r",stdin);
	int ncase;
	cin>>ncase;
	while(ncase--){
		cin >> n;
		ans = 0;
		ll x = 0,y = 0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			x += a[i]*a[i];
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&b[i]);
			y += b[i]*b[i];
			ans -= a[i]*b[i];
		}
		cout<<-ans*ans+x*y<<endl;
	}
	return 0;
}