#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define rep(i,s,t) for(int i=s;i<t;i++)
typedef pair<int,int>ii;

int n,m,Size,len;
char s[210][210];
map<ii,bool>vis;
vector<int>v[16],choose;
vector<ii>node;
int dx[]={-1,-1,1,1};
int dy[]={-1,1,-1,1};

inline int getone(int i){
	int ret=0;
	while(i) {ret++,i-=i&(-i);}
	return ret;
}

inline void Init(){
	int all=(1<<Size);
	rep(i,1,all){
		v[getone(i)].push_back(i);
	}
}

inline bool ok(int x,int y,int xx,int yy){
	if(xx>=0 && xx<n){
		if(s[xx][y]=='#') return 0;
	}
	if(yy>=0 && yy<m){
		if(s[x][yy]=='#') return 0;
	}
	return 1;
}

inline bool flood(int now){
	rep(i,0,len){
		if(i!=now){
			int x=node[choose[i]].first,y=node[choose[i]].second;
			int xx=x-1,yy=y+1;
			if(!ok(x,y,xx,yy)) return 0;
			vis[node[choose[i]]]=vis[ii(x,yy)]=vis[ii(xx,y)]=1;
		}
	}
	return 1;
}

inline bool check(int now,int j){
	int x=node[choose[now]].first,y=node[choose[now]].second;
	vis.clear();
	int xx=x+dx[j],yy=y+dy[j];
	if(!ok(x,y,xx,yy)) return 0;
	if(!flood(now)) return 0;
	vis[ii(x,yy)]=vis[ii(xx,y)]=vis[node[choose[now]]]=1;
	rep(i,0,Size){
		if(!vis[node[i]]) return 0;
	}
	return 1;
}

inline bool dfs(int tmp){
	int S=v[tmp].size();
	rep(i,0,S){
		int st=v[tmp][i];
		choose.clear();
		rep(j,0,Size){
			if(st&(1<<j)) choose.push_back(j);
		}
		len=choose.size();
		rep(j,0,len){
			if(check(j,0)) return 1;
			if(check(j,1)) return 1;
			if(check(j,2)) return 1;
			if(check(j,3)) return 1;
		}
	}
	return 0;
}

int main(){
	while(scanf("%d%d",&n,&m), n||m){
		node.clear();
		rep(i,0,n){
			scanf("%s",s[i]);
			rep(j,0,m){
				if(s[i][j]=='.'){
					node.push_back(ii(i,j));
				}
			}
		}
		Size=node.size();
		if(Size==0){
			puts("0");continue;
		}
		rep(i,1,Size+1) v[i].clear();
		Init();
		int ans=1;
		while(ans<=Size && !dfs(ans)) ans++;
		if(ans==Size+1) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}
