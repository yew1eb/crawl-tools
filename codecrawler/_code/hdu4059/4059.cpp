/*
ID:cxlove
PROB:HDU 4059 
HINT:数论+容斥原理
DATA:2012.4.7
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define LL long long
#define MOD 1000000007
using namespace std;
LL res;  //30对MOD的逆元
int prime[10000],cnt=0,flag[10005]={0};
vector<int>fact;
LL PowMod(LL a,LL b){
	LL ret=1;
	while(b){
		if(b&1)
			ret=(ret*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ret;
}
LL Sum(LL n){ //求an=n^4,的前n项和
	LL ans=n;
	ans=(ans*(n+1))%MOD;
	ans=(ans*((2*n+1)%MOD))%MOD;
	ans=(ans*(((3*n*n)%MOD+(3*n)%MOD-1+MOD)%MOD))%MOD;
	ans=(ans*res)%MOD;
	return ans;
}
LL Pow(LL n){ //求n^4
	LL ans=n;
	ans=(((((ans*n)%MOD)*n)%MOD)*n)%MOD;
	return ans;
}
int t;
void Prime(){  //筛选素数，便于后面的分解
	for(int i=2;i<=10000;i++){
		if(flag[i]) continue;
		prime[cnt++]=i;
		for(int j=2;j*i<=10000;j++)
			flag[i*j]=1;
	}
}
void Init(){ 
	res=PowMod(30,MOD-2);   //求30对MOD的逆元
	Prime();
	scanf("%d",&t);
}
LL dfs(int idx,LL n){    //容斥原理
	LL ret=0,tmp;
	for(int i=idx;i<fact.size();i++){
		tmp=fact[i];
		ret=(ret+(Sum(n/tmp)*Pow(tmp))%MOD)%MOD;
		ret=((ret-dfs(i+1,n/tmp)*Pow(tmp))%MOD+MOD)%MOD;
	}
	return ret%MOD;
}
int main(){
	LL n;
	Init();
	while(t--){
		scanf("%I64d",&n);
		fact.clear();
		LL tmp=n;
		for(int i=0;i<cnt&&prime[i]<=tmp;i++)
			if(tmp%prime[i]==0){
				fact.push_back(prime[i]);
				while(tmp%prime[i]==0)
					tmp/=prime[i];
			}
		if(tmp!=1)
			fact.push_back(tmp);		
		LL sum=((Sum(n)-dfs(0,n))%MOD+MOD)%MOD;
		printf("%I64d\n",sum);
	}
	return 0;
}
