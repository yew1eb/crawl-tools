#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

const int inf = 0x3f3f3f3f;
const int maxn = 10010;
int val[maxn];

struct SegNode {
	int left, right, exp, level, lazy, min_;
	int mid() {
		return (left + right) >> 1;
	}
};

struct SegmentTree {
	SegNode tree[maxn*5];

	void PushUp(int idx) {
		tree[idx].exp = std::max(tree[idx<<1].exp, tree[idx<<1|1].exp);
		tree[idx].level = std::max(tree[idx<<1].level, tree[idx<<1|1].level);
		tree[idx].min_ = std::min(tree[idx<<1].min_, tree[idx<<1|1].min_);
	}

	void PushDown(int idx) {
		tree[idx<<1].exp += tree[idx].lazy * tree[idx<<1].level;
		tree[idx<<1].min_ -= tree[idx].lazy;
		tree[idx<<1].lazy += tree[idx].lazy;
		tree[idx<<1|1].exp += tree[idx].lazy * tree[idx<<1|1].level;
		tree[idx<<1|1].min_ -= tree[idx].lazy;
		tree[idx<<1|1].lazy += tree[idx].lazy;
		tree[idx].lazy = 0;
	}

	void build(int left, int right, int idx) {
		tree[idx].left = left; tree[idx].right = right;
		tree[idx].exp = 0; tree[idx].level = 1;
		tree[idx].lazy = 0; tree[idx].min_ = val[1];
		if (left == right) return ;
		int mid = (left + right) >> 1;
		build(left, mid, idx<<1);
		build(mid + 1, right, idx<<1|1);
		PushUp(idx);
	}

	void update(int left, int right, int idx, int value) {
		if (tree[idx].left == tree[idx].right) {
			tree[idx].exp += tree[idx].level * value;
			while (tree[idx].exp >= val[tree[idx].level])
				tree[idx].level++;
			tree[idx].min_ = (val[tree[idx].level] - tree[idx].exp) / tree[idx].level;
			return ;
		}
		if (tree[idx].left == left && tree[idx].right == right) {
			if (value >= tree[idx].min_) {
				PushDown(idx);
				int mid = (left + right) / 2;
				update(left, mid, idx << 1, value);
				update(mid + 1, right, idx << 1 | 1, value);
				PushUp(idx);
			} else {
				tree[idx].exp += tree[idx].level * value;
				tree[idx].min_ -= value;
				tree[idx].lazy += value;
			}
			return ;
		}
		int mid = tree[idx].mid();
		if (tree[idx].lazy)
			PushDown(idx);
		if (mid >= right)
			update(left, right, idx << 1, value);
		else if (mid < left)
			update(left, right, idx << 1 | 1, value);
		else {
			update(left, mid, idx << 1, value);
			update(mid + 1, right, idx << 1 | 1, value);
		}
		PushUp(idx);
	}

	int query(int left, int right, int idx) {
		if (tree[idx].left == left && tree[idx].right == right) 
			return tree[idx].exp;
		if (tree[idx].lazy)
			PushDown(idx);
		int mid = tree[idx].mid();
		if (mid >= right)
			return query(left, right, idx << 1);
		else if (mid < left) 
			return query(left, right, idx << 1 | 1);
		else 
			return std::max(query(left, mid, idx<<1), query(mid+1, right, idx<<1|1));
	}
};

SegmentTree seg;

int main() {
	int test, n, k, q, left, right, value;
	char ch[111];
	scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++) {
		scanf("%d %d %d", &n, &k, &q);
		for (int i = 1; i < k; i++)
			scanf("%d", &val[i]);
		val[k] = inf;
		printf("Case %d:\n", cas);
		seg.build(1, n, 1);
		for (int qq = 1; qq <= q; qq++) {
			scanf("%s", ch);
			if (ch[0] == 'W') {
				scanf("%d %d %d", &left, &right, &value);
				seg.update(left, right, 1, value);
			} else {
				scanf("%d %d", &left, &right);
				printf("%d\n", seg.query(left, right, 1));
			}
		}
		puts("");
	}
	return 0;
}