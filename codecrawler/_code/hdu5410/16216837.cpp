#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

const int N = 2010;

int dp[N];
int p[N],w[N],k[N];
int n,m;
int flag[N][N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&p[i],&w[i],&k[i]);
        }
        int maxx = 0;
        memset(flag,0,sizeof(flag));
        memset(dp,0,sizeof(dp));
        for(int i=0; i<m; i++)
        {
            for(int j=n; j>=p[i]; j--)
            {
                dp[j] = max(dp[j],dp[j-p[i]]+w[i]+k[i]);
                maxx = max(dp[j],maxx);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=p[i];j<=n;j++){
                dp[j] = max(dp[j],dp[j-p[i]]+w[i]);
                maxx = max(dp[j],maxx);
            }
        }
        printf("%d\n",maxx);
    }

    return 0;
}
