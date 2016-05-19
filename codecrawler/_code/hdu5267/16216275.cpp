#include <bits/stdc++.h>
using namespace std ;

typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )
#define ls T[o].Ls
#define rs T[o].Rs
#define lson rs , T[o].l , m
#define rson ls , m + 1 , T[o].r
#define mid ( ( T[o].l + T[o].r ) >> 1 )

const int MAXN = 10005 ;
const int MAXE = 20005 ;

struct Edge {
    int v , n ;
    Edge () {}
    Edge ( int v , int n ) : v ( v ) , n ( n ) {}
} ;

struct Node {
    int L , R , tree , subtree ;
    Node () {}
    Node ( int L , int R , int t , int t2 = 0 ) : L ( L ) , R ( R ) , tree ( t ) , subtree ( t2 ) {}
} ;
struct Tree {
    int l , r , Ls , Rs , sum , lazy ;
} ;

Edge E[MAXE] ;
int H[MAXN] , cntE ;
int vis[MAXN] , siz[MAXN] , pre[MAXN] ;
int Q[MAXN] , head , tail ;
int in[MAXN * 15] , ou[MAXN * 15] , dfs_clock ;
pair < int , int > op[MAXN] ;
//pair < pair < int , int > , int > Root[MAXN * 2] ;
vector < Node > G[MAXN] ;
Node node[MAXN] , Root[MAXN * 2] ;
int cnt ;

int n , m ;
int val[MAXN] ;
LL ans[MAXN] , res ;
int zero[MAXN * 2] , one[MAXN * 2] ;
Tree T[MAXN * 60] ;
int Troot[MAXN * 2] , cur ;
int tot[MAXN * 2] , tmp[MAXN * 2] ;

void init () {
    cnt = 0 ;
    cntE = 0 ;
    dfs_clock = 0 ;
    clr ( tot , 0 ) ;
    clr ( vis , 0 ) ;
    clr ( ans , 0 ) ;
    clr ( H , -1 ) ;
}

void addedge ( int u , int v ) {
    E[cntE] = Edge ( v , H[u] ) ;
    H[u] = cntE ++ ;
}

int get_root ( int s ) {
    head = tail = 0 ;
    pre[s] = 0 ;
    Q[tail ++] = s ;
    while ( head != tail ) {
        int u = Q[head ++] ;
        for ( int i = H[u] ; ~i ; i = E[i].n ) {
            int v = E[i].v ;
            if ( vis[v] || v == pre[u] ) continue ;
            pre[v] = u ;
            Q[tail ++] = v ;
        }
    }
    int root = s , root_siz = n ;
    while ( head ) {
        int u = Q[-- head] , cnt = 0 ;
        siz[u] = 1 ;
        for ( int i = H[u] ; ~i ; i = E[i].n ) {
            int v = E[i].v ;
            if ( vis[v] || v == pre[u] ) continue ;
            siz[u] += siz[v] ;
            if ( cnt < siz[v] ) cnt = siz[v] ;
        }
        cnt = max ( cnt , tail - siz[u] ) ;
        if ( cnt < root_siz ) {
            root_siz = cnt ;
            root = u ;
        }
    }
    return root ;
}

void get_tree ( int u , int f , int tree , int subtree ) {
    in[u] = ++ dfs_clock ;
    for ( int i = H[u] ; ~i ; i = E[i].n ) {
        int v = E[i].v ;
        if ( vis[v] || v == f ) continue ;
        get_tree ( v , u , tree , subtree ) ;
    }
    ou[u] = dfs_clock ;
    G[u].push_back ( Node ( in[u] , ou[u] , tree , subtree ) ) ;
}

void dfs ( int u ) {
    int root = get_root ( u ) ;
    vis[root] = 1 ;
    int tree = ++ cnt ;
    in[root] = ++ dfs_clock ;
    for ( int i = H[root] ; ~i ; i = E[i].n ) {
        int v = E[i].v ;
        if ( vis[v] ) continue ;
        int subtree = ++ cnt ;
        get_tree ( v , 0 , tree , subtree ) ;
        //Root[subtree] = make_pair ( make_pair ( in[v] , ou[v] ) , tree ) ;
        Root[subtree] = Node ( in[v] , ou[v] , tree ) ;
        tot[tree] -= ( ou[v] - in[v] ) * ( ou[v] - in[v] + 1 ) ;
    }
    ou[root] = dfs_clock ;
    tot[tree] += ( ou[root] - in[root] ) * ( ou[root] - in[root] + 1 ) ;
    //Root[tree] = make_pair ( make_pair ( in[root] , ou[root] ) , 0 ) ;
    Root[tree] = Node ( in[root] , ou[root] , tree ) ;
    node[root] = Node ( in[root] , ou[root] , tree ) ;
    for ( int i = H[root] ; ~i ; i = E[i].n ) {
        int v = E[i].v ;
        if ( !vis[v] ) dfs ( v ) ;
    }
}

