#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 200005;
int a[maxn];
int dp[maxn];

int main()
{
    int test, test_case = 1, n, m, l;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d%d", &n, &m, &l);
        a[0] = 0, a[n+1] = m;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a+n+2);
        memset(dp, 0, sizeof(dp));
        int step = 0, maxlast = 0;
        for (int i = 1; i <= n + 1; ++i)
        {
            if (a[i] - a[i - 1] <= l) //å¦æä¸¤ç³å¤´é´è·ç¦»å°äºæç­äºlï¼åä¸ä¸å¸æ å³
            {
                if (maxlast + l >= a[i])
                {
                    dp[i] = step + 1;
                }
                else
                {
                    maxlast = a[i - 1];
                    step = dp[i - 1];
                    dp[i] = step + 1;
                }
            }
            else
            {//å¦åï¼ä¸å¸ä¸æ­çäº¤æ¿å¢å maxlast+l+1,a[i-1]+l+1çç³å¤´
                //ç±maxlastå¢å çææ¥è¿a[i]çåæ 
                int ii = maxlast + (a[i] - maxlast) / (l + 1) * (l + 1);
                int ii_step = step + (a[i] - maxlast) / (l + 1) * 2;
                //ç±a[i-1]å¢å çææ¥è¿a[i]çåæ 
                int jj = a[i - 1] + (a[i] - a[i - 1]) / (l + 1) * (l + 1);
                int jj_step = dp[i - 1] + (a[i] - a[i - 1]) / (l + 1) * 2;
                //if ((jj > ii && ii + l >= a[i]) || (jj < ii && jj + l < a[i]))
                if (jj > ii)
                {//è·³å°iiååè·³å°a[i]
                    if (a[i] != ii)
                    {
                        dp[i] = ii_step + 1;
                        maxlast = ii;
                        step = ii_step;
                    }
                    else
                    {
                        dp[i] = ii_step;
                        maxlast = jj;
                        step = jj_step;
                    }
                }
                else
                {
                    if (a[i] != jj)
                    {
                        dp[i] = jj_step + 1;
                        maxlast = jj;
                        step = jj_step;
                    }
                    else
                    {
                        dp[i] = jj_step;
                        maxlast = ii;
                        step = ii_step;
                    }
                }
            }
        }
        printf ("Case #%d: %d\n", test_case++, dp[n + 1]);
    }
    return 0;
}
