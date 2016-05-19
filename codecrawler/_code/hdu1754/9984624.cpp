#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)

const int maxn = 200005;
struct node 
{
    int l, r;
    int Max;
}tree[maxn*4];
int num[maxn];
void build(int rt, int l, int r) 
{
    tree[rt].l = l;
    tree[rt].r = r;
    if(tree[rt].l == tree[rt].r) {
        tree[rt].Max = num[l];
        return ;
    }
    int mid = (tree[rt].l + tree[rt].r)>>1;
    build(LL(rt), l, mid);
    build(RR(rt), mid+1, r);
    tree[rt].Max = max(tree[LL(rt)].Max, tree[RR(rt)].Max);
}
void update(int rt, int pos, int val) {
    if(tree[rt].l == tree[rt].r) {
        tree[rt].Max = val;
        return ;
    }
    int mid = (tree[rt].l + tree[rt].r)>>1;
    if(pos <=mid) update(LL(rt), pos, val);
    else update(RR(rt), pos, val);
    tree[rt].Max = max(tree[LL(rt)].Max, tree[RR(rt)].Max);
}
int query(int rt, int l, int r) {
    if(l <= tree[rt].l && r >= tree[rt].r) {
        return tree[rt].Max;
    }
    int mid = (tree[rt].l + tree[rt].r)>>1;
    int ret = 0;
    if(l <= mid) ret =max(ret, query(LL(rt), l, r) );
    if(r > mid ) ret =max(ret, query(RR(rt), l, r) );
    return ret;
}
int main()
{
    int n, m, i, a, b, val;
    while(scanf("%d%d",&n,&m)!=EOF) 
    {
        for(i=1; i<=n; ++i) scanf("%d",&num[i]);
        build(1,1,n);
        char op[10];
        while(m--)
        {
            scanf("%s",op);
            if(op[0]=='Q') {
                scanf("%d%d",&a,&b);
                printf("%d\n", query(1,a,b));
            }
            else if(op[0]=='U') {
                scanf("%d%d",&a,&val);
                update(1,a,val);
            }
        }
    }
    return 0;
}

