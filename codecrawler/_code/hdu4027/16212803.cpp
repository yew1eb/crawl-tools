#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int N=100010;
int n, m;
struct node
{
    int l, r, mid;
    int cnt, add;
    __int64 sum[8];
} a[N*4];
__int64 b[N], mx;
int mxk;

void build(int l, int r, int p)
{
    a[p].l = l;
    a[p].r = r;
    a[p].mid = (l+r)>>1;
    a[p].cnt = a[p].add = 0;
    int i;
    if(l==r)
    {
        a[p].sum[0] = b[l];
        if(b[l]==0)
        {
            for(i=1; i<=mxk; i++)
                a[p].sum[i] = 0;
            return ;
        }
        for(i=1; a[p].sum[i-1]>1; i++)
            a[p].sum[i] = sqrt((double)a[p].sum[i-1]);
        for( ;i<=mxk; i++)
            a[p].sum[i] = 1;
        return;
    }
    build(l, a[p].mid, p*2);
    build(a[p].mid+1, r, p*2+1);
    for(i=0; i<=mxk; i++)
        a[p].sum[i] = a[p*2].sum[i]+a[p*2+1].sum[i];
}

inline void down(int p)
{
    if(a[p].add!=0)
    {
        a[p*2].cnt += a[p].add;
        a[p*2].add += a[p].add;
        a[p*2+1].cnt += a[p].add;
        a[p*2+1].add += a[p].add;
        a[p].add = 0;
    }
}

void update(int l, int r, int p)
{
    if(a[p].l==l && a[p].r==r)
    {
        a[p].cnt += 1;
        a[p].add += 1;
        return;
    }

    down(p);
    if(r<=a[p].mid)
        update(l, r, p*2);
    else if(l>a[p].mid)
        update(l, r, p*2+1);
    else
    {
        update(l, a[p].mid, p*2);
        update(a[p].mid+1, r, p*2+1);
    }
}

__int64 query(int l, int r, int p)
{
    if(a[p].l==l && a[p].r==r)
    {
        if(a[p].cnt>mxk)
            a[p].cnt = mxk;
        if(a[p].cnt==mxk || a[p].l==a[p].r)
            return a[p].sum[a[p].cnt];
        down(p);
        return query(l, a[p].mid, p*2)+query(a[p].mid+1, r, p*2+1);
    }

    down(p);
    if(r<=a[p].mid)
        return query(l, r, p*2);
    else if(l>a[p].mid)
        return query(l, r, p*2+1);
    else
        return query(l, a[p].mid, p*2)+query(a[p].mid+1, r, p*2+1);
}

int main()
{
    int i, cas1, op, x, y;
    cas1=1;
    while(scanf("%d", &n)!=EOF)
    {
        mx = 0;
        for(i=1; i<=n; i++)
        {
            scanf("%I64d", &b[i]);
            if(b[i]>mx)
                mx = b[i];
        }
        for(i=1; mx>1; i++, mx=sqrt((double)mx));
        mxk = i;

        build(1, n, 1);
        scanf("%d", &m);
        printf("Case #%d:\n", cas1++);
        while(m--)
        {
            scanf("%d%d%d", &op, &x, &y);
            if(x>y)
                swap(x, y);
            if(op==0)
                update(x, y, 1);
            else
                printf("%I64d\n", query(x, y, 1));
        }
        printf("\n");
    }

    return 0;
}