void pushdown ( int o ) {
    int m = mid ;
    if ( T[o].lazy ) {
        T[ls].lazy ^= 1 ;
        T[rs].lazy ^= 1 ;
        T[ls].sum = m - T[o].l + 1 - T[ls].sum ;
        T[rs].sum = T[o].r - m - T[rs].sum ;
        T[o].lazy = 0 ;
    }
}

void build ( int& o , int l , int r ) {
    o = ++ cur ;
    T[o].l = l ;
    T[o].r = r ;
    T[o].sum = T[o].lazy = 0 ;
    if ( l == r ) return ;
    int m = mid ;
    build ( T[o].Ls , l , m ) ;
    build ( T[o].Rs , m + 1 , r ) ;
}

void update ( int L , int R , int o ) {
    if ( L <= T[o].l && T[o].r <= R ) {
        T[o].lazy ^= 1 ;
        T[o].sum = T[o].r - T[o].l + 1 - T[o].sum ;
        return ;
    }
    pushdown ( o ) ;
    int m = mid ;
    if ( L <= m ) update ( L , R , ls ) ;
    if ( m <  R ) update ( L , R , rs ) ;
    T[o].sum = T[ls].sum + T[rs].sum ;
}

int query ( int L , int R , int o ) {
    if ( L <= T[o].l && T[o].r <= R ) return T[o].sum ;
    pushdown ( o ) ;
    int m = mid ;
    if ( R <= m ) return query ( L , R , ls ) ;
    if ( m <  L ) return query ( L , R , rs ) ;
    return query ( L , R , ls ) + query ( L , R , rs ) ;
}


void show ( int o ) {
    if ( T[o].l == T[o].r ) {
        if ( T[o].l <= 5 ) printf ( "%d " , T[o].sum ) ;
        if ( T[o].l == 5 ) printf ( "\n" ) ;
        return ;
    }
    pushdown ( o ) ;
    int m = mid ;
    show ( ls ) ;
    show ( rs ) ;
}

