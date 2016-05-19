#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std ;

typedef long long LL ;

#pragma comment(linker, "/STACK:16777216")
#define Log( i , a , b ) for ( int i = a ; ( 1 << i ) <= b ; ++ i )
#define rep( i , a , b ) for ( int i = a ; i < b ; ++ i )
#define For( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define travel( e , H , u ) for ( Edge* e = H[u] ; e ; e = e -> next )
#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )

const int MAXN = 100005 ;
const int MAXE = 200005 ;
const int INF = 0x3f3f3f3f ;

struct Edge {
    int v , c ;
    Edge* next ;
} E[MAXE] , *H[MAXN] , *edge ;

struct Node {
    int dis ;
    int idx ;
    Node () {}
    Node ( int dis , int idx ) : dis ( dis ) , idx ( idx ) {}
    bool operator < ( const Node& a ) const {
        if ( dis != a.dis ) return dis < a.dis ;
        return idx < a.idx ;
    }
    bool operator > ( const Node& a ) const {
        return a < *this ;
    }
    bool operator <= ( const Node& a ) const {
        return !( a < *this ) ;
    }
    bool operator >= ( const Node& a ) const {
        return !( *this < a ) ;
    }
    Node operator + ( const int& val ) const {
        return Node ( dis + val , idx ) ;
    }
    Node operator - ( const int& val ) const {
        return Node ( dis - val , idx ) ;
    }
} node[MAXN] , S[MAXN] ;

int Q[MAXN] , head , tail ;
int vis[MAXN] ;
int Time ;
int siz[MAXN] ;
int num[MAXN] ;
int mart[MAXN] ;
int ans[MAXN] ;
int dis[MAXN] ;
int size ;
int root ;
int cnt ;
int n ;

void clear () {
    edge = E ;
    num[0] = n ;
    clr ( H , 0 ) ;
    head = tail = 0 ;
    clr ( ans , 0 ) ;
}

void addedge ( int u , int v , int c ) {
    edge->v = v ;
    edge->c = c ;
    edge->next = H[u] ;
    H[u] = edge ++ ;
}

void spfa () {
    while ( head != tail ) {
        int u = Q[head ++] ;
        if ( head == MAXN ) head = 0 ;
        vis[u] = Time - 1 ;
        travel ( e , H , u ) {
            int v = e->v ;
            Node tmp = node[u] + e->c ;
            if ( node[v] > tmp ) {
                node[v] = tmp ;
                if ( vis[v] != Time ) {
                    vis[v] = Time ;
                    Q[tail ++] = v ;
                    if ( tail == MAXN ) tail = 0 ;
                }
            }
        }
    }
}

void get_siz ( int u , int fa = 0 ) {
    siz[u] = 1 ;
    travel ( e , H , u ) {
        int v = e->v ;
        if ( v != fa && vis[v] != Time ) {
            get_siz ( v , u ) ;
            siz[u] += siz[v] ;
        }
    }
}

void get_root ( int u , int fa = 0 ) {
    num[u] = 0 ;
    travel ( e , H , u ) {
        int v = e->v ;
        if ( v != fa && vis[v] != Time ) {
            get_root ( v , u ) ;
            num[u] = max ( num[u] , siz[v] ) ;
        }
    }
    num[u] = max ( num[u] , size - siz[u] ) ;
    if ( num[u] < num[root] ) root = u ;
}

void get_dis ( int u , int val , int fa = 0 ) {
    dis[u] = val ;
    S[++ cnt] = node[u] - val ;//ä¸¢è¿Sæ°ç»
    travel ( e , H , u ) {
        int v = e->v ;
        if ( v != fa && vis[v] != Time ) {
            get_dis ( v , dis[u] + e->c , u ) ;
        }
    }
}

int search ( const Node& x ) {//äºåæ¥æ¾ï¼å¦ææ²¡ææ¾å°ç®æ ï¼åè¿åå°äºxçæå¤§çæ°çä¸æ 
    int l = 0 , r = cnt ;
    while ( l < r ) {
        int m = ( l + r + 1 ) >> 1 ;
        if ( S[m] <= x ) l = m ;
        else r = m - 1 ;
    }
    return r ;
}

void get_ans ( int u , int sign , int fa = 0 ) {
    if ( !mart[u] ) {//ä¸ºä¸æ¯martçç¹è®¡ç®è½è¢«å¶å é¢çç¹çä¸ªæ°
        int tmp = search ( Node ( dis[u] , u ) ) ;
        ans[u] += ( cnt - tmp ) * sign ;
    }
    travel ( e , H , u ) {
        int v = e->v ;
        if ( v != fa && vis[v] != Time ) {
            get_ans ( v , sign , u ) ;
        }
    }
}

void deal ( int u , int val , int sign ) {
    cnt = 0 ;
    get_dis ( u , val ) ;//å¾å°dist
    sort ( S + 1 , S + cnt + 1 ) ;
    get_ans ( u , sign ) ;//è®¡ç®è´¡ç®
}

void divide ( int u ) {//åæ²»
    get_siz ( u ) ;//å¾å°å­æ è§æ¨¡
    size = siz[u] ;
    root = 0 ;
    get_root ( u ) ;//å¯»æ¾uæå¨çå­æ çéå¿
    vis[root] = Time ;
    deal ( root , 0 , 1 ) ;//å¾å°è¯¥å­æ åææçè´¡ç®ï¼ä¸ç®¡æ¯ä¸æ¯åä¸æ£µå­æ ç
    travel ( e , H , root ) if ( vis[e->v] != Time ) deal ( e->v , e->c , -1 ) ;//å»éï¼æé¤åä¸æ£µå­æ çè´¡ç®
    travel ( e , H , root ) if ( vis[e->v] != Time ) divide ( e->v ) ;//éå½å¤ç
}

void solve () {
    int x , y , c ;
    clear () ;
    rep ( i , 1 , n ) {
        scanf ( "%d%d%d" , &x , &y , &c ) ;
        addedge ( x , y , c ) ;
        addedge ( y , x , c ) ;
    }
    For ( i , 1 , n ) {
        scanf ( "%d" , &mart[i] ) ;
        if ( mart[i] ) {
            node[i] = Node ( 0 , i ) ;
            Q[tail ++] = i ;
        } else node[i] = Node ( INF , 0 ) ;
    }
    ++ Time ;
    spfa () ;
    ++ Time ;
    divide ( 1 ) ;
    int res = 0 ;
    For ( i , 1 , n ) if ( ans[i] > res ) res = ans[i] ;
    printf ( "%d\n" , res ) ;
}

int main () {
    Time = 0 ;
    clr ( vis , 0 ) ;//ä¼å
    while ( ~scanf ( "%d" , &n ) ) solve () ;
    return 0 ;
}