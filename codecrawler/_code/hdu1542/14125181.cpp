#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 123;

double pt[maxn<<1];

struct node 
{
    int l, r, cover;
    double total;
    int mid(){ return (l+r)>>1;}
} trees[maxn<<3];

struct line 
{
    double y1, y2, x;
    int cover;
} lines[maxn<<2];

int cmp_line(const line& a, const line& b) 
{
    return a.x < b.x;
}

void build_tree(int rt, int l, int r)
{
    trees[rt].l = l; 
    trees[rt].r = r;
    trees[rt].cover = 0;
    trees[rt].total = 0.0;
    if(l == r)
        return ;
    int mid = trees[rt].mid();
    build_tree(rt<<1, l, mid);
    build_tree(rt<<1|1, mid+1, r);
}

void PushUp(int rt)
{
    if(trees[rt].cover)
        trees[rt].total = pt[trees[rt].r+1] - pt[trees[rt].l];
    else if(trees[rt].l == trees[rt].r)
        trees[rt].total = 0.0;
    else 
        trees[rt].total = trees[rt<<1].total + trees[rt<<1|1].total;
}

void update(int rt, int l, int r, int val)
{
    if(trees[rt].l >= l && trees[rt].r <= r)
    {
        trees[rt].cover += val;
        PushUp(rt);
        return ;
    }
    int mid = trees[rt].mid();
    if(r <= mid)
        update(rt<<1, l, r, val);
    else if(l > mid)
        update(rt<<1|1, l, r, val);
    else {
        update(rt<<1, l, mid, val);
        update(rt<<1|1, mid+1, r, val);
    }
    PushUp(rt);
}

int main()
{
    double x1, y1, x2, y2;
    int n, m, cas = 1;
    while(scanf("%d", &n),n)
    {
        for(int i=0; i<n; ++i) 
        {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            pt[i] = y1;
            lines[i].cover = 1;
            lines[i].x = x1;
            lines[i].y1 = y1;
            lines[i].y2 = y2;
            
            pt[i+n] = y2;
            lines[i+n].cover = -1;
            lines[i+n].x = x2;
            lines[i+n].y1 = y1;
            lines[i+n].y2 = y2;
        }
        m = 2*n;
        sort(pt, pt+m);
        int tol = 1;
        for(int i=1; i<m; ++i) 
        {
            if(pt[i-1]!=pt[i])
                pt[tol++] = pt[i];
        }
        build_tree(1, 0, tol-1);
        sort(lines, lines+m, cmp_line);

        double ans = 0;
        int yy1, yy2;
        printf("Test case #%d\n", cas++);
        for(int i=0; i<m; ++i) 
        {
            yy1 = lower_bound(pt, pt+tol, lines[i].y1) - pt;
            yy2 = lower_bound(pt, pt+tol, lines[i].y2) - pt;
            yy2--;
            if(i>0 && lines[i].x > lines[i-1].x) {
                ans += trees[1].total*(lines[i].x-lines[i-1].x);
            }
            update(1, yy1, yy2, lines[i].cover);
        }
        printf("Total explored area: %.2f\n\n", ans);
    }
    return 0;
}
