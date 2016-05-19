#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 100000000
int dp[25][505];
int pos[25][15];
int main()
{
    int N, K;
    while(~scanf("%d%d", &N, &K))
    {
        for(int j = 1; j <= N; ++j)
        for(int i = 1; i <= 500; ++i)
            dp[j][i] = INF;
        for(int i = 1; i <= K; ++i)
        {
            scanf("%d", &pos[1][i]);
            dp[1][pos[1][i]] = 0;
        }
        for(int i = 2; i <= N; ++i)
        {
            for(int j = 1; j <= K; ++j)
            {
                scanf("%d", &pos[i][j]);
                for(int k = 1; k <= K; ++k)
                {
                    int temp;
                    if(dp[i][pos[i][j]] > (temp = dp[i - 1][pos[i - 1][k]] + abs(pos[i][j] - pos[i - 1][k])))
                        dp[i][pos[i][j]] = temp;
                }
            }
        }
        int ans = INF;
        for(int i = 1; i <= 500; ++i)
        {
            if(dp[N][i] < ans)
                ans = dp[N][i];
        }
        printf("%d\n", ans);
    }
    return 0;
}