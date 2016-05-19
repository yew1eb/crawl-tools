#include <string.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int euler(int n){
    int temp = n;
	int sq_n = sqrt(n+0.5);
	int ans = n;
	for(int i = 2;i<=sq_n;i++){
		if(n%i==0){
			ans = ans/i*(i-1);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans = ans/n*(n-1);
	return ans;
}

int main(void){
	//freopen("","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		if(m==1){
		    printf("%d\n",n);
		    continue;
		}
		int ans = 0;
		int sq_n = sqrt(n+0.5);
		for(int i = 2;i<=sq_n;i++){
			if(n%i==0){
			    if(i>=m) ans+=euler(n/i);
				if(n/i>=m) ans+=euler(i);
			}
		}
		if(n!=1&&sq_n*sq_n==n&&sq_n>=m) ans-=euler(sq_n);
		printf("%d\n",ans+1);
	}
}