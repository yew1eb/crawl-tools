#include <stdio.h>
#include <string.h>

const int maxn = 50000 + 5;
int SUM[maxn<<4];
int num[maxn];

void PushUp(int rt)
{
    SUM[rt] = SUM[rt<<1] + SUM[rt<<1|1];
}
void build(int rt, int l, int r)
{
    if(l == r)
    {
        SUM[rt] = num[l];
        return ;
    }
    int m = (l+r)>>1;
    build(rt<<1, l, m);
    build(rt<<1|1, m+1, r);
    PushUp(rt);
}

void update(int rt, int l, int r, int p, int v)
{
    if(l == r)
    {
        SUM[rt] += v;
        return ;
    }
    int m = (l+r)>>1;
    if(p<=m) update(rt<<1, l, m, p, v);
    if(p>m) update(rt<<1|1, m+1, r, p, v);
    PushUp(rt);
}

int query(int rt, int l, int r, int L, int R)
{
    if(L<=l && r<=R)
    {
        return SUM[rt];
    }

    int m = (l+r)>>1;
    int ret = 0;
    if(L<=m) ret += query(rt<<1, l, m, L, R);
    if(R>m)  ret += query(rt<<1|1, m+1, r, L, R);
    return ret;
}
int main()
{
    int t, i, n, a, b;
    scanf("%d", &t);
    for(int cas=1; cas<=t; ++cas)
    {
        printf("Case %d:\n", cas);
        scanf("%d", &n);
        for(i=1; i<=n; ++i) scanf("%d", &num[i]);
        build(1, 1, n);
        char cmd[10];
        while(scanf("%s", cmd))
        {
            if(cmd[0]=='E') break;
            scanf("%d%d", &a, &b);
            if(cmd[0] == 'Q')
            {
                int ret = query(1, 1, n, a, b);
                printf("%d\n", ret);
            }
            else if(cmd[0] =='S')
            {
                update(1, 1, n, a, -b);
            }
            else if(cmd[0]=='A')
            {
                update(1, 1, n, a, b);
            }
        }
    }
    return 0;
}
