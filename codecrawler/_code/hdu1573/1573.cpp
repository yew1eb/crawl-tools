#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define LL  long long
#define MOD 1000000007
#define eps 1e-6
#define N 100010
#define zero(a)  fabs(a)<eps
using namespace std;
LL extend_gcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	LL gcd=extend_gcd(b,a%b,x,y);
	LL tmp=x;
	x=y;
	y=tmp-a/b*x;
	return gcd;
}
int a[10],b[10];
int n,m;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
			scanf("%d",&a[i]);
		for(int j=0;j<m;j++)
			scanf("%d",&b[j]);
		LL a1,a2,b1,b2,x,y;
		bool flag=false;
		a1=a[0];b1=b[0];
		for(int i=1;i<m;i++){
			a2=a[i];b2=b[i];
			LL gcd=extend_gcd(a1,a2,x,y);
			if((b2-b1)%gcd){
				flag=true;
				break;
			}
			LL t=a2/gcd;
			x=(x*(b2-b1))/gcd;
			x=(x%t+t)%t;
			b1=a1*x+b1;
			a1=(a1*a2)/gcd;
			b1=(b1%a1+a1)%a1;
		}
		if(flag||n<b1)
			printf("0\n");
		else
			printf("%d\n",(n-b1)/a1+1-(b1==0?1:0));
	}
	return 0;
}