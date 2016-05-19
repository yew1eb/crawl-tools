#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N =  200010;
const int inf = -0x3f3f3f3f;
int dp[N];
int xis[N];
int n, cnt;
struct node
{
	int l, r;
	int val;
}tree[N << 2];

struct node2
{
	int g;
	int h;
}box[N];

int BinSearch(int val)
{
	int l = 1, r = cnt, mid;
	int ans;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (xis[mid] > val)
		{
			r = mid - 1;
		}
		else if (xis[mid] < val)
		{
			l = mid + 1;
		}
		else
		{
			ans = mid;
			break;
		}
	}
	return ans;
}

void build(int p, int l, int r)
{
	tree[p].l = l;
	tree[p].r = r;
	tree[p].val = inf;
	if (l == r)
	{
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
}

void update(int p, int pos, int val)
{
	if (tree[p].l == tree[p].r)
	{
		tree[p].val = val;
		return;
	}
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (pos <= mid)
	{
		update(p << 1, pos, val);
	}
	else
	{
		update(p << 1 | 1, pos, val);
	}
	tree[p].val = max(tree[p << 1].val, tree[p << 1 | 1].val);
}

int query(int p, int l, int r)
{
	if (l <= tree[p].l && tree[p].r <= r)
	{
		return tree[p].val;
	}
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (r <= mid)
	{
		return query(p << 1, l, r);
	}
	else if (l > mid)
	{
		return query(p << 1 | 1, l, r);
	}
	else
	{
		return max(query(p << 1, l, mid), query(p << 1 | 1, mid + 1, r));
	}
}

int main()
{
	while (~scanf("%d", &n))
	{
		int ans = 0;
		cnt = 1;
		xis[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d%d", &box[i].h, &box[i].g);
			xis[++cnt] = box[i].h;
		}
		sort (xis, xis + cnt + 1);
		cnt = unique(xis, xis + cnt + 1) - xis - 1;
		build(1, 1, cnt);
		dp[0] = 0;
		update(1, 1, dp[0]);
		for (int i = 1; i <= n; ++i)
		{
			int j = BinSearch(box[i].h), last;
			if (j == 1)
			{
				dp[i] = box[i].g;
			}
			else
			{
				last = query(1, 1, j - 1);
				dp[i] = last + box[i].g;
			}
			update(1, j, dp[i]);
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}