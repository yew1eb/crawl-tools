#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

const int N=1100000;
int ans[N],num[10];

void func(int k,int c){
	while(k){
		num[k%10]+=c;
		k/=10;
	}
}

int check(int a,int b,int n){
	memset(num,0,sizeof num);
	func(a,1),func(b,1),func(n,-1);
	for(int i=0;i<10;i++)
		if(num[i]!=0) return 0;
	return 1;
}

int isvp(int n){
	int l=sqrt(1.0*n);
	for(int i=2;i<=l;i++){
		if(n%i!=0) continue;
		if(check(i,n/i,n))	 return 1;
	}
	return 0;
}

int find(int n){
	if(ans[n]!=0)//已经存在
		return ans[n];
	if(isvp(n))//是vp数
		return ans[n]=n;
	return ans[n]=find(n+1);//下一个vp数
}

int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		if(ans[n]==0)
			find(n);
		printf("%d\n",ans[n]);
	}
	return 0;
}