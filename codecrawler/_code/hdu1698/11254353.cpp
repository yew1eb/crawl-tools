#include<cstdio>

const int maxn = 100000 + 5;
int sum[maxn*4], add[maxn*4], L[maxn*4], R[maxn*4];

void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void PushDown(int rt, int len)
{
    if(add[rt]) {
        sum[rt<<1] = add[rt]*(len-(len>>1));
        sum[rt<<1|1] = add[rt]*(len>>1);
        add[rt<<1] = add[rt<<1|1] = add[rt];
        add[rt] = 0;
    }
}
void build(int rt, int l, int r)
{
    L[rt] = l, R[rt] = r;
    add[rt] = 0;
    if(l == r) {
        sum[rt] = 1;
        return ;
    }
    int mid = (l + r)>>1;
    build(rt<<1, l, mid);
    build(rt<<1|1, mid+1, r);
    PushUp(rt);
}
void update(int rt, int l, int r, int val)
{
    if(l<=L[rt] && R[rt]<=r) {
        add[rt] = val;
        sum[rt] = val*(R[rt]-L[rt]+1);
        return ;
    }
    PushDown(rt, R[rt]-L[rt]+1);
    int mid = (L[rt] + R[rt])>>1;
    if(l<=mid) update(rt<<1, l, r, val);
    if(r>mid)  update(rt<<1|1, l, r, val);
    PushUp(rt);
}
int main()
{
    int t, n, q, x, y, z;
    scanf("%d", &t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%d", &n);
        build(1, 1, n);
        scanf("%d", &q);
        while(q--) {
            scanf("%d%d%d", &x, &y, &z);
            update(1, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n",cas, sum[1]);
    }
    return 0;
}
