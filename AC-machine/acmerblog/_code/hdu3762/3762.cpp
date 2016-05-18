#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>   
#include <map>
#include <string>  
#include <climits> 
#include <set>
#include <string>    
#include <sstream>
#include <utility>   
#include <ctime>

using std::priority_queue;
using std::vector;
using std::swap;
using std::stack;
using std::sort;
using std::max;
using std::min;
using std::pair;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::set;
using std::queue;
using std::string;
using std::istringstream;
using std::make_pair;
using std::getline;
using std::greater;
using std::endl;
using std::multimap;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PAIR;
typedef multimap<int, int> MMAP;

const int MAXN(40010);
const int SIGMA_SIZE(82);
const int MAXM(500010);
const int MAXE(60010);
const int MAXH(18);
const int INFI((INT_MAX-1) >> 2);
const int BASE(131);
const int MOD(20071027);
const ULL LIM(1000000000000000ull);

template<typename T>
struct NODE
{
	NODE *ch[2];
	int r, s;
	T key;
	int cmp(const T &op) const
	{
		if(op == key) return -1;
		return op < key? 0: 1;
	}
	void maintain()
	{
		s = ch[0]->s+ch[1]->s+1;
	}
};

template<typename T>  //内存回收类
struct POOL
{
	typedef NODE<T> ND;
	ND pool[MAXN];
	ND *ind_p;
	ND *bump[MAXN];
	int ind_b;
	void init()
	{
		ind_p = pool;
		ind_b = 0;
	}
	ND *NEW()
	{
		return ind_b? bump[--ind_b]: ind_p++;
	}
	void FREE(ND *sour)
	{
		bump[ind_b++] = sour;
	}
};

template<typename T>
struct TREAP
{
	typedef NODE<T> ND;
	static POOL<T> pool;
	static ND *NIL;
	ND *RT;
	T tkey;
	void init()
	{
		if(NIL == 0)
		{
			pool.init();
			NIL = pool.NEW();
			NIL->ch[0] = NIL->ch[1] = NIL;
			NIL->s = 0;
			NIL->r = -1;
		}
		RT = NIL;
	}
	void rotate(ND *&sour, int f)
	{
		ND *tp = sour->ch[f^1];
		sour->ch[f^1] = tp->ch[f];
		tp->ch[f] = sour;
		sour->maintain();
		tp->maintain();
		sour = tp;
	}
	void insert( T &value)
	{
		tkey = value;
		insert_(RT);
	}
	void insert_(ND *&sour)
	{
		if(sour == NIL)
		{
			sour = pool.NEW();
			sour->ch[0] = sour->ch[1] = NIL;
			sour->key = tkey;
			sour->r = rand();
			sour->s = 1;
		}
		else
		{
			int f = (tkey < sour->key? 0: 1);
			insert_(sour->ch[f]);
			if(sour->ch[f]->r > sour->r)
				rotate(sour, f^1);
			sour->maintain();
		}
	}
	void remove(const T &value)
	{
		tkey = value;
		remove_(RT);
	}
	void remove_(ND *&sour)
	{
		int f = sour->cmp(tkey);
		if(f == -1)
		{
			if(sour->ch[0] == NIL)
				pool.FREE(sour), sour = sour->ch[1];
			else
				if(sour->ch[1] == NIL)
					pool.FREE(sour), sour = sour->ch[0];
				else
				{
					int f2 = (sour->ch[0]->r > sour->ch[1]->r? 1: 0);
					rotate(sour, f2);
					remove_(sour->ch[f2]);
				}
		}
		else
			remove_(sour->ch[f]);
		if(sour != NIL)
			sour->maintain();
	}
	ND *find(const T &value)
	{
		ND *sour = RT;
		while(sour != NIL)
		{
			int f = sour->cmp(value);
			if(f == -1)
				break;
			sour = sour->ch[f];
		}
		return sour;
	}
	ND *select(int kth)
	{
		ND *sour = RT;
		int tk;
		while(sour != NIL && kth != (tk = sour->ch[0]->s+1))
		{
			if(kth < tk)
				sour = sour->ch[0];
			else
			{
				kth -= tk;
				sour = sour->ch[1];
			}
		}
		return sour;
	}
	int rank(const T &value) //此出结果为左界
	{
		ND *sour = RT;
		int ret = 1;
		while(sour != NIL)
		{
			if(value < sour->key) //如果此处改成<则求出的结果为右界+1
				sour = sour->ch[0];
			else
			{
				ret += sour->ch[0]->s+1;
				sour = sour->ch[1];
			}
		}
		return ret;
	}
	ND *pre(const T &value)  //返回小于value的最大元素的索引,否则返回NIL
	{
		tkey = value;
		return pre_(RT);
	}
	ND *pre_(ND *sour)
	{
		if(sour == NIL)
			return NIL;
		if(tkey <= sour->key)
			return pre_(sour->ch[0]);
		else
		{
			ND *tp = pre_(sour->ch[1]);
			return tp == NIL? sour: tp;
		}
	}

