#include <stdio.h>
#include <string.h>
#define MAXN 16
#define INF 0x7fffffff
struct tt {
    int time, deadline;
    char name[105];
} hw[MAXN];

struct t {
    int pre, now;
    int score, time;
    t() {pre = -1;}
} dp[1 << MAXN];

void print(int k)
{
    if(dp[k].pre!=-1)
    {
        print(dp[k].pre);
        printf("%s\n", hw[ dp[k].now ].name );
    }
}
int main()
{
    int T, n, s, i, recent, past, reduce, j, max;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%s %d %d", &hw[i].name, &hw[i].deadline, &hw[i].time);
        max = 1 << n;
        for (s = 1; s < max; s++) {
            dp[s].score = INF;
            for (i = n - 1; i >= 0; i--) {
                recent = 1 << i;
                if (s & recent) {
                    past = s - recent;
                    reduce = dp[past].time + hw[i].time - hw[i].deadline;
                    if (reduce < 0)
                        reduce = 0;
                    if (reduce + dp[past].score < dp[s].score) {
                        dp[s].score = dp[past].score + reduce;
                        dp[s].now = i;
                        dp[s].pre = past;
                        dp[s].time = dp[past].time + hw[i].time;
                    }
                }
            }
        }
        printf("%d\n", dp[max - 1].score);
        print(max-1);
    }
    return 0;
}
