#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[60000][11];
int cnt[11][11];
int three[12];
int m,n;
int f[60000][11];
void init()
{
    three[1]=1;
    for(int i=2;i<=11;i++)
        three[i]=three[i-1]*3;
    for(int i=0;i<three[11];i++)
    {
        int tmp=i;
        for(int j=1;j<=10;j++)
        {
            f[i][j]=tmp%3;
            tmp/=3;
        }
    }
}
int main()
{
    init();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(dp,0x7f,sizeof(dp));
        memset(cnt,0x7f,sizeof(cnt));
        int ans=dp[0][0];
        int inf=ans;
        int x,y,d;
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&d);
            cnt[x][y]=cnt[y][x]=min(cnt[x][y],d);
        }
        for(int i=1;i<=n;i++)
            dp[three[i]][i]=0;
        for(int state=1;state<three[n+1];state++)
        {
            bool ok=1;
            for(int i=1;i<=n;i++)
            {
                if(f[state][i]==0)
                    ok=0;
                if(dp[state][i]==inf)
                    continue;
                for(int j=1;j<=n;j++)
                {
                    if(i==j)
                        continue;
                    if(f[state][j]==2)
                        continue;
                    if(cnt[i][j]==inf)
                        continue;
                    dp[state+three[j]][j]=min(dp[state+three[j]][j],dp[state][i]+cnt[i][j]);
                }
            }
            if(ok)
            {
                for(int i=1;i<=n;i++)
                {
                    ans=min(ans,dp[state][i]);
                }
            }
        }
        if(ans==inf)
            ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}