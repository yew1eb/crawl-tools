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
#define BUG puts("here!!!")

using namespace std;

const int MAX = 100010;
struct Tnode{
    int l,r,lb,rb,lw,rw,sb,sw,sum;bool t;short cover;
    int mid() { return MID(l,r);}
    int len() { return r - l;}
    bool in(int ll,int rr) { return l >= ll && r <= rr; }
    void lr(int ll,int rr){ l = ll; r = rr;}
};
Tnode node[MAX*3];
bool aa[MAX];
void init()
{
    memset(aa,false,sizeof(aa));
    memset(node,0,sizeof(node));
}
void Updata_len(int t)
{
    node[t].sum = node[t].len() - node[t].sum;
}
void Swap(int t)
{
    swap(node[t].rw,node[t].rb);
    swap(node[t].lw,node[t].lb);
    swap(node[t].sw,node[t].sb);
}
void Updata_wb(int t,int v1,int v2)
{
    node[t].rb = node[t].lb = node[t].sb = v1;
    node[t].rw = node[t].lw = node[t].sw = v2;
    node[t].sum = v1;
}
void Updata_cover(int t)
{
    if( node[t].cover == 1 )
    {
        Updata_wb(L(t), 0, node[L(t)].len());
        Updata_wb(R(t), 0, node[R(t)].len());
    }
    else
    {
        Updata_wb(L(t), node[L(t)].len(), 0);
        Updata_wb(R(t), node[R(t)].len(), 0);
    }
}
void Pushdown_len(int t)
{
    if( node[t].cover > 0 && node[t].len() != 1 )
    {
        node[R(t)].cover = node[L(t)].cover = node[t].cover;
        Updata_cover(t);
        node[L(t)].t = node[R(t)].t = 0;
    }
    node[t].cover = 0;
}
void Updata_sum(int t)
{
    node[t].lw = node[L(t)].lw + ( node[L(t)].lw == node[L(t)].len() ? node[R(t)].lw : 0 );
    node[t].rw = node[R(t)].rw + ( node[R(t)].rw == node[R(t)].len() ? node[L(t)].rw : 0 );
    node[t].sw = max(node[R(t)].sw, max(node[L(t)].sw, node[L(t)].rw + node[R(t)].lw));
    node[t].lb = node[L(t)].lb + ( node[L(t)].lb == node[L(t)].len() ? node[R(t)].lb : 0 );
    node[t].rb = node[R(t)].rb + ( node[R(t)].rb == node[R(t)].len() ? node[L(t)].rb : 0 );
    node[t].sb = max(node[R(t)].sb, max(node[L(t)].sb, node[L(t)].rb + node[R(t)].lb));    
    node[t].sum = node[L(t)].sum + node[R(t)].sum;
}             
void Pushdown_xor(int t)
{
    if( node[t].len() == 1 )
    {
        node[t].t = 0;
        return ;
    }
    if( node[t].t )
    {
        node[R(t)].t = !node[R(t)].t;
        node[L(t)].t = !node[L(t)].t;
        Swap(R(t)); Swap(L(t));
        Updata_len(R(t)); Updata_len(L(t));
        node[t].t = !node[t].t;
    }
}
void Build(int t,int l,int r)
{
    node[t].lr(l,r);
    if( node[t].len() == 1 )
    {
        node[t].sum = node[t].lb = node[t].rb = node[t].sb = aa[l];
        node[t].lw = node[t].rw = node[t].sw = 1 - aa[l];
        return ;
    }
    int mid = MID(l,r);
    Build(L(t),l,mid);
    Build(R(t),mid,r);
    Updata_sum(t);
}
void Updata(int t,int l,int r,int val)
{
    Pushdown_len(t);
    Pushdown_xor(t);
    if( node[t].in(l,r) )
    {
        if( val != 3 )
        {
            node[t].cover = val;
            if( node[t].cover == 1 )
                Updata_wb(t, 0, node[t].len());
            else
                Updata_wb(t, node[t].len(), 0);
            return ;
        }
        else
        {
            node[t].t = !node[t].t;
            Swap(t);
            Updata_len(t);
            return ;
        }
    }
    if( node[t].len() == 1 ) return ;
    int mid = MID(node[t].l,node[t].r);
    if( l < mid )  Updata(L(t), l, r, val);
    if( r > mid )  Updata(R(t), l, r, val);
    Updata_sum(t);
}

int Query_nor(int t,int l,int r)
{
    Pushdown_len(t);
    Pushdown_xor(t);
    if( node[t].in(l,r) ) return node[t].sum;
    if( node[t].len() == 1 ) return 0;
    int mid = node[t].mid();
    int ans = 0;
    if( l < mid )  ans += Query_nor(L(t),l,r);
    if( r > mid )  ans += Query_nor(R(t),l,r);
    Updata_sum(t);
    return ans;
}

int Query_xor(int t,int l,int r)
{
    Pushdown_len(t);
    Pushdown_xor(t);
    if( node[t].in(l,r) ) return node[t].sb;
    if( node[t].len() == 1 ) return 0;
    int mid = node[t].mid();
    int ans = 0;
    if( l >= mid )
        ans = max(ans,Query_xor(R(t),l,r));
    else
        if( r <= mid )
            ans = max(ans,Query_xor(L(t),l,r));
        else
        {
            ans = max(ans, Query_xor(L(t), l, mid));
            ans = max(ans, Query_xor(R(t), mid, r));
            int a = ( node[L(t)].rb <= mid - l ? node[L(t)].rb : mid - l);
            int b = ( node[R(t)].lb <= r - mid ? node[R(t)].lb : r - mid);
            ans = max(ans, a+b);
        }
    Updata_sum(t);
    return ans;
}

int main()
{
    int n,m,ncases,a,b,ind;
    
    scanf("%d",&ncases);
    
    while( ncases-- )
    {
        init();
        scanf("%d%d",&n,&m);
        
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a);
            if( a ) aa[i] = 1;
        }
        Build(1,0,n);
        while( m-- )
        {
            scanf("%d%d%d",&ind,&a,&b);
            
            if( ind == 0 ) Updata(1,a,b+1,1);     
            if( ind == 1 ) Updata(1,a,b+1,2);
            if( ind == 2 ) Updata(1,a,b+1,3);
            if( ind == 3 )
            {
                int ans = Query_nor(1,a,b+1);
                printf("%d\n",ans);
            }
            if( ind == 4 )
            {
                int ans = Query_xor(1,a,b+1);
                printf("%d\n",ans);
            }
        }
    }
return 0;
}
