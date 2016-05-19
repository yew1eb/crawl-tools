#include <cstdio>
#include <cstring>
using namespace std;

#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
const int maxn = 5005;
struct node 
{
    int l, r;
    int sum;
}tree[maxn*4];
int a[maxn];

void build(int rt, int l, int r) 
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].sum = 0;
    if(tree[rt].l == tree[rt].r) {
        return ;
    }
    int mid = (tree[rt].l + tree[rt].r)>>1;
    build(LL(rt), l, mid);
    build(RR(rt), mid+1, r);
}
void update(int rt, int pos)
{
    if(tree[rt].l == tree[rt].r) {
        tree[rt].sum += 1;
        return ;
    }
    int mid = (tree[rt].l + tree[rt].r)>>1;
    if(pos <=mid) update(LL(rt), pos);
    else update(RR(rt), pos);
    tree[rt].sum = tree[LL(rt)].sum + tree[RR(rt)].sum;
}
int  query(int rt, int l, int r) 
{
    if(l <= tree[rt].l && tree[rt].r <= r) {
        return tree[rt].sum;
    }
    int mid = (tree[rt].l + tree[rt].r)>>1;
    int ret = 0;
    if(l <= mid) ret += query(LL(rt), l, r);
    if(r > mid)  ret += query(RR(rt), l, r);
    return ret;
}
int main()
{
    int n, i, ret, sum;
    while(scanf("%d",&n)!=EOF)
    {
        build(1, 0, n-1);
        sum = 0;
        for(i=0; i<n; ++i) {
            scanf("%d",&a[i]);
            sum += query(1, a[i], n-1);
            update(1,a[i]);
        }
        ret = sum;
        for(i=0; i<n-1; ++i) {
            ret += n- a[i] - a[i] - 1;
            if(sum > ret) sum = ret;
        }
        printf("%d\n", sum);
    }
    return 0;
}
