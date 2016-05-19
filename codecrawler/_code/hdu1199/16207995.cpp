#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#define MID(x,y) ((x+y)>>1)
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )

using namespace std;

const int MAX = 4010;
int x[MAX];
struct Tnode{int l,r;int col;};
struct NODE{int x,y;bool col;};
NODE nn[MAX];
Tnode node[MAX*4];
int col[MAX];
void init()
{
    memset(col,0,sizeof(col));
    memset(nn,0,sizeof(nn));
    memset(node,0,sizeof(node));
}

void Build(int t,int l,int r)
{
    if( l >= r ) return ;
    node[t].l = l; node[t].r = r;
    node[t].col = 0;
    if( l == r - 1 ) return ;
    int mid = MID(l,r);
    Build(L(t),l,mid);
    Build(R(t),mid,r);
}

void Updata(int t,int l,int r,int col)
{
    if( l >= r ) return ;
    if( node[t].l == l && node[t].r == r )
    {
        node[t].col = col;
        return ;
    }
    if( node[t].col >= 0 && node[t].col != col )
    {
        node[R(t)].col = node[L(t)].col = node[t].col;
        node[t].col = -1;
    }
    int mid = MID(node[t].l,node[t].r);
    if( l >= mid )
        Updata(R(t),l,r,col);
    else
        if( r <= mid )
            Updata(L(t),l,r,col);
        else
        {
            Updata(L(t),l,mid,col);
            Updata(R(t),mid,r,col);
        }
}

void Query(int t,int l,int r)
{
    if( l >= r ) return ;
    if( node[t].col >= 0 )
    {
        for(int i=node[t].l; i<node[t].r; i++)
            col[i] = node[t].col;
        return ;
    }
    int mid = MID(node[t].l,node[t].r);
    if( l >= mid )
        Query(R(t),l,r);
    else
        if( r <= mid )
            Query(L(t),l,r);
        else
        {
            Query(L(t),l,mid);
            Query(R(t),mid,r);
        }
}
void solve(int *x,int cnt,int n)
{
    Build(1,0,cnt);
    for(int i=0; i<n; i++)
    {
        int xx = lower_bound(x,x+cnt,nn[i].x) - x;
        int yy = lower_bound(x,x+cnt,nn[i].y) - x;
        Updata(1,xx,yy,nn[i].col);    
    }
    Query(1,0,cnt);
    int s = 0,e = 0,te,ts;
    int mmax = 0;
    x[cnt] = 0; x[cnt] = x[cnt-1];
    for(int i=0; i<cnt; i++)
    {
        if( col[i] != 1 ) continue;
        ts = x[i];
        while( col[i] == 1 )
            i++;
        if( i > cnt ) break;
        te = x[i];
        if( te - ts > e - s )
        {
            e = te;
            s = ts;
        }
    }
    if( s == e )
        printf("Oh, my god\n");
    else
        printf("%d %d\n",s,e-1);
}

int main()
{
    int n;
    char s[5];
    while( ~scanf("%d",&n) )
    {
        init();
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%s",&nn[i].x,&nn[i].y,s);
            nn[i].y++;
            x[cnt++] = nn[i].x;
            x[cnt++] = nn[i].y;
            if( s[0] == 'w' )
                nn[i].col = 1;
        }
        sort(x,x+cnt);
        cnt = unique(x,x+cnt) - x;
        solve(x,cnt,n);
    }
return 0;
}
