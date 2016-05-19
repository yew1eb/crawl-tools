#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int bit[19];
__int64 dp[19][19][2005];
//posä¸ºå½åä½ç½®
//oä¸ºæ¯ç¹
//lä¸ºåç©
//workä¸ºæ¯å¦æä¸é
__int64 dfs(int pos,int o,int l,int work)
{
    if(pos == -1)
        return l == 0;//å·²ç»å¨é¨ç»åå®äº
    if(l<0)//åç©åä¸ºè´ï¼ååé¢çå¿ç¶å°äº0
        return 0;
    if(!work && dp[pos][o][l]!=-1)//æ²¡æä¸éï¼ä¸å·²ç»è¢«æç´¢è¿äº
        return dp[pos][o][l];
    __int64 ans = 0;
    int end = work?bit[pos]:9;//æä¸éå°±è®¾ä¸ºä¸éï¼å¦åå°±è®¾ä¸º9
    for(int i=0; i<=end; i++)
    {
        int next = l;
        next += (pos-o)*i;//åç©
        ans+=dfs(pos-1,o,next,work&&i==end);
    }
    if(!work)
        dp[pos][o][l] = ans;
    return ans;
}

__int64 solve(__int64 n)
{
    int len = 0;
    while(n)
    {
        bit[len++] = n%10;
        n/=10;
    }
    __int64 ans = 0;
    for(int i = 0; i<len; i++)
    {
        ans+=dfs(len-1,i,0,1);
    }
    return ans-(len-1);//æé¤æ0,00,000....è¿äºæåµ
}

int main()
{
    int T;
    __int64 l,r;
    scanf("%d",&T);
    memset(dp,-1,sizeof(dp));
    while(T--)
    {
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",solve(r)-solve(l-1));
    }

    return 0;
}
