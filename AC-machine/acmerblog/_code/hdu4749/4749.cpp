#include<cstdio>
#include<cstring>
using namespace std;

int n,m,k;
int cp[100005][2];
int app[30];
int s1[100005],s2[100005];
int nxt[100005];

void init1(){
	for(int i=0;i<=k;i++) app[i]=-1;
	for(int i=0;i<m;i++){
		cp[i][0]=-1;
		for(int j=s2[i];j>0;j--)
			if(app[j]>=0){
				cp[i][0]=app[j];
				break;
			}
		cp[i][1]=-1;
		for(int j=s2[i];j<=k;j++)
			if(app[j]>=0){
				cp[i][1]=app[j];
				break;
			}
		app[s2[i]]=i;
	}
}

bool fit(int *s,int p){
	int v=*s;
	s-=p;
	if(cp[p][0]<0 && cp[p][1]<0) return 1;
	if(cp[p][0]<0) return v<s[cp[p][1]];
	if(cp[p][1]<0) return v>s[cp[p][0]];
	if(cp[p][0]==cp[p][1])
		return s[p]==s[cp[p][0]];
	return s[p]<s[cp[p][1]] && s[p]>s[cp[p][0]];
}

void init2(){
	nxt[0]=-1;
	int i=0,j=-1;
	while(i<m){
		if(j==-1 || fit(&s2[i],j)) nxt[++i]=++j;
		else j=nxt[j];
	}
}

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		for(int i=0;i<n;i++) scanf("%d",&s1[i]);
		for(int i=0;i<m;i++) scanf("%d",&s2[i]);
		init1();
		init2();
		int i=0,j=0;
		int ans=0;
		while(i<n){
			j=0;
			while(i<n && j<m){
				if(j==-1 || fit(&s1[i],j)) ++i,++j;
				else j=nxt[j];
			}
			if(j==m) ++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
