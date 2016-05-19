#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n,m;
int score[52][52];
int dp[102][52];//dp[i][j]è¡¨ç¤ºä¸ºåiä¸ªé³ç¬¦ï¼ä»¥ç¬¬jç§é³ç¬¦ç»å°¾æè·å¾çæå¤§åæ°
int note[102];
int ans;

void DP()
{
    memset(dp,0,sizeof(dp));
    for(int i=2;i<=n;i++)
    {
        if(note[i]>0)
        {
            if(note[i-1]>0)
                dp[i][note[i]]=dp[i-1][note[i-1]]+score[note[i-1]][note[i]];
            else
            {
                for(int j=1;j<=m;j++)
                    dp[i][note[i]]=max(dp[i][note[i]],dp[i-1][j]+score[j][note[i]]);
            }
        }
        else
        {
            if(note[i-1]>0)
            {
                for(int j=1;j<=m;j++)
                    dp[i][j]=max(dp[i][j],dp[i-1][note[i-1]]+score[note[i-1]][j]);
            }
            else
            {
                for(int j=1;j<=m;j++)
                    for(int k=1;k<=m;k++)
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+score[k][j]);
            }
        }
    }
    ans=-1;
    if(note[n]>0)
        ans=dp[n][note[n]];
    else
    {
        for(int j=1;j<=m;j++)
        {
            if(ans<dp[n][j])
                ans=dp[n][j];
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
            cin>>score[i][j];
        for(int i=1;i<=n;i++)
            cin>>note[i];
        DP();
        cout<<ans<<endl;
    }
    return 0;
}
