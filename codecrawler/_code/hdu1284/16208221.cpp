#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

__int64 dp[33005]={0};
int n;

int main()
{
    dp[0] = 1;
    for( int i=1 ; i<=3 ; i++ )
        for( int j=i ; j<=33000 ; ++j )
            dp[j] += dp[j-i];
    while( scanf("%d",&n) == 1 ){
        printf("%I64d\n",dp[n]);
    }    
    return 0;
}
