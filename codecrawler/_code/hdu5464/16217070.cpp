#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int dp[1010][1010];
int num[1010];
const int Mod=1e9+7;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,p;
        scanf("%d%d",&n,&p);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        int sum=1;
        for(int i=1;i<=n;i++)
        {
            num[i]%=p;
            if(num[i]<0) num[i]+=p;
            for(int j=0;j<p;j++) dp[i][j]=dp[i-1][j];
            dp[i][num[i]]=(dp[i][num[i]]+1)%Mod;
            for(int j=0;j<p;j++)
            {
                dp[i][(num[i]+j)%p]=(dp[i-1][j]+dp[i][(num[i]+j)%p])%Mod;
            }
        }
        printf("%d\n",dp[n][0]+1);
    }
}
