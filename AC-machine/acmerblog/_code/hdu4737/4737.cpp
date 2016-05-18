/*
 Author : Speedcell
 Update : 2013-05-30
Version : soppYcell 2.2(a)
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <memory>
#include <complex>
#include <numeric>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

using namespace std;

#pragma pack(4)

#ifndef __CONSTANT__
#define __CONSTANT__

typedef long long LONG;

const double pi = acos(-1.0);
const int   inf = 0x7f7f7f7f;
const LONG  INF = 0x7f7f7f7f7f7f7f7fll;

const int go[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

#endif // __CONSTANT__

#ifndef __IO__
#define __IO__

inline bool RD(int    & a) {return scanf("%d",&a)!=EOF;}
inline bool RD(char   & a) {return scanf("%c",&a)!=EOF;}
inline bool RD(char   * a) {return scanf("%s", a)!=EOF;}
inline bool RD(double & a) {return scanf("%lf",&a)!=EOF;}
inline bool RD(LONG   & a) {return scanf("%I64d",&a)!=EOF;}

template<class T1> inline bool
    IN(T1 & a) {return RD(a);}
template<class T1,class T2> inline bool
    IN(T1 & a,T2 & b) {return RD(a)&&RD(b);}
template<class T1,class T2,class T3> inline bool
    IN(T1 & a,T2 & b,T3 & c) {return RD(a)&&RD(b)&&RD(c);}
template<class T1,class T2,class T3,class T4> inline bool
    IN(T1 & a,T2 & b,T3 & c,T4 & d) {return RD(a)&&RD(b)&&RD(c)&&RD(d);}
template<class T1,class T2,class T3,class T4,class T5> inline bool
    IN(T1 & a,T2 & b,T3 & c,T4 & d,T5 & e) {return RD(a)&&RD(b)&&RD(c)&&RD(d)&&RD(e);}
template<class T1,class T2,class T3,class T4,class T5,class T6> inline bool
    IN(T1 & a,T2 & b,T3 & c,T4 & d,T5 & e,T6 & f) {return RD(a)&&RD(b)&&RD(c)&&RD(d)&&RD(e)&&RD(f);}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> inline bool
    IN(T1 & a,T2 & b,T3 & c,T4 & d,T5 & e,T6 & f,T7 & g) {return RD(a)&&RD(b)&&RD(c)&&RD(d)&&RD(e)&&RD(f)&&RD(g);}

inline void PT(int    a) {printf("%d",a);}
inline void PT(char   a) {printf("%c",a);}
inline void PT(char * a) {printf("%s",a);}
inline void PT(double a) {printf("%f",a);}
inline void PT(LONG   a) {printf("%I64d",a);}
inline void PT(const char a[]) {printf("%s",a);}

template<class T1> inline void
    OT(T1 a) {PT(a);}
template<class T1,class T2> inline void
    OT(T1 a,T2 b) {PT(a),PT(' '),PT(b);}
template<class T1,class T2,class T3> inline void
    OT(T1 a,T2 b,T3 c) {PT(a),PT(' '),PT(b),PT(' '),PT(c);}
template<class T1,class T2,class T3,class T4> inline void
    OT(T1 a,T2 b,T3 c,T4 d) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d);}
template<class T1,class T2,class T3,class T4,class T5> inline void
    OT(T1 a,T2 b,T3 c,T4 d,T5 e) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d),PT(' '),PT(e);}
template<class T1,class T2,class T3,class T4,class T5,class T6> inline void
    OT(T1 a,T2 b,T3 c,T4 d,T5 e,T6 f) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d),PT(' '),PT(e),PT(' '),PT(f);}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> inline void
    OT(T1 a,T2 b,T3 c,T4 d,T5 e,T6 f,T7 g) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d),PT(' '),PT(e),PT(' '),PT(f),PT(' '),PT(g);}

template<class T1> inline void
    OL(T1 a) {PT(a),PT('\n');}
template<class T1,class T2> inline void
    OL(T1 a,T2 b) {PT(a),PT(' '),PT(b),PT('\n');}
template<class T1,class T2,class T3> inline void
    OL(T1 a,T2 b,T3 c) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT('\n');}
template<class T1,class T2,class T3,class T4> inline void
    OL(T1 a,T2 b,T3 c,T4 d) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d),PT('\n');}
template<class T1,class T2,class T3,class T4,class T5> inline void
    OL(T1 a,T2 b,T3 c,T4 d,T5 e) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d),PT(' '),PT(e),PT('\n');}
template<class T1,class T2,class T3,class T4,class T5,class T6> inline void
    OL(T1 a,T2 b,T3 c,T4 d,T5 e,T6 f) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d),PT(' '),PT(e),PT(' '),PT(f),PT('\n');}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> inline void
    OL(T1 a,T2 b,T3 c,T4 d,T5 e,T6 f,T7 g) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d),PT(' '),PT(e),PT(' '),PT(f),PT(' '),PT(g),PT('\n');}

#endif // __IO__

#ifndef __MACRO__
#define __MACRO__

#define ML(times) int tcase; IN(tcase); FOR(times,1,tcase)

#define FOR(i,a,b) for(int i=int(a),_##i=int(b);i<=_##i;i++)
#define DWN(i,b,a) for(int i=int(b),_##i=int(a);_##i<=i;i--)
#define ECH(i,u,pre,next) for(int i=int(pre[u]);i!=-1;i=int(next[i]))

#define MEM(a,v) memset(a,v,sizeof(a))
#define CLR(a,v) FOR(_i##a,0,sizeof(a)/sizeof(a[0])-1) a[_i##a]=v

#define LOOP(a,n)                                               \
    FOR(_i##a,0,(n)-1)                                          \
        OT(a[_i##a]),OT(_i##a!=__i##a?' ':'\n')
#define LOOP2(a,n,m)                                            \
    FOR(_i##a,0,(n)-1) FOR(_j##a,0,(m)-1)                       \
        OT(a[_i##a][_j##a]),OT(_j##a!=__j##a?' ':'\n')
#define LOOPG(G,n,pre,next)                                     \
    FOR(_i##a,0,(n)-1) ECH(_j##a,_i##a,pre,next)                \
        OL(_i##a,G[_j##a].v,G[_j##a].w)

#endif // __MACRO__

#ifndef __BIT__
#define __BIT__

template<class T> inline T lb(T i) {return i&-i;}
template<class T> inline T lc(T i) {return i<<1;}
template<class T> inline T rc(T i) {return i<<1|1;}
template<class T> inline T at(T a,int i) {return a& (T(1)<<i);}
template<class T> inline T nt(T a,int i) {return a^ (T(1)<<i);}
template<class T> inline T s1(T a,int i) {return a| (T(1)<<i);}
template<class T> inline T s0(T a,int i) {return a&~(T(1)<<i);}

#endif // __BIT__

#ifndef __DOUBLE__
#define __DOUBLE__

const double eps = 1e-8;

inline int cmp(double a,double b=0) {return fabs(a-b)<eps?0:((a-b)>eps?+1:-1);}

inline double fmax(double a,double b) {return cmp(a,b)>0?a:b;}
inline double fmin(double a,double b) {return cmp(a,b)<0?a:b;}

#endif // __DOUBLE__

const int MAXV = 100002;

class SegmentTree
{
private:
	int L,R,a[MAXV<<2];

	#define ls(l,r,i) l,(l+r)>>1,lc(i)
	#define rs(l,r,i) ((l+r)>>1)+1,r,rc(i)

	void add(int v,int l,int r,int i)
	{
		if(l<=r) a[i]|=v;
	}
	void up(int l,int r,int i)
	{
		if(l<r) a[i]=a[lc(i)]|a[rc(i)];
	}
	void update(int x,int v,int l,int r,int i)
	{
		if(x==l&&r==x) add(v,l,r,i);
		else
		{
			if(x<=(l+r)/2) update(x,v,ls(l,r,i));
			else update(x,v,rs(l,r,i));
			up(l,r,i);
		}
	}
	int query(int v,int now,int l,int r,int i)
	{
		if(l>r) return -1;
		else if((a[i]|now)<v) return r;
		else
		{
			if(l==r) return -1;
			else if((a[lc(i)]|now)>=v) return query(v,now,ls(l,r,i));
			else return max((l+r)/2,query(v,a[lc(i)]|now,rs(l,r,i)));
		}
	}
public:
	void clear(int l,int r)
	{
		L=l;
		R=r;
		MEM(a,0);
	}
	void update(int x,int v)
	{
		update(x,v,L,R,1);
	}
	int query(int x,int v)
	{
		int ans=query(v,0,L,R,1);
		if(ans<x) return 0;
		else return ans-x+1;
	}
}st;

int n,m,v[MAXV];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("A Bit Fun.txt","r",stdin);
    #else
    #endif

    ML(times)
    {
    	IN(n,m);
    	int ans=0;
    	st.clear(0,n-1);
    	FOR(i,0,n-1) IN(v[i]);
    	DWN(i,n-1,0)
    	{
    		st.update(i,v[i]);
    		ans+=st.query(i,m);
    	}
    	printf("Case #%d: %d\n",times,ans);
    }

    return 0;
}