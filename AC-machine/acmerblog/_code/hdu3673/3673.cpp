#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string.h>
using namespace std;

#define MAXN 100100

map<int,int> mp;

int Max[MAXN<<2],in[MAXN],inT[MAXN],shop[MAXN];

int getmax(int x,int y){
	if (in[x]>in[y]) return x;
	if (in[x]<in[y]) return y;
	if (inT[x]<inT[y]) return x;
	else return y;
}

void update(int x,int l,int r,int rt){
	if (l==r){
		Max[rt]=x;
		return;
	}
	int m=(l+r)>>1;
	if (x<=m) update(x,l,m,rt<<1);
	else update(x,m+1,r,rt<<1|1);
	Max[rt]=getmax(Max[rt<<1],Max[rt<<1|1]);
}

int main(){
	int caseT=0,S,n,x;
	while (scanf("%d%d",&S,&n)!=EOF){
		if (S==0&&n==0) break;
		mp.clear();
		int cnt=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			if (mp.find(x)==mp.end()) mp[x]=++cnt;
			shop[i]=mp[x];
		}
		memset(Max,0,sizeof(Max));
		memset(in,0,sizeof(in));
		memset(inT,0,sizeof(inT));
		int now=0,ans=0;
		for (int i=1;i<=n;i++){
			if (in[shop[i]]){
				in[shop[i]]++;
//				cout<<1<<' '<<i<<' '<<shop[i]<<endl;
			}
			else if (now<S){
				in[shop[i]]++; inT[shop[i]]=i;
				now++;
	//			cout<<2<<' '<<i<<endl;
			}
			else {
				int t=Max[1];
				in[t]=0; inT[t]=0; in[shop[i]]++; inT[shop[i]]=i;
				update(t,1,n,1);
				ans++;
			}
			update(shop[i],1,n,1);
		//	cout<<Max[1]<<' '<<in[Max[1]]<<' '<<inT[Max[1]]<<endl;
		}
		printf("Case %d: %d\n",++caseT,ans);
	}
	return 0;
}