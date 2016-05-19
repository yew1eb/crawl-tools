#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1<<29;

int day[15][15],price[15][15][35];
int dp[15][1005];

int main(){
    int n,k;
    int t = 0;
    while (scanf("%d%d",&n,&k) != EOF && n+k){
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                if (i != j){
                    scanf("%d",&day[i][j]);
                    for (int l = 1; l <= day[i][j]; l++)
                        scanf("%d",&price[i][j][l]);
                }
            }
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = INF;

        dp[1][0] = 0;

        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= n; j++)
                for (int l = 1; l <= n; l++)
                    if (j != l){
                        int a = (i - 1) % day[l][j] + 1;  // 看看是坐第几趟的
                        if (price[l][j][a] && dp[l][i-1] != INF)
                            dp[j][i] = min(dp[j][i],dp[l][i-1] + price[l][j][a]);
                    }
        printf("Scenario #%d\n", ++t);
        if (dp[n][k] != INF)
            printf("The best flight costs %d.\n\n", dp[n][k]);
        else printf("No flight possible.\n\n");
    }
    return 0;
}