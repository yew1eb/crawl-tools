//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
#define root 1,1,n

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int MAXN=100010;
const int MAXE=2000005;

struct Edge
{
    int to, from;
    Edge () {}
    Edge ( int to , int from) : to (to) , from (from) {}
} ;

struct Node* null ;

struct Node
{
    Node* c[2] ;
    Node* f ;
    bool flip ;
    int minv , val ;
    int eidx , idx ;
    void newnode ( int v , int i )
    {
        c[0] = c[1] = f = null ;
        minv = val = v ;
        eidx = idx = i ;
        flip = 0 ;
    }
    void rev ()
    {
        if ( this == null ) return ;
        swap ( c[0] , c[1] ) ;
        flip ^= 1 ;
    }
    void up ()
    {
        if ( this == null ) return ;
        if ( val <= c[0]->minv && val <= c[1]->minv )
        {
            minv = val ;
            eidx = idx ;
        }
        else if ( c[0]->minv <= c[1]->minv && c[0]->minv <= val )
        {
            minv = c[0]->minv ;
            eidx = c[0]->eidx ;
        }
        else
        {
            minv = c[1]->minv ;
            eidx = c[1]->eidx ;
        }
    }
    void down ()
    {
        if ( this == null ) return ;
        if ( flip )
        {
            c[0]->rev () ;
            c[1]->rev () ;
            flip = 0 ;
        }
    }
    bool is_root ()
    {
        return f == null || f->c[0] != this && f->c[1] != this ;
    }
    void sign_down ()
    {
        if ( !is_root () ) f->sign_down () ;
        down () ;
    }
    void setc ( Node* o , int d )
    {
        c[d] = o ;
        o->f = this ;
    }
    void rot ( int d )
    {
        Node* p = f ;
        Node* g = f->f ;
        p->setc ( c[d] , !d ) ;
        if ( !p->is_root () ) g->setc ( this , f == g->c[1] ) ;
        else f = g ;
        setc ( p , d ) ;
        p->up () ;
    }
    void splay ()
    {
        sign_down () ;
        while ( !is_root () )
        {
            if ( f->is_root () ) rot ( this == f->c[0] ) ;
            else
            {
                if ( f == f->f->c[0] )
                {
                    if ( this == f->c[0] ) f->rot ( 1 ) , rot ( 1 ) ;
                    else rot ( 0 ) , rot ( 1 ) ;
                }
                else
                {
                    if ( this == f->c[1] ) f->rot ( 0 ) , rot ( 0 ) ;
                    else rot ( 1 ) , rot ( 0 ) ;
                }
            }
        }
        up () ;
    }
    void access ()
    {
        Node* o = this ;
        for ( Node* x = null ; o != null ; x = o , o = o->f )
        {
            o->splay () ;
            o->setc ( x , 1 ) ;
            o->up () ;
        }
        splay () ;
    }
    void make_root ()
    {
        access () ;
        rev () ;
    }
    void link ( Node* o )
    {
        make_root () ;
        f = o ;
    }
    void cut ()
    {
        access () ;
        c[0] = c[0]->f = null ;
        up () ;
    }
    void cut ( Node* o )
    {
        make_root () ;
        o->cut () ;
    }
    int get_min ( Node* o )
    {
        make_root () ;
        o->access () ;
        return o->eidx ;
    }
} ;

Node pool[MAXN+MAXE];
Node* cur;
Node* node[MAXN];
Node* edge[MAXE];

Edge E[MAXE+MAXN];

int U[MAXE],V[MAXE];
int n,idx;
ll ans;
ll dp[MAXN];

vector<int> g[MAXN];

void init(int n)
{
    idx=0,ans=0;
    cur=pool;
    cur->newnode(INF,-1);
    null=cur++;
    for(int i=1;i<=n;i++)
    {
        cur->newnode(INF,-1);
        node[i]=cur++;
    }
}

void addedge(int u,int v)
{
    int eidx=node[u]->get_min(node[v]);
    if(E[eidx].from >= u) return;
    U[idx]=u;
    V[idx]=v;
    cur->newnode(u,idx);
    edge[idx]=cur;
    E[idx]=Edge(v,u);
    edge[eidx]->cut(node[U[eidx]]);
    edge[eidx]->cut(node[V[eidx]]);
    edge[idx]->link(node[u]);
    edge[idx]->link(node[v]);
    ans+=u-E[eidx].from;
    idx++;cur++;
}

void init()
{
    init(100000);
    for(int i=2;i<=100000;i++)
    {
        g[i].pb(1); 
        for(int j=i+i;j<=100000;j+=i)
            g[j].pb(i);
    }

    int sz;
    for(int i=2;i<=100000;i++)
    {
        sz=g[i].size();
        U[idx]=g[i][sz-1];
        V[idx]=i;
        cur->newnode(g[i][sz-1],idx);
        edge[idx]=cur;
        E[idx]=Edge(i,g[i][sz-1]);
        edge[idx]->link(node[g[i][sz-1]]);
        edge[idx]->link(node[i]);
        ans+=g[i][sz-1];
        idx++;cur++;
        for(int j=sz-2;j>=0;j--)
            addedge(g[i][j],i);
        dp[i]=ans;
    }
}

int main()
{
    init();
    int m;
    while(~scanf("%d",&m))
        printf("%lld\n",dp[m]);
    return 0;
} 