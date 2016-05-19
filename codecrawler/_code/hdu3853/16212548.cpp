#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

double dp[1005][1005],map[1005][1005][3];

int main()
{
    int r,c,i,j,k;
    while(~scanf("%d%d",&r,&c))
    {
        memset(dp,0,sizeof(dp));
        for(i = 1; i<=r; i++)
            for(j = 1; j<=c; j++)
                for(k = 0; k<3; k++)
                    scanf("%lf",&map[i][j][k]);
        for(i = r; i>0; i--)
        {
            for(j = c; j>0; j--)
            {
                if(i == r && j == c)//å°è¾¾ç»ç¹äº
                    continue;
                if(fabs(1-map[i][j][0])<1e-7)//åçåå°çæ¦çä¸º1
                    continue;
                dp[i][j] = (map[i][j][1]*dp[i][j+1]+map[i][j][2]*dp[i+1][j]+2)/(1-map[i][j][0]);//+2æ¯å°ä¸ä¸æ ¼æ¶èçè½é
            }
        }
        printf("%.3lf\n",dp[1][1]);
    }

    return 0;
}
