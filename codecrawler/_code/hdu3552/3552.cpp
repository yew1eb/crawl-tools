#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 111111;
struct node {
	int a,b;
	void input(void) { scanf("%d%d",&a,&b); }
	bool operator<(const node &r)const { return a>r.a; }
}p[N];
int main(void) {
	int n,t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++) p[i].input();
		sort(p+1,p+n+1);
		int res=0x7fffffff;
		int b=0;
		p[n+1].a=0;
		for(int i=1;i<=n+1;i++) {
			b=max(b,p[i-1].b);
			res=min(res,p[i].a+b);
		}
		printf("Case %d: %d\n",cas,res);
	}
	return 0;
}