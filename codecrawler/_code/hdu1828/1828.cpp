#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define ll __int64
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std ;

int max ( int a , int b ) { return a > b ? a : b ; }
int min ( int a , int b ) { return a < b ? a : b ; }
const int maxn = 222222 ;
int sum[maxn<<2] , cnt[maxn<<2] ;

struct Edge
{
    int l , r , h , id ;
    bool operator < ( const Edge &p ) const
    {
        return h < p.h ;
    }
}edge[maxn] ;

struct Rec
{
    int a , b , c , d ;
} rec[maxn] ;

void init ()
{
    memset ( sum , 0 , sizeof ( sum ) ) ;
    memset ( cnt , 0 , sizeof ( cnt ) ) ;
}

void build_seg ( int l , int r , int h , int id , int i )
{
    edge[i].l = l , edge[i].r = r , edge[i].h = h , edge[i].id = id ;
}

void push_up ( int l , int r , int rt )
{
    if ( cnt[rt] ) sum[rt] = r - l + 1 ;
    else if ( l == r ) sum[rt] = 0 ;
    else sum[rt] = sum[rt<<1] + sum[rt<<1|1] ;
}

void update ( int a , int b , int c , int l , int r , int rt )
{
    if ( a <= l && r <= b )
    {
        cnt[rt] += c ;
        push_up ( l , r , rt ) ;
        return ;
    }
    int m = ( l + r ) >> 1 ;
    ll ret = 0 ;
    if ( a <= m ) update ( a , b , c , lson ) ;
    if ( m < b ) update ( a , b , c , rson ) ;
    push_up ( l , r , rt ) ;
}

ll solve ( int m )
{
    init () ;
    ll ret = 0 ;
    sort ( edge + 1 , edge + m + 1 ) ;
    int i , last = 0 ;
    int l = 10001 , r = -10001 ;
    for ( i = 1 ; i <= m ; i ++ ) 
    {
        r = max ( r , edge[i].r ) ;
        l = min ( l , edge[i].l ) ;
    }
    for ( i = 1 ; i <= m ; i ++ )
    {
        update ( edge[i].l , edge[i].r - 1 , edge[i].id , l , r , 1 ) ;
        ret += abs ( last - sum[1] ) ;
        last = sum[1] ;
    }
    return ret ;
}

int main ()
{
    int n , i , j , a , b , c , d ;
    while ( scanf ( "%d" , &n ) != EOF )
    {
        ll ans = 0 ;
        for ( i = 1 ; i <= n ; i ++ )
            scanf ( "%d%d%d%d" , &rec[i].a , &rec[i].b , &rec[i].c , &rec[i].d ) ;
        int m = 0 ;
        for ( i = 1 ; i <= n ; i ++ )
        {
            m ++ ;
            build_seg ( rec[i].a , rec[i].c , rec[i].b , 1 , m ) ;
            m ++ ;
            build_seg ( rec[i].a , rec[i].c , rec[i].d , -1 , m ) ;
        }
        ans += solve ( m ) ;
        m = 0 ;
        for ( i = 1 ; i <= n ; i ++ )
        {
            m ++ ;
            build_seg ( rec[i].b , rec[i].d , rec[i].a , 1 , m ) ;
            m ++ ;
            build_seg ( rec[i].b , rec[i].d , rec[i].c , -1 , m ) ;
        }
        ans += solve ( m ) ;
        printf ( "%I64d\n" , ans ) ;
    }
}