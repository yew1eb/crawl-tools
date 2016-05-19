#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int maxn = 100000 + 10;
struct node {
    int l, r;
    LL sum, fibsum;
    int lazy;
} tree[maxn*4];

LL f[100];
void calc_fib()
{
    int i;
    f[0] = f[1] = 1;
    for(i=2; i<=91; ++i) f[i] = f[i-1] + f[i-2];
}

LL Find(LL x)
{
    int t = lower_bound(f, f+92, x) - f;
    LL k;
    if(t==0) k = 1;
    else {
        if(abs(f[t]- x)<abs(x-f[t-1])) k = f[t];
        else k = f[t-1];
    }
    return k;
}

void PushUp(int rt)
{
    tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
    tree[rt].fibsum = tree[rt<<1].fibsum + tree[rt<<1|1].fibsum;
}

void PushDown(int rt)
{
    if(tree[rt].lazy) {
        tree[rt<<1].sum = tree[rt<<1].fibsum;
        tree[rt<<1|1].sum = tree[rt<<1|1].fibsum;
        tree[rt<<1].lazy = tree[rt<<1|1].lazy = 1;
        tree[rt].lazy = 0;
    }
}
void build(int rt, int l, int r)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].sum = tree[rt].fibsum = 0;
    tree[rt].lazy = 0;
    if(l == r) {
        tree[rt].sum = 0;
        tree[rt].fibsum = 1;
        return ;
    }
    int mid = (l+r)>>1;
    build(rt<<1, l, mid);
    build(rt<<1|1, mid+1, r);
    PushUp(rt);
}

void add(int rt, int pos, LL v)
{
    if(tree[rt].l == tree[rt].r) {
        tree[rt].lazy = 0;
        tree[rt].sum += v;
        tree[rt].fibsum = Find(tree[rt].sum );
        return ;
    }
    PushDown(rt);
    int mid = (tree[rt].l + tree[rt].r)>>1;
    if(pos<= mid)   add(rt<<1, pos, v);
    else            add(rt<<1|1, pos, v);
    PushUp(rt);
}

LL sum(int rt, int l, int r)
{
    if(l <= tree[rt].l && tree[rt].r <= r) {
        return tree[rt].sum;
    }
    PushDown(rt);
    int mid = (tree[rt].l + tree[rt].r)>>1;
   /* LL ret = 0;
    if(l<=mid) ret += sum(rt<<1, l, r);
    if(r > mid) ret += sum(rt<<1|1, l, r);
    return ret;
    */
    if(r<=mid) return sum(rt<<1, l, r);
    else if(l>mid) return sum(rt<<1|1, l, r);
    else return sum(rt<<1, l, mid) + sum(rt<<1|1,mid+1, r);
}

void update(int rt, int l, int r)
{
    if(l <= tree[rt].l && tree[rt].r <= r) {
        tree[rt].lazy = 1;
        tree[rt].sum = tree[rt].fibsum;
        return ;
    }
    PushDown(rt);
    int mid = (tree[rt].l + tree[rt].r)>>1;

    if(l<=mid) update(rt<<1, l, r);
    if(r >mid) update(rt<<1|1, l, r);
    PushUp(rt);
}

int main()
{
    int n, m;
    int op, l, r;
   // freopen("in.txt","r",stdin);
    calc_fib();
    while(~scanf("%d%d", &n, &m)) {
        build(1,1,n);
        while(m--) {
            scanf("%d%d%d", &op, &l, &r);
            if(op==1) add(1, l, r);
            if(op==2) printf("%I64d\n", sum(1, l, r));
            if(op==3) update(1, l, r);
        }
    }
    return 0;
}
