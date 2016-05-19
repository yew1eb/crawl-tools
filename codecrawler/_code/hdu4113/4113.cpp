#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-8
#define ll long long
#define maxm 51000


#define STATE 510000
#define HASH 10007
#define maxd 15

int n,m;
char maze[maxd][maxd];
int code[maxd];
struct HASHMAP{
	int head[HASH],nxt[STATE],sz;
	int state[STATE],f[STATE];
	void clear(){sz=0;memset(head,-1,sizeof(head));}
	void push(int st,int ans){
		int h = st%HASH;
		for(int i=head[h];i!=-1;i=nxt[i]){
			if(st==state[i]){
				f[i] = min(f[i], ans);
				return ;
			}
		}
		state[sz]=st, f[sz]=ans, nxt[sz]=head[h];
		head[h]=sz++;
	}
}hm[2][2];
void decode(int st){
	for(int i=0;i<=m;++i) code[i] = st&3, st>>=2;
}
int encode(){
	int ret=0;
	for(int i=m;i>=0;--i) ret = ret<<2|code[i];
	return ret;
}
bool jud(int i,int j,int in){
	if(maze[i][j]=='o') return in;
	if(maze[i][j]=='x') return !in;
	return true;
}
int edx,edy;
int ans;
void dp(int i,int j,int cur,int in){
	int xo = (1<<(j*2));
	int ox = (2<<(j*2));
	int oo = xo|ox;
	int mv = (j==m?2:0);
	for(int k=0;k<hm[cur][in].sz;++k){
		decode(hm[cur][in].state[k]);
		int left = code[j-1];
		int up = code[j];
		if(left && up){
			if(left==2 && up==1){
				if(i>=edx+1 && j>=edy+1){
					int to = hm[cur][in].state[k] ^ (ox>>2) ^ (xo);
					if(to==0) ans = min(ans, hm[cur][in].f[k]+1);
				}
				continue;
			}
			if(left==1 && up==1){
				for(int jj=j-1,c=0;jj>=0;--jj){
					if(code[jj]==1)++c;
					if(code[jj]==2)--c;
					if(c==0){code[jj]^=3;break;}
				}
				code[j-1]=code[j]=0;
			}
			if(left==2 && up==2){
				for(int jj=j,c=0;jj<=m;++jj){
					if(code[jj]==2)++c;
					if(code[jj]==1)--c;
					if(c==0){code[jj]^=3;break;}
				}
				code[j-1]=code[j]=0;
			}
			if(left==1 && up==2){
				code[j-1]=code[j]=0;
			}
			if(jud(i-1,j,in^1))
				hm[cur^1][in^1].push(encode()<<mv, hm[cur][in].f[k]+1);
		}else if(left || up){
			int in2 = in;
			if(up) in2^=1;
			int tmp = left | up;
			code[j-1]=tmp, code[j]=0;
			if(i+1<=n)
				if(jud(i-1,j,in2) && jud(i,j-1,!in2) && jud(i,j,in2))
					hm[cur^1][in2].push(encode()<<mv, hm[cur][in].f[k]+1);
			code[j-1]=0, code[j]=tmp;
			if(j+1<=m)
				if(jud(i-1,j,in2) && jud(i,j-1,!in2) && jud(i,j,!in2))
					hm[cur^1][in2].push(encode()<<mv, hm[cur][in].f[k]+1);
		}else {
			if(jud(i-1,j,in) && jud(i,j-1,in) && jud(i,j,in))
				hm[cur^1][in].push(hm[cur][in].state[k]<<mv, hm[cur][in].f[k]);
			code[j-1]=2, code[j]=1;
			if(i+1<=n && j+1<=m)
				if(jud(i-1,j,in) && jud(i,j-1,in) && jud(i,j,!in))
					hm[cur^1][in].push(encode()<<mv, hm[cur][in].f[k]+1);
		}
	}
}
int solve(){
	int cur=0;
	hm[0][0].clear();
	hm[0][1].clear();
	hm[0][0].push(0,0);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(maze[i][j]=='o') edx=i,edy=j;
	ans=inf;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			hm[cur^1][0].clear();
			hm[cur^1][1].clear();
			dp(i,j,cur,0);
			dp(i,j,cur,1);
			cur^=1;
		}
	}
	if(ans==inf) return -1;
	return ans;
}
int main(){
	int t,ca=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(maze,0,sizeof(maze));
		for(int i=1;i<=n;++i) scanf("%s",maze[i]+1);
		++n,++m;
		for(int i=0;i<=n;++i) maze[i][0]=maze[i][m]='.';
		for(int j=0;j<=m;++j) maze[0][j]=maze[n][j]='.';
		printf("Case #%d: %d\n",++ca, solve());
	}
	return 0;
}
