#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int mod = 1e9 + 7;

int test, n, p;
long long a[1005];
long long dp[1005][1005];

int main()
{
    //freopen("i.txt","r",stdin);
    //freopen("o.txt","w",stdout);
    
    int i, j;
    cin >> test;
    while (test--)
    {
        cin >> n >> p;
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] = a[i] % p;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (i = 1; i <= n; i++)
        {
            for (j = 0; j < p; j++)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][(j + p - a[i]) % p]) % mod;
            }
        }
        cout << dp[n][0] << endl;
    }
    //system("pause");
    return 0;
}
