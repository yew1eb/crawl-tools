/**
hdu5435 æ°ä½dpï¼å¤§æ°çå¤çï¼
é¢ç®å¤§æï¼ä¸ä¸ªæ°å­çå¼ä¸ºå®åä¸ªä½ä¸æ°å­å¼æçç»æï¼ç»å®ä¸¤ä¸ªæ°ï¼é®äºèé­åºé´åææææ°å­å¼å¾åä¸ºå¤å°ï¼
è§£é¢æè·¯ï¼æç¨çæ¯è®°å¿è¯æç´¢çåæ³ï¼å¥½åéå½èæ¶æ¯è¾å¤å§ï¼æ¯èµæ¶è¿äºï¼åæ¥ç»å¤æäºï¼æåèæ¯TLEã
           ç½ä¸å­¦çæ¹æ³ï¼ dp[i][j][k]è¡¨ç¤ºåiä½æ°ï¼k==0||k==1ï¼å¼æå¼ä¸ºjçæ°æå¤å°ä¸ªï¼kä¸º0åè¡¨ç¤ºå°ç»å°¾äºï¼1è¡¨ç¤ºæ²¡æå°ç»å°¾
           æåæ³¨æåå«åæ¨¡ä¼TLEï¼å·ä½çä»£ç æä¹å®ç°çå§
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
const int maxn=100005;
const LL mod=1e9+7;

char s1[maxn],s2[maxn];
int bit[maxn];
LL dp[maxn][16][2];

LL solve(char *a)
{
    int n=strlen(a);
    for(int i=1; i<=n; i++)bit[i]=a[i-1]-'0';
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=0; i<n; i++)
    {
        int num=bit[i+1];
        for(int j=0; j<16; j++)
        {
            dp[i][j][0]%=mod;
            dp[i][j][1]%=mod;
            if(dp[i][j][0]>0)
            {
                dp[i+1][j^num][0]+=dp[i][j][0];
                for(int k=0; k<num; k++)
                {
                    dp[i+1][j^k][1]+=dp[i][j][0];
                }
            }
            if(dp[i][j][1]>0)
            {
                for(int k=0; k<=9; k++)
                {
                    dp[i+1][j^k][1]+=dp[i][j][1];
                }
            }
        }
    }
    LL ans=0;
    for(int i=1; i<=15; i++)
    {
        ans+=(dp[n][i][0]+dp[n][i][1])*(LL)i;
        ans%=mod;
    }
    ans%=mod;
    return ans;
}

int main()
{
    int T,tt=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",s1,s2);
        int n=strlen(s1);
        LL ans=s1[0]-'0';
        for(int i=1; i<n; i++)
            ans^=(s1[i]-'0');
        printf("Case #%d: %I64d\n",++tt,(solve(s2)-solve(s1)+ans+mod)%mod);
    }
    return 0;
}
