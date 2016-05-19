/*****************************************
USER: a180285
PROB: 
LANG: C++
2013,UESTC
*****************************************/

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>
# include <sstream>

# define For(i,a)   for((i)=0;i<(a);(i)++)
# define MAX(x,y)   ((x)>(y)? (x):(y))
# define MIN(x,y)   ((x)<(y)? (x):(y))
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0x7f,sizeof(a)))
# define pb(a)      push_back(a)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;


template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}

const int oo=1<<30          ;
const double eps=1e-7       ;
const int N=100000 + 128              ;
const int M=300               ;
const int MAXQ = N * 95	;
const int MAXB = N * 16		;
const ll P=10000000097ll    ;

#pragma 	pack(1)

struct Block
{
	int* vp;
	int last;
	ll sum;
};

int Q[MAXQ];
int* Qp[N];
Block B[MAXB];

int num, qn;
int len, bn;
int now;

void outputlimit()
{
	while( 1 )
		puts("RE");
}

int get_length(int kth)
{
	return MIN(num-kth*len, len);
}

int* new_vp(int* old,int n)
{
	int* p = Qp[now];
	Qp[now] += n;
	if(Qp[now] - Q >= MAXQ)
		outputlimit();
	for(int i=0; i<n; i++)
		p[i] = old[i];
	return p;
}

void read()
{
	for(len=1; len*len<num; len++)
		;
	bn = (num+len-1) / len;
	for(int i=0; i<num; i++)
		scanf("%d", &Q[i]);
	
	for(int i=0; i<bn; i++)
	{
		B[i].vp = Q + len * i;
		B[i].last = 0;
		B[i].sum = 0;
		int n = get_length(i);
		for(int j=0; j<n; j++)
			B[i].sum += B[i].vp[j];
	}
	
	int sum = 0;
	for(int i=0; i<bn; i++)
		sum += get_length(i);
	if(sum != num)
		while( 1 )
			puts("sum != num");
	now = 0;
	
	Qp[now] = Q + num;
}

void add(int l,int r,ll d)
{
	l--;
	now++;
	Qp[now] = Qp[now-1];
	Block* b   = B + now*bn;
	Block* old = b - bn;
	
	if(now*bn + bn >= MAXB)
		outputlimit();
	
	for(int i=0; i<bn; i++)
		b[i] = old[i];
	for(int i=l/len; i*len<r; i++)
	{
		int st = i * len;
		int ed = st + get_length(i);
		if(l<=st && ed<=r)
		{
			b[i].sum += d * get_length(i);
			b[i].last += d;
		}
		else
		{
			int mn = MAX(st, l) - st;
			int mx = MIN(ed, r) - st;
			
			b[i].vp = new_vp(b[i].vp, get_length(i));
			b[i].sum += d * (ll)(mx - mn);
			for(int j=mn; j<mx; j++)
				b[i].vp[j] += d;
		}
	}
}

void print()
{

}

ll query(int t,int l,int r)
{
	l--;
	Block* b = B + t*bn;
	
	if(now*bn + bn >= MAXB)
		outputlimit();
	
	
	ll ans = 0;
	for(int i=l/len; i*len<r; i++)
	{
		int st = i * len;
		int ed = st + get_length(i);
		if(l<=st && ed<=r)
		{
			ans += b[i].sum;
		}
		else
		{
			int mn = MAX(st, l) - st;
			int mx = MIN(ed, r) - st;
			ans += b[i].last * (ll)(mx - mn);
			for(int j=mn; j<mx; j++)
				ans += b[i].vp[j];
		}
	}
	return ans;
}

void doit()
{
// 1. C l r d: Adding a constant d for every {Ai | l <= i <= r}, and increase the time stamp by 1, this is the only operation that will cause the time stamp increase. 
// 2. Q l r: Querying the current sum of {Ai | l <= i <= r}.
// 3. H l r t: Querying a history sum of {Ai | l <= i <= r} in time t.
// 4. B t: Back to time t. And once you decide return to a past, y
	int l, r, d, t;
	ll ans;
	for(int i=0; i<qn; i++)
	{
		char q;
		scanf(" %c", &q);
		switch(q)
		{
		case 'C':
			scanf("%d %d %d", &l, &r, &d);
			add(l, r, d);
			break;
		case 'Q':
			scanf("%d %d", &l, &r);
			ans = query(now, l, r);
			printf("%I64d\n", ans);
			break;
		case 'H':
			scanf("%d %d %d", &l, &r, &t);
			ans = query(t, l, r);
			printf("%I64d\n", ans);
			break;
		case 'B':
			scanf("%d", &t);
			now = t;
			break;
		}
	}
}

int main()
{
#ifdef Hw
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
	double use = 0;
	use += sizeof(Q);
	use += sizeof(Qp);
	use += sizeof(B);
	printf("%f MB\n", use / (1<<20));
#endif
	while( 2==scanf("%d %d", &num, &qn) )
	{
		read();
		doit();
		print();
	}

    return 0;
}

/**

10 15
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Q 1 1
Q 1 2
Q 1 3
Q 1 4
Q 1 5
Q 1 6
Q 1 7
Q 1 8
Q 1 9
Q 1 10

2 4
0 0
C 1 1 1
C 2 2 -1
Q 1 2
H 1 2 1
 
Sample Output
4
55
9
15

0
1
 

**/