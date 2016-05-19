#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[32768];

int main()
{
    int n;
    int val[3] = {1,2,3};
    while(~scanf("%d",&n))
    {
        int i,j;
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(i = 0;i<3;i++)
        {
            for(j = val[i];j<=n;j++)
            {
                dp[j]+=dp[j-val[i]];
            }
        }
        printf("%d\n",dp[n]);
    }

    return 0;
}
