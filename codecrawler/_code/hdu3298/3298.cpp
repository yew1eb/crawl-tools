#include <cstdio>
#include <cstring>
typedef long long llong;
const int Max=100010,MaxE=100010;
struct Edge{
	int v;
	Edge *nxt;
};
int N,M,a[Max];
Edge *hd[Max],e[MaxE*2],*ne;
bool vst[Max];
llong S,ans;
llong abs(llong x){return x<0?-x:x;}
void insert(int u,int v){
	ne->v=v,ne->nxt=hd[u];
	hd[u]=ne++;
	ne->v=u,ne->nxt=hd[v];
	hd[v]=ne++;
}
llong dfs(int u){
	if(vst[u]) return 0;
	vst[u]=true;
	llong size=a[u];
	for(Edge *p=hd[u];p;p=p->nxt){
		size+=dfs(p->v);
	}
	if(abs(S-size*2)<ans) ans=abs(S-size*2);
	return size;
}
int main(){
	for(int cas=1;scanf("%d %d",&N,&M)==2;++cas){
		if(N==0 && M==0) break;
		S=0;
		for(int i=0;i<N;++i){
			scanf("%d",a+i);
			S+=a[i]; 
		}
		memset(hd,0,sizeof(hd[0])*N);
		ne=e;
		for(int i=0;i<M;++i){
			int u,v;
			scanf("%d %d",&u,&v);
			--u,--v;
			insert(u,v); 
		}
		ans=S;
		dfs(0);
		memset(vst,0,sizeof(vst[0])*N);
		printf("Case %d: %I64d\n",cas,ans); 
	}
	return 0;
}