	ND *suc(const T &value) //返回大于value的最小元素索引,否则返回NIL
	{
		tkey = value;
		return suc_(RT);
	}
	ND *suc_(ND *sour)
	{
		if(sour == NIL)
			return NIL;
		if(tkey >= sour->key)
			return suc_(sour->ch[1]);
		else
		{
			ND *tp = suc_(sour->ch[0]);
			return tp == NIL? sour: tp;
		}
	}
	void merge(ND *&sour) //合并以sour为根节点的子树
	{
		if(sour == NIL)
			return;
		merge(sour->ch[0]);
		merge(sour->ch[1]);
		insert(sour->key);
		pool.FREE(sour);
		sour = NIL;   //一定要把sour置为NIL，不然爆栈
	}
	void removetree(ND *&sour) //删除以sour为根节点的子树
	{
		if(sour == NIL)
			return;
		removetree(sour->ch[0]);
		removetree(sour->ch[1]);
		pool.FREE(sour);
		sour = NIL;  //一定要把sour置为NIL，不然爆栈 
	}
	void debug()
	{
		printf("/****************************************/\n");
		debug_(RT, 0);
		printf("/****************************************/\n");
	}

	void debug_(ND *sour, int vec)
	{
		if(sour == NIL)
			return;
		debug_(sour->ch[0], vec+1);
		for(int i = 0; i < vec; ++i)
			printf("     ");
		printf("%d\n", sour->key);
		debug_(sour->ch[1], vec+1);
	}
};

TREAP<int>::ND *TREAP<int>::NIL = 0;
POOL<int> TREAP<int>::pool; 

struct FIND_SET
{
	int fa[MAXN];
	int find(int sour)
	{
		return sour == fa[sour]? sour: fa[sour] = find(fa[sour]);
	}
};

struct OP
{
	char type;
	int op1, op2;
};

TREAP<int> trp[20010];
FIND_SET fs;
int weight[20010];
OP arr[MAXM];
int cnt;
TREAP<int>::ND *NIL = TREAP<int>::NIL;
int from[MAXE], to[MAXE];
bool is_remove[MAXE];

void add_edge(int ind)
{
	int u = fs.find(from[ind]), v = fs.find(to[ind]);
	if(u != v)
	{
		if(trp[u].RT->s < trp[v].RT->s)
		{
			fs.fa[u] = v;
			trp[v].merge(trp[u].RT);
		}
		else
		{
			fs.fa[v] = u;
			trp[u].merge(trp[v].RT);
		}
	}
}

int main()
{
	int n, m, n_case(0);
	TREAP<int>::ND *tp;
	for(int i = 1; i <= 20000; ++i)
		trp[i].init();
	while(scanf("%d%d", &n, &m), n+m)
	{
		for(int i = 1; i <= n; ++i)
			scanf("%d", weight+i);
		for(int i = 1; i <= m; ++i)
			scanf("%d%d", from+i, to+i);
		memset(is_remove, 0, sizeof(is_remove));
		cnt = 0;
		while(scanf(" %c", &arr[cnt].type), arr[cnt].type != 'E')
		{
			if(arr[cnt].type == 'D')
			{
				scanf("%d", &arr[cnt].op1);
				is_remove[arr[cnt].op1] = true;
			}
			else
				scanf("%d%d", &arr[cnt].op1, &arr[cnt].op2);
			if(arr[cnt].type == 'C')
				swap(arr[cnt].op2, weight[arr[cnt].op1]);
			++cnt;
		}
		for(int i = 1; i <= n; ++i)
		{
			trp[i].removetree(trp[i].RT);
			trp[i].init();
			trp[i].insert(weight[i]);
			fs.fa[i] = i;
		}
		for(int i = 1; i <= m; ++i)
			if(!is_remove[i])
				add_edge(i);
		double ans = 0;
		int ansi = 0;
		int tu;
		for(int i = cnt-1; i >= 0; --i)
		{
			switch(arr[i].type)
			{
			case 'D':	add_edge(arr[i].op1);
			break;
			case 'Q':	tu = fs.find(arr[i].op1);
						if(arr[i].op2 >= 1 && arr[i].op2 <= trp[tu].RT->s)
						{
							tp = trp[tu].select(trp[tu].RT->s-arr[i].op2+1);
							ans += tp->key;
						}
						++ansi;
			break;
			case 'C':	tu = fs.find(arr[i].op1);
						trp[tu].remove(weight[arr[i].op1]);
						trp[tu].insert(arr[i].op2);
						weight[arr[i].op1] = arr[i].op2;
			break;
			}
		}
		printf("Case %d: %.6f\n", ++n_case, ans/ansi);
	}
	return 0;
}
