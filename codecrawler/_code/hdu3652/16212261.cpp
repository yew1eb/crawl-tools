#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int bit[15];
int dp[15][15][3];
//dp[i][j][k]
//i:æ°ä½
//j:ä½æ°
//k:3ç§æä½ç¶åµï¼0ï¼æ«å°¾ä¸æ¯1,1ï¼æ«å°¾æ¯1,2ï¼å«æ13

int dfs(int pos,int mod,int have,int lim)//limè®°å½ä¸é
{
    int num,i,ans,mod_x,have_x;
    if(pos<=0)
        return mod == 0 && have == 2;
    if(!lim && dp[pos][mod][have] != -1)//æ²¡æä¸éå¹¶ä¸å·²è¢«è®¿é®è¿
        return dp[pos][mod][have];
    num = lim?bit[pos]:9;//åè®¾è¯¥ä½æ¯2ï¼ä¸ä¸ä½æ¯3ï¼å¦æç°å¨ç®å°è¯¥ä½ä¸º1ï¼é£ä¹ä¸ä¸ä½æ¯è½åå°9çï¼å¦æè¯¥ä½ä¸º2ï¼ä¸ä¸ä½åªè½åå°3
    ans = 0;
    for(i = 0; i<=num; i++)
    {
        mod_x = (mod*10+i)%13;//çæ¯å¦è½æ´é¤13ï¼èä¸ç±äºæ¯ä»åæ¥æ°å­æé«ä½å¼å§ç®ï¼ç»å¿çåå­¦å¯ä»¥åç°ï¼äºå®ä¸è¿ä¸ªè¿ç¨å°±æ¯ä¸ä¸ªé¤æ³è¿ç¨
        have_x = have;
        if(have == 0 && i == 1)//æ«å°¾ä¸æ¯1ï¼ç°å¨å å¥çæ¯1
            have_x = 1;//æ è®°ä¸ºæ«å°¾æ¯1
        if(have == 1 && i != 1)//æ«å°¾æ¯1ï¼ç°å¨å å¥çä¸æ¯1
            have_x = 0;//æ è®°ä¸ºæ«å°¾ä¸æ¯1
        if(have == 1 && i == 3)//æ«å°¾æ¯1ï¼ç°å¨å å¥çæ¯3
            have_x = 2;//æ è®°ä¸ºå«æ13
        ans+=dfs(pos-1,mod_x,have_x,lim&&i==num);//lim&&i==numï¼å¨æå¼å§ï¼ååºçnumæ¯æé«ä½ï¼æä»¥å¦æiæ¯numå°ï¼é£ä¹içä¸ä¸ä½é½å¯ä»¥å°è¾¾9ï¼èi==numäºï¼æå¤§è½å°è¾¾çå°±åªæ,bit[pos-1]
    }
    if(!lim)
        dp[pos][mod][have] = ans;
    return ans;
}

int main()
{
    int n,len;
    while(~scanf("%d",&n))
    {
        memset(bit,0,sizeof(bit));
        memset(dp,-1,sizeof(dp));
        len = 0;
        while(n)
        {
            bit[++len] = n%10;
            n/=10;
        }
        printf("%d\n",dfs(len,0,0,1));
    }

    return 0;
}
