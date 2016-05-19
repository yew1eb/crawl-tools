#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[1005][1005];
int a[1005];
int cnt[1005];

int main()
{
    int N , Q;
    while(scanf("%d%d" , &N , &Q)!= EOF)
    {
        for(int i = 1 ; i <= N ; i ++ ) scanf("%d", &a[i]);
        memset(dp,0,sizeof(0));
        for(int i = 1 ; i <= N ; i ++ )
        {
            for(int j = 1 ; j < i ; j ++ )
            {
                if(a[i] < a[j]) dp[1][i] ++ ;
            }
            dp[1][i] += dp[1][i-1];
        }
        for(int i = 2 ; i <= N ; i ++ )
        {
            int ans = 0;
            for(int j = i ; j <= N ; j ++ )
            {
                if(a[i - 1] > a[j]) ans -= 1 ;
                dp[i][j] = dp[i-1][j] + ans;
            }

        }
        for(int i = 0 ; i < Q ; i ++ )
        {
            int b , c;
            scanf("%d%d", &b , &c);
            printf("%d\n" , dp[b][c]);
        }
    }
    return 0;
}