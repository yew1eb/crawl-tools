#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;

typedef long long LL ;

#define rep( i , a , b ) for ( int i = a ; i < b ; ++ i )
#define FOR( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define rev( i , a , b ) for ( int i = a ; i >= b ; -- i )
#define travel( e , H , u ) for ( Edge* e = H[u] ; e ; e = e -> next )
#define clr( a , x ) memset ( a , x , sizeof a )
#define CPY( a , x ) memcpy ( a , x , sizeof a )

const int MAXN = 30005 ;
const int MAXE = 200005 ;
const int INF = 0x3f3f3f3f ;

struct Edge {
    int v , c ;
    Edge* next ;
} E[MAXE] , *H[MAXN] , *edge ;

struct Node {
    int num , v , c ;
    Node () {}
    Node ( int num , int v , int c ) : num ( num ) , v ( v ) , c ( c ) {}
    bool operator < ( const Node& a ) const {
        return num < a.num ;
    }
} T[MAXN] ;

struct Shortest_Path {
    Edge E[MAXE] , *H[MAXN] , *edge ;
    int Q[MAXN] , head , tail ;
    int d[MAXN] ;
    bool vis[MAXN] ;
    int n ;
    
    void clear () {
        edge = E ;
        clr ( H , 0 ) ;
    }
    
    void Addedge ( int u , int v , int c ) {
        edge -> v = v ;
        edge -> c = c ;
        edge -> next = H[u] ;
        H[u] = edge ++ ;
    }
    
    void spfa ( int s ) {
        clr ( d , INF ) ;
        clr ( vis , 0 ) ;
        head = tail = 0 ;
        d[s] = 0 ;
        Q[tail ++] = s ;
        while ( head != tail ) {
            int u = Q[head ++] ;
            if ( head == MAXN ) head = 0 ;
            vis[u] = 0 ;
            travel ( e , H , u ) {
                int v = e -> v , c = e -> c ;
                if ( d[v] > d[u] + c ) {
                    d[v] = d[u] + c ;
                    if ( !vis[v] ) {
                        vis[v] = 1 ;
                        if ( d[v] < d[Q[head]] ) {
                            if ( head == 0 ) head = MAXN ;
                            Q[-- head] = v ;
                        } else {
                            Q[tail ++] = v ;
                            if ( tail == MAXN ) tail = 0 ;
                        }
                    }
                }
            }
        }
    }

    void build_tree () ;
} S ;

bool vis[MAXN] ;
int siz[MAXN] ;
int num[MAXN] ;
int cnt[MAXN] ;
int dp[MAXN] ;
int G[MAXN] ;
int F[MAXN] ;

int ans1 , ans2 ;
int node_num ;
int n , K ;
int root ;

void clear () {
    S.n = n ;
    edge = E ;
    num[0] = n ;
    S.clear () ;
    clr ( H , 0 ) ;
    clr ( vis , 0 ) ;
    ans1 = ans2 = 0 ;
}

void addedge ( int u , int v , int c ) {
    edge -> v = v ;
    edge -> c = c ;
    edge -> next = H[u] ;
    H[u] = edge ++ ;
}

void get_siz ( int u , int fa = 0 ) {
    siz[u] = 1 ;
    travel ( e , H , u ) {
        int v = e -> v ;
        if ( !vis[v] && v != fa ) {
            get_siz ( v , u ) ;
            siz[u] += siz[v] ;
        }
    }
}

void get_root ( int u , int fa = 0 ) {
    num[u] = 0 ;
    travel ( e , H , u ) {
        int v = e -> v ;
        if ( !vis[v] && v != fa ) {
            get_root ( v , u ) ;
            num[u] = max ( num[u] , siz[v] ) ;
        }
    }
    num[u] = max ( num[u] , node_num - siz[u] ) ;
    if ( num[u] < num[root] ) root = u ;
}

