#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define max(a,b)    ((a)>(b)?(a):(b))
const int maxn = 105;
double dp[10005];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double p, gai[maxn];
        int n, money[maxn];
        scanf("%lf %d", &p, &n);
        int i, j;
        int sum = 0;
        for (i=0; i<n; i++)
        {
            scanf("%d %lf", &money[i], &gai[i]);
            sum += money[i];
        }
        memset(dp, 0, (sum+1)*sizeof(dp[0]));
        dp[0] = 1;

        if (p <= 1-1e-8)
        {
            for (i=0; i<n; i++)
                for (j=sum; j>=money[i]; j--)
                {
                    double tmp = (1.0-gai[i]) * dp[j-money[i]];
                    dp[j] = max(dp[j], tmp);
                }

            for (i=sum; 1 - dp[i] >= p; i--);
            printf("%d\n", i);
        }
        else
        {
            printf("%d\n", sum);
        }
    }
    return 0;
}