void solve () {
    int u , v ;
    init () ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &val[i] ) ;
        G[i].clear () ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        scanf ( "%d%d" , &u , &v ) ;
        addedge ( u , v ) ;
        addedge ( v , u ) ;
    }
    dfs ( 1 ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d" , &op[i].first , &op[i].second ) ;
    }
    
    /*for ( int j = 1 ; j <= n ; ++ j ) {
        printf ( "%d %d\n" , node[j].first , node[j].second ) ;
    }*/
    for ( int i = 0 ; i < 15 ; ++ i ) {
        cur = 0 ;
        clr ( tmp , 0 ) ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            build ( Troot[node[j].tree] , node[j].L , node[j].R ) ;
        }
        for ( int j = 1 ; j <= n ; ++ j ) if ( val[j] & 1 ) {
            //printf ( "%d %d\n" , node[j].first , node[j].second , dfs_clock ) ;
            update ( node[j].L , node[j].R , Troot[node[j].tree] ) ;
            for ( int k = 0 ; k < G[j].size () ; ++ k ) {
                int L = G[j][k].L ;
                int R = G[j][k].R ;
                int tree = G[j][k].tree ;
                //if ( i == 0 ) printf ( "%d %d %d %d\n" , L , R , T[Troot[tree]].l , T[Troot[tree]].r ) ;
                update ( L , R , Troot[tree] ) ;
            }
        }
        res = 0 ;
        for ( int j = 1 ; j <= cnt ; ++ j ) {
            int tree = Root[j].tree ;
            int L = Root[j].L ;
            int R = Root[j].R ;
            int L1 = Root[tree].L ;
            int R1 = Root[tree].R ;
            //if ( !i ) printf ( "%d %d %d %d %d %d\n" , L , R , L1 , R1 , j , tree ) ;
            one[j] = query ( L , R , Troot[tree] ) ;
            //printf ( "ok\n" ) ;
            zero[j] = R - L + 1 - one[j] ;
            //if ( i == 0 ) printf ( "%d %d %d %d\n" , L , R , zero[j] , one[j] ) ;
        }
        for ( int j = 1 ; j <= cnt ; ++ j ) {
            if ( Root[j].tree != j ) {
                int tree = Root[j].tree ;
                int L = Root[tree].L ;
                int color = query ( L , L , Troot[tree] ) ;
                int x1 = zero[tree] - zero[j] ;
                int y1 = one[tree] - one[j] ;
                int x2 = zero[j] ;
                int y2 = one[j] ;
                //if ( i == 0 ) printf ( "%d %d %d %d\n" , x1 , x2 , y1 , y2 ) ;
                //if ( !i ) printf ( "%d %d %d %d\n" , x1 , x2 , y1 , y2 ) ;
                //if ( !i ) printf ( "1.%lld " , res ) ;
                int t ;
                if ( color ) t = x1 * x2 + y1 * y2 ;
                else t = x1 * y2 + x2 * y1 ;
                tmp[tree] += t ;
                res += t ;
                //if ( !i ) printf ( "%lld\n" , res ) ;
            } else {
                int tree = Root[j].tree ;
                int L = Root[tree].L ;
                int color = query ( L , L , Troot[tree] ) ;
                //if ( !i ) printf ( "0.%lld " , res ) ;
                res += one[j] - color ;
                tmp[tree] += one[j] - color ;
                //if ( !i ) printf ( "%lld\n" , res ) ;
            }
        }
        //if ( i < 3 ) printf ( "%lld\n" , res ) ;
        ans[0] += res * ( 1 << i ) ;
        for ( int j = 1 ; j <= m ; ++ j ) {
            int x = op[j].first ;
            if ( ( val[x] & 1 ) != ( op[j].second & 1 ) ) {
                for ( int k = 0 ; k < G[x].size () ; ++ k ) {
                    int L = G[x][k].L ;
                    int R = G[x][k].R ;
                    int tree = G[x][k].tree ;
                    int subtree = G[x][k].subtree ;
                    int color = query ( Root[tree].L , Root[tree].L , Troot[tree] ) ;
                    int t ;
                    if ( i == 0 && j == 4 ) {
                        //printf ( "mid:%d %d %d %d\n" , color , op[j].second & 1 , tree , subtree ) ;
                    }
                    one[subtree] = query ( Root[subtree].L , Root[subtree].R , Troot[tree] ) ;
                    zero[subtree] = Root[subtree].R - Root[subtree].L + 1 - one[subtree] ;
                    if ( i == 0 && j == 4 ) {
                        //printf ( "next:%lld %d %d %d %d %d %d\n" , res , tmp[tree] , zero[subtree] , one[subtree] , zero[tree] , one[tree] , t ) ;
                    }
                    zero[tree] -= zero[subtree] ;
                    one[tree] -= one[subtree] ;
                    if ( color ) t = zero[tree] * zero[subtree] + one[tree] * one[subtree] ;
                    else t = zero[tree] * one[subtree] + zero[subtree] * one[tree] ;
                    res -= 2 * t ;
                    tmp[tree] -= 2 * t ;
                    if ( i == 0 && j == 4 ) {
                        //printf ( "next:%lld %d %d %d %d %d %d\n" , res , tmp[tree] , zero[subtree] , one[subtree] , zero[tree] , one[tree] , t ) ;
                    }
                    update ( L , R , Troot[tree] ) ;
                    one[subtree] = query ( Root[subtree].L , Root[subtree].R , Troot[tree] ) ;
                    zero[subtree] = Root[subtree].R - Root[subtree].L + 1 - one[subtree] ;
                    if ( color ) t = zero[tree] * zero[subtree] + one[tree] * one[subtree] ;
                    else t = zero[tree] * one[subtree] + zero[subtree] * one[tree] ;
                    res += 2 * t ;
                    tmp[tree] += 2 * t ;
                    zero[tree] += zero[subtree] ;
                    one[tree] += one[subtree] ;
                }
                int L = node[x].L ;
                int R = node[x].R ;
                int tree = node[x].tree ;
                int color = query ( L , L , Troot[tree] ) ;
                //if ( i == 0 && j == 1 ) printf ( "%d %d %lld\n" , color , op[j].second & 1 , res ) ;
                swap ( zero[tree] , one[tree] ) ;
                update ( L , R , Troot[tree] ) ;
                res -= tmp[tree] ;
                tmp[tree] = tot[tree] - tmp[tree] ;
                res += tmp[tree] ;
                val[x] ^= 1 ;
            }
            ans[j] += res * ( 1 << i ) ;
        }
        for ( int j = 1 ; j <= n ; ++ j ) {
            val[j] >>= 1 ;
        }
        for ( int j = 1 ; j <= m ; ++ j ) {
            op[j].second >>= 1 ;
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        printf ( "%I64d\n" , ans[i] ) ;
    }
}

int main () {
    while ( ~scanf ( "%d%d" , &n , &m ) ) solve () ;
    return 0 ;
}