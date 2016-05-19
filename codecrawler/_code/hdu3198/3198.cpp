#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>

using namespace std;

typedef long long ll;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FORST(X,S,T) for(int X=(S); X<=(T); X++)  
#define RFORST(X,S,T) for(int X=(S); X>=(T); X--)  
#define FOR(X,XB) for(int X=0; X<(XB); X++)
#define RFOR(X,XB) for(int X=(XB)-1; X>=0; X--)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define FILL(x,v) memset(x,v,sizeof(x))
const int INF = (int)1E9;
#define MAXN 1005

int N;
char buf[MAXN];
int odeg[26], ideg[26];
bool g[26][26], v[26], h[26];
void dfs(int k){
	v[k] = 1;
	REP(i,0,26) if(g[k][i] && !v[i]) dfs(i);
}
int main(){
	int cs;
	cin >> cs;
	while(cs--){
		int st;
		scanf("%d", &N);
		FILL(odeg,0); FILL(ideg,0); FILL(g,0); FILL(h,0);
		REP(i,0,N){
			scanf("%s", buf);
			int l = strlen(buf);
			int c0 = buf[0]-'a', cl = buf[l-1]-'a';
			odeg[c0]++; ideg[cl]++;
			g[c0][cl] = 1;
			h[c0] = h[cl] = 1;
			st = c0;
		}
		bool ok = 1;
		int ii=0, oo=0;
		REP(i,0,26){
			if(ideg[i]!=odeg[i]){
				if(ideg[i]==odeg[i]+1) ii++;
				else if(odeg[i]==ideg[i]+1) { oo++; st = i; }
				else{ ok = 0; break; }
			}
		}
		if(ok && (ii==1 && oo==1 || ii==0 && oo==0)){
			FILL(v,0);
			dfs(st);
			REP(i,0,26) if(h[i] && !v[i]) { ok = 0; break; }
		}else ok = 0;
		if(ok) puts("Ordering is possible.");
		else puts("The door cannot be opened.");
	}
	return 0;
}