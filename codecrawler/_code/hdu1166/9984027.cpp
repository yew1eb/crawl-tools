#include <cstdio>
#include <cstring>
using namespace std;

#define LL(x) ((x)<<1)
#define RR(x) ((x)<<1|1)
const int maxn = 55555;
struct point
{
    int l, r;
    int sum;
    int mid(){
        return (l+r)>>1;
    }
}tree[maxn*4];
int num[maxn];

void build(int rt, int l, int r) 
{
    tree[rt].l = l;
    tree[rt].r = r;
    if(tree[rt].l == tree[rt].r) {
        tree[rt].sum = num[l];
        return;
    }
    int mid = (tree[rt].l+tree[rt].r)>>1;
    build(LL(rt), l, mid);
    build(RR(rt), mid+1, r);
    tree[rt].sum = tree[LL(rt)].sum + tree[RR(rt)].sum;
}
void update(int rt, int pos, int val) 
{
    if(tree[rt].l == tree[rt].r) {
        tree[rt].sum +=val;
        return;
    }
    int mid = (tree[rt].l+tree[rt].r)>>1;
    if(pos<=mid) update(LL(rt), pos, val);
    else   update(RR(rt), pos, val);
    tree[rt].sum = tree[LL(rt)].sum + tree[RR(rt)].sum;
}

int query(int rt, int l, int r) 
{
    if(l <= tree[rt].l && r >= tree[rt].r) 
        return tree[rt].sum;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    int ret = 0;
    if(l <= mid) ret  += query(LL(rt), l, r);
    if( r > mid) ret += query(RR(rt), l, r);
    return ret;
}
int main()
{
    int T, n, i, a, b, val;
    char str[10];
    scanf("%d",&T);
    for(int cas = 1; cas<=T; ++cas) {
        scanf("%d",&n);
        for(i=1; i<=n; ++i) scanf("%d",&num[i]);
        build(1,1,n);
        printf("Case %d:\n", cas);
        while(1)
        {
            scanf("%s",str);
            if(str[0]=='E') break;
            if(str[0]=='Q'){
                scanf("%d%d",&a,&b);
                printf("%d\n",query(1,a,b));
            } 
            else if(str[0]=='A') {
                scanf("%d%d",&a,&val);
                update(1,a,val);
            }
            else if(str[0]=='S') {
                scanf("%d%d",&a,&val);
                update(1,a,-val);
            }
        }
    }
}
