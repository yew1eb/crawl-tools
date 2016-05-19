#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;

const int MAX = 2010;
typedef __int64 LL;
int z[MAX], y[MAX], cntz, cnty;
struct point{                // ä¸ç»´ç¹çå®ä¹ 
    int x, y, z;
    void get()
    {
        scanf("%d%d%d", &x, &y, &z);
    }
};
struct Tnode{                // ä¸ç»´çº¿æ®µæ  
    int l,r,cover, once, twice, len;
    int mid() { return MID(l,r);}
    bool in(int ll,int rr) { return l >= ll && r <= rr; }
    void lr(int ll,int rr){ l = ll; r = rr;}
};
struct box{                    // é¿æ¹ä½å®ä¹ 
    point a, b;
};
struct Sline{int x,y1,y2,flag;};    // æ«æçº¿å®ä¹ 

Tnode node[MAX<<2];
box bo[MAX];
Sline l[MAX];

void add_line(int x1,int y1,int x2,int y2,int &cnt)
{
    l[cnt].x = x1; l[cnt].y1 = y1; l[cnt].y2 = y2;
    l[cnt++].flag = 1;
    l[cnt].x = x2; l[cnt].y1 = y1; l[cnt].y2 = y2;
    l[cnt++].flag = -1;
}
bool cmp(Sline a, Sline b)
{
    if( a.x == b.x )
        return a.flag > b.flag;
    return a.x < b.x;
}
void Build(int t,int l,int r)
{
    node[t].lr(l, r);
    node[t].cover = node[t].once = node[t].twice = node[t].len = 0;
    if( node[t].l == node[t].r - 1 )
        return ;
    int mid = MID(l,r);
    Build(L(t),l,mid);
    Build(R(t),mid,r);
}
void Updata_len(int t)
{
    if( node[t].cover >= 3 )
    {
        node[t].once = node[t].twice = 0;
        node[t].len = y[node[t].r] - y[node[t].l];
        return ;
    }
    if( node[t].cover == 2 )
    {
        if( node[t].l == node[t].r - 1 )
        {
            node[t].twice = y[node[t].r] - y[node[t].l];
            node[t].len = node[t].once = 0;
        }
        else
        {
            node[t].once = 0;
            node[t].len = node[R(t)].len + node[L(t)].len + node[R(t)].once + node[L(t)].once + 
                node[L(t)].twice + node[R(t)].twice;
            node[t].twice = y[node[t].r] - y[node[t].l] - node[t].len;
        }
        return ;
    }
    if( node[t].cover == 1 )
    {
        if( node[t].l == node[t].r - 1 )
        {
            node[t].len = node[t].twice = 0;
            node[t].once = y[node[t].r] - y[node[t].l];
        }
        else
        {
            node[t].len = node[R(t)].len + node[L(t)].len + node[L(t)].twice + node[R(t)].twice;
            node[t].twice = node[L(t)].once + node[R(t)].once;
            node[t].once = y[node[t].r] - y[node[t].l] - node[t].len - node[t].twice;
        }
        return ;    
    }
    if( node[t].cover == 0 )
    {
        if( node[t].l == node[t].r - 1 )
            node[t].len = node[t].once = node[t].twice = 0;
        else
        {
            node[t].len = node[R(t)].len + node[L(t)].len;
            node[t].once = node[R(t)].once + node[L(t)].once;
            node[t].twice = node[R(t)].twice + node[L(t)].twice;
        }
        return ;
    }
}
void Updata(int t, Sline p)
{
    if( y[node[t].l] >= p.y1 && y[node[t].r] <= p.y2 )
    {
        node[t].cover += p.flag;
        Updata_len(t);
        return ;
    }
    if( node[t].l == node[t].r - 1 ) return ;
    int mid = node[t].mid();
    if( p.y1 < y[mid] ) Updata(L(t), p);
    if( p.y2 > y[mid] ) Updata(R(t), p);
    Updata_len(t);
}
LL solve(int n)
{
    sort(y, y+cnty);
    sort(z, z+cntz);
    cnty = unique(y, y+cnty) - y;
    cntz = unique(z, z+cntz) - z;
    
    LL ans = 0;
    
    Build(1, 0, cnty-1);
    FOR(i, 0, cntz-1)
    {
        LL area = 0;
        int cnt = 0;
        FOR(k, 0, n)
            if( bo[k].a.z <= z[i] && bo[k].b.z > z[i] )
                add_line(bo[k].a.x, bo[k].a.y, bo[k].b.x, bo[k].b.y, cnt);

        sort(l, l+cnt, cmp);
        
        Updata(1, l[0]);
        FOR(k, 1, cnt)
        {
            area += node[1].len *1ll* (l[k].x - l[k-1].x);    // æ³¨æè¿ç¹ï¼ä¸ä¹1llä¼WAãã 
            Updata(1, l[k]);
        }
        ans += area * (z[i+1] - z[i]);
    }
    return ans;
}

int main()
{
    int ncases, ind = 1, n;
    
    scanf("%d", &ncases);
    
    while( ncases-- )
    {
        scanf("%d", &n);
        cntz = cnty = 0;
        FOR(i, 0, n)
        {
            bo[i].a.get();
            bo[i].b.get();
    
            y[cnty++] = bo[i].a.y;    // ç¦»æ£å y åæ  
            y[cnty++] = bo[i].b.y;
            
            z[cntz++] = bo[i].a.z;    // ç¦»æ£å z åæ  
            z[cntz++] = bo[i].b.z;
        }
        
        LL ans = solve( n );
        printf("Case %d: %I64d\n", ind++, ans);
    }
return 0;
}
