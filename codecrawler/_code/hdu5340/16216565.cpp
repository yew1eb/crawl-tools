#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
#pragma comment(linker,"STACK:102400000,102400000") ;
#define maxn 50000
char str[maxn] , s[maxn] ;
int p[maxn] ;
int pre[maxn] , suf[maxn] ;
int init() {
    int i = 0 , j = 0 , l = strlen(str) ;
    s[j++] = '$' ;
    while( i < l ) {
        s[j++] = '#' ;
        s[j++] = str[i] ;
        i++ ;
    }
    s[j++] = '#' ;
    s[j] = '\0' ;
    return j ;
}
void Manacer(int l) {
    int i , max1 = 0 , id ;
    for(i = 1 ; i < l ; i++) {
        if( max1 > i )
            p[i] = min( p[2*id-i],max1-1 ) ;
        else
            p[i] = 1 ;
        while( s[i-p[i]] == s[i+p[i]] )
            p[i]++ ;
        if( p[i]+i > max1 ) {
            max1 = p[i]+i ;
            id = i ;
        }
    }
}
int solve(int i,int len) {
    int l , r , j , m ;
    l = i-p[i] ;
    r = i+p[i] ;
    if( i%2 ) m = i-1 ;
    else m = i ;
    j = max( r-len+2,2-l ) ;
    j = max(j,0) ;
    if( (l+j)%2 ) j++ ;
    for( ; l+j < m ; j += 2) {
        if( pre[l+j] && suf[r-j] ) break ;
    }
    if( l+j < m ) return 1 ;
    return 0 ;
}
int main() {
    int t , m , i , j , len , l , r ;
    scanf("%d", &t) ;
    while( t-- ) {
        scanf("%s", str) ;
        len = init() ;
        Manacer(len) ;
        memset(pre,0,sizeof(pre)) ;
        memset(suf,0,sizeof(suf)) ;
        for(i = 1 ; i < len ; i++) {
            if( i-p[i]+1 == 1 )
                pre[ i+p[i]-2 ] = 1 ;
            else if( i-p[i]+1 == 2  )
                pre[ i+p[i]-1 ] = 1 ;
            if( i+p[i]-1 == len-1 )
                suf[ i-p[i]+2 ] = 1 ;
            else if( i+p[i]-1 == len-2 )
                suf[ i-p[i]+1 ] = 1 ;
        }
        for(i = 1 ; i <= len-i ; i++) {
            if( solve(i,len) ) break ;
            if( solve(len-i,len) ) break ;
        }
        if( i <= len-i )
            printf("Yes\n") ;
        else
            printf("No\n") ;
    }
    return 0 ;
}
