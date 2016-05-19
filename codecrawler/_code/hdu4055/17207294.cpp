#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 1e3 + 2;
const int mod = 1e9 + 7;

int dp[N][N],sum[N][N];

char str[N];

int main()
{
    dp[1][1] = sum[1][1] = 1;
    while(~scanf("%s",str+1))
    {
        int n = strlen(str+1) + 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(str[i-1] == 'I')
                    dp[i][j] = sum[i-1][j-1];
                else if(str[i-1] == 'D')
                    dp[i][j] = (sum[i-1][i-1] - sum[i-1][j-1] + mod) % mod;
                else
                    dp[i][j] = sum[i-1][i-1];
                sum[i][j] = (sum[i][j-1] + dp[i][j]) % mod;
            }
        }
        printf("%d\n",sum[n][n]);
    }
    return 0;
}
