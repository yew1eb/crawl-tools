#include <stdio.h>

int dp[10002] = {1, 2, 8, 20};

int main()
{
    int i, n;
    for(i = 4; i < 10001; ++i)
        dp[i] = dp[i-1] + 6 * (i - 1);
    scanf("%d", &n);
    while(n--){
        scanf("%d", &i);
        printf("%d\n", dp[i]);
    }
    return 0;
}