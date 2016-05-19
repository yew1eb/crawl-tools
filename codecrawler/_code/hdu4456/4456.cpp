#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define lowbit(x) (x&(-x))
using namespace std ;
struct Operation {
    int op , x , y , z ;
} p[88888] ;
int base = 100000 ;
const int N = 2222222 ;
vector<int> mp ;
int val[N] , tot , n , m ;
const int maxn = 22222 ;

inline int get ( int x , int y ) {
    x = x * base + y ;
    y = lower_bound(mp.begin(),mp.end(),x) - mp.begin() ;
    if ( y == tot || mp[y] != x ) return -1 ;
    return y ;
}

void update ( int x , int y , int z ) {
    while ( x < n*2+100 ) {
        int pos = y ;
        while ( pos < n*2+100 ) {
            int now = get (x,pos) ;
            val[now] += z ;
            pos += lowbit ( pos ) ;
        }
        x += lowbit ( x ) ;
    }
}

int sum ( int x , int y ) {
    int ret = 0 ;
    while ( x ) {
        int pos = y ;
        while ( pos ) {
            int now = get ( x , pos ) ;
            if (now != -1) ret += val[now] ;
            pos -= lowbit ( pos ) ;
        }
        x -= lowbit ( x ) ;
    }
    return ret ;
}

int query ( int x1 , int y1 , int x2 , int y2 ) {
    int ret1 = sum(x1-1,y1-1) , ret2 = sum(x2,y2) , ret3 = sum(x1-1,y2) , ret4 = sum(x2,y1-1) ;
//    printf ( "ret2 = %d\n" , ret2 ) ;
    return ret1+ret2-ret3-ret4 ;
}

int get_num () {
    int n = 0 , flag = 1 ;
    char c ;
    while ( (c = getchar ()) && c != '-' && (c<'0'||c>'9') ) ;
    if ( c == '-' ) flag = -1 ;
    else n = c - '0' ;
    while ( (c = getchar ()) && c >= '0' && c <= '9' ) n = n * 10 + c - '0' ;
    return n * flag ;
}

void add ( int t , int x , int y ) {
        while ( x < n*2+100 ) {
            int pos = y ;
            while ( pos < n*2+100 ) {
			//	if ( tot == N - 1 ) while (1) ;
                mp.push_back ( x * base + pos ) ;
                pos += lowbit ( pos ) ;
            }
            x += lowbit ( x ) ;
        }
}

void read ( int i ) {
    p[i].op = get_num () ;
    p[i].x = get_num () ;
    p[i].y = get_num () ;
    p[i].z = get_num () ;
    int x = p[i].x + p[i].y - 1 , y = n - p[i].x + p[i].y ;
    if ( p[i].op == 1 ) add ( 1 , x , y ) ;
}

int main () {
	while ( scanf ( "%d" , &n ) && n ) {
        scanf ( "%d" , &m ) ;
        mp.clear () ;
        memset ( val , 0 , sizeof ( val ) ) ;
        for ( int i = 1 ; i <= m ; i ++ )
            read ( i ) ;
        sort ( mp.begin() , mp.end() ) ;
        vector<int>::iterator it = unique(mp.begin() , mp.end()) ;
        mp.erase(it,mp.end()) ;
   //     tot = unique ( mp + 1 , mp + tot + 1 ) - mp - 1 ;
		tot = mp.size () ;
        for ( int i = 1 ; i <= m ; i ++ ) {
            int op , x , y , z ;
            op = p[i].op ;
            x = p[i].x ;
            y = p[i].y ;
            z = p[i].z ;
    //        printf ( "op = %d , x = %d , y = %d , z = %d\n" , op , x , y , p[i].z ) ;
            int xx = x + y - 1 , yy = n - x + y ;
            if ( op == 1 ) {
                update ( xx , yy , z ) ;
            } else {
                int x1 = std::max ( 1 , xx  - z ) ;
                int y1 = std::max ( 1 , yy  - z ) ;
                int x2 = std::min ( 2*n-1 , xx  + z ) ;
                int y2 = std::min ( 2*n-1 , yy  + z ) ;
                printf ( "%d\n" , query ( x1 , y1 , x2 , y2 ) ) ;
            }
        }
    }
    return 0 ;
}
