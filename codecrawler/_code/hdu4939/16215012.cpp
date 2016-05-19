#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1505;
typedef __int64 LL;
LL dp[N][N];
int main()
{
    LL x, y, z, t, n, i, j;
    int T, cas = 0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d",&n,&x,&y,&z,&t);
        memset(dp, 0, sizeof(dp));
        LL ans = n * t * x; //å¨é¨æ¾çº¢å¡
        for(i = 1; i <= n; i++)  //åiä¸ªåä½é¿åº¦
        {
            for(j = 0; j <= i; j++) // èå¡æ°é
            {
                if(j == 0)
                    dp[i][j] = dp[i-1][j] + (i - j - 1) * y * t;
                else
                {
                    LL tmp1 = dp[i-1][j-1] + (i - j) * y * (t + (j - 1) * z); //ç¬¬jä¸ªåä½é¿åº¦æ¾èå¡
                    LL tmp2 = dp[i-1][j] + (i - j - 1) * y * (t + j * z); //ç¬¬jä¸ªåä½é¿åº¦ä¸æ¾èå¡
                    dp[i][j] = max(tmp1, tmp2);
                }
                ans = max(ans, dp[i][j] + (n - i) * x * (t + j * z) + (n - i) * (t + j * z) * (i - j) * y);
            }
        }
        printf("Case #%d: %I64d\n", ++cas, ans);
    }
    return 0;
}