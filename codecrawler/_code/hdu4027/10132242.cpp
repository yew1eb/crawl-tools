#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100100;
typedef long long LL;
struct node {
    int l, r;
    LL sum;
    bool flag;
} tree[maxn*4];
LL num[maxn];

void PushUp(int rt)
{
    tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
    tree[rt].flag = (tree[rt<<1].flag && tree[rt<<1|1].flag);
}
void build(int rt, int l, int r)
{
    tree[rt].l = l, tree[rt].r = r;
    if(l == r) {
        tree[rt].sum = num[l];
        if(tree[rt].sum <=1) tree[rt].flag = true;
        else tree[rt].flag = false;
        return ;
    }
    int m = (l + r) >>1;
    build(rt<<1, l, m);
    build(rt<<1|1, m+1, r);
    PushUp(rt);
}
void update(int rt, int l, int r)
{
    if(tree[rt].l == l && tree[rt].r == r)
    {
        if(tree[rt].flag) return  ;
        if(tree[rt].l == tree[rt].r)
        {
            tree[rt].sum = (LL)sqrt(tree[rt].sum);
            if(tree[rt].sum <= 1)
                tree[rt].flag  = true;
            return ;
        }
    }
    int m  = (tree[rt].l + tree[rt].r ) >>1;
    if( r <= m) update(rt<<1, l, r);
    else if(l > m) update(rt<<1|1, l, r);
    else
    {
        update(rt<<1, l, m);
        update(rt<<1|1, m+1, r);
    }
    PushUp(rt);
}
LL query(int rt, int l, int r)
{
    if(l == tree[rt].l && tree[rt].r == r) {
        return tree[rt].sum;
    }
    int m = (tree[rt].l + tree[rt].r) >>1;
    if(r <= m)  return query(rt<<1, l, r);
    else if( l > m) return query(rt<<1|1, l, r);
    else return query(rt<<1, l, m) + query(rt<<1|1, m+1, r);
}
int main()
{
    int i, n, m;
    int tp, a, b;
    int cas = 1;
    //freopen("d:\\in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF) {
        for(i=1; i<=n; ++i) scanf("%I64d",&num[i]);
        build(1,1,n);
        scanf("%d",&m);
        printf("Case #%d:\n",cas++);
        while(m--) {
            scanf("%d%d%d",&tp,&a,&b);
            if(a>b) swap(a,b);
            if(tp==0) {
                update(1,a,b);
            } else {
                printf("%I64d\n",query(1,a,b) );
            }
        }
        printf("\n");
    }
    return 0;
}
