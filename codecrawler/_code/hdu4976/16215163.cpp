//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<cctype>
#include<string>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<map>
#include<set>
using namespace std;
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back(x)
typedef __int64 LL;
//typedef unsigned __int64 ULL;
/* ****************** */
const LL INF = 1LL<<55;
const double INFF = 1e100;
const double eps = 1e-8;
const LL mod = 10000000007LL;
const int NN = 1010;
const int MM = 400010;
/* ****************** */

int re[NN], a[NN], dp[NN][NN];

int main()
{
    int cas, ee = 0;
    int i, j, t, n, max_n, ans;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        memset(re, -1, sizeof(re));
        max_n = 0;
        for(i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
            max_n = max(max_n, a[i]);
        }
        sort(a+1, a+1+n);
        for(i = 1; i <= n; i ++)
        {
            for(j = a[i]; j >= 1; j --)
            {
                if(re[j] == -1)
                {
                    re[j] = a[i];
                    break;
                }
            }
        }

        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(i = 0; i < max_n; i ++)
            for(j = 0; j <= i + 1; j ++)
                if(dp[i][j]!=-1)
                {
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
                    t = j + 1 + i - re[i+1];
                    if(re[i+1] != -1 && t >= 0)
                    {
                        dp[i+1][t] = max(dp[i+1][t], dp[i][j]+1);
                    }
                }

        ans = 0;
        for(j = 0; j <= max_n + 1; j ++)
            ans = max(ans, dp[max_n][j]);
        printf("Case #%d: %d\n", ++ee, ans);
    }
    return 0;
}
