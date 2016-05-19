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
#define maxn 200000+10
char str[maxn] ;
int dp[maxn][2] , a[maxn] ;
int main() {
    int t , step = 0 , i , j , n , temp ;
    scanf("%d", &t) ;
    while( t-- ) {
        scanf("%s", str) ;
        n = strlen(str) ;
        for(i = 0 ; i < n ; i++)
            scanf("%d", &a[i]) ;
        memset(dp,-1,sizeof(dp)) ;
        if( str[0] == '?' ) {
            dp[0][0] = 0 ;
            dp[0][1] = a[0] ;
        }
        else if( str[0] == '0' )
            dp[0][0] = 0 ;
        else
            dp[0][1] = a[0] ;
        for(i = 1 ; i < n ; i++) {
            if( str[i] == '0' ) {
                temp = -1 ;
                if( dp[i-1][0] != -1 )
                    temp = max(temp,dp[i-1][0] ) ;
                if( dp[i-1][1] != -1 )
                    temp = max(temp,dp[i-1][1]+a[i]) ;
                dp[i][0] = temp ;
            }
            else if( str[i] == '1' ) {
                temp = -1 ;
                if( dp[i-1][0] != -1 )
                    temp = max(temp,dp[i-1][0]+a[i]) ;
                if( dp[i-1][1] != -1  )
                    temp = max(temp,dp[i-1][1]) ;
                dp[i][1] = temp ;
            }
            else {
                temp = -1 ;
                if( dp[i-1][0] != -1 )
                    temp = max(temp,dp[i-1][0] ) ;
                if( dp[i-1][1] != -1 )
                    temp = max(temp,dp[i-1][1]+a[i]) ;
                dp[i][0] = temp ;
                temp = -1 ;
                if( dp[i-1][0] != -1 )
                    temp = max(temp,dp[i-1][0]+a[i]) ;
                if( dp[i-1][1] != -1  )
                    temp = max(temp,dp[i-1][1]) ;
                dp[i][1] = temp ;
            }
        }
        printf("Case #%d: %d\n", ++step, max(dp[n-1][0],dp[n-1][1])) ;
    }
    return 0 ;
}