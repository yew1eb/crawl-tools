#include <cstdio>
#include <deque>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;

#define Debug(x) (cerr << #x << " = " << (x) << endl)
#define Debug2(x, y) (cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl)
template<class T> inline T& RD(T &x){  
    char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';  
    return x;  
}


const int inf = 0x3f3f3f3f;
const int maxn = 100005;

int ra[maxn];
int d[maxn];
int fa[maxn];

vector<int> v[maxn];

int dfs(int u){	
	ra[u] = 0;
	for(int i=0;i<v[u].size();i++){
		ra[u]= max(dfs(v[u][i])+1,ra[u]);
	}
	return ra[u];
}

int main(){
	int T;
	scanf("%d",&T);
	while(T --){
		int n,e,m;
		scanf("%d%d%d",&n,&e,&m);
		memset(ra,0,sizeof(ra));	
		memset(d,0,sizeof(d));
		memset(fa,0,sizeof(fa));

		//build tree
		for(int i=1;i<=n;i++)v[i].clear();

		for(int i=0;i<e;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			v[b].push_back(a);
			fa[a] = 1;
		}

		//calc the deepth of each node
		for(int i=1;i<=n;i++){
			if(fa[i] == 0)dfs(i);
		}

		//calc count of each deepth
		int _max = 0;
		for(int i=1;i<=n;i++){
			d[ra[i]] ++;
			_max = max(_max,ra[i]);
		}


		//cnt: time 	lft: the can-do job last turn left
		int cnt = 0,lft = 0;

		//if I want to finish d[i] and there is lft left
		for(int i=0;i<=_max;i++){
			int td = d[i];
			//if current time > the deepth, I can use the left; 
			if(cnt > i){
				d[i] -= lft;
				//mode lft that I can use
				if(d[i] < 0){
					lft -= td;
					continue;
				}				
			}
			//calc the time I should  use and the job left
			cnt += d[i]/m;
			if(d[i]%m)cnt ++;
			lft = m - d[i]%m;
			if(lft == m)lft = 0;
		}
		printf("%d\n", cnt);
	}
	return 0;
}