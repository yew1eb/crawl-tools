#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#define CLR(arr,x) memset(arr,x,sizeof(arr))
#define FOR(i,j,n) for(j=i;j<n;++j)
#define FOR2(i,j,n) for(j=i;j>=n;--j)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
using namespace std ;
const int maxn = 3000+100;
const int inf = 0x3f3f3f3f ;
int ans[maxn][5000+1] ;
void And() {
    int i  , j , k ;
    CLR(ans,0) ;
    ans[1][0] = 2 , ans[1][1] = 3;
    FOR(2,i,3001) {
        FOR(0,k,2){
            FOR(0,j,5000){
            ans[i][j+k] += ans[1][k]*ans[i-1][j] ;
            }
        }
        FOR(0,j,5000) {
            ans[i][j+1] += ans[i][j]/10 ;
             ans[i][j] = ans[i][j]%10 ;
        }
    }
}
int main() {
    int t , i , j , n , cas = 1;
    cin >>t ;
    And() ;
    while(t--) {
        scanf("%d",&n) ;
        printf("Case #%d: ",cas++) ;
        if(!n) cout << 1 << endl ;
        FOR2(5000,i,0){
            if(ans[n][i]) {
               FOR2(i,j,0) {
                    printf("%d",ans[n][j]) ;
               }
            printf("\n") ;
               break;
            }
        }
    }
    return 0 ;
}