//线段树
#include <stdio.h>

#define MAX 262145

int tmp;

typedef struct _tree
{
	int left;
	int right;
	int count;
}tree;

tree t[MAX*3];

void build_tree(int c, int left, int right)
{
	int mid;
	t[c].left = left;
	t[c].right = right;
	t[c].count = right - left + 1;
	if(left == right)return ;
	mid = (left + right)>>1;
	build_tree(2*c, left, mid);
	build_tree(2*c+1, mid+1, right);
}

void del(int c, int ki)
{
	if(t[c].left == t[c].right){
		tmp = t[c].right;
		t[c].count --;
		return;
	}
	if(ki <= t[2*c].count){	//if the left tree'count is less than ki then the ki-th min number must be at the left tree
		del(2*c, ki);
	}
	else {	//else it is at the right tree
		del(2*c+1, ki - t[2*c].count);
	}
	t[c].count --;
}

int main()
{
	int t, n, k, cas, ki;
	__int64 res;
	scanf("%d", &t);
	for(cas = 1; cas <= t; cas ++){
		scanf("%d%d", &n, &k);
		build_tree(1, 1, n);
		res = 0;
		while(k --){
			scanf("%d", &ki);
			del(1, ki);
			res += tmp;
		}
		printf("Case %d: %I64d\n", cas, res);
	}
	return 0;
}
