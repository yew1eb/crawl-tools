#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf ((1<<30)-1)
int map[12][12];
int dp[59049][12];//iç¶æå½åå¨jç¹
int dig[59049][12];//iç¶æjç¹å»è¿å æ¬¡
int thr[12]= {0,1,3,9,27,81,243,729,2187,6561,19683,59049};
int main()
{
    int n,m;
    int a,b,c;
    memset(dig,0,sizeof(dig));
    for(int i=0; i<59049; ++i)
    {
        int t=i;
        for(int j=1; j<=10&&t; ++j)
        {
            dig[i][j]=t%3;
            t/=3;
        }
    }
    for(; ~scanf("%d%d",&n,&m);)
    {
        memset(map,-1,sizeof(map));
        memset(dp,-1,sizeof(dp));
        for(; m--;)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(map[a][b]==-1)
                map[a][b]=map[b][a]=c;
            else
                map[a][b]=map[b][a]=min(map[a][b],c);//æ¶é¤éè¾¹
        }
        for(int i=1; i<=n; ++i) dp[thr[i]][i]=0;
        int ans=inf;
        for(int i=0; i<thr[n+1]; ++i)
        {
            bool flag=true;
            for(int j=1; j<=n; ++j)
            {
                if(!dig[i][j]) flag=false;
                if(dp[i][j]==-1) continue;
                for(int k=1; k<=n; ++k)
                {
                    if((k==j)||(map[j][k]==-1)||(dig[i][k]>=2))
                        continue;
                    if((dp[i+thr[k]][k]==-1)||(dp[i+thr[k]][k]>dp[i][j]+map[j][k]))
                        dp[i+thr[k]][k]=dp[i][j]+map[j][k];
                }
            }
            if(flag)
            {
                for(int j=1; j<=n; ++j)
                    if(dp[i][j]!=-1)
                        ans=min(ans,dp[i][j]);
            }
        }
        if(ans==inf) puts("-1");
        else         printf("%d\n",ans);
    }
    return 0;
}
