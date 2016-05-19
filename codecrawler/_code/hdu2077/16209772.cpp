#include <stdio.h>
///è¿­ä»£
int main()
{
    __int64 dp[21] = {0,1};
    int i;
    for(i = 2; i < 21; ++i )
        dp[i] = 3 * dp[i-1] + 1;///ä»ä¸­é´æ±å­ç§»å¥ç§»é¤
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&i);
        printf("%I64d\n",(dp[i-1] + 1)<<1);///æå¤§çå¯æ¾ä¸é¢
    }

    return 0;
}
