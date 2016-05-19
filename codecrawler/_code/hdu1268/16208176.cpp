#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int w, l;
    while(~scanf("%d %d", &w, &l))
    {
        long long m = 0, n = 0;
        int maxp = 0, maxs = 0;
        long long positive[100005], side[100005];           //æ­£é¢åä¾§é¢çå»æ¯å±æå¤å°æ¨å
        int positive_high[100005], side_high[100005];         //æ­£é¢åä¾§é¢æ¯ä¸ªé«åº¦åºç°çæ¬¡æ°
        memset(positive, 0, sizeof(positive));
        memset(side, 0, sizeof(side));
        memset(positive_high, 0, sizeof(positive_high));
        memset(side_high, 0, sizeof(side_high));
        int temp;
        for(int i = 0; i < w; i++)
        {
            scanf("%d", &temp);
            positive_high[temp]++;
            for(int j = 1; j <= temp; j++)
            {
                positive[j]++;
            }
            maxp = temp > maxp ? temp : maxp;
        }

        for(int i = 0; i < l; i++)
        {
            scanf("%d", &temp);
            side_high[temp]++;
            for(int j = 1; j <= temp; j++)
            {
                side[j]++;
            }
            maxs = temp > maxs ? temp : maxs;
        }

        if(maxs != maxp)
        {
            printf("No solution.\n");
            continue;
        }

        for(int i = 1; i <= maxp; i++)
        {
            n += positive[i] * side[i];            //æå¤§å¼ï¼æ¯å±æ­£é¢åä¾§é¢çä¹ç§¯
        }

        for(int i = 1; i <= maxp; i++)
        {
            if(positive_high[i] || side_high[i])
            {
                m += max(positive_high[i], side_high[i]) * i;        //æå°å¼ï¼å¯¹äºæ¯ä¸ªåºç°çé«åº¦æ­£é¢åä¾§é¢ä¸­åæå¤§å¼
            }
        }

        printf("%lld %lld\n", m, n);
    }
    return 0;
}
