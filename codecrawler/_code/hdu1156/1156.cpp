#include <stdio.h>
#include <string.h>

#define MAX 100005
#define NODE_NUM 450000

struct node {
	int l, r;
	int val;
};

node tree[NODE_NUM];
int m;
int ans[MAX];

void buildTree(int l, int r, int n) {
	tree[n].l = l;
	tree[n].r = r;
	tree[n].val = 0;

	if (l == r)
		return ;

	int mid = (l + r)>>1;
	buildTree(l, mid, n<<1);
	buildTree(mid + 1, r, n<<1|1);
}

void query(int l, int r, int n) {
	if (tree[n].l == l && tree[n].r == r) {
		tree[n].val++;
		return ;
	} else {
		int mid = (tree[n].l + tree[n].r)>>1;
		if (r <= mid) {
			query(l, r, n<<1);
		} else if (l > mid) {
			query(l, r, n<<1|1);
		} else {
			query(l, mid, n<<1);
			query(mid + 1, r, n<<1|1);
		}
	}
}

void getResult(int n) {
	if (tree[n].l == tree[n].r) {
		ans[m] = tree[n].val;
		++m;

		return ;
	} else {
		tree[n<<1].val += tree[n].val;
		tree[n<<1|1].val += tree[n].val;

		getResult(n<<1);
		getResult(n<<1|1);
	}
}

int main() {
	int n;
	int a, b;
	int i;

	while (scanf("%d", &n) == 1 && n) {
		m = 0;
		buildTree(1, n, 1);

		for (i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			query(a, b, 1);
		}

		getResult(1);
		printf("%d", ans[0]);
		for (i = 1; i < m; i++) {
			printf(" %d", ans[i]);
		}
		printf("\n", m);
	}

	return 0;
}