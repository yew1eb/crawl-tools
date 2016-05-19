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

const int MAX = 110;
const int MAXM = 1005;
const int inf = 10000000;
struct Tnode{
    int l,r,val;
    int getlen() { return r - l;}
    int getmid() { return MID(l,r);}
    void lr(int ll,int rr){ l = ll; r = rr;}
};
struct T2node
{ 
    int l,r;
    Tnode son[MAXM<<2];
    int getlen() { return r - l;}
    int getmid() { return MID(l,r);}
    void lr(int ll,int rr){ l = ll; r = rr;}
    
};
T2node node[MAX<<2];
void init()
{
    memset(node,0,sizeof(node));
}
void sub_build(int f,int t,int l,int r)
{
    node[f].son[t].lr(l,r); node[f].son[t].val = -inf;
    if( l == r - 1 ) return ;
    int mid = MID(l,r);
    sub_build(f,L(t),l,mid);
    sub_build(f,R(t),mid,r);
}

void Build(int t,int l1,int r1,int l2,int r2)
{
    node[t].lr(l1,r1);
    sub_build(t,1,l2,r2);
    if( l1 == r1 - 1 ) return ;
    int mid = MID(l1,r1);
    Build(L(t),l1,mid,l2,r2);
    Build(R(t),mid,r1,l2,r2);
} 

void sub_updata(int f,int t,int l,int r,int val)
{
	node[f].son[t].val = max(node[f].son[t].val,val);
    if( node[f].son[t].l >= l && node[f].son[t].r <= r ) return ;
    if( node[f].son[t].getlen() == 1 ) return ;
    int mid = node[f].son[t].getmid();
    if( l < mid ) sub_updata(f,L(t),l,r,val);
    if( r > mid ) sub_updata(f,R(t),l,r,val);
}

void Updata(int t,int l1,int r1,int l2,int r2,int val)
{
    sub_updata(t,1,l2,r2,val);
    if( node[t].l >= l1 && node[t].r <= r1 ) return ;
    if( node[t].getlen() == 1 ) return ;
    int mid = node[t].getmid();
    if( l1 < mid ) Updata(L(t),l1,r1,l2,r2,val);
    if( r1 > mid ) Updata(R(t),l1,r1,l2,r2,val);
} 
        
int sub_query(Tnode *node,int t,int l,int r)
{
    if( node[t].l >= l && node[t].r <= r )
        return node[t].val;
    if( node[t].l == node[t].r - 1 ) return -inf;
    int mid = node[t].getmid();
    int ans = -inf;
    if( l < mid )
    	ans = max(ans,sub_query(node,L(t),l,r));
    if( r >= mid )
    	ans = max(ans,sub_query(node,R(t),l,r));
    return ans;
}
 
int Query(int t,int l1,int r1,int l2,int r2)
{
    if( node[t].l >= l1 && node[t].r <= r1 )
        return sub_query(node[t].son,1,l2,r2);
    if( node[t].getlen() == 1 ) return -inf;
    int mid = node[t].getmid();
    int ans = -inf;
    if( l1 < mid )
    	ans = max(ans,Query(L(t),l1,r1,l2,r2));
    if( r1 >= mid )
    	ans = max(ans,Query(R(t),l1,r1,l2,r2));
    return ans;
}
int main()
{
    int k,h,h1,h2;
    int n = 201,m = 1001;
    char ch[5];
    double a,l,a1,a2;
    while( ~scanf("%d",&k) && k )
    {
        init();
        Build(1,100,n,0,m);
        while( k-- )
        {
            scanf("%s",ch);
            if( ch[0] == 'I' )
            {
                scanf("%d%lf%lf",&h,&a,&l);
                int aa = (int)(a*10);
                int ll = (int)(l*10);
                Updata(1,h,h+1,aa,aa+1,ll);
            }
            else
            {
                scanf("%d%d%lf%lf",&h1,&h2,&a1,&a2);
                if( h1 > h2 ) swap(h1,h2);
                if( a1 > a2 ) swap(a1,a2);
                int ans = Query(1,h1,h2+1,(int)(a1*10),(int)(a2*10)+1);
                if( ans < -1 )
                    printf("-1\n");
                else
                    printf("%.1lf\n",ans/10.0);
            }
        }
    }
return 0;
}