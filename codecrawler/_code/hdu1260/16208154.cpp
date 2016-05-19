#include <iostream>
#include <algorithm>
using namespace std;
const int M = 2005;
int num1[M] , num2[M];
int dp[M];
int cas;
int n;
int main()
{
    scanf("%d",&cas);
    while( cas-- ){
        scanf("%d",&n);
        for( int i=1 ; i<=n ; i++ )
            scanf("%d",&num1[i]);
        for( int i=2 ; i<=n ; i++ )
            scanf("%d",&num2[i]);
        dp[0] = 0;
        dp[1] = num1[1];    
        for( int i=2 ; i<=n ; i++ ){
            dp[i] = min( dp[i-1]+num1[i] , dp[i-2]+num2[i] );    
        }
        int t1,t2,t3;
        dp[n] += 8*3600;
        t1 = dp[n]/3600;
        dp[n] %= 3600;
        t2 = dp[n] / 60;
        dp[n] %= 60;
        t3 = dp[n];
        if( t1 >= 12 ){
            printf("%02d:%02d:%02d pm\n",t1-12,t2,t3);
        }
        else
            printf("%02d:%02d:%02d am\n",t1,t2,t3);
    }    
    return 0;
} 
