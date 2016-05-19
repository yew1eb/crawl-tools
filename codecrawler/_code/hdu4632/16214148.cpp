#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int mod = 10007;
char str[1005];
int dp[1005][1005];

int main()
{
    int t,i,j,k,len,cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        len = strlen(str);
        for(i = 0; i<len; i++)
            dp[i][i] = 1;//åä¸ªå­ç¬¦è¯å®æ¯ä¸ä¸ªåæå­ä¸²
        for(i = 1; i<len; i++)
        {
            for(j = i-1; j>=0; j--)
            {
                dp[j][i] = (dp[j+1][i]+dp[j][i-1]-dp[j+1][i-1]+mod)%mod;//ä¹åæ²¡æå modï¼waäºï¼j~içåºé´çåææ°æ¯j+1~iä¸j~i-1åºé´åææ°çåï¼ä½æ¯è¦æ³¨æè¿éä¼æéå¤ç
                if(str[i] == str[j])
                    dp[j][i] = (dp[j][i]+dp[j+1][i-1]+1+mod)%mod;//å¦æåºé´ä¸¤å¤´æ¯ç¸ç­çï¼åè¦å ä¸dp[j+1][i-1]+1ï¼å ä¸ºé¦å°¾æ¯å¯ä»¥ç»æä¸ä¸ªåæå­ä¸²çï¼èä¸é¦å°¾å¯ä»¥ä¸ä¸­é´ä»»ä½ä¸ä¸ªåæå­ä¸²ç»ææ°çåæå­ä¸²
            }
        }
        printf("Case %d: %d\n",cas++,dp[0][len-1]);
    }

    return 0;
}
