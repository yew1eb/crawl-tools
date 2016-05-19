/*

http://hi.baidu.com/chenwenwen0210/item/00cb739a43e8516bf14215eb


http://www.cnblogs.com/kuangbin/archive/2013/05/24/3097767.html

  */

#include<cstdio>
#include<cstring>

const int maxn=5000;
int SG[maxn];
int n,m;
bool vis[maxn];
bool map[2][maxn];

int Gao(int tot){
	int i,j,k;
	if(SG[tot]!=-1)return SG[tot]; 
	memset(vis,0,sizeof(vis));
	for(i=0;i<=tot-i-1;i++){
		k=Gao(i)^Gao(tot-i-1)^1;
		vis[k]=1;
	}
	for(i=0;i<=tot-i-2;i++){
		k=Gao(i)^Gao(tot-i-2);
		vis[k]=1;
	}
	for(i=0;i<maxn;i++)
		if(!vis[i]){
			SG[tot]=i;
			break;
		}
	return SG[tot];
}

void Init(){
	memset(SG,-1,sizeof(SG));
	for(int i=1;i<maxn;i++)
		SG[i]=Gao(i);
}

int main(){
	int i,j,T,x,y;
	Init();
	int cas;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		memset(map,0,sizeof(map));
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			x--;y--;
			map[x][y]++;
		}
		int ans=0;
		int len=0;
		for(i=0;i<n;i++){
			if(map[0][i] ||map[1][i]){
				ans^=SG[len];
				len=0;
				if(map[0][i] && map[1][i])
					continue;
				ans^=1;
			}else{
				len++;
			}
		}
		ans^=SG[len];
		if(ans)printf("Case %d: Alice\n",cas);
		else printf("Case %d: Bob\n",cas);
	}
	return 0;
}
