#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 50007;

int size, head[N], n;
int pr[N], next[N], in[N];
struct Edge
{
	int v, next;

	void ini(int a, int b)
	{
		v = b;
		next = head[a];
		head[a] = size++;
	}
};
Edge edge[N];
int ch[N << 1][2], fa[N << 1];

void build(int x) //建树（size 表示最后加进来的节点）
{
	fa[x] = size;
	ch[size][1] = x;
	size = x;
	for(int i = head[x]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		build(v);
	}
	fa[x + n] = size;
	ch[size][1] = x + n;
	size = x + n;
}

void init()
{
	memset(ch, 0, sizeof(ch));
	for(int i = next[0]; i != -1; i = next[i])
	{
		size = 0;
		build(i);
	}
}

inline void rotate(int x, bool f)
{
	int y = fa[x];
	int z = fa[y];
	ch[y][!f] = ch[x][f];
	fa[ch[x][f]] = y;
	fa[x] = z;
	if(z)
		ch[z][ch[z][1] == y] = x;
	ch[x][f] = y;
	fa[y] = x;
}

void splay(int x, int g)
{
	int y = fa[x];
	while(y != g)
	{
		int z = fa[y];
		bool f = (ch[y][0] == x);
		if(z != g && f == (ch[z][0] == y))
			rotate(y, f);
		rotate(x, f);
		y = fa[x];
	}
}

void move(int a, int b)
{
	if(a == b)
		return ;
	splay(a, 0);
	splay(a + n, a);
	for(int i = b; i; i = fa[i]) //判断b是否为a的孩子
		if(ch[a + n][0] == i)
			return ;
	int x, y;
	x = ch[a][0];
	y = ch[a + n][1];
	ch[a][0] = ch[a + n][1] = fa[x] = fa[y] = 0; //把[a, a + n]取出来
	if(x && y)
	{
		while(ch[y][0])
			y = ch[y][0];
		ch[y][0] = x;
		fa[x] = y;
	}
	if(b == 0) //[a, a + n]已经独立为一棵树了
		return ;
	splay(b, 0);
	int i;
	for(i = ch[b][1]; ch[i][0]; i = ch[i][0]) ; //找b后面的一个节点
	splay(i, b);
	ch[i][0] = a;
	fa[a] = i;
}

int que(int a)
{
	splay(a, 0); //把a移动到根，方便找这棵树的最小值
	for(; ch[a][0]; a = ch[a][0]) ;
	return a;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	bool f = false;
	while(~scanf("%d", &n))
	{
		if(f)
			puts("");
		else
			f = true;
		int tmp = 0;
		pr[0] = next[0] = -1;
		size = 0;
		memset(head, -1, sizeof(head));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", in + i);
			if(in[i])
				edge[size].ini(in[i], i);
			else
			{
				next[tmp] = i;
				next[i] = -1;
				pr[i] = tmp;
				tmp = i;
			}
		}
		init();
		int m;
		scanf("%d", &m);
		while(m--)
		{
			char s[10];
			int a;
			scanf("%s%d", s, &a);
			if(s[0] == 'M')
			{
				int b;
				scanf("%d", &b);
				move(a, b);
			}
			else
				printf("%d\n", que(a));
		}
	}
	return 0;
}