int get_num ( int u , int fa = 0 , int d = 0 ) {
    int res = 0 ;
    travel ( e , H , u ) {
        int v = e -> v ;
        if ( !vis[v] && v != fa ) res = max ( res , get_num ( v , u , d + 1 ) ) ;
    }
    return res + 1 ;
}

void get_cnt ( int u , int fa , int k , int val ) {
    if ( k > K ) return ;
    if ( val > dp[k] ) {
        dp[k] = val ;
        cnt[k] = 1 ;
    } else if ( val == dp[k] ) cnt[k] ++ ;
    travel ( e , H , u ) {
        int v = e -> v ;
        if ( !vis[v] && v != fa ) get_cnt ( v , u , k + 1 , val + e -> c ) ;
    }
}

void tree_dfs ( int u ) {
    get_siz ( u ) ;
    root = 0 ;
    node_num = siz[u] ;
    get_root ( u ) ;
    if ( num[root] * 2 + 1 < K ) return ;//ä¼å
    int rt = root , m = 0 ;
    vis[rt] = 1 ;
    travel ( e , H , rt ) {
        int v = e -> v ;
        if ( !vis[v] ) tree_dfs ( v ) ;
    }
    travel ( e , H , rt ) {
        int v = e -> v , c = e -> c ;
        if ( !vis[v] ) T[m ++] = Node ( get_num ( v ) , v , c ) ;
    }
    sort ( T , T + m ) ;
    FOR ( i , 0 , K ) F[i] = -INF , G[i] = 0 ;//
    rep ( i , 0 , m ) {
        FOR ( j , 1 , T[i].num ) dp[j] = -INF , cnt[j] = 0 ;
        get_cnt ( T[i].v , rt , 1 , T[i].c ) ;
        int N = min ( K , T[i].num ) ;
        FOR ( j , 1 , N ) {
            if ( j == K - 1 ) {
                if ( dp[j] > ans1 ) {
                    ans1 = dp[j] ;
                    ans2 = cnt[j] ;
                } else if ( dp[j] == ans1 ) ans2 += cnt[j] ;
                break ;
            }
            int tmp = K - j - 1 ;
            if ( dp[j] + F[tmp] > ans1 ) {
                ans1 = dp[j] + F[tmp] ;
                ans2 = cnt[j] * G[tmp] ;
            } else if ( dp[j] + F[tmp] == ans1 ) ans2 += cnt[j] * G[tmp] ;
        }
        FOR ( j , 1 , N ) {
            if ( dp[j] > F[j] ) {
                F[j] = dp[j] ;
                G[j] = cnt[j] ;
            } else if ( dp[j] == F[j] ) G[j] += cnt[j] ;
        }
    }
    vis[rt] = 0 ;
}

void Shortest_Path :: build_tree () {
    clr ( vis , 0 ) ;
    vis[1] = 1 ;
    FOR ( u , 1 , n ) {
        travel ( e , H , u ) {
            int v = e -> v , c = e -> c ;
            if ( !vis[v] && d[v] == d[u] + c ) {
                addedge ( u , v , c ) ;
                addedge ( v , u , c ) ;
                vis[v] = 1 ;
            }
        }
    }
}

void scanf ( int& x , char c = 0 ) {
    while ( ( c = getchar () ) < '0' || c > '9' ) ;
    x = c - '0' ;
    while ( ( c = getchar () ) >= '0' && c <= '9' ) x = x * 10 + c - '0' ;
}

void solve () {
    int u , v , c , m ;
    scanf ( n ) ; scanf ( m ) ; scanf ( K ) ;
    clear () ;
    rep ( i , 0 , m ) {
        scanf ( u ) , scanf ( v ) , scanf ( c ) ;
        S.Addedge ( u , v , c ) ;
        S.Addedge ( v , u , c ) ;
    }
    S.spfa ( 1 ) ;
    S.build_tree () ;
    tree_dfs ( 1 ) ;
    printf ( "%d %d\n" , ans1 , ans2 ) ;
}

int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    while ( T -- ) solve () ;
    return 0 ;
}