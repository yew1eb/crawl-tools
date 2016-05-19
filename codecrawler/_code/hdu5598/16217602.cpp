#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;
typedef long long ll;

const int mod = 1000000007;

ll x;
ll le, ri, G, T;

int nn[65], mm[65], xx[65];
ll dp[65][2][2];

void input()
{
    scanf("%lld%lld%lld%lld", &le, &ri, &G, &T);
}

ll cal(ll n, ll m)
{
    memset(dp, 0, sizeof(dp));

    int i;
    for (i = 63; i >= 0; i--)
    {
        nn[i] = (n >> i) & 1;
        mm[i] = (m >> i) & 1;
        xx[i] = (x >> i) & 1;
    }
    int flag = 0;//æ¾é¦ä½çæ è®°
    for (i = 62; i >= 0; i--)
    {
        if (flag == 0)
        {
            if (!nn[i] && !mm[i] && !xx[i])//0 0 0
                continue;
            else if (!nn[i] && !mm[i] && xx[i])//0 0 1
                return 0;
            else if (!nn[i] && mm[i] && !xx[i])//0 1 0
            {
                //å ä¸ºæ¯é¦ä½ï¼åªè½æ¯0 0 0ï¼ä¸å¯è½æ¯1 1 0
                dp[i][1][0] = 1;
            }
            else if (!nn[i] && mm[i] && xx[i])//0 1 1
            {
                //å ä¸ºæ¯é¦ä½ï¼åªè½æ¯0 1 1ï¼ä¸å¯è½æ¯1 0 1
                dp[i][1][1] = 1;
            }
            else if (nn[i] && !mm[i] && !xx[i])//1 0 0
            {
                //å ä¸ºæ¯é¦ä½ï¼åªè½æ¯0 0 0ï¼ä¸å¯è½æ¯1 1 1
                dp[i][0][1] = 1;
            }
            else if (nn[i] && !mm[i] && xx[i])//1 0 1
            {
                //å ä¸ºæ¯é¦ä½ï¼åªè½æ¯1 0 1ï¼ä¸å¯è½æ¯0 1 1
                dp[i][1][1] = 1;
            }
            else if (nn[i] && mm[i] && !xx[i])//1 1 0
            {
                //è¿æ¶å¯ä»¥æ¯ 1 1 0ï¼ä¹å¯ä»¥æ¯0 0 0
                dp[i][1][1] = 1;
                dp[i][0][0] = 1;
            }
            else if (nn[i] && mm[i] && xx[i])//1 1 1
            {
                //è¿æ¶å¯ä»¥æ¯ 1 0 1ï¼ä¹å¯ä»¥æ¯0 1 1
                dp[i][1][0] = 1;
                dp[i][0][1] = 1;
            }
            flag = 1;
        }
        else
        {
            if (!nn[i] && !mm[i] && !xx[i])//0 0 0
            {
                dp[i][1][1] = dp[i + 1][1][1];
                dp[i][0][1] = dp[i + 1][0][1];
                dp[i][1][0] = dp[i + 1][1][0];
                dp[i][0][0] = dp[i + 1][0][0] * 2;

            }
            else if (!nn[i] && !mm[i] && xx[i])//0 0 1
            {
                dp[i][0][1] = dp[i + 1][0][1];
                dp[i][1][0] = dp[i + 1][1][0];
                dp[i][0][0] = dp[i + 1][0][0] * 2;
            }
            else if (!nn[i] && mm[i] && !xx[i])//0 1 0
            {
                dp[i][0][1] = dp[i + 1][0][1];
                dp[i][1][0] = dp[i + 1][1][0];
                dp[i][0][0] = dp[i + 1][0][0] * 2;

                //1 1 0çæåµ
                dp[i][0][0] += dp[i + 1][0][1];

                //0 0 0çæåµ
                dp[i][1][0] += dp[i + 1][1][1];
            }
            else if (!nn[i] && mm[i] && xx[i])//0 1 1
            {
                dp[i][1][1] = dp[i + 1][1][1];
                dp[i][0][1] = dp[i + 1][0][1];
                dp[i][1][0] = dp[i + 1][1][0];
                dp[i][0][0] = dp[i + 1][0][0] * 2;

                // 1 0 1 
                dp[i][0][0] += dp[i + 1][0][1];
            }
            else if (nn[i] && !mm[i] && !xx[i])//1 0 0
            {
                dp[i][0][1] = dp[i + 1][0][1];
                dp[i][1][0] = dp[i + 1][1][0];
                dp[i][0][0] = dp[i + 1][0][0] * 2;

                //0 0 0çæåµænè¿é¨åéæ¾äºåºæ¥
                dp[i][0][0] += dp[i + 1][1][0];
                dp[i][0][1] += dp[i + 1][1][1];

            }
            else if (nn[i] && !mm[i] && xx[i])//1 0 1
            {
                dp[i][1][1] = dp[i + 1][1][1];
                dp[i][0][1] = dp[i + 1][0][1];
                dp[i][1][0] = dp[i + 1][1][0];
                dp[i][0][0] = dp[i + 1][0][0] * 2;

                // 0 1 1
                dp[i][0][0] += dp[i + 1][1][0];
            }
            else if (nn[i] && mm[i] && !xx[i])//1 1 0
            {
                dp[i][1][1] = dp[i + 1][1][1];
                dp[i][0][1] = dp[i + 1][0][1];
                dp[i][1][0] = dp[i + 1][1][0];
                dp[i][0][0] = dp[i + 1][0][0] * 2;

                //0 0 0
                dp[i][0][0] += (dp[i + 1][1][0] + dp[i + 1][0][1] + dp[i + 1][1][1]);
            }
            else if (nn[i] && mm[i] && xx[i])//1 1 1
            {
                dp[i][0][1] = dp[i + 1][0][1];
                dp[i][1][0] = dp[i + 1][1][0];
                dp[i][0][0] = dp[i + 1][0][0] * 2;

                //0 1 1
                dp[i][0][1] += dp[i + 1][1][1];
                dp[i][0][0] += dp[i + 1][1][0];

                //1 0 1
                dp[i][1][0] += dp[i + 1][1][1];
                dp[i][0][0] += dp[i + 1][0][1];
            }
        }
    }
    return (dp[0][0][0] + dp[0][1][0] + dp[0][0][1] + dp[0][1][1])%mod;
}

void solve()
{
    x = G^T;
    ll ans = ((ri - le + 1) * 2) % mod;
    ans = (ans - (cal(ri, ri) - cal(le - 1, ri) * 2 + cal(le-1, le-1)) % mod + mod) % mod;

    printf("%lld\n", ans);
}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--)
    {
        input();
        solve();
    }

    //system("pause");
    return 0;
}