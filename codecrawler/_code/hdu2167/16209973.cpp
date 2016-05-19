#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1<<16
int s[N],dp[16][N],map[16][16],sum,n,m,ans;

void solve()
{
    m=0;
    for(int i=0; i<(1<<n); i++)
        if((i&(i<<1))==0)//ç¸é»çä¸åçæåµå­èµ·æ¥ï¼å«å¿äºå¤é¢çæ¬å·ï¼æä¹ä¸æ¯å¾æ¸æ¥ä½è¿ç®çä¼åçº§...æå¾è®°ï¼åæ­£å ä¸æ¬å·ç»å¯¹ä¸ä¼é
            s[m++]=i;
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
        for(int j=0; j<m; j++)
        {
            sum=0;
            for(int k=0; k<n; k++)
                if(s[j]&(1<<k))//æ¾å°s[j]è¯¥ç§æåµä¸­é½åäºåªäºæ°ï¼è¿ä¸ªå¯ä»¥éè¿&è¿ç®æ¥å®ç°
                    sum+=map[i][k];
            dp[i][j]=sum;
            for(int k=0; k<m; k++)
            {
                if(s[j]&s[k])//ä¸ä¸ä¸æ»¡è¶³çï¼è·³
                    continue;
                if(s[j]&(s[k]>>1))//å³ä¸ä¸æ»¡è¶³çï¼è·³
                    continue;
                if(s[j]&(s[k]<<1))//å·¦ä¸ä¸æ»¡è¶³çï¼è·³
                    continue;
                dp[i][j]=max(dp[i][j],dp[i-1][k]+sum);//å¾ç®åçç¶æè½¬ç§»æ¹ç¨ï¼ä¸é¢çå¨æ¯æ´åï¼å¯ä¸çdpææ³å°±æ¯è¿
            }
        }
    ans=0;
    for(int i=0; i<m; i++)
        ans=max(ans,dp[n][i]);//æåä¸è¡ä¹æå¾å¤ç¶æï¼æ¾åºè¿äºç¶æä¸­æå¤§ç
    cout<<ans<<endl;
}
int main()
{
    char str[111];//è¯»å¥æ°æ®
    while(gets(str))
    {
        int len=strlen(str);
        n=0;
        for(int i=0; i<len; i+=3)
            map[1][n++]=(str[i]-'0')*10+(str[i+1]-'0');
        for(int i=2; i<=n; i++)
        {
            int nn=0;
            gets(str);
            for(int j=0; j<len; j+=3)
                map[i][nn++]=(str[j]-'0')*10+(str[j+1]-'0');
        }
        solve();
        getchar();
    }
}