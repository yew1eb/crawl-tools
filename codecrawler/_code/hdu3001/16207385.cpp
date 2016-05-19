#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;
const int INF=0x3f3f3f3f;
int s[12],dp[60000][12],n,m,tir[60000][12],map[12][12];
void init()
{
    s[0]=1;
    for(int i=1; i<=10; i++)
        s[i]=s[i-1]*3;
    for(int i=0; i<=s[10]; i++)
    {
        int t=i;
        for(int j=0; j<10; j++)
        {
            tir[i][j]=t%3;
            t/=3;
        }
    }
}
void DP()
{
    int i,j,k,ans=INF;
    for(i=0; i<s[n]; i++)
    {
        int flag=1;//ææä½é½è¢«éåè¿
        for(j=0; j<n; j++)
        {
            if(0==tir[i][j]) flag=0;//ç¹jå¨iéåå
            if(dp[i][j]==INF) continue;
            for(k=0; k<n; k++)
            {
                if(j==k||tir[i][k]==2)continue;
                if(map[k][j]==INF)continue;
                int l=i+s[k];
                dp[l][k]=min(dp[l][k],dp[i][j]+map[j][k]);
            }
        }
        if(flag)
            for(int t=0; t<n; t++)
            {
                ans=min(ans,dp[i][t]);
            }
    }
    if(ans==INF)cout<<-1<<endl;
    else cout<<ans<<endl;
}
int main()
{
    init();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j,k,a,b,c;
        memset(dp,INF,sizeof(dp));
        memset(map,INF,sizeof(map));
        for(i=0; i<n; i++)dp[s[i]][i]=0;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            a--,b--;
            map[a][b]=map[b][a]=min(map[a][b],c);
        }
        DP();
    }
    return 0;
}
