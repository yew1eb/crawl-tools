#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned __int64
#define ll __int64
//#define ull unsigned long long
//#define ll long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define middle (l+r)>>1
#define MOD 1000000007
#define esp (1e-8)
const int INF=0x3F3F3F3F;
const double DINF=10000.00;
//const double pi=acos(-1.0);
const int N=100010;
int n,m;
int X[N<<1],mmax[N<<4],dp[N];
struct rct{
	int x1,y1,x2,y2;
	void write(){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	}
	bool operator < (const rct& p) const {
		return y1 < p.y1;
	}
}a[N];
struct node{
	int pos,id;
	node(){}
	node(int _pos,int _id) : pos(_pos),id(_id){}
	bool operator < (const node& p) const {
		return a[id].y2 > a[p.id].y2;
	}
}nd;

void PushUp(int rt){
	mmax[rt]=max(mmax[rt<<1],mmax[rt<<1|1]);
}

void Update(int l,int r,int rt,int p,int c){
	if(l==r){mmax[rt]=max(mmax[rt],c);return;}
	int mid=middle;
	if(p<=mid) Update(lson,p,c);
	else Update(rson,p,c);
	PushUp(rt);
}

int Query(int l,int r,int rt,int L,int R){
	if(L<=l && r<=R) return mmax[rt];
	int mid=middle,ret=0;
	if(L<=mid) ret=max(ret,Query(lson,L,R));
	if(mid<R) ret=max(ret,Query(rson,L,R));
	return ret;
}

int bs(int key,int size,int A[]){
	int l=0,r=size-1,mid;
	while(l<=r){
		mid=middle;
		if(key>A[mid]) l=mid+1;
		else if(key<A[mid]) r=mid-1;
		else return mid;
	}return -1;
}

int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int i,j,k,ret;
	//int T,cas;scanf("%d",&T);for(cas=1;cas<=T;cas++)
	while(~scanf("%d",&n)){
		if(!n) break;
		for(i=m=0;i<n;i++){
			a[i].write(),dp[i]=1;
			X[m++]=a[i].x1;X[m++]=a[i].x2;
		}
		sort(X,X+m);
		for(i=k=1;i<m;i++) if(X[i]!=X[i-1]) X[k++]=X[i];
		sort(a,a+n);
		priority_queue<node>pq;
		memset(mmax,0,sizeof(mmax));
		for(i=ret=0;i<n;i++){
			while(!pq.empty()){
				nd=pq.top();
				if(a[nd.id].y2<a[i].y1){
					pq.pop();
					Update(0,k,1,nd.pos+1,dp[nd.id]);
				}else break;
			}
			dp[i]=Query(0,k,1,0,bs(a[i].x1,k,X))+1;
			pq.push(node(bs(a[i].x2,k,X),i));
			ret=max(ret,dp[i]);
		}
		printf("%d\n",ret);
	}
	return 0;
}