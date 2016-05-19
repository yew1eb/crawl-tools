#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int val[5005];
int dp[255555];

int main()
{
    int n,i,j,a,b,l,sum;
    while(~scanf("%d",&n),n>0)
    {
        memset(val,0,sizeof(val));
        memset(dp,0,sizeof(dp));
        l = 0;
        sum = 0;
        for(i = 0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            while(b--)
            {
                val[l++] = a;//å°ä»·å¼å­å¥æ°ç»
                sum+=a;
            }
        }
        for(i = 0;i<l;i++)
        {
            for(j = sum/2;j>=val[i];j--)//01èå
            {
                dp[j] = max(dp[j],dp[j-val[i]]+val[i]);
            }
        }
        printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
    }

    return 0;
}
