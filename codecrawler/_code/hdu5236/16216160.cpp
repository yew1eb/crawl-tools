#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=100010;
const double INF=1e16;
double dp[maxn];
int N,X;
double P;
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lf%d",&N,&P,&X);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++)
            dp[i]=(dp[i-1]+1)/(1-P);
        double ans=INF;
        for(int i=1;i<=N;i++)
        {
            int a=N/i,b=N%i;
            ans=min(ans,dp[a+1]*b+dp[a]*(i-b)+X*i);
        }
        printf("Case #%d: %.6lf\n",cas++,ans);
    }
    return 0;
}
