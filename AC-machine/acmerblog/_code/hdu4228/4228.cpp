#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define N 1000005
ll prime[N],primenum;//有primenum个素数 math.h
void PRIME(ll Max_Prime){
	primenum=0;
	prime[primenum++]=2;
	for(ll i=3;i<=Max_Prime;i+=2)
	for(ll j=0;j<primenum;j++)
		if(i%prime[j]==0)break;
		else if(prime[j]>sqrt((double)i) || j==primenum-1)
		{
			prime[primenum++]=i;
			break;
		}
}
ll n, ans, sum;
void dfs(ll a,ll s, ll t, ll l){
	if(s>n<<1)return ;
	if(s==2*n || s==2*n-1){
		ans = min(ans, a);
		return ;
	}
	if(t>20)return;
	for(ll i = 1; i <= l; i++) {
	a *= prime[t];
	dfs(a,s*(i+1), t+1,i);
	}
}
int main(){
	ll i,j,u,v;
	PRIME(100);
	while(cin>>n, n) {
	ans = 1e18;
	dfs(1,1,0,60);
	cout<<ans<<endl;
	}	
	return 0;
}