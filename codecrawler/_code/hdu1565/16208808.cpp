#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int L = 20000;
int n,a[20][20];
int dp[L],tem[L];
int now[L],pre[L];
int ans[L],pre_size,now_size;

void dfs(int id,int k,int p,int sum)
{
    if(k>=n)//è¶è¿nåå¯ä»¥è®°å½è¿ä¸ªç¶æ
    {
        now[++now_size] = p;
        ans[now_size] = sum;
        return ;
    }
    dfs(id,k+2,p|(1<<k),sum+a[id][k]);//è¿ä¸ªä½ç½®åäºï¼é£ä¹å°±è¦å ä¸è¿ä¸ªä½çäºè¿å¶ï¼éè¿æè¿ç®å¾åºï¼è¿ä¸ªä½ç½®åäºçè¯ï¼é£ä¹ä¸ä¸ä¸ªè¦åçè³å°è¦è·³ä¸¤æ ¼
    dfs(id,k+1,p,sum);//è¿ä¸ªä½ç½®ä¸åå¹¶è·³ä¸æ ¼
}

void DP()
{
    int i,j,k;
    for(k = 1; k<=n; k++)
    {
        now_size = 0;
        dfs(k,0,0,0);//æåºæ­¤è¡çææç¶æ
        for(i = 1; i<=now_size; i++)
            dp[i] = 0;
        for(i = 1; i<=now_size; i++)
        {
            for(j = 1; j<=pre_size; j++)
            {
                if(now[i]&pre[j]) continue;//ç¸ä¸ä¸º1ï¼è¯ææç¸é»èä¸ç»§ç»­å¾ä¸
                dp[i] = max(dp[i],tem[j]+ans[i]);
            }
        }
        for(i = 1; i<=now_size; i++)//ç®åè¿è¡çç¶æä¿å­ä¸ºä¸ä¸è¡
        {
            tem[i] = dp[i];
            pre[i] = now[i];
        }
        pre_size = now_size;
    }
}

int main()
{
    int i,j;
    while(~scanf("%d",&n))
    {
        for(i = 1; i<=n; i++)
            for(j = 0; j<n; j++)
                scanf("%d",&a[i][j]);
        tem[1] = pre[1] = 0;//ååä¸ä¸ªï¼ä½æ¯ä½ç½®å¹¶ä¸ç¡®å®ï¼
        pre_size = 1;
        DP();
        int ans = 0;
        for(i = 1;i<=pre_size;i++)
        ans = max(ans,tem[i]);
        printf("%d\n",ans);
    }

    return 0;
}
