#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <algorithm>
using namespace std ;
#pragma comment(linker, "/STACK:102400000,102400000")
#define LL __int64
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define maxn 310000
int p[maxn] ;
int s[maxn] , str[maxn] ;
int cl[maxn<<2] ;
vector <int> vec[maxn] ;
int init(int l) {
    int i = 0 , j = 0 ;
    str[j++] = -2 ;
    while( i < l ) {
        str[j++] = -1 ;
        str[j++] = s[i] ;
        i++ ;
    }
    str[j++] = -1 ;
    str[j] = -3 ;
    return j ;
}
void Manacer(int l) {
    int i , max1 = 0 , id ;
    for(i = 1 ; i < l ; i++) {
        if( max1 > i )
            p[i] = min(p[2*id-i],max1-i) ;
        else
            p[i] = 1 ;
        while( str[i-p[i]] == str[i+p[i]] )
            p[i]++ ;
        if( p[i]+i > max1) {
            max1 = p[i] + i ;
            id = i ;
        }
    }
}
void push_up(int rt) {
    cl[rt] = max(cl[rt<<1],cl[rt<<1|1]) ;
}
void update(int i,int k,int l,int r,int rt) {
    if( l == r ) {
        if( k ) cl[rt] = i ;
        else cl[rt] = 0 ;
        return ;
    }
    int mid = (l+r)/2 ;
    if( i <= mid ) update(i,k,l,mid,rt<<1) ;
    else update(i,k,mid+1,r,rt<<1|1) ;
    push_up(rt) ;
}
int query(int ll,int rr,int l,int r,int rt) {
    if( ll > rr || ll > r || rr < l ) return -1 ;
    if( ll <= l && rr >= r ) return cl[rt] ;
    int mid = (l+r)/2 ;
    return max( query(ll,rr,l,mid,rt<<1) , query(ll,rr,mid+1,r,rt<<1|1) ) ;
}
int main() {
    int t , step = 0 ;
    int i , j , n , m , l , k , max1 ;
    scanf("%d", &t) ;
    while( t-- ) {
        scanf("%d", &n) ;
        for(i = 0 ; i < n ; i++)
            scanf("%d", &s[i]) ;
        l = init(n) ;
        Manacer(l) ;
        for(i = 0 ; i < l ; i++)
            vec[i].clear() ;
        for(i = 1 ; i < l ; i += 2 ) {
            vec[ i-p[i]+1 ].push_back(i) ;
        }
        memset(cl,-1,sizeof(cl)) ;
        max1 = -1 ;
        for(i = 1 ; i < l ; i += 2) {
            m = vec[i].size() ;
            for(j = 0 ; j < m ; j++)
                update(vec[i][j],1,1,l,1) ;
            update(i,0,1,l,1) ;
            k = query(i+1,i+p[i]-1,1,l,1) ;
            max1 = max(max1,(k-i)/2*3) ;
        }
        if( max1 == -1 ) max1 = 0 ;
        printf("Case #%d: %d\n", ++step, max1) ;
    }
    return 0 ;
}