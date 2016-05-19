#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll __int64
#define ls rt<<1
#define rs ls|1
#define lson l,mid,ls
#define rson mid+1,r,rs
#define middle (l+r)>>1
#define clr_all(x,c) memset(x,c,sizeof(x))
#define clr(x,c,n) memset(x,c,sizeof(x[0])*(n+1))
#define eps (1e-8)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define PI (acos(-1.0))
#pragma comment(linker, "/STACK:102400000,102400000")
template <class T> T _max(T x,T y){return x>y? x:y;}
template <class T> T _min(T x,T y){return x<y? x:y;}
template <class T> T _abs(T x){return (x < 0)? -x:x;}
template <class T> T _mod(T x,T y){return (x > 0)? x%y:((x%y)+y)%y;}
template <class T> void _swap(T &x,T &y){T t=x;x=y;y=t;}
template <class T> void getmax(T& x,T y){x=(y > x)? y:x;}
template <class T> void getmin(T& x,T y){x=(x<0 || y<x)? y:x;}
int TS,cas=1;
const int M=100000+5;
int n,f[M],tot;

ll dfs(int pos,int sum){
	if(pos==tot) return 0;
	ll cnt=(n/sum-1),ret=(1+cnt)*cnt/2*sum;
	for(int i=pos+1;i<=tot;i++)
		ret=((ret-dfs(i,sum*f[i]))+MOD)%MOD;
	return ret;
}

void run(){
	int i,j;
	int nn=n;
	for(i=2,tot=0;i*i<=nn;i++) if(nn%i==0){
		while(nn%i==0) nn/=i;
		f[tot++]=i;
	}
	if(nn>1) f[tot++]=nn;
	ll ret=0;
	for(i=0;i<tot;i++)
		ret=(ret+dfs(i,f[i]))%MOD;
	printf("%I64d\n",ret);
}

void preSof(){
}

int main(){
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 preSof();
 //run();
 while((~scanf("%d",&n)),n) run();
 //for(scanf("%d",&TS);cas<=TS;cas++) run();
 return 0;
}