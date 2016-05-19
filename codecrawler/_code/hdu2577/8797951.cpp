#include <stdio.h>
#include <string.h>
#define MAXN 105
#define min(a,b) ((a)<(b)?(a):(b))
const int shift = 1;
const int on = 1;
const int off = 1;
int dp[MAXN][2];
//dp[][0] ±íÊ¾¹ØÁË caps lock; dp[][1]±íÊ¾¿ª×Åcaps lock
char str[MAXN];

int solve()
{
    scanf("%s", str);
    int len = strlen(str);
    int i;
    if (str[0] >= 'A' && str[0] <= 'Z') {
        dp[0][0] = shift + 1;
        dp[0][1] = on + 1;
    } else {
        dp[0][0] = 1;
        dp[0][1] = 1 + on;
    }
    for (i = 1; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            dp[i][0] = min(dp[i - 1][0] + shift + 1, dp[i - 1][1] + 1 + off);
            dp[i][1] = min(dp[i - 1][0] + on + 1, dp[i - 1][1] + 1);
        } else {
            dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + off + 1);
            dp[i][1] = min(dp[i - 1][0] + 1 + on, dp[i - 1][1] + shift + 1);
        }
    }
    return dp[len - 1][0];
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
    return 0;
}
