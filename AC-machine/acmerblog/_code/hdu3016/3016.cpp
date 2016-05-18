#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=100000;

struct node{
	int l,r,id;
	int lazy;
}a[4*maxn];

struct line{
	int l,r,lid,rid,h,c,id;
	bool friend operator < (line x,line y){
		return x.h<y.h;
	} 
}data[maxn+100];

int n,dp[maxn];

void input(){
	data[0].l=0,data[0].r=100000,data[0].h=0,data[0].c=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&data[i].h,&data[i].l,&data[i].r,&data[i].c);
	}
	sort(data,data+n+1);
	for(int i=0;i<=n;i++){
		dp[i]=-1;data[i].id=i;
		data[i].lid=-1;data[i].rid=-1;
	}
}

void build(int l,int r,int k){
	a[k].l=l;a[k].r=r;a[k].id=0;a[k].lazy=-1;
	if(l<r){
		int mid=(l+r)/2;
		build(l,mid,2*k);
		build(mid+1,r,2*k+1);
	}
}

void pushDown(int k){
	if(a[k].lazy<0) return;
	a[2*k].lazy=a[k].lazy;
	a[2*k].id=a[k].lazy;
	a[2*k+1].lazy=a[k].lazy;
	a[2*k+1].id=a[k].lazy;
	a[k].lazy=-1;
}

int query(int l,int r,int k){
	if(l<=a[k].l && a[k].r<=r){
		return a[k].id;
	}else{
		pushDown(k);
		int mid=(a[k].l+a[k].r)/2;
		if(r<=mid) return query(l,r,2*k);
		else return query(l,r,2*k+1);
	}
}

void insert(int l,int r,int k,int id){
	if(l<=a[k].l && a[k].r<=r){
		a[k].id=id;
		a[k].lazy=id;
	}else{
		pushDown(k);
		int mid=(a[k].l+a[k].r)/2;
		if(r<=mid) insert(l,r,2*k,id);
		else if(l>=mid+1) insert(l,r,2*k+1,id);
		else{
			insert(l,mid,2*k,id);
			insert(mid+1,r,2*k+1,id);
		}
	}
}

void computing(){
	build(0,maxn,1);
	for(int i=1;i<=n;i++){
		data[i].lid=query(data[i].l,data[i].l,1);
		data[i].rid=query(data[i].r,data[i].r,1);
		insert(data[i].l,data[i].r,1,data[i].id);
	}
	dp[n]=100+data[n].c;
	for(int i=n;i>=1;i--){
		//cout<<data[i].h<<" "<<data[i].lid<<" "<<data[i].rid<<endl;
		if(data[i].lid>=0){
			int id=data[i].lid;
			dp[id]=max(dp[id],dp[i]+data[id].c);
		}
		if(data[i].rid>=0){
			int id=data[i].rid;
			dp[id]=max(dp[id],dp[i]+data[id].c);
		}
	}
	if(dp[0]>0) cout<<dp[0]<<endl;
	else cout<<"-1"<<endl;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		input();
		computing();
	}
	return 0;
}