#include<cstdio>
#include<cstring>
#include<map>
#include<set>

using namespace std;

map<int,int> cnt;
set<int> sames;
bool no[100005];
int Ts,s,n;
int a[100005];

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d",&Ts);
	while(Ts--) {
		memset(no,0,sizeof(no));
		cnt.clear(),sames.clear();
		scanf("%d%d",&s,&n);
		for(int i=0;i<n;++i) scanf("%d",a+i);

		int idx=-1;
		for(int i=0;i<min(s,n);++i) {
			if(cnt[a[i]]>0) {idx=i; break;}
			cnt[a[i]]++;
		}
		if(idx==-1) {
			printf("%d\n",s); continue;
		}
		for(int i=idx;i<min(s,n);++i) {
			if(cnt[a[i]]>0) sames.insert(a[i]);
			cnt[a[i]]++;
		}
		for(int i=0;i<n;++i) {
			if(sames.size()) no[i]=1;
			if(i+s<n) {
				if(cnt[a[i+s]]>0) sames.insert(a[i+s]);
				cnt[a[i+s]]++;
			}
			if(cnt[a[i]]==2) sames.erase(a[i]);
			cnt[a[i]]--;
		}
		int ans=0;
		for(int i=0;i<idx;++i) {
			bool can=1;
			for(int j=i+1;j<n;j+=s) can &= !no[j];
			ans += can;
		} printf("%d\n",ans);
	}
}