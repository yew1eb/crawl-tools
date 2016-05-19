#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <queue>
#include <stack>
#define INF 999999999
#define eps 0.00001
#define LL long long
#define maxn 1000005
using namespace std;

int mp[10][10];
int tmp[10][10];

int n,m,q;
int ans ;

void init() {
	memset(mp,0,sizeof(mp));
}

int cal(int x,int y) {
	if(mp[x][y] == 1)return 0;
	int mark = 0;
	for(int i=y-1;i>=0;i--) {
		if(mp[x][i] == 1)
			mark++;
		else if(mp[x][i] == 2) {
			if(mark == 1) return 0;
			else mark++;
		}
	}
	mark = 0;
	for(int i=x-1;i>=0;i--) {
		if(mp[i][y] == 1)
			mark++;
		else if(mp[i][y] == 2) {
			if(mark == 1)return 0;
			else mark++;
		}
	}
	return 1;
}

void dfs(int x,int y,int cnt) {
	int tx = x/n;
	if(n == 1)tx = 0;
	int ty = y%m;
	ans = max(ans,cnt);
	if(tx >= n) return;
	if(tx == 0 && y >= n * m)return;
	if(cal(tx,ty)) {
		mp[tx][ty] = 2;
		dfs(x+1,y+1,cnt+1);
		mp[tx][ty] = 0;

		dfs(x+1,y+1,cnt);
	}
	else
		dfs(x+1,y+1,cnt);
}

int main() {
	while(scanf("%d %d %d",&n,&m,&q) == 3) {
		init();
		ans = 0;
		memset(tmp,0,sizeof(tmp));
		while(q--) {
			int x,y;
			scanf("%d %d",&x,&y);
			mp[x][y] = 1;
			tmp[x][y] = 1;
		}
		dfs(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}