//可持久化trie树，题目已知一棵树，每个点有点权，询问一对点路径上点权与给定值异或的最大值
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100100
using namespace std;

struct Edge{
	int v,next;
}edge[N*2];

int head[N],val[N],cnt,n,m;

void addedge(int u,int v){
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
	edge[cnt].v=u;
	edge[cnt].next=head[v];
	head[v]=cnt++;
}

struct Trie{
	int go[2],cnt;
}trie[N*17];
int root[N],tot;

int insert(int id,int num){
	int p=++tot,tem=p;
	trie[p]=trie[id];
	for(int i=15;i>=0;i--){
		int tmp=(num>>i)&1;
		trie[++tot]=trie[trie[p].go[tmp]];
		trie[tot].cnt++;
		trie[p].go[tmp]=tot;
		p=tot;
	}
	return tem;
}

void dfs(int u,int father){
	root[u]=insert(root[father],val[u]);
	for(int i=head[u];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(v==father)continue;
		dfs(v,u);
	}
}

struct Query{
	int v,id,w,next;
}query[N*2];

int head2[N],cnt2,f[N],lca[N],ans[N];
bool flag[N];

void addedge2(int u,int v,int w,int id){
	query[cnt2].v=v;
	query[cnt2].w=w;
	query[cnt2].id=id;
	query[cnt2].next=head2[u];
	head2[u]=cnt2++;
	query[cnt2].v=u;
	query[cnt2].w=w;
	query[cnt2].id=id;
	query[cnt2].next=head2[v];
	head2[v]=cnt2++;
}

int find(int u){
	if(u==f[u]) return u;
	return f[u]=find(f[u]);
}

void tarjan(int u,int father){
	for(int i=head[u];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(v==father) continue;
		tarjan(v,u);
		f[v]=u;
	}
	flag[u]=1;
	for(int i=head2[u];i!=-1;i=query[i].next){
		int v=query[i].v;
		if(flag[v]){
			lca[query[i].id]=find(v);
		}
	}
}

int findans(int u,int v,int LCA,int num){
	int p1=root[u],p2=root[v],p3=root[LCA],ans_tmp=0;
	for(int i=15;i>=0;i--){
		int tmp=(num>>i)&1;
		int sum=trie[trie[p1].go[!tmp]].cnt+trie[trie[p2].go[!tmp]].cnt-2*trie[trie[p3].go[!tmp]].cnt;
		if(sum>0){
			p1=trie[p1].go[!tmp];
			p2=trie[p2].go[!tmp];
			p3=trie[p3].go[!tmp];
			ans_tmp+=1<<i;
		}
		else{
			p1=trie[p1].go[tmp];
			p2=trie[p2].go[tmp];
			p3=trie[p3].go[tmp];
		}
	}
	return max(ans_tmp,num^val[LCA]);
}

void solve(){
	for(int i=1;i<=n;i++)
		for(int j=head2[i];j!=-1;j=query[j].next){
			int id=query[j].id;
			if(ans[id]!=-1)continue;
			ans[id]=findans(i,query[j].v,lca[id],query[j].w);
		}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}

void init(){
	memset(head,-1,sizeof(head));
	memset(head2,-1,sizeof(head2));
	memset(ans,-1,sizeof(ans));
	cnt=cnt2=0;
}

int main(){
	int u,v,w;
	while(scanf("%d %d",&n,&m)!=EOF){
		init();
		for(int i=1;i<=n;i++) scanf("%d",&val[i]);
		for(int i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			addedge(u,v);
		}
		root[0]=0;
		trie[0].go[0]=trie[0].go[1]=0;
		trie[0].cnt=0;
		tot=0;
		dfs(1,0);
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&u,&v,&w);
			addedge2(u,v,w,i);
		}
		for(int i=1;i<=n;i++) f[i]=i;
		memset(flag,0,sizeof(flag));
		tarjan(1,0);
		solve();
	}
    return 0;
}
