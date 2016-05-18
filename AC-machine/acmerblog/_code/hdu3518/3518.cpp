#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define maxn 1000005
#define eps 1e-8
#define inf 1<<30
#define zero(a) fabs(a)<eps
using namespace std;
//以下为倍增算法求后缀数组
int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(const char *r,int *sa,int n,int m){
	int i,j,p,*x=wa,*y=wb,*t; 
	for(i=0;i<m;i++) Ws[i]=0; 
	for(i=0;i<n;i++) Ws[x[i]=r[i]]++; 
	for(i=1;i<m;i++) Ws[i]+=Ws[i-1]; 
	for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i; 
	for(j=1,p=1;p<n;j*=2,m=p){ 
		for(p=0,i=n-j;i<n;i++) y[p++]=i; 
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j; 
		for(i=0;i<n;i++) wv[i]=x[y[i]]; 
		for(i=0;i<m;i++) Ws[i]=0; 
		for(i=0;i<n;i++) Ws[wv[i]]++; 
		for(i=1;i<m;i++) Ws[i]+=Ws[i-1]; 
		for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i]; 
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++) 
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++; 
	} 
	return; 
}
int sa[maxn],Rank[maxn],height[maxn];
//求height数组
void calheight(const char *r,int *sa,int n){
	int i,j,k=0;
	for(i=1;i<=n;i++) Rank[sa[i]]=i;
	for(i=0;i<n;height[Rank[i++]]=k)
		for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);
	return;
}
int slove(int k,int n){
	int mmax=0,mmin=inf,ans=0;
	for(int i=1;i<=n;i++){
		if(height[i]<k){
			if(mmax-mmin>=k)
				ans++;
			mmax=0;mmin=inf;
		}
		else{
			mmax=max(max(sa[i-1],sa[i]),mmax);
			mmin=min(min(sa[i-1],sa[i]),mmin);
		}
	}
	if(mmax-mmin>=k) ans++;
	return ans;
}
char str[maxn];
int main(){
	while(scanf("%s",str)!=EOF&&strcmp(str,"#")){
		int n=strlen(str);
		da(str,sa,n+1,130);
		calheight(str,sa,n);
		int ans=0;
		for(int i=1;i<=n/2;i++)
			ans+=slove(i,n);
		printf("%d\n",ans);
	}
	return 0;
}