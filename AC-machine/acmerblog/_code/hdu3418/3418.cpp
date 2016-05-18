//BISMILLAHIRRAHMANIRRAHIM

//#pragma warning (disable: 4786)
//#pragma comment (linker, "/STACK:0x800000")
//#define _CRT_SECURE_NO_WARNINGS 1

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n,m,i,l,a[200],t;
	i64 st,fn,md,cr,lv;
	while(cin>>n>>m) {
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		st=0;
		fn=100000000000000000ll;
		while(st+1<fn) {
			md=(st+fn)>>1;
			cr=lv=0;
			for(i=0;i<n && lv<m;i++) {
				if(a[i]>=md) lv++;
				else if(cr+a[i]<md) cr+=a[i];
				else {
					cr=(cr+a[i])%md;
					lv++;
				}
			}
			if(lv>=m) st=md;
			else fn=md-1;
		}
		if(st<fn) {
			md=fn;
			cr=lv=0;
			for(i=0;i<n && lv<m;i++) {
				if(a[i]>=md) lv++;
				else if(cr+a[i]<md) cr+=a[i];
				else {
					cr=(cr+a[i])%md;
					lv++;
				}
			}
			if(lv>=m) st=fn;
		}
		cout<<st<<'\n';
	}
	return 0;
}