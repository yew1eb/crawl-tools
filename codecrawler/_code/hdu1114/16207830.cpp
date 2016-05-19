#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1000005];

int main()
{
    int t;
    int wa,wb,w;
    int n,val[505],wei[505],i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&wa,&wb);
        w = wb-wa;//å¿é¡»åå»å°çªæ¬èº«éé
        scanf("%d",&n);
        for(i = 0;i<n;i++)
        scanf("%d%d",&val[i],&wei[i]);
        for(i = 0;i<=w;i++)
        {
            dp[i] = 10000000;//å ä¸ºè¦æ±å°çï¼æä»¥dpæ°ç»å¿é¡»å­å¤§æ°
        }
        dp[0] = 0;
        for(i = 0;i<n;i++)
        {
            for(j = wei[i];j<=w;j++)
            {
                dp[j] = min(dp[j],dp[j-wei[i]]+val[i]);
            }
        }
        if(dp[w] == 10000000)
        printf("This is impossible.\n");
        else
        printf("The minimum amount of money in the piggy-bank is %d.\n",dp[w]);
    }

    return 0;
}
