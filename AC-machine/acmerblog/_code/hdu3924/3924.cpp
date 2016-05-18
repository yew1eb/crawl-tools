#include<stdio.h>
#include<math.h>
typedef long long ll;
ll a[30],s[30];
void init(){
	int i,j,k;
	a[0]=a[1]=1;
	s[0]=0;
	for(i=2;i<=20;i++)
		for(j=0;j<i;j++)
			for(k=0;k<=i-1-j;k++)
				a[i]+=a[j]*a[k]*a[i-1-j-k];
	for(i=1;i<=20;i++)
		s[i]=s[i-1]+a[i];
}
void cal(ll n,ll &rank,ll &num){
	int i;
	for(i=1;i<=20;i++)
		if(s[i]>n)
			break;
	rank=n-s[i-1];
	num=i;
}
void solve(ll num,ll rank){
	ll i,j,k;
	ll ii,jj,kk;
	ll ss,tem;
	if(num==1){
		printf("X");
		return ;
	}
	for(i=0;i<num;i++){
		for(ss=0,j=0;j<num-i;j++)
			ss+=a[j]*a[num-i-j-1];
		if(ss*a[i]>rank){
			ii=rank/ss;
			rank%=ss;
			break;
		}
		else
			rank-=ss*a[i];
	}
	for(j=0;j<num-i;j++){
		if(a[j]*a[num-i-1-j]>rank){
			break;
		}
		else
			rank-=a[j]*a[num-1-i-j];
	}
	if(i!=0){
		printf("(");
		solve(i,ii);
		printf(")");
	}
	if(j!=0){
		printf("(");
		solve(j,rank/a[num-1-i-j]);
		printf(")");
	}
	if(num-i-j-1!=0){
		printf("(");
		solve(num-1-i-j,rank%a[num-1-i-j]);
		printf(")");
	}
	printf("X");
}
int main(){
	int t,T;
	ll n,rank,num;
	//freopen( "E.in", "r", stdin );
	//freopen( "a.txt", "w", stdout );
	init();
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%I64d",&n);        //%I64d被HDU坑死、、、、
		cal(n-1,rank,num);
		solve(num,rank);
		printf("\n");
	}
}