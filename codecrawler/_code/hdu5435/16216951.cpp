#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int mod = 1e9 + 7;

int dp[100020][20], ans[20];
char a[100020], b[100020];
int solve(char * str)
{
    int ret = 0;
    int len = strlen(str);
    memset(ans, 0, sizeof(ans));
    int pre = 0;
    for (int i = 0; i < len; i++)
    {
        int num = str[i] - '0';
        for (int j = 0; j < num; j++)
            for (int k = 0; k <= 15; k++)
            {
                ans[pre ^ k ^ j] += dp[len - i - 1][k];
                ans[pre ^ k ^ j] %= mod;
            }
        pre ^= num;
    }
    for (int i = 0; i <= 15; i++)
        ret = (ret + (long long)i * ans[i]) % mod;
    return ret;
}
int main()
{
    int t;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i < 100010; i++)
        for (int k = 0; k < 10; k++)
            for (int j = 0; j <= 15; j++)
            {
                dp[i][j ^ k] += dp[i - 1][j];
                dp[i][j ^ k] %= mod;
            }
    scanf("%d", &t);
    int cas = 0;
    while (t--)
    {
        cas++;
        scanf("%s", a);
        scanf("%s", b);
        int len = strlen(b);
        int last = 0;
        for (int i = 0; i < len; i++)
            last ^= (b[i] - '0');
        int ans = (solve(b) - solve(a) + mod) % mod;
        ans = (ans + last) % mod;
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}