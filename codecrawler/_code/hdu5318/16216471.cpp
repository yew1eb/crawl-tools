#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std ;
 #pragma comment(linker, "/STACK:1024000000,1024000000")
#define LL __int64
const int MOD = 1e9+7 ;
struct node{
    LL a[60][60] ;
};
char str[60][60] ;
LL a[60] , len[60] ;
stack<int> sta ;
int n ;
node mul(node p,node q) {
    int i , j , k ;
    node temp ;
    for(i = 0 ; i < n ; i++) {
        for(j = 0 ; j < n ; j++){
            temp.a[i][j] = 0 ;
            for(k = 0 ; k < n ; k++) {
                temp.a[i][j] = (temp.a[i][j] + p.a[i][k]*q.a[k][j]) % MOD ;
            }
        }
    }
    return temp ;
}
node pow(node p,int k) {
    node temp ;
    int i , j ;
    memset(temp.a,0,sizeof(temp.a)) ;
    for(i = 0 ; i < n ; i++) temp.a[i][i] = 1 ;
    while( k ) {
        if( k%2 ) temp = mul(temp,p) ;
        p = mul(p,p) ;
        k /=2 ;
    }
    return temp ;
}
int main() {
    int t , m ;
    int i , j , k , l ;
    node temp ;
    LL ans ;
    scanf("%d", &t) ;
    while( t-- ) {
        scanf("%d %d", &n, &m) ;
        for(i = 0 ; i < n ; i++)
            scanf("%I64d", &a[i]) ;
        sort(a,a+n) ;
        n = unique(a,a+n)-a;
        while( !sta.empty() ) sta.pop() ;
        for(i = 0 ; i < n ; i++) {
            do{
                sta.push(a[i]%10) ;
                a[i] /= 10 ;
            }while( a[i] ) ;
            len[i] = 0 ;
            while( !sta.empty() ) {
                str[i][ len[i]++ ] = sta.top()+'0' ;
                sta.pop() ;
            }
            str[i][ len[i] ] == '\0' ;
        }
        memset(temp.a,0,sizeof(temp.a)) ;
        for(i = 0 ; i < n ; i++) {
            for(j = 0 ; j < n ; j++) {
                for(l = 2 ; l <= len[i] && l <= len[j] ; l++) {
                    for(k = 0 ; k < l ; k++)
                        if( str[i][ len[i]-l+k ] != str[j][k] ) break ;
                    if( k >= l ){
                        temp.a[i][j] = 1 ;
                        break ;
                    }
                }
            }
        }
        temp = pow(temp,m-1) ;
        for(i = 0 , ans = 0 ; i < n ; i++){
            for(j = 0 ; j < n ; j++) {
                ans = (ans + temp.a[i][j]) % MOD ;
            }
        }
        printf("%I64d\n", ans) ;
    }

}
