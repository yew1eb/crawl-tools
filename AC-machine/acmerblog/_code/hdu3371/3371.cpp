#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
struct edge{
	int u,v,w;
	bool operator <(const edge& ee)const{return w<ee.w;} 
}e[25005];
int p[505],cas,n,m,k,hash[505];
int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
int main(){
	scanf("%d",&cas); 
	while(cas--){
		scanf("%d%d%d",&n,&m,&k);
		
		for(int i=1;i<=n;i++)p[i]=i;
		memset(hash,0,sizeof hash);
		
		for(int i=0;i<m;i++)
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		for(int i=0;i<k;i++){
			int t,st,en;
			scanf("%d%d",&t,&st);t--;
			while(t--){
				scanf("%d",&en);
				p[find(st)]=find(en);	
			}	
		}
		int tot=0,cnt=0;
		for(int i=1;i<=n;i++)
			if(!hash[find(i)])tot++,hash[find(i)]=1;
		tot--;//需要增加的边的条数 
			 
		sort(e,e+m);
		
		int res=0;
		for(int i=0;i<m;i++){
			int x=find(e[i].u),y=find(e[i].v);	
			if(x==y)continue;
			res+=e[i].w;
			p[x]=y;
			cnt++;
			if(cnt==tot)break;//已经连通了 
		}
		
		if(cnt<tot)printf("-1\n");
		else printf("%d\n",res);
	}
}