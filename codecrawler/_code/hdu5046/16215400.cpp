#include <stdio.h>    
#include <string.h>    
#include <algorithm>    
#include <vector>    
#include <math.h>  
#include <stdlib.h>
using namespace std;    

const int maxn = 60 + 10 ;    
const int maxr = 60 + 10 ;    
const int maxnode = 60 * 60 + maxr + 10 ;    

#define FOR( i , A , s ) for( int i = A[s] ; i != s ; i = A[i] )     

struct DLX{    
    // maxn åæ° , maxnode æ»èç¹æ° , maxr è¡æ°    
    int n , sz ;    
    int S[maxn] ;     

    int row[maxnode] , col[maxnode] ;    
    int L[maxnode] , R[maxnode] , U[maxnode] , D[maxnode] ;    
    int H[maxr] ;    

    int ansd , ans[maxr] ;    

    void init( int N ) {    
        n = N ;    
        // ç¬¬ä¸è¡çèæç»ç¹    
        for( int i = 0 ; i <= n ; i ++ ) {    
            U[i] = D[i] = i ;    
            L[i] = i - 1 ;     
            R[i] = i + 1 ;    
        }    
        R[n] = 0 ; L[0] = n ;    
        sz = n + 1 ;    
        // æ¯ä¸åçä¸ªæ°    
        memset( S , 0 , sizeof(S) ) ;    
        // H[i] = -1 è¡¨ç¤ºè¿ä¸è¡è¿æ²¡æ 1     
        // å¦åè¡¨ç¤ºç¬¬ä¸ä¸ª 1 ç sz æ¯å¤å°    
        memset( H , -1 , sizeof(H)) ;    
    }    

    // å¨ç¬¬rè¡ç¬¬cåæ·»å ä¸ä¸ª1    
    void Link( int r , int c ) {    
        row[sz] = r ;    
        col[sz] = c ;    
        S[c] ++ ;    

        D[sz] = c ; U[sz] = U[c] ;    
        D[U[c]] = sz ; U[c] = sz ;    

        if( H[r] < 0 ) { H[r] = L[sz] = R[sz] = sz ; }    
        else{    
            R[sz] = H[r] ;    
            L[sz] = L[H[r]] ;    
            R[L[sz]] = sz ;    
            L[R[sz]] = sz ;    
        }    

        sz ++ ;    

    }    

    // å é¤ ç¬¬ c å    
    void remove ( int c ) {    
        FOR( i , D , c ) {  
            L[R[i]] = L[i] ;  
            R[L[i]] = R[i] ;  
        }  
    }    

    // æ¢å¤ç¬¬ c å    
    void restore( int c ) {   
        FOR( i , D , c ) {  
            L[R[i]] = R[L[i]] = i ;  
        }  
    }    

    bool vis[maxn] ;  

    int f() {  
        int ans = 0 ;  
        FOR( i , R , 0 ) vis[i] = true ;  
        FOR( i , R , 0 ) {  
            if( vis[i] ) {  
                vis[i] = false ;  
                ans ++ ;  
                FOR( j , D , i )  
                    FOR( k , R , j )  
                    vis[col[k]] = false ;  
            }  
        }  
        return ans ;  
    }  

    bool dfs( int d ) {  
        // åªæ  
        if( d + f() > best ) return false ;  
        // R[0] = 0 è¡¨ç¤ºæ¾å°ä¸ä¸ªå¯è¡è§£  
        if( R[0] == 0 ) return d <= best ;    
        // æ¾å° s æå°çå , å å¿«æç´¢çéåº¦    
        int c = R[0] ;    
        FOR( i , R , 0 )  
            if( S[i] < S[c] ) c = i ;  
        FOR( i , D , c ) {    
            remove(i);    
            FOR( j , R , i ) remove( j );    
            if (dfs(d + 1))   
                return true ;    
            FOR( j , R , i ) restore( j ) ;    
            restore( i ) ;    
        }    
        return false ;  
    }    

    bool solve( int k ) {    
        best = k ;  
        return dfs(0) ;  
    }    
    int best ;  
} dlx ;    

int n , m , k ;  
__int64 ABS( __int64 x ) {
    return x  < 0 ? -x : x ;
}

struct Point{  
    __int64 x , y ;  
    void get(){  
        scanf( "%I64d%I64d" , &x , &y ) ;  
    }  

    friend __int64 dist ( const Point &a  , const Point & b ) {  
        return ABS( a.x - b.x ) + ABS ( a.y - b.y ) ;
    }  
};  

Point city[65] ;  

__int64 dis[60*60+10] ;

int lisanhua( int Index ) {
    int cnt = 1 ;
    for( int i = 1 ; i < Index ; i ++ ) {
        if( dis[i] != dis[i-1] ) 
            dis[cnt++] = dis[i] ;
    }
    return cnt - 1 ;
}

int main(){  
    int cas ;  
    int casn = 1 ;
    scanf( "%d" , &cas ) ;  
    while( cas -- ) {  
        scanf( "%d%d" , &n, &k ) ;  
        for( int i = 1 ; i <= n ; i ++ ) {  
            city[i].get() ;  
        } 
        int Index = 0 ;
        for( int i = 1 ; i <= n ; i ++ ) {
            for( int j = i ; j <= n ; j ++ ) {
                dis[Index++] = dist( city[i] , city[j] ) ;
            }
        }
        sort( dis , dis + Index ) ;
        Index = lisanhua( Index ) ;
        __int64 l = 0 , r = Index ;  
        __int64 mid ;  
        while( l < r ) {  
            mid = ( l + r ) / 2 ;  
            dlx.init( n ) ;  
            for( int i = 1 ; i <= n ; i ++ ) {  
                for( int j = 1 ; j <= n ; j ++ ) {  
                    if( dist( city[i] , city[j] ) <= dis[mid] ) {  
                        dlx.Link( i , j ) ;  
                    }  
                }  
            }  
            if( dlx.solve( k ) ) {  
                r = mid ;  
            }else{  
                l = mid + 1 ;  
            }  
        }  
        printf( "Case #%d: %I64d\n" , casn ++ , dis[l] ) ;  
    }  
    return 0 ;  
}  