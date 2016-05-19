#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,a[205],b[205],dp[205];

int LICS()
{
    int MAX,i,j,k;
    memset(dp,0,sizeof(dp));
    MAX = 0;
    for(i = 1; i<=n; i++)
    {
        k = 0;
        for(j = 1; j<=n-i+1; j++)
        {
            if(a[i] == b[j])
            {
                if(j!=(n-i+1))//æ²¡ä¸èªèº«å¹é
                {
                    if(dp[j]<(dp[k]+2))//é¿åº¦å 2
                        dp[j] = dp[k]+2;
                }
                else//ä¸èªèº«å¹éäº
                {
                    if(dp[j]<(dp[k]+1))//èªèº«æä»¥åªå 1é¿åº¦
                        dp[j] = dp[k]+1;
                }
            }
            else if(a[i]>b[j] && dp[k]<dp[j])
                k = j;
            if(MAX<dp[j])
                MAX = dp[j];
        }
    }

    return MAX;
}

int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = 1; i<=n; i++)
            scanf("%d",&a[i]);
        for(i = 1; i<=n; i++)
            b[i] = a[n-i+1];
        printf("%d\n",LICS());
    }

    return 0;
}
