#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s1[105],s2[105];
int dp[105][105];//dp[i][j]ä¸ºi~jçå·æ³
int ans[105],i,j,k,len;

int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        len = strlen(s1);
        memset(dp,0,sizeof(dp));
        for(j = 0; j<len; j++)
        {
            for(i = j; i>=0; i--)//jä¸ºå°¾ï¼iä¸ºå¤´
            {
                dp[i][j] = dp[i+1][j]+1;//åæ¯ä¸ªåç¬å·
                for(k = i+1; k<=j; k++)//iå°jä¸­é´ææçå·æ³
                {
                    if(s2[i]==s2[k])
                        dp[i][j] = min(dp[i][j],(dp[i+1][k]+dp[k+1][j]));//iä¸kç¸åï¼å¯»æ¾iå·å°kçæä¼æ¹æ¡
                }
            }
        }
        for(i = 0; i<len; i++)
            ans[i] = dp[0][i];//æ ¹æ®ansçå®ä¹ååå§å
        for(i = 0; i<len; i++)
        {
            if(s1[i] == s2[i])
                ans[i] = ans[i-1];//å¦æå¯¹åºä½ç½®ç¸ç­ï¼è¿ä¸ªä½ç½®å¯ä»¥ä¸å·
            else
            {
                for(j = 0; j<i; j++)
                    ans[i] = min(ans[i],ans[j]+dp[j+1][i]);//å¯»æ¾jæ¥åå²åºé´å¾å°æä¼è§£
            }
        }
        printf("%d\n",ans[len-1]);
    }

    return 0;
}
