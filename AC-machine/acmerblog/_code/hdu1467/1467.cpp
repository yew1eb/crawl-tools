#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define maxn 2100
#define inf 2139062143
using namespace std;

int N;
char map[120*2][120*2];
int dp[120*2][120*2];
int ans;

int DP1()
{
    int i,j;
    int res=0;
    int kk=2*N-1;
    memset(dp,0,sizeof(dp));
    for(i=1; i<=kk; i=i+2)
    {
        if(map[1][i]=='-')
        {
            dp[1][i]=1;
            res=1;
        }
        else
        {
            dp[1][i]=0;
        }
    }

    for(i=2; i<=N; i++)
    {
        kk--;
        for(j=i; j<=kk; j=j+2)
        {
            if(map[i][j]=='-')
            {
                if(map[i-1][j]=='-')
                {
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j+1])+1;
                }
                else
                {
                    dp[i][j]=1;
                }
            }
            else
            {
                dp[i][j]=0;
            }
            res=max(res,dp[i][j]);
        }
    }
    return res;
}

int DP2()
{
    int i,j;
    int res=0;
    int kk=N;
    for(i=N-1; i>=1; i--)
    {
        kk++;
        for(j=i+1; j<=kk; j=j+2)
        {
            if(map[i][j]=='-')
            {
                if(map[i+1][j]=='-')
                {
                    dp[i][j]=min(dp[i+1][j-1],dp[i+1][j+1])+1;
                }
                else
                {
                    dp[i][j]=1;
                }
            }
            else
            {
                dp[i][j]=0;
            }
            res=max(res,dp[i][j]);
        }
    }
    return res;
}

int main()
{
  //  freopen("input.txt","r",stdin);
    int i,j;
    int test=0;
    while(scanf("%d",&N)==1&&N)
    {
        getchar();
        for(i=1; i<=N; i++)
        {
            gets(map[i]+1);
            for(j=2*N-1+i; j<=2*N-1; j++)
            {
                map[i][j]=' ';
            }
            map[i][0]=' ';
        }
        ans=DP1();
        ans=max(ans,DP2());
        printf("Triangle #%d\n",++test);
        printf("The largest triangle area is %d.\n\n",ans*ans);
    }
    return 0